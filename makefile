CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic

TARGET = studentDB

OBJS = main.o address.o date.o student.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp address.h date.h student.h
	$(CXX) $(CXXFLAGS) -c main.cpp

address.o: address.cpp address.h
	$(CXX) $(CXXFLAGS) -c address.cpp

date.o: date.cpp date.h
	$(CXX) $(CXXFLAGS) -c date.cpp

student.o: student.cpp student.h address.h date.h
	$(CXX) $(CXXFLAGS) -c student.cpp

run: $(TARGET)
	./$(TARGET)

debug: CXXFLAGS += -g
debug: clean all

valgrind: $(TARGET)
	valgrind --leak-check=full ./$(TARGET)

clean:
	rm -f *.o $(TARGET)
