FILES := $(shell find . -name '*.cpp')

LDFLAGS=-lsfml-graphics -lsfml-window -lsfml-system 

all: $(FILES)
	g++ -g -o pong $(FILES) $(LDFLAGS)
