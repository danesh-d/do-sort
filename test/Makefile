GOOGLE_TEST_LIB = gtest
GOOGLE_MOCK_LIB = gmock
GOOGLE_TEST_MOCK_INCLUDE = /usr/local/include

G++ = g++
G++_FLAGS = -c -Wall -std=c++11 -I $(GOOGLE_TEST_MOCK_INCLUDE)
LD_FLAGS = -L /usr/local/lib -l $(GOOGLE_TEST_LIB) -l $(GOOGLE_MOCK_LIB) -l pthread

OBJECTS = main.o gtest_do_sort.o
TARGET = gtest_do_sort

gtest: $(TARGET)

$(TARGET): $(OBJECTS)
	g++ -o $(TARGET) $(OBJECTS) $(LD_FLAGS)

%.o : %.cpp
	$(G++) $(G++_FLAGS) $<

clean:
	rm -f $(TARGET) $(OBJECTS)

.PHONY: all clean

