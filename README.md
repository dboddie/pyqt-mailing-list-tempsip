pyqt-wrapped-app
================

A sample PyQt wrapper for a C++ application.

Licensed under the GNU General Public License, either version 3 of the License,
or (at your option) any later version. See the COPYING file for details.

The example has been built in stages. Each stage has a corresponding tag in the
repository. Use `git checkout` with each tag to see the code for that stage:

 1. initial_app

    The original application that we want to wrap or extend in Python.

 2. make_app_a_library

    We build the application as a library. This means that it can no longer be
    run as a standalone C++ application. You could build the application as
    both a library and a standalone executable.

 3. added_simple_wrapper

    A Python module called wrapped_app is created by adding a SIP wrapper for
    the application's main window.

 4. python_main_program

    We add a main program to replace the one written in C++. We could remove
    the main.cpp file from the build at this point. Note that we have not
    replaced or rewritten any of the GUI code; we access and control the same
    C++ classes from Python.

 5. wrap_the_dialog_class

    We want to extend or rewrite the login dialog in Python. By adding a
    wrapper for the LoginDialog class, we can create an instance of it in
    Python and pass it to the MainWindow instance for it to use. This is done
    in preparation for the next step.

 6. extended_dialog_in_python

    The code here gets a little convoluted because the GUI of the dialog is
    already well defined in C++, but we create a Python subclass of the C++
    LoginDialog class and modify the GUI a little, using some run-time tricks
    enabled by Qt. We also add a method to the dialog to check that the user's
    input is not completely invalid.
