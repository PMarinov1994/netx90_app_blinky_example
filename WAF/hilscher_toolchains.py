#!/usr/bin/env python
# encoding: utf-8

import os
import sys
import re

import waflib.Tools.gcc
import waflib.Tools.gxx

from waflib import Build, Context, Options, Utils
from waflib.Configure import conf
from waflib.TaskGen import feature, before_method

def options(opt):
    opt.add_option('--custom-toolchain', action='store_true', dest='use_custom_toolchain', default=False,
                    help=u'Use a custom toolchain for all builds')

    opt.add_option('--compiler-prefix', action='store', dest='custom_toolchain_prefix', default='arm-none-eabi',
                    help='Select a custom compiler prefix (e.g. "arm-none-eabi" [default])')

    opt.add_option('--compiler-path', action='store', dest='custom_toolchain_path', default=None,
                    help=r'Select a custom compiler path (e.g. "C:\Programme\Codesourcery\Sourcery G++ Lite\bin")')

    opt.add_option('--compiler-driver', action='store', dest='custom_toolchain_driver', default='gcc',
                    help=r'Select a custom compiler driver (e.g. "gcc" [default])')

    opt.add_option('--cxxcompiler-driver', action='store', dest='custom_toolchain_cxxdriver', default='g++',
                    help=r'Select a custom C++ compiler driver (e.g. "g++" [default])')

    opt.load('asm gcc')

def configure(conf):
    conf.setenv('')

    if not conf.env['CONDITIONS']:
        raise conf.errors.WafError(u'Must load hilscher_netx before hilscher_toolchains in %s' % conf.cur_script.abspath())

    conf.env['use_custom_toolchain'] = conf.options.use_custom_toolchain

    for toolchain in conf.get_requested_toolchains():
        try:
            find_cross_gcc(conf, toolchain)
        except conf.errors.ConfigurationError:
            conf.start_msg("Toolchain '" + toolchain + "'")
            conf.end_msg("not found (Some projects may not be available for building)", 'YELLOW')

    if conf.options.use_custom_toolchain or conf.options.custom_toolchain_path:
        find_cross_gcc(conf, 'custom')

@conf
def find_cross_gcc(conf, name):
    '''This function is only left for backwards compat'''
    conf.configure_toolchain(name)

    conf.start_msg("Toolchain '" + name + "'")
    conf.end_msg("%s %s" %(conf.env.CC_NAME, ".".join(conf.env.CC_VERSION)))

    conf.setenv(name, conf.env)
    conf.setenv('')

@feature('*')
@before_method('propagate_uselib_vars')
def apply_conditions(self):
    ''' Apply build conditions '''

    _vars = self.get_uselib_vars()
    env = self.env

    for var in _vars:
        env.append_value(var, env[var + '__debug'])

    for var in _vars:
        env.append_value(var, env[var + '__optimize'])

    # For legacy wscripts, set feature to include feature vars as
    # previous. legacy scripts should be reworked at some time
    self.features = ['compile_' + self.env.CONDITIONS] + Utils.to_list(getattr(self, 'features', []))

###############################################################################
###############################################################################
# Support functions to define toolchains and devices
###############################################################################
###############################################################################

class toolchain(object):
    ''' a special decorator class used to wrap common actions around
        a toolchain configure func and toregister all defined toolchains'''
    toolchains = {}

    def __init__(self, name, *aliases):
        super(toolchain,self).__init__()
        self.name    = name
        self.envname = 'toolchain_%s' % self.name

        self.toolchains[self.name] = self

        for x in aliases:
            self.toolchains[x] = self

    def __call__(self,*args,**kwargs):
        configure_func =  getattr(self,'configure_function',None)

        if configure_func:
            return self.configure_toolchain(*args,**kwargs)
        else:
            # this will be invoked on the first call
            return self.setup_configure_func(*args,**kwargs)

    def setup_configure_func(self,func):
        self.configure_function = func
        return self

    def configure_toolchain(self,ctx):
        envname = self.envname

        if envname in ctx.all_envs:
            ctx.setenv(envname)
        else:
            ctx.setenv('')
            ctx.setenv(envname,ctx.env)
            ctx.env['TOOLCHAIN'] = self.name

            try:
                self.configure_function(ctx)
            except:
                ctx.setenv('')
                del ctx.all_envs[envname]
                raise

    def get_env(self, ctx):
        return ctx.all_envs[self.envname]

    def select_toolchain(self,ctx):
        envname = self.envname

        if envname in ctx.all_envs:
            ctx.setenv(envname)
        else:
            raise ctx.errors.ConfigurationError('Toolchain %s not configured' % self.name)

    def target_triple_func(self, func):
        self.target_triple = func

    @classmethod
    def alias(cls, toolchain, aliases):
        toolchains = cls.toolchains

        orig = toolchains[toolchain]

        aliases = Utils.to_list(aliases)
        for x in Utils.to_list(aliases):
            if x not in toolchains:
                toolchains[x] = orig


    @classmethod
    def get_toolchain_info(cls, bld, toolchain, build_id, platform):
        if build_id:
            bld.setup_build(build_id)
        else:
            if toolchain in bld.all_envs:
                bld.setenv(toolchain)
            elif "toolchain_" + toolchain in bld.all_envs:
                bld.setenv("toolchain_" + toolchain)
            else:
                bld.fatal("Toolchain not found")

        t = cls.toolchains[bld.env['TOOLCHAIN']]

        return t.target_triple(bld, platform), \
               '.'.join(bld.env['CC_VERSION'])

    @classmethod
    def get_toolchain_info_on_error(cls, bld, toolchain, platform):
        bld.setenv('')

        try:
            t = cls.toolchains[toolchain]
        except:
            target_triple = 'unknown-notfound-none'
        else:
            target_triple = t.target_triple(bld, platform) or 'unknown-notfound-none'

        return target_triple, 'x.x.x'

    @classmethod
    def get_name_prefix(cls, bld, toolchain = None, suffix = None, build_id = None, platform = None):
        """
        Constructs a clean prefix for the component names (e.g. "arm-hitex-elf/4.0.3/rcX_V2.0/")
        <b> Mandatory parameter </b>
        @param toolchain \b string: identification of toolchain to use in build.
        @param suffix \b string: identification of the rcX (e.g. "rcX_V2.0", "rcX_V2.1" and so on).
        """
        try:
            target_triple, version = cls.get_toolchain_info(bld, toolchain, build_id, platform)
        except bld.errors.WafError:
            target_triple, version = cls.get_toolchain_info_on_error(bld, toolchain, platform)
        finally:
            bld.setenv('')

        return "/".join(x for x in (target_triple, version, suffix, '') if x is not None)

# register get_name_prefix function with configuration/build context
conf(toolchain.get_name_prefix)

def get_toolchain(name):
    u''' Getter function to work around name clashes '''
    global toolchain
    return toolchain.toolchains[name]

@conf
def configure_toolchain(conf,name):
    try:
        func = get_toolchain(name)
    except KeyError:
        raise conf.errors.ConfigurationError('Unknown toolchain %s' % name)

    func(conf)

def set_optimize_flags(env, conditions, **kwargs):
    if conditions != env.CONDITIONS:
        return

    for var,value in kwargs.items():
        if value is not None:
            env[var.upper() + '__optimize'] = Utils.to_list(value)

@conf
def set_toolchain_optimize_flags(conf, toolchain, conditions, cflags = None, cxxflags = None, defines = None, linkflags = None):
    u''' Set/override optimization flags for particular condition'''

    if conf.cmd != 'configure':
        conf.fatal(u'Function set_toolchain_optimize_flags() only allowed in configure()')

    env = get_toolchain(toolchain).get_env(conf)
    set_optimize_flags(env,conditions, cflags = cflags, cxxflags = cxxflags, defines=defines, linkflags=linkflags)


@conf
def set_target_optimize_flags(bld, name, conditions, cflags = None, cxxflags = None, defines = None, linkflags = None):
    u''' Set/override optimization flags for particular condition'''

    if not isinstance(bld,Build.BuildContext):
        bld.fatal(u'Function set_target_optimize_flags() only allowed in build()')

    try:
        env = bld.all_envs['target_' + name]
    except KeyError:
        raise bld.errors.WafError(u'Environment for target \'%s\' not found. (Target not yet declared?)' % name)

    set_optimize_flags(env, conditions, cflags = cflags, cxxflags = cxxflags, defines=defines, linkflags=linkflags)

@conf
def select_toolchain(ctx,name):
    try:
        func = get_toolchain(name).select_toolchain
    except KeyError:
        raise ctx.errors.ConfigurationError('Unknown toolchain %s' % name)
    func(ctx)

    # Sanity check to ensure that configure command was invoked with same arguments
    # as build command
    if ctx.options.conditions is not None:
        if ctx.env.CONDITIONS != ctx.options.conditions:
            raise ctx.errors.WafError('Condition mismatch between build & configure')

class device(object):
    ''' a special decorator class used to wrap common actions around
        a device configure func and to register all know device setups'''
    devices = {}

    def __init__(self,devices,toolchains):
        super(device,self).__init__()

        devices = Utils.to_list(devices)
        self.name       = '_'.join(devices)
        self.toolchains = Utils.to_list(toolchains)

        global toolchain

        for x in self.toolchains:
            if x not in toolchain.toolchains:
                raise Exception('Unknown Toolchain %s' % x)

        for x in devices:
            self.devices.setdefault((x, None), self)

            for y in self.toolchains:
                self.devices[(x, y)] = self


    def __call__(self,*args,**kwargs):
        configure_func =  getattr(self,'configure_function',None)

        if configure_func:
            return self.configure_device(*args,**kwargs)
        else:
            # this will be invoked on the first call
            return self.setup_configure_func(*args,**kwargs)

    def setup_configure_func(self,func):
        self.configure_function = func
        return self

    def configure_device(self,ctx,device, toolchain = None):
        toolchain = Utils.to_list(toolchain)

        for x in (toolchain or self.toolchains):
            try:
                ctx.configure_toolchain(x)
                break
            except ctx.errors.ConfigurationError:
                pass
        else:
            raise ctx.errors.ConfigurationError('Unable to configure a suitable toolchain for %s' % device)

        envname = 'device_%s_%s' % (self.name,ctx.env['TOOLCHAIN'])

        if envname in ctx.all_envs:
            ctx.setenv(envname)
        else:
            ctx.setenv(envname,ctx.env)
            ctx.env['DEVICE'] = self.name

            try:
                self.configure_function(ctx)
            except:
                ctx.setenv('')
                del ctx.all_envs[envname]
                raise

@conf
def configure_device(conf, name, toolchain = None):
    global device
    try:
        func = device.devices[(name, toolchain)]
    except KeyError:
        raise conf.errors.ConfigurationError('Unknown device %s' % name)

    func(conf,name, toolchain)

@conf
def apply_device_flags(ctx, name, toolchain):
    '''Function to update the current environment with device
       specific flags. This function is meant for backwards compat'''
    global device

    try:
        func = device.devices[(name, toolchain)]
    except KeyError:
        raise ctx.errors.ConfigurationError('Unknown device %s' % name)

    if toolchain not in func.toolchains:
        raise ctx.errors.ConfigurationError('Invalid toolchain %r for device %r in %r' % (toolchain,name,ctx.cur_script.path_from(ctx.root)))

    func.configure_function(ctx)
    ctx.env.append_value('DEFINES', '__' + name.upper())


###############################################################################
###############################################################################
# Definition of setup functions for common compiler types
###############################################################################
###############################################################################
@conf
def setup_gnu_binutils(conf, path_list = None):
    u'''Setup GNU binutils variables for current environment'''
    env = conf.env

    prefix = env['GNU_BINUTILS_PREFIX'] or ''

    for tool in 'ar readelf objdump objcopy strip nm'.split():
        executable_name = prefix + tool
        conf.find_program(executable_name, var=tool.upper(), path_list=path_list)

    env.ARFLAGS = 'rcs'


@conf
def gcc_optimize_flags(conf):
    f = conf.env.append_value

    if conf.env.CONDITIONS == 'debug':
        f('CFLAGS__optimize',   ['-O0'])
        f('CXXFLAGS__optimize', ['-O0'])
    else:
        f('CFLAGS__optimize',   ['-Os'])
        f('CXXFLAGS__optimize', ['-Os'])
        f('DEFINES__optimize',  ['NDEBUG=1'])

@conf
def setup_gnu_gcc_toolchain(conf, prefix, compiler = None, cxxcompiler = None, path_list=None):
    env = conf.env

    env.stash()
    try:
        env['GNU_GCC_PREFIX']      = prefix
        env['GNU_BINUTILS_PREFIX'] = prefix

        conf.setup_gnu_binutils(path_list)

        compiler    = compiler or (env['GNU_GCC_PREFIX'] + 'gcc')
        cxxcompiler = cxxcompiler or (env['GNU_GCC_PREFIX'] + 'g++')

        cc = conf.find_program(compiler, var='CC', path_list=path_list)
        cc = conf.cmd_to_list(cc)

        cxx = conf.find_program(cxxcompiler, var='CXX', mandatory=False, path_list=path_list)
        cxx = conf.cmd_to_list(cxx)

        conf.env.CC  = cc
        conf.env.AS  = cc

        env['CC_NAME']    = 'gcc'
        env['CC_VERSION'] = conf.cmd_and_log(env.CC + ["-dumpversion"]).strip().split('.')
        env['MACHINE']    = env['MACHINE'] or conf.cmd_and_log(env.CC +["-dumpmachine"]).strip()
        env['DEST_OS']    = 'Unknown'

        # backwards compat. Since we support clang now as well,
        # there is no common CC_PREFIX anymore. (CLANG is not prefixed)
        # please use 'MACHINE' for future developments
        env['CC_PREFIX']  = prefix.strip('-')

        conf.cc_load_tools()
        conf.gcc_common_flags()
        conf.cc_add_flags()

        conf.env.AS_TGT_F = '-o'

        if(cxx):
            env['CXX_NAME'] = 'gcc'
            env['CXX'] = cxx

            conf.cxx_load_tools()
            conf.gxx_common_flags()
            conf.cxx_add_flags()

        conf.link_add_flags()

        # we have to use gnu99 because we use some non standard gnu extensions conditionally
        # when __GNUC__ is defined
        env.append_value('CFLAGS_standard_c99', [ "-std=gnu99" ])

    except conf.errors.ConfigurationError:
        env.revert()
        raise

@conf
def setup_llvm_toolchain(conf, target, path_list=None):
    env = conf.env

    compiler = 'clang'

    env.stash()
    try:
        env['MACHINE'] = target

        if target:
            env['GNU_BINUTILS_PREFIX'] = "%s-" % target
        else:
            env['GNU_BINUTILS_PREFIX'] = ""

        conf.setup_gnu_binutils(path_list)

        config = conf.find_program('llvm-config', var='LLVM_CONFIG', path_list=path_list)
        env['LLVM_CONFIG'] = conf.cmd_to_list(config)

        cc = conf.find_program(compiler, var='CC', path_list=path_list)
        cc = conf.cmd_to_list(cc) + ['-target', target]

        env['CC_NAME']    = compiler
        env['CXX_NAME']   = compiler

        env['CC_VERSION'] = conf.cmd_and_log(env.LLVM_CONFIG + ["--version"]).strip().split('.')

        env.CC     = cc
        env['CXX'] = cc
        env.AS     = cc
        env.ARFLAGS = 'rcs'

        env['LINK_CC']  = env['CC']
        env['LINK_CXX'] = env['CC']

        conf.clang_common_flags()

        f = env.append_value
        f('INCLUDES', conf.cmd_and_log(env.LLVM_CONFIG + ["--includedir"]).splitlines())
        f('LIBPATH',  conf.cmd_and_log(env.LLVM_CONFIG + ["--libdir"]).splitlines())

        conf.env.AS_TGT_F = ['-c', '-o']
        conf.cc_add_flags()
        conf.link_add_flags()

        # we have to use gnu99 because we use some non standard gnu extensions conditionally
        # when __GNUC__ is defined
        env.append_value('CFLAGS_standard_c99', [ "-std=gnu99" ])

        #env.stash()
        #try:
        #    conf.env.prepend_value('LINKFLAGS', ['-v'])
        #    conf.env.prepend_value('CFLAGS', ['-v'])
        #    conf.check_cc(lib='c', msg = 'Checking if clang supports target %s' % target, okmsg='Yes', errmsg='No')
        #finally:
        #    env.revert()

    except conf.errors.ConfigurationError:
        env.revert()
        raise

@conf
def clang_common_flags(conf):
    """
    Common flags for g++ on nearly all platforms
    """
    v = conf.env

    v['CC_SRC_F']           = []
    v['CC_TGT_F']           = ['-c', '-o']

    v['CXX_SRC_F']           = []
    v['CXX_TGT_F']           = ['-c', '-o']


    v['CCLNK_SRC_F']         = []
    v['CCLNK_TGT_F']         = ['-o']
    v['CXXLNK_SRC_F']        = []
    v['CXXLNK_TGT_F']        = ['-o']
    v['CPPPATH_ST']          = '-I%s'
    v['DEFINES_ST']          = '-D%s'

    v['LIB_ST']              = '-l%s' # template for adding libs
    v['LIBPATH_ST']          = '-L%s' # template for adding libpaths
    v['STLIB_ST']            = '-l%s'
    v['STLIBPATH_ST']        = '-L%s'
    v['RPATH_ST']            = '-Wl,-rpath,%s'

    v['SONAME_ST']           = '-Wl,-h,%s'
    v['SHLIB_MARKER']        = '-Wl,-Bdynamic'
    v['STLIB_MARKER']        = '-Wl,-Bstatic'

    # program
    v['cprogram_PATTERN']    = '%s'
    v['cxxprogram_PATTERN']  = '%s'

    # shared library
    v['CXXFLAGS_cshlib']   = ['-fPIC']
    v['LINKFLAGS_cshlib']  = ['-shared']
    v['cshlib_PATTERN']    = 'lib%s.so'

    v['CXXFLAGS_cxxshlib']   = ['-fPIC']
    v['LINKFLAGS_cxxshlib']  = ['-shared']
    v['cxxshlib_PATTERN']    = 'lib%s.so'

    # static lib
    v['LINKFLAGS_cstlib']  = ['-Wl,-Bstatic']
    v['cstlib_PATTERN']    = 'lib%s.a'

    v['LINKFLAGS_cxxstlib']  = ['-Wl,-Bstatic']
    v['cxxstlib_PATTERN']    = 'lib%s.a'

###############################################################################
###############################################################################
# Definition of standard toolchains and devices
###############################################################################
###############################################################################
@toolchain('hitex')
def configure_toolchain_hitex(conf):
    path = None
    if 'PATH_GNU_ARM' in os.environ:
        path = [os.path.join(os.environ['PATH_GNU_ARM'], 'bin')]

    conf.setup_gnu_gcc_toolchain(prefix = 'arm-hitex-elf-', path_list = path)
    conf.gcc_arm_flags()
    conf.gcc_optimize_flags()

@configure_toolchain_hitex.target_triple_func
def target_triple_toolchain_hitex(bld, platform):
    return 'arm-hitex-elf'

if sys.platform.startswith("win"):
    try:
        import _winreg as winreg
    except:
        import winreg

    def get_registry_string_value(key, value_name):
        value = None

        with  winreg.ConnectRegistry(None, winreg.HKEY_LOCAL_MACHINE) as aReg:
            try:
                with winreg.OpenKey(aReg, key) as aKey:
                    value, typ = winreg.QueryValueEx(aKey, value_name)
            except WindowsError:
                pass

            if value is None and hasattr(winreg, 'KEY_WOW64_32KEY'):
                try:
                    with winreg.OpenKey(aReg, key, 0, winreg.KEY_READ | winreg.KEY_WOW64_32KEY) as aKey:
                        value, typ = winreg.QueryValueEx(aKey, value_name)
                except WindowsError:
                    pass

            if value is not None:
                assert typ is winreg.REG_SZ

                if sys.version_info[0] == 2:
                    value = value.encode('ascii', 'ignore')

        return value
else:
    def get_registry_string_value(key, value_name):
        return None


@toolchain('codesourcery')
def configure_toolchain_codesourcery(conf):
    # get path to toolchain
    path = None

    if 'CS_PATH' in os.environ:
        path = [os.path.join(os.environ['CS_PATH'],'bin')]
    else:
        if sys.platform.startswith("win"):
          install_loc = get_registry_string_value(r"SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\Sourcery G++ Lite for ARM EABI", "InstallLocation")

          if install_loc is not None:
            path = [os.path.join(install_loc, 'bin')]

    conf.setup_gnu_gcc_toolchain(prefix = 'arm-none-eabi-', path_list=path)
    conf.gcc_arm_flags()
    conf.gcc_optimize_flags()

    f = conf.env.append_value

    f('LINKFLAGS', ['-Wl,-gc-sections'])

    f('CFLAGS_enable_gc_sections',    ['-ffunction-sections', '-fdata-sections'])
    f('CXXFLAGS_enable_gc_sections',  ['-ffunction-sections', '-fdata-sections'])

@configure_toolchain_codesourcery.target_triple_func
def target_triple_toolchain_codesourcery(bld, platform):
    return 'arm-none-eabi'

@toolchain('gccarmemb')
def configure_toolchain_gccarmemb(conf):
    # get path to toolchain
    path = None

    if 'GCC_ARM_PATH' in os.environ:
        path = [os.path.join(os.environ['GCC_ARM_PATH'],'bin')]

    # as long as it is not defined how the gcc compiler V4.9 provided by arm fits into
    # the hilscher compiler versioning system building using codesourcery gcc V4.5.2
    # the arm compiler must be explicitly enabled by means of environment variable GCC_ARM_PATH.
    # If this variable is not set, the toolchain will not be available
    # Further its not clear, how waf shall distinguish codesourcery / arm compiler if they
    # are found via path (Actually there is no need to do so, but as for now the compiler version
    # in the target names breaks everything then.)
    if path:
        conf.setup_gnu_gcc_toolchain(prefix = 'arm-none-eabi-', path_list = path)
        conf.gcc_arm_flags()
        conf.gcc_optimize_flags()

        f = conf.env.append_value

        f('LINKFLAGS', ['-Wl,-gc-sections'])

        f('CFLAGS_enable_gc_sections',    ['-ffunction-sections', '-fdata-sections'])
        f('CXXFLAGS_enable_gc_sections',  ['-ffunction-sections', '-fdata-sections'])

        f('CFLAGS_disable_unaligned_access',   ['-mno-unaligned-access'])
        f('CXXFLAGS_disable_unaligned_access', ['-mno-unaligned-access'])
    else:
        conf.fatal('GCC_ARM_PATH environment variable must be set to enable ARM V4.9 toolchain')

@configure_toolchain_gccarmemb.target_triple_func
def target_triple_toolchain_gccarmemb(bld, platform):
    if isinstance(platform, str):
        platform = platform.lower()

    if platform:
        try:
            return {
                'netx'              : 'arm-none-eabi',
                'netx10'            : 'arm-none-eabi',
                'netx50'            : 'arm-none-eabi',
                'netx51'            : 'arm-none-eabi',
                'netx52'            : 'arm-none-eabi',
                'netx90'            : 'armv7em-none-eabi',
                'netx90_app'        : 'armv7em-none-eabi',
                'netx90_app_softfp' : 'armv7em-none-eabi',
                'netx90_app_hardfp' : 'armv7em-none-eabihf',
                'netx100'           : 'arm-none-eabi',
                'netx500'           : 'arm-none-eabi',
                'netx4000'          : 'armv7r-none-eabi',
            }[platform]
        except KeyError:
            bld.fatal('GCC ARM Embedded toolchain does not support platform "%s"'% platform)
    else:
        bld.fatal('GCC ARM Embedded toolchain requires "platform" argument for function get_name_prefix()')


match_ecoscentric_version = re.compile(r'.* release (?P<version>[0-9a-z]+\.[0-9a-z]+\.[0-9a-z]+)\W').match

@toolchain('ecoscentric')
def configure_toolchain_ecoscentric(conf):
    # get path to toolchain
    path = os.environ.get('PATH_GCC_ARM_ECOSCENTRIC', None)

    if path:
        conf.setup_gnu_gcc_toolchain(prefix = 'arm-eabi-', path_list = [ path + os.sep + 'bin'])
        conf.gcc_arm_flags()
        conf.gcc_optimize_flags()

        f = conf.env.append_value

        f('LINKFLAGS', ['-Wl,-n', # Disable alignment by default
                        '-Wl,-gc-sections'
        ])

        #f('CFLAGS_enable_gc_sections',    ['-ffunction-sections', '-fdata-sections'])
        #f('CXXFLAGS_enable_gc_sections',  ['-ffunction-sections', '-fdata-sections'])

        f('CFLAGS_disable_unaligned_access',   ['-mno-unaligned-access'])
        f('CXXFLAGS_disable_unaligned_access', ['-mno-unaligned-access'])

        try:
            readme_node = conf.root.find_resource(path + os.sep + 'README.txt')
            content = readme_node.read()

            first_line = content.splitlines()[0]
            m = match_ecoscentric_version(first_line)
            conf.env['CC_VERSION'] = m.group('version').split('.')
        except Exception as e:
            conf.fatal(u'Unable to determine eCosCentric toolchain version: %s' % (str(e)))
    else:
        conf.fatal('PATH_GCC_ARM_ECOSCENTRIC environment variable must be set to enable eCosCentric toolchain')

@configure_toolchain_ecoscentric.target_triple_func
def target_triple_toolchain_ecoscentric(bld, platform):
    if isinstance(platform, str):
        platform = platform.lower()

    if platform:
        try:
            return {
                'netx90'            : 'armv7em-ecoscentric-ecospro-eabi',
                'netx4000'          : 'armv7r-ecoscentric-ecospro-eabi',
            }[platform]
        except KeyError:
            bld.fatal('GCC ARM Embedded toolchain does not support platform "%s"'% platform)
    else:
        bld.fatal('eCosCentric ARM toolchain requires "platform" argument for function get_name_prefix()')


@toolchain('custom')
def configure_toolchain_custom(conf):
    opt = Options.options

    conf.setup_gnu_gcc_toolchain(
        prefix = opt.custom_toolchain_prefix + '-',
        compiler=opt.custom_toolchain_driver,
        cxxcompiler=opt.custom_toolchain_cxxdriver,
        path_list=[opt.custom_toolchain_path]
    )

    conf.gcc_arm_flags()
    conf.gcc_optimize_flags()

    f = conf.env.append_value

    f('CFLAGS',    ['-ffunction-sections', '-fdata-sections'])
    f('CXXFLAGS',  ['-ffunction-sections', '-fdata-sections'])
    f('LINKFLAGS', ['-Wl,-gc-sections'])

@configure_toolchain_custom.target_triple_func
def target_triple_toolchain_custom(bld, platform):
    return bld.env['MACHINE']

@toolchain('arm-eabi')
def configure_toolchain_arm_eabi(conf):
    exc = None
    for x in 'arm-none-eabi- arm-eabi-'.split():
        try:
            conf.setup_gnu_gcc_toolchain(prefix = x)
            break
        except conf.errors.ConfigurationError as e:
            exc = exc or e
    else:
        raise exc

    conf.gcc_arm_flags()
    conf.gcc_optimize_flags()

    f = conf.env.append_value

    f('CFLAGS',    ['-ffunction-sections', '-fdata-sections'])
    f('CXXFLAGS',  ['-ffunction-sections', '-fdata-sections'])
    f('LINKFLAGS', ['-Wl,-gc-sections'])

@configure_toolchain_arm_eabi.target_triple_func
def target_triple_toolchain_arm_eabi(bld, platform):
    return 'arm-none-eabi'

@conf
def get_xpic_llvm_version(conf, path_list=None):
    env = conf.env

    if not env['LLC']:
        llc = conf.find_program('llc', var='llc', path_list=path_list)
        env['LLC'] = conf.cmd_to_list(llc)

    # we try to get the xpic llvm version running 'bin/llc.exec --version'
    # when ran with '--version' attribute the llc.exe behaves unexpectedly
    # and exits with error code '1', interrupting the build process;
    # to avoid that, we enclose the 'cmd_to_log' command in a try/catch block
    # and parse the xpic llvm version from the exception message
    # which contains the actual process output

    try:
        out = conf.cmd_and_log(env.LLC  + ["--version"])
    except Exception as e:
        out = e.stdout

    version = out.split('version: V')[1].split('Git')[0].strip().split('.')

    return version

@conf
def xpic_optimize_flags(conf):
    f = conf.env.append_value

    if conf.env.CONDITIONS == 'debug':
        f('CFLAGS__optimize',   ['-O0'])
        f('CXXFLAGS__optimize', ['-O0'])
    else:
        f('CFLAGS__optimize',   ['-Os'])
        f('CXXFLAGS__optimize', ['-Os'])
        f('DEFINES__optimize',  ['NDEBUG=1'])

    if conf.env.CONDITIONS != 'release':
        f('CFLAGS__debug',   ['-g', '-gdwarf-2'])
        f('CXXFLAGS__debug', ['-g', '-gdwarf-2'])

@toolchain('llvm-xpic', 'llvm_xpic')
def configure_toolchain_xpic(conf):
    path = None

    if 'PATH_LLVM_XPIC' in os.environ:
        # new version llvm
        path = [os.path.join(os.environ['PATH_LLVM_XPIC'], 'bin')]
    else:
        if 'PATH_GNU_XPIC' in os.environ:
            # old version llvm
            path = [os.path.join(os.environ['PATH_GNU_XPIC'], 'bin')]

    conf.setup_llvm_toolchain(target='xpic', path_list=path)

    # overide compiler name with xpic specific name
    conf.env['CC_NAME']    = 'xpic-llvm'
    conf.env['CXX_NAME']   = 'xpic-llvm'

    try:
        conf.env['CC_VERSION'] = conf.get_xpic_llvm_version(path_list=path)
    except:
        conf.msg('Extracting xpic backend version', result = 'fail', color = 'YELLOW')

    f = conf.env.append_value

    f('DEFINES', ['__XPIC__'])

    conf.xpic_optimize_flags()

    # fix wrong directories in xpic compiler
    libdir_list = conf.cmd_and_log(conf.env['LLVM_CONFIG'] + ["--libdir"]).splitlines()
    f('LIBPATH',  [x+"/gcc/xpic-hilscher-elf/0.1.1" for x in libdir_list])

    f('STLIB_default_standardlibs',   ['m', 'c', 'gcc'])

@configure_toolchain_xpic.target_triple_func
def target_triple_toolchain_xpic(bld, platform):
    if platform is not None:
        if platform not in ('xpic', 'xpic2'):
            bld.fatal('Invalid platform %s for xpic toolchain' % platform)

        return '%s-hilscher-elf' % platform
    else:
        return 'xpic-hilscher-elf'

@toolchain('llvm-arm')
def configure_toolchain_llvm_arm(conf):
    '''this doesnt work yet'''
    path = None
    conf.setup_llvm_toolchain(target='arm-none-eabi', path_list=path)

    conf.gcc_arm_flags()
    conf.gcc_optimize_flags()

    f = conf.env.append_value

@configure_toolchain_llvm_arm.target_triple_func
def target_triple_toolchain_llvm_arm(bld, target):
    return 'arm-none-eabi'

@toolchain('gcc-linux')
def configure_toolchain_gcc_linux(conf):
    if sys.platform in ("linux","linux2"):
        conf.setup_gnu_gcc_toolchain(prefix='')
        conf.gcc_optimize_flags()
        conf.env.append_value('LINKFLAGS', ['-Wl,-gc-sections'])
    else:
        conf.fatal('GCC Linux toolchain not available none linux os')

@configure_toolchain_gcc_linux.target_triple_func
def target_triple_toolchain_gcc_linux(bld, platform):
    return bld.env['MACHINE'] or 'none-linux-gnu'

@toolchain('mingw32', 'mingw')
def configure_toolchain_mingw32(conf):
    if sys.platform in ("win32","win64"):
        conf.setup_gnu_gcc_toolchain(prefix = 'mingw32-')
        conf.gcc_optimize_flags()

        conf.env['DEST_OS'] = 'win32'
        conf.gcc_modifier_platform()
        conf.env.append_value('LINKFLAGS', ['-Wl,-gc-sections'])
    else:
        conf.fatal('MinGW toolchain not available none windows os')

@configure_toolchain_mingw32.target_triple_func
def target_triple_toolchain_mingw32(bld, platform):
    return bld.env['MACHINE'] or 'none-pc-mingw32'

@toolchain('mingw64')
def configure_toolchain_mingw64(conf):
    if sys.platform in ("win64"):
        conf.setup_gnu_gcc_toolchain(prefix = 'mingw64')
        conf.gcc_optimize_flags()

        conf.env['DEST_OS'] = 'win32'
        conf.gcc_modifier_platform()
        conf.env.append_value('LINKFLAGS', ['-Wl,-gc-sections'])
    else:
        conf.fatal('MinGW 64 toolchain not available none 64 bit windows os')

@configure_toolchain_mingw64.target_triple_func
def target_triple_toolchain_mingw64(bld, platform):
    return bld.env['MACHINE'] or 'none-pc-mingw64'

# Lets define some common aliases
if sys.platform in ("linux","linux2"):
    toolchain.alias('gcc-linux', ['linux', 'posix', 'native', 'gcc'])
elif sys.platform in ("win32"):
    toolchain.alias('mingw32', ['win', 'native','gcc'])

    @toolchain('posix')
    def configure_toolchain_unavail(conf):
        conf.fatal('Posix toolchain not available none posix os')
elif sys.platform in ('win64'):
    @toolchain('win', 'native')
    def configure_toolchain_native(conf):
        try:
            configure_toolchain_mingw64.configure_toolchain(conf)
        except conf.errors.ConfigurationError:
            configure_toolchain_mingw32.configure_toolchain(conf)

    @configure_toolchain_native.target_triple_func
    def target_triple_toolchain_native(bld, platform):
        return bld.env['MACHINE']

    @toolchain('posix')
    def configure_toolchain_unavail(conf):
        conf.fatal('Posix toolchain not available none posix os')

@conf
def cc_version(conf):
    a,b,c = conf.env['CC_VERSION'] or ('0', '0', '0')

    c = c.rstrip('abcdefghijklmnopqrstuvwxyz')
    return (int(a), int(b), int(c))

@conf
def gcc_flags(conf):
    f = conf.env.append_value

    for x in 'CFLAGS CXXFLAGS'.split():
        f(x,[ '-Wall',
              '-Wredundant-decls',
              '-Wno-inline',
              '-Winit-self'])

    f('ASFLAGS',[ '-Wall',
                  '-Wredundant-decls',
                  '-Wno-inline',
                  '-c'])

    for x in 'CFLAGS CXXFLAGS'.split():
        f(x + '_check_ansi', ['-ansi',
                              '-pedantic'])

    for x in 'CFLAGS CXXFLAGS'.split():
        f(x + '_check_extra', ['-Wconversion',
                               '-Wmissing-field-initializers',
                               '-Wsign-compare',
                               '-Wpointer-arith',
                               '-Wcast-qual'])

    if conf.cc_version() >= (4,1,2):
        f('CFLAGS_check_extra', ['-Wc++-compat'])

    # define CFLAGS_warninglevel1 and CXXFLAGS_warninglevel2
    for x in 'CFLAGS CXXFLAGS'.split():
        f(x + '_warninglevel1', [ "-Wsystem-headers",
                                  "-Wbad-function-cast",
                                  "-Wsign-compare",
                                  "-Waggregate-return",
                                  "-Wswitch-default",
                                  "-Wstrict-prototypes",
                                  '-Wpointer-arith',
                                  ])

@feature("check_extra", "check_ansi", "warninglevel1", "standard_c99")
def compile_check_dummy(self):
    # make waf happy
    pass

@conf
def gcc_arm_flags(conf):
    f = conf.env.append_value

    f('CFLAGS_compile_arm',   ['-marm'])
    f('CXXFLAGS_compile_arm',   ['-marm'])
    f('LINKFLAGS_compile_arm',   ['-marm'])
    f('CFLAGS_compile_thumb', ['-mthumb'])
    f('CXXFLAGS_compile_thumb', ['-mthumb'])
    f('LINKFLAGS_compile_thumb', ['-mthumb'])

    conf.env['cprogram_PATTERN']   = '%s.elf'
    conf.env['cxxprogram_PATTERN'] = '%s.elf'

    # we prefer gdwarf-2 output for use with lauterbach t32
    if conf.get_conditions() != 'release':
        f('CFLAGS__debug',   ['-g', '-gdwarf-2'])
        f('CXXFLAGS__debug', ['-g', '-gdwarf-2'])
        f('ASFLAGS__debug',  ['-Wa,-gdwarf2'])

@conf
def gcc_netx_flags(conf):
    conf.gcc_flags()

    f = conf.env.append_value

    for x in 'CFLAGS CXXFLAGS'.split():
        f(x,[ '-mlong-calls',
              '-mapcs',
              '-mthumb-interwork',
              '-fshort-enums',
              '-fno-common'])

    f('ASFLAGS',[ '-mapcs',
                  '-mthumb-interwork',
                  '-fshort-enums',
                  '-c'])

    f('LINKFLAGS', [ '-mthumb-interwork', '-nostdlib'])

    f('DEFINES', ['_NETX_'])
    f('STLIB_nxo_standardlibs', ['m', 'gcc'])
    f('STLIB_default_standardlibs',   ['m', 'c', 'gcc'])


@device('netx', 'hitex codesourcery arm-eabi gccarmemb')
def configure_device_netx(conf):
    conf.gcc_netx_flags()

    for x in 'CFLAGS CXXFLAGS ASFLAGS LINKFLAGS'.split():
        conf.env.append_value(x, ['-march=armv5te'])
        if conf.env.TOOLCHAIN != 'hitex':
            # hitex does not fully support this
            conf.env.append_value(x, ['-msoft-float', '-mfpu=vfp', '-mfloat-abi=soft'])

@device('netx50','hitex codesourcery arm-eabi gccarmemb')
def configure_device_netx50(conf):
    conf.gcc_netx_flags()

    if conf.cc_version()[0:2] < (4,1):
        mcpu = '-mcpu=arm9e'
    else:
        mcpu = '-mcpu=arm966e-s'

    for x in 'CFLAGS CXXFLAGS ASFLAGS'.split():
        conf.env.append_value(x, mcpu)

    if conf.env.TOOLCHAIN == 'hitex':
        # Workaround for hitex linking
        # hitex compiler chooses hardware fp library whenever something
        # else than arm926ej-s is specified
        conf.env.append_value('LINKFLAGS', '-mcpu=arm926ej-s')
    else:
        conf.env.append_value('LINKFLAGS', mcpu)

    for x in 'CFLAGS CXXFLAGS ASFLAGS LINKFLAGS'.split():
        if conf.env.TOOLCHAIN != 'hitex':
            # hitex does not fully support this
            conf.env.append_value(x, ['-msoft-float', '-mfpu=vfp', '-mfloat-abi=soft'])

@device('netx10 netx51 netx52','codesourcery arm-eabi gccarmemb')
def configure_device_netx51(conf):
    conf.gcc_netx_flags()

    if conf.cc_version()[0:2] < (4,1):
        mcpu = '-mcpu=arm9e'
    else:
        mcpu = '-mcpu=arm966e-s'

    for x in 'CFLAGS CXXFLAGS ASFLAGS'.split():
        conf.env.append_value(x, mcpu)

    if conf.env.TOOLCHAIN == 'hitex':
        # Workaround for hitex linking
        # hitex compiler chooses hardware fp library whenever something
        # else than arm926ej-s is specified
        conf.env.append_value('LINKFLAGS', '-mcpu=arm926ej-s')
    else:
        conf.env.append_value('LINKFLAGS', mcpu)

    for x in 'CFLAGS CXXFLAGS ASFLAGS LINKFLAGS'.split():
        conf.env.append_value(x, ['-msoft-float', '-mfpu=vfp', '-mfloat-abi=soft'])

@device('netx100 netx500','hitex codesourcery arm-eabi gccarmemb')
def configure_device_netx100(conf):
    conf.gcc_netx_flags()

    for x in 'CFLAGS CXXFLAGS ASFLAGS LINKFLAGS'.split():
        conf.env.append_value(x, '-mcpu=arm926ej-s')
        if conf.env.TOOLCHAIN != 'hitex':
            # hitex does not fully support this
            conf.env.append_value(x, ['-msoft-float', '-mfpu=vfp', '-mfloat-abi=soft'])

@device('netx4000','gccarmemb ecoscentric')
def configure_device_netx4000(conf):
    conf.gcc_flags()

    f = conf.env.append_value

    for x in 'CFLAGS CXXFLAGS'.split():
        f(x,[ '-mlong-calls',
              '-mapcs',
              '-fno-common',])

    f('ASFLAGS',[ '-mapcs',
                  '-c'])

    f('LINKFLAGS', ['-mthumb-interwork', '-nostdlib'])

    f('DEFINES', ['_NETX_'])
    f('STLIB_nxo_standardlibs',       ['gcc'])
    f('STLIB_default_standardlibs',   ['gcc'])

    for x in 'CFLAGS CXXFLAGS ASFLAGS LINKFLAGS'.split():
        # Floating point operations will invoke library functions
        # no hardware floating instructions will be enabled
        # see WAF-132 for details
        f(x, ['-march=armv7-r'])

        # software floating point
        f(x, ['-mfloat-abi=soft'])

        # hardware floating point with soft floating point api
        #f(x, ['-mfpu=vfpv3-d16', '-mfloat-abi=softfp'])

        # support hardware floating point with floating point calling convention
        # (fpu registers will be used to pass arguments)
        # WARNING: this produces incompatible code with above
        # option. Ether choose the softfp or this, not both
        #f(x, ['-mfpu=vfpv3-d16', '-mfloat-abi=hard'])

def configure_device_armv7em(conf):
    conf.gcc_flags()

    # Cortex-M4 onyl implements Thumb-2 instruction encoding but
    # no ARM instruction enconding
    conf.env['CFLAGS_compile_arm']      = []
    conf.env['CXXFLAGS_compile_arm']    = []
    conf.env['LINKFLAGS_compile_arm']   = []
    conf.env['CFLAGS_compile_thumb']    = []
    conf.env['CXXFLAGS_compile_thumb']  = []
    conf.env['LINKFLAGS_compile_thumb'] = []

    f = conf.env.append_value

    for x in 'CFLAGS CXXFLAGS'.split():
        f(x,[ '-mlong-calls',
              '-mapcs',
              '-fno-common',
              '-mthumb'])

    f('ASFLAGS',[ '-mapcs',
                  '-c',
                  '-mthumb'])

    # -mthumb is needed for linking to select correct libraries
    # see gcc -print-multi-lib output
    f('LINKFLAGS', [ '-nostdlib', '-mthumb'])

    f('DEFINES', ['_NETX_'])
    f('STLIB_nxo_standardlibs',       ['gcc'])
    f('STLIB_default_standardlibs',   ['gcc'])

    for x in 'CFLAGS CXXFLAGS ASFLAGS LINKFLAGS'.split():
        # Floating point operations will invoke library functions
        # no hardware floating instructions will be enabled
        # see WAF-132 for details
        f(x, ['-march=armv7e-m'])


@device('netx90','gccarmemb ecoscentric')
def configure_device_netx90(conf):
    configure_device_armv7em(conf)

    f = conf.env.append_value
    for x in 'CFLAGS CXXFLAGS ASFLAGS LINKFLAGS'.split():
        # software floating point
        f(x, ['-mfloat-abi=soft'])


@device('netx90_app','gccarmemb')
def configure_device_netx90(conf):
    configure_device_armv7em(conf)

    f = conf.env.append_value
    for x in 'CFLAGS CXXFLAGS ASFLAGS LINKFLAGS'.split():
        # software floating point
        f(x, ['-mfloat-abi=soft'])

@device('netx90_app_softfp','gccarmemb')
def configure_device_netx90(conf):
    configure_device_armv7em(conf)

    f = conf.env.append_value
    for x in 'CFLAGS CXXFLAGS ASFLAGS LINKFLAGS'.split():
        f(x, ['-mfpu=fpv4-sp-d16', '-mfloat-abi=softfp'])

@device('netx90_app_hardfp','gccarmemb')
def configure_device_netx90(conf):
    configure_device_armv7em(conf)

    f = conf.env.append_value
    for x in 'CFLAGS CXXFLAGS ASFLAGS LINKFLAGS'.split():
        f(x, ['-mfpu=fpv4-sp-d16', '-mfloat-abi=hard'])


@device('xpic','llvm-xpic')
def configure_device_xpic(conf):
    conf.env.prepend_value('CFLAGS',  ['-Wa,-mmcu=xpic'])
    conf.env.prepend_value('CXXFLAGS',['-Wa,-mmcu=xpic'])
    conf.env.prepend_value('ASFLAGS', ['-Wa,-mmcu=xpic'])
    conf.env.prepend_value('LINKFLAGS', '-mcpu=xpic')

    conf.env['cprogram_PATTERN']   = '%s.elf'
    conf.env['cxxprogram_PATTERN'] = '%s.elf'


@device('xpic2','llvm-xpic')
def configure_device_xpic2(conf):
    conf.env.prepend_value('CFLAGS',  ['-Wa,-mmcu=xpic2'])
    conf.env.prepend_value('CXXFLAGS',['-Wa,-mmcu=xpic2'])
    conf.env.prepend_value('ASFLAGS', ['-Wa,-mmcu=xpic2'])
    conf.env.prepend_value('LINKFLAGS', '-mcpu=xpic2')


    conf.env['cprogram_PATTERN']   = '%s.elf'
    conf.env['cxxprogram_PATTERN'] = '%s.elf'

@conf
def host_optimize_flags(conf):
    f = conf.env.append_value

    if conf.env.CONDITIONS == 'debug':
        f('CFLAGS__optimize',   ['-O0'])
        f('CXXFLAGS__optimize', ['-O0'])
    else:
        f('CFLAGS__optimize',   ['-O3'])
        f('CXXFLAGS__optimize', ['-O3'])
        f('DEFINES__optimize',  ['NDEBUG=1'])

    if conf.env.CONDITIONS != 'release':
        f('CFLAGS__debug',   ['-g'])
        f('CXXFLAGS__debug', ['-g'])
        f('ASFLAGS__debug',  ['-Wa,-g'])

@device('linux', 'gcc-linux')
def configure_device_linux(conf):
    conf.gcc_flags()
    conf.host_optimize_flags()

    f = conf.env.append_value

    f('STLIB',   ['m', 'c', 'gcc'])
    f('TOOL_OPTIONS', ["linkerscript_optional"])

@device('win32', 'mingw32')
def configure_device_win32(conf):
    conf.gcc_flags()
    conf.host_optimize_flags()

    f = conf.env.append_value

    f('TOOL_OPTIONS', ["linkerscript_optional"])

@device('win64', 'mingw64')
def configure_device_win64(conf):
    conf.gcc_flags()
    conf.host_optimize_flags()

    f = conf.env.append_value
    f('TOOL_OPTIONS', ["linkerscript_optional"])

@device('native', 'native')
def configure_device_native(conf):
    conf.gcc_flags()
    conf.host_optimize_flags()

    f = conf.env.append_value
    f('TOOL_OPTIONS', ["linkerscript_optional"])

