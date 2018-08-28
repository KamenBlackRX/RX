#Choose Compiler
CXX=%s

#GTKFLAGS=-Wextra $(shell pkg-config --cflags --libs gtk+-3.0)
CFLAGS=-g -std=c++11 -Wreturn-local-addr -pthread
CPPFLAGS= 
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
	
	$(CXX) $(CFLAGS) $(CPPFLAGS) -o $(MAIN) $^

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
