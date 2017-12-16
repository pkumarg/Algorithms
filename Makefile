CC=g++

SRC= $(shell find . -name "*.cpp")

TARGET=$(patsubst %.cpp, %, $(SRC))

all: $(TARGET)

%:%.cpp
			$(CC) $^ -o $@

clean:
	rm -f $(TARGET)
