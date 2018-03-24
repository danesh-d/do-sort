# do-sort
A C/C++ collection for sorting functions.

The library which is written in C++ but is compatible with both C and C++.

# How to run
------------
The test routines can be executed by running:

$ make test
$ test/test_do_sort

The test program as well as the library code is compiled using C++11 features.

$ make gtest
$ test/gtest_do_sort

A test suite consisted of Google tests will be compiles and an executable will
be generated.

Please note that the tool chain is now explicitly using C++11 but GCC uses C++14
from version 6.1 and above.

