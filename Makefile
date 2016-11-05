IDIR = src
CC = gcc
CFLAGS = -I$(IDIR)
CXX = g++
CXXFLAGS = -I$(DIR) -O3

ODIR = src
LDIR = lib
TDIR = test

TEST_TARGET = test_do_sort

.PHONY: do_sort test clean

test: #$(OBJ)
	mkdir -p $(LDIR)
	$(CXX) $(TDIR)/test_do_sort.cc -o $(TDIR)/test_do_sort
	$(TDIR)/$(TEST_TARGET)
	rm ./$(TDIR)/$(TEST_TARGET)

