CC := g++
CFLAGS := -std=c++11 -Wall -Wextra

SRCS := matrix.cpp main.cpp
OBJS := $(SRCS:.cpp=.o)
DEPS := $(OBJS:.o=.d)

TARGET := myprogram

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

clean:
	rm -f $(OBJS) $(DEPS) $(TARGET)

-include $(DEPS)