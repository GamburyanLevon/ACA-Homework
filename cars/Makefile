CC = g++
CFLAGS = -std=c++11 -Wall
SRC = main.cpp car.cpp crossover.cpp electricSedan.cpp hyperCar.cpp jeep.cpp sedan.cpp sportsCar.cpp
OBJ = $(SRC:.cpp=.o)
EXECUTABLE = my_program

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXECUTABLE)

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXECUTABLE)
