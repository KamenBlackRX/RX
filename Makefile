#Choose Compiler
CXX=g++

#GTKFLAGS=-Wextra $(shell pkg-config --cflags --libs gtk+-3.0)
SDLFLAGS=$(shell pkg-config --cflags --libs sdl2)
GLEWFLAGS=$(shell pkg-config --cflags --libs glew)
XFLAGS=$(shell pkg-config --cflags --libs x11)

CFLAGS=-g -std=c++11 -Wreturn-local-addr -pthread
CPPFLAGS= -lSDL2
LDFLAGS=-L lSDL2
SOURCE=$(wildcard src/*.cpp)
INCLUDES =$(wildcard include/*.h)
MAIN=RX

#Store if user is root info
IS_ROOT=$(shell whoami)

.PHONY: clean

all:  $(MAIN)
	@echo Program is sucessfull compiled;

$(MAIN): $(SOURCE)
	@echo $(GLEWFLAGS)
	$(CXX) $(CFLAGS) $^ $(SDLFLAGS) $(GLEWFLAGS) $(XFLAGS) -o $(MAIN)

static: $(SOURCE)

	$(CXX) $(CFLAGS) -o $(MAIN) -static $^
		
install:

	if [ "$(shell whoami)" = "root" ]; then \
		install -c -m 755  $(MAIN) /usr/bin; \
	else \
		sudo /usr/bin/install -c -m 755  $(MAIN) /usr/bin; \
	fi;

clean:
	rm -f $(MAIN) *.o

configure:
	@echo Searching Dependences unsolved... 
	@./configure
