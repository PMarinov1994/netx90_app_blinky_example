import sys
import re
top = "."
out = "build"

# Compare two version strings
#    Returns -1 if version A is older than version B
#    Returns  0 if version A and B are equivalent
#    Returns  1 if version A is newer than version B
def cmpVersions(versionA, versionB):
    def normalize(v):
        # convert version (e.g. "1.10.1.0") string into a tuple. --> [1,10,1,0]
        # Tuples can be easily compared using cmp
        return [int(x) for x in re.sub(r'(\.0+)*$','', v).split(".")]
    return cmp(normalize(versionA), normalize(versionB))

REQUIRED_TOOLCHAINS = ["gccarmemb"]
HILSCHER_VERSION_COMPATIBILITY = '1.10.1.0'

def options(ctx):
    try:
        ctx.load("hilscher_netx hilscher_firmware hilscher_extras", tooldir="WAF")
        print("Loaded WAF options from project.")
    except:
        ctx.load("hilscher_netx hilscher_firmware hilscher_extras")
        print("Loaded WAF options from netX Studio.")
        
    from hilscher_netx import HILSCHER_VERSION

    # Load the hboot_image_compiler.py wAF extension module    
    ctx.load("hboot_image_compiler", tooldir=".")

    if (cmpVersions(HILSCHER_VERSION, HILSCHER_VERSION_COMPATIBILITY) < 0):
        sys.stderr.write("Hilscher Waf V" + HILSCHER_VERSION + " is not recommended, please use at least V" + HILSCHER_VERSION_COMPATIBILITY + " or newer!\n")
        
    sys.stdout.flush()
    ctx.autorecurse(mandatory = False)


def configure(conf):
    try:
        conf.load("hilscher_netx hilscher_firmware hilscher_extras", tooldir="WAF")
        print("Loaded WAF configuration from project.")
    except:            
        conf.load("hilscher_netx hilscher_firmware hilscher_extras")
        print("Loaded WAF configuration from netX Studio.")

    # Load the hboot_image_compiler.py wAF extension module
    conf.load("hboot_image_compiler", tooldir=".")

    conf.setenv("")
    conf.env["UsedToolchain"] = "gccarmemb"
    conf.env["UsedPlatform"]  = "netx90_app"
    
    sys.stdout.flush()
    conf.autorecurse(mandatory = False)

def dist(bld):
    pass

def build(bld):
    bld.autorecurse() 
