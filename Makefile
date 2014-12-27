CC=g++
CFLAGS=-Wall
LDFLAGS=
EXEC=OpenGL-Draw
TEXEC=Test-OpenGL-Draw
SRC= $(wildcard src/*.cpp lib/*.cpp)
TEST := $(SRC) $(wildcard test/*.cpp)
TEST := $(filter-out src/main.cpp, $(TEST))
OBJ= $(SRC:.c=.o)

run: mrproper all
	@./$(EXEC)

test: mrproper $(TEXEC)
	@./$(TEXEC)

all: $(EXEC)

$(TEXEC): $(TEST)
	@$(CC) -o $@ $^ $(LDFLAGS)

OpenGL-Draw: $(SRC)
	@$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	@$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	@rm -rf *.o

mrproper: clean
	@rm -rf $(EXEC)
	@rm -rf $(TEXEC)