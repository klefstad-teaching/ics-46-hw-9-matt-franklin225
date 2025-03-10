CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -Werror -Wfatal-errors -pedantic
SRCS = src/ladder_main.cpp src/ladder.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = ladder_main

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

clean:
	rm -f $(OBJS) $(TARGET)