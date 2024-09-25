import os.path

from _version import get_versions  # this import should match the project where this script it used
import re

"""
Use this function to get a version string based on the projects tag.

The Base tag format to use in the vcs is 'v{MAJOR}.{MINOR}.{PATCH}'
where the leading 'v' is the tag-prefix that is necessary to determine that it is a version tag.

This tool accepts three different kind of tags:

Development (dev):
    Used to build development versions of a Tool.
    You can build versions with projects that are currently not on a Tag.
    If the most recent tag was a dev-Tag you will receive a version that counts the distance to said Tag.

    To set a dev Tag add '.dev' to the end of the Tag.

    tag: v3.0.23.dev (including commits after tag)
    version.py: 3.0.23.dev+1.g0693e89
    --version:  3.0.23.dev+1.g0693e89 (BUILD 20211001H1709)
    py-package: hil_nxt_hwconfig-3.0.23.dev0+1.g0693e89.tar.gz


Evaluation (alpha):
    The Evaluation version is meant for testing the tool before the actual Release.
    An Evaluation version can't be built with a dirty repository or a tool that is
    currently not directly on the evaluation Tag.

    Since pep440 does not provide/accept a tag with 'eval' in it we have to use 'alpha' instead.
    So to set an eval Tag add '.alpha' to the end of the Tag.

    tag: v3.0.23.alpha
    version.py: 3.0.23.alpha
    --version:  3.0.23.alpha  (BUILD 20211001H1709)
    py-package: hil_nxt_hwconfig-3.0.23a0.tar.gz

Release:
    The Release version is meant for a release build.
    Like the evaluation tag, the release Tag also is not allowed on a dirty repository or
    one that is not the current commit of the release Tag.
    No Postfix is necessary for the Tag.

    tag: v3.0.23
    version.py: 3.0.23
    --version:  3.0.23 (BUILD 20211001H1709)
    py-package: hil_nxt_hwconfig-3.0.23.tar.gz

origin:
http://scm.netx01.hilscher.local/git/netx_tools/hwconfig
Branch: hboot_image_collection
Revision: 0e4258bdd402185d0a1dca7ed1749771d46f8423
Author: fwoermann <fwoermann@hilscher.com>
Date: 12.10.2021 17:57:12
"""

version_tag_regex = r"(\d+)\.(\d+).(\d+)\.*([a-z]+)*\+*(\d*).*"
ROOT_PATH = os.path.dirname(os.path.dirname(__file__))


class VersionHandler:
    def __init__(self):

        self.version_dict = get_versions()

        # set default variable values
        self.release_type = None
        self.dirty = None
        self.distance = None
        self.time_string = None
        self.major = None
        self.minor = None
        self.patch = None

    def check_version_tag(self):
        # get data from version dict
        match = re.match(version_tag_regex, self.version_dict['version'])
        if match:
            self.major = match.group(1)
            self.minor = match.group(2)
            self.patch = match.group(3)
            self.release_type = match.group(4)
            self.distance = match.group(5) if match.group(5) is not '' else '0'
            self.dirty = self.version_dict.get("dirty")
            self.version_dict['release_type'] = self.release_type
            self.version_dict['major'] = self.major
            self.version_dict['minor'] = self.minor
            self.version_dict['patch'] = self.patch
        else:
            # throw exception if the tag style does not match
            raise AttributeError("The tool does not have a valid version string! '%s'" % self.version_dict['version'])

    def get_time_sting(self):
        # get the time string from version dict
        time_regex = r"(\d{4})-(\d{1,2})-(\d{1,2})T(\d{2}):(\d{2}):(\d{2})\+(\d{4})"
        time_match = re.match(time_regex, self.version_dict['date'])
        if not time_match:
            raise AttributeError("invalid date stamp found in version dict '%s'" % self.version_dict['date'])
        year = time_match.group(1)
        month = time_match.group(2)
        day = time_match.group(3)
        hour = time_match.group(4)
        minute = time_match.group(5)
        self.time_string = "%s%s%sH%s%s" % (year, month, day, hour, minute)
        self.version_dict['time_string'] = self.time_string
        return self.time_string

    def validate_version(self):
        # check if version is valid
        if self.release_type not in ['dev']:
            # only dev builds can be dirty or not on a tagged commit
            if self.dirty:
                raise AttributeError("Invalid Version: Eval and Release versions can't be dirty! Build a new Version!")
            # eval and release must be from a tagged commit
            if self.distance != "0":
                raise AttributeError(
                    "Invalid Version: Eval and Release versions can only be build with a tagged commit!"
                    " Build a new Version!"
                )
            self.version_dict['distance'] = self.distance

    def get_final_version_string(self):
        # get final version string
        version_string = self.version_dict['version']
        version_string += " (BUILD %s)" % self.time_string

        # version is just the 'major.minor.patch' format
        version = "%s.%s.%s" % (self.major, self.minor, self.patch)

        # return all if the below so we provide whats needed
        self.version_dict['version_string'] = version_string

        return version_string, version, self.dirty


def get_version_strings():
    """ Get version information.
    uses versioneer.py to get version information.

    :return:
        __version__ (string): complete version string for printing
        __revision__ (string): version string in format 'major.minor.patch'
        version_clean (flag): boolean if vcs is a clean version
    """
    # create version handler
    version_handler = VersionHandler()
    # check version tag and get information from versioneer
    version_handler.check_version_tag()
    # get the time from versioneer and create time string from tha tinformation
    version_handler.get_time_sting()
    # validate the combination of repo state and release type
    version_handler.validate_version()
    # get the version strings
    version_string, version, dirty = version_handler.get_final_version_string()
    return version_string, version, dirty
