CXX=g++
CXXFLAGS=-m32 -std=c++11 -Iinclude -Wall
LDFLAGS=-fPIC -shared 
DEPS=
OUT=-o bin/skin-changer.so

.PHONY: all setup clean

all: setup
	$(CXX) $(CXXFLAGS) src/*.cpp $(LDFLAGS) $(DEPS) $(OUT)

setup:
	-mkdir -p bin

clean:
	-rm -f *.o bin/*.so