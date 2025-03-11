CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -Werror -Wfatal-errors -pedantic
SRCS = src/dijkstras_main.cpp src/dijkstras.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = main

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

clean:
	rm -f $(OBJS) $(TARGET)