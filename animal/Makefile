CXX = g++
CXXFLAGS = -std=c++11 -Wall
TARGET = myprogram

SRCS = main.cpp dog.cpp cat.cpp bird.cpp fish.cpp elephant.cpp animal.cpp
OBJS = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<
