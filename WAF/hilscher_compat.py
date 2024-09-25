#! /usr/bin/env python
# encoding: utf-8
import shutil

from waflib import Task, Node

if not hasattr(Node.Node,"nice_path"):
    """ Inject nice_path method for waf versions >= 1.7.0.0,
        where this function had been removed """

    def nice_path(self, env=None):
        """
        Return the path seen from the launch directory. It is often used for printing nodes in the console to open
        files easily.

        :param env: unused, left for compatibility with waf 1.5
        """
        return self.path_from(self.ctx.launch_node())
    Node.Node.nice_path = nice_path

def always_run(cls):
    """ This decorator has been replaced since waf version 1.7.0.0
        with an attribute but is required for waf versions below. We therefore
        reintroduce it here to dynamically adapt to waf version """
    try:
        d = Task.always_run
    except AttributeError:
        cls.always_run = True
        return cls
    else:
        return d(cls)

