IDIR = .
CC = gcc
CFLAGS = -I$(IDIR)
CXX = g++
CXXFLAGS = -I$(DIR) -O3

ODIR = src
LDIR = lib
TDIR = test

LIBS = -L$(LDIR) -ldo_sort

TEST_TARGET = test_do_sort

_DEPS = $(ODIR)/do_sort.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = do_sort.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

BUILD = $(OBJ) \
	$(CXX) do_sort.cc -c -o $(ODIR) $(CFLAGS) \
	ar rcs $(LDIR)\libdo_sort.a $(ODIR)\do_sort.o

.PHONY: do_sort test clean

do_sort: $(OBJ)
	mkdir -p $(LDIR)
	ar rcs $(LDIR)/libdo_sort.a $(ODIR)/do_sort.o

test: $(OBJ)
	mkdir -p $(LDIR)
	ar rcs $(LDIR)/libdo_sort.a $(ODIR)/do_sort.o
	$(CXX) $(TDIR)/test_do_sort.cc -o $(TDIR)/test_do_sort $(LIBS)
	$(TDIR)/$(TEST_TARGET)
	rm ./$(TDIR)/$(TEST_TARGET)

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ do_sort $(LDIR)/libdo_sort.a $(TDIR)/test_do_sort
