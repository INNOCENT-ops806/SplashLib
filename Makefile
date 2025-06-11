
CXX=g++
AR=ar
BUILD_DIR=./build
LIB_DIR=./lib
BUILD_ARGS=-I./include/ -L/usr/lib -lraylib -lm

libName=Splash

all: compile
	$(AR) rcs $(LIB_DIR)/lib$(libName).a $(BUILD_DIR)/$(libName).o

compile: ./src/$(libName).cpp ./include/$(libName).h
	$(CXX) -c ./src/$(libName).cpp -o $(BUILD_DIR)/$(libName).o $(BUILD_ARGS)

clean:
	rm $(BUILD_DIR)/*
	rm $(LIB_DIR)/*

