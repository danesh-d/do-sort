IDIR = .
CC = gcc
CFLAGS = -I$(IDIR)
CXX = g++
CXXFLAGS = -I$(DIR) -O3

ODIR = .
LDIR = .

LIBS = -L$(IDIR) -ldo_sort

TEST_TARGET = test_do_sort

_DEPS = do_sort.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = do_sort.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

BUILD = $(OBJ) \
	$(CXX) do_sort.cc -c -o $(CFLAGS) \
	ar rcs libdo_sort.a do_sort.o

.PHONY: do_sort test clean

do_sort: $(OBJ)
	$(CXX) do_sort.cc $(CFLAGS) -c
	ar rcs libdo_sort.a do_sort.o

test: $(OBJ)
	$(CXX) do_sort.cc $(CFLAGS) -c
	ar rcs libdo_sort.a do_sort.o
	$(CXX) test_do_sort.cc -o test_do_sort $(LIBS)
	./$(TEST_TARGET)
	rm ./$(TEST_TARGET)

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ do_sort libdo_sort.a test_do_sort
