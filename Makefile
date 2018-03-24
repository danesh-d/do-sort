IDIR = src
CC = gcc
CFLAGS = -I$(IDIR)
CXX = g++
CXXFLAGS = -I$(DIR) -O3 -std=c++11

ODIR = src
LDIR = lib
TDIR = test

TEST_TARGET = test_do_sort

.PHONY: do_sort test clean

test:
	mkdir -p $(LDIR)
	$(CXX) $(CXXFLAGS) $(TDIR)/test_do_sort.cc -o $(TDIR)/test_do_sort

gtest:
	cd test && $(MAKE)

clean:
	cd test && rm -rf test_do_sort && $(MAKE) clean
