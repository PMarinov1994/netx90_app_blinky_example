#! /usr/bin/env python
# encoding: utf-8
########################################################################################
# Copyright (c) Hilscher Gesellschaft fuer Systemautomation mbH. All Rights Reserved.
########################################################################################
# $Id:  $:
#
# hilscher waf python3 support
########################################################################################
import waflib.Context
import os

def options(opt):
    pass

def configure(conf):
    # change to parent environment object
    conf.setenv('')
    env = conf.env

    env.stash()
    try:
        if 'JAVA_HOME' in os.environ:
            conf.env['JAVA_HOME'] = os.environ['JAVA_HOME']
            JAVA = conf.find_program('java', var = 'JAVA', path_list=[conf.env['JAVA_HOME'] + os.sep + 'bin'])
        else:
            JAVA = conf.find_program('java', var = 'JAVA')
            conf.env['JAVA_HOME'] = os.path.normpath(env.os.path.join(JAVA, '..', '..'))

        (out,err) = conf.cmd_and_log([JAVA] + ["--version"], output=waflib.Context.BOTH)
    finally:
        env.revert()

