CC=g++
CFLAGS=-g --std=c++11

SRC= $(shell find . -name "*.cpp")

TARGET=$(patsubst %.cpp, %, $(SRC))

all: $(TARGET)

%:%.cpp
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(TARGET)
