CC = g++
ARGS = -std=c++17 -x c++ -o
OUTPUT = image.out
FILES = main.cpp photo.cpp

make run: $(FILES)
	$(CC) $(ARGS) $(OUTPUT) $(FILES) && ./$(OUTPUT)
