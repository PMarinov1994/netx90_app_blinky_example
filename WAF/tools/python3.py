#! /usr/bin/env python
# encoding: utf-8
########################################################################################
# Copyright (c) Hilscher Gesellschaft fuer Systemautomation mbH. All Rights Reserved.
########################################################################################
# $Id:  $:
#
# hilscher waf python3 support
########################################################################################
from waflib.Configure import conf
from waflib import Utils
import waflib.Context
import os

def options(opt):
    pass

def configure(conf):
    # change to parent environment object
    conf.setenv('')
    env = conf.env

    PYTHON3 = conf.find_program('python3')

    (_,err) = conf.cmd_and_log([PYTHON3] + ["-E", "-c", r"import sys; sys.stderr.write('\n'.join([sys.base_prefix,sys.executable]));"], output=waflib.Context.BOTH)
    try:
        (python3_base, python3_executable) = err.splitlines()
    except Exception as e:
        print("Error parsing python output into version: " + err.strip())
        raise

    # patch path for python
    conf.env['PYTHON3']            = python3_executable
    conf.env['PYTHON3_PYTHONPATH'] = []

    conf.msg('Using program python3', conf.env['PYTHON3'])

@conf
def run_python3(ctx, cmd, pythonpath = None, env = None, quiet=waflib.Context.STDERR, **kw):
    cmd = [ctx.env['PYTHON3']] + Utils.to_list(cmd)
    pythonpath = Utils.to_list(pythonpath) + ctx.env['PYTHON3_PYTHONPATH']

    env = dict(env or os.environ)
    env['PYTHONPATH'] = os.pathsep.join(pythonpath)

    return ctx.cmd_and_log(cmd, output=waflib.Context.BOTH, quiet=quiet, env = env, **kw)
