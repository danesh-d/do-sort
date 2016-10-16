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

_DEPS = $(ODIR)/do_sort.h \
				$(ODIR)/bubble_sort.h \
				$(ODIR)/selection_sort.h \
				$(ODIR)/insertion_sort.h \
				$(ODIR)/strand_sort.h \
				$(ODIR)/quick_sort.h \
				$(ODIR)/merge_sort.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = do_sort.o \
			 bubble_sort.o \
			 selection_sort.o \
			 insertion_sort.o \
			 strand_sort.o \
			 quick_sort.o \
			 merge_sort.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

BUILD = $(OBJ) \
	$(CXX) do_sort.cc \
         bubble_sort.cc \
				 selection_sort.cc \
				 insertion_sort.cc \
				 strand_sort.cc \
				 quick_sort.cc \
				 merge_sort.cc \
				 -c -o $(ODIR) $(CFLAGS)

BUILD_LIB = ar rcs $(LDIR)/libdo_sort.a \
                   $(ODIR)/do_sort.o \
                   $(ODIR)/bubble_sort.o \
                   $(ODIR)/selection_sort.o \
                   $(ODIR)/insertion_sort.o \
                   $(ODIR)/strand_sort.o \
                   $(ODIR)/quick_sort.o \
                   $(ODIR)/merge_sort.o

.PHONY: do_sort test clean

do_sort: $(OBJ)
	mkdir -p $(LDIR)
	$(BUILD_LIB)

test: $(OBJ)
	mkdir -p $(LDIR)
	$(BUILD_LIB)
	$(CXX) $(TDIR)/test_do_sort.cc -o $(TDIR)/test_do_sort $(LIBS)
	$(TDIR)/$(TEST_TARGET)
	rm ./$(TDIR)/$(TEST_TARGET)

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ do_sort $(LDIR)/libdo_sort.a $(TDIR)/test_do_sort

