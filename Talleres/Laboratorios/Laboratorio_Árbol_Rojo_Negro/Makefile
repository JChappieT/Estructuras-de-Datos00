CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

# Archivos fuente y de encabezado
SRC = biblioteca.cpp main.cpp
OBJ = $(SRC:.cpp=.o)
DEPS = biblioteca.h

# Nombre del ejecutable
TARGET = main

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean