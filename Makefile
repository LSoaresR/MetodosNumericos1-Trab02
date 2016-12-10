LIB_DIR  = lib/
SRC_DIR  = src/
TEST_DIR = test/

CFLAGS += -Wall -Wextra -I $(SRC_DIR) -I $(LIB_DIR) -I $(TEST_DIR)

all: main.o

main.o:
	g++ src/main.cpp src/Exception.cpp src/Matrix.cpp src/Dados.cpp -o make/main

clean:
	rm make/*