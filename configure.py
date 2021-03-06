#!/usr/bin/env python

"""
configure.py - Configuration script for the pyqt-wrapped-app example.

Copyright (C) 2013 David Boddie <david.boddie@met.no>

This file is part of the pyqt-wrapped-app example.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
"""

import glob, os, sys
import sipconfig

if __name__ == "__main__":

    inc_dir = "src"
    lib_dir = "src"
    dest_pkg_dir = "temp"
    
    config = sipconfig.Configuration()
    
    # The name of the SIP build file generated by SIP and used by the build
    # system.
    sip_files_dir = "sip"
    
    if not os.path.exists("modules"):
        os.mkdir("modules")
    
    # Run SIP to generate the code.
    
    output_dir = "modules"
    build_file = "tempsip.sbf"
    build_path = os.path.join(output_dir, build_file)
    
    if not os.path.exists(output_dir):
        os.mkdir(output_dir)
    
    sip_file = os.path.join("sip", "tempsip_mod.sip")
    
    command = " ".join([config.sip_bin,
                        "-c", output_dir,
                        "-b", build_path,
                        "-I"+config.sip_inc_dir,
                        "-I"+inc_dir,
                        "-I/usr/include",
                        "-Isip",
                        "-w",
                        "-o", # generate docstrings for signatures
                        sip_file])
    sys.stdout.write(command+"\n")
    sys.stdout.flush()
    
    if os.system(command) != 0:
        sys.exit(1)
    
    # Create the Makefile.
    makefile = sipconfig.ModuleMakefile(
        config, build_file, dir=output_dir,
        install_dir=dest_pkg_dir
        )
    
    makefile.extra_include_dirs += [os.path.abspath(inc_dir)]
    makefile.extra_lib_dirs += [os.path.abspath(lib_dir)]
    makefile.extra_lflags += ["-Wl,-rpath="+os.path.abspath("src")]
    makefile.extra_libs += ["tempsip"]
    
    makefile.generate()
    
    sipconfig.ParentMakefile(
        configuration = config,
        subdirs = ["src", output_dir],
        ).generate()
    
    os.chdir("src")
    if os.system("qmake-qt4") != 0:
        os.system("qmake")
    
    sys.exit()

