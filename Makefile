CC = g++
CFLAGS = -O2 -g -Wall -std=c++17

SOURCES = DigitalRain.cpp Raindrop.cpp main.cpp
OBJECTS = $(SOURCES:.cpp=.o)
TARGET = matrix

:$(TARGET)

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $(OBJECTS) -lcurses

clean:
	rm -rvf $(OBJECTS)