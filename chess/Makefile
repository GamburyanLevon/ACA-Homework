CXX = g++
CXXFLAGS = -std=c++11 -Wall
TARGET = myprogram

SRCS = main.cpp figure.cpp bishop.cpp queen.cpp rook.cpp knight.cpp pawn.cpp chessboard.cpp king.cpp
OBJS = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<
