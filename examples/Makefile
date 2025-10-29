CC = g++
CFLAGS = -Wall -std=c++11

RAYLIB_FLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

TARGET = example.out

SOURCE = example.cpp

#:NOTE: For example purpose, I have all the file in the same directory
SPLASH_INC = . # This is where the header file for the Splashlib is located

# Path to the compiled library file (for libSplash.a)
SPLASH_LIB_DIR = . #This is where the library file is located

# Name of the static library file (without the 'lib' prefix or '.a' extension)
SPLASH_LIB = Splash


all: $(TARGET)

$(TARGET): $(SOURCE)
	@echo "Compiling and Linking the example application..."
	
	$(CC) $(CFLAGS) $(SOURCE) -o $(TARGET) -I$(SPLASH_INC) \
	-L$(SPLASH_LIB_DIR) -l$(SPLASH_LIB) \
	$(RAYLIB_FLAGS)

	@echo "Successfully created $(TARGET) in the example directory."

clean:
	rm -f $(TARGET)

.PHONY: all clean
