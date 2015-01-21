CC=g++
CFLAGS=-Wall
LDFLAGS=-lSDL -lGL -lGLU
EXEC=Glaw
TEXEC=Test-Glaw
SRC= $(wildcard src/*.cpp src/*/*.cpp)
TEST := $(SRC) $(wildcard test/*.cpp)
TEST := $(filter-out src/main.cpp, $(TEST))
OBJ= $(SRC:.c=.o)

all: $(EXEC)

run: mrproper all
	@./$(EXEC)

test: mrproper $(TEXEC)
	@./$(TEXEC)

$(TEXEC): $(TEST)
	@$(CC) -o $@ $^ $(LDFLAGS)

$(EXEC): $(SRC)
	@$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	@$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	@rm -rf *.o

mrproper: clean
	@rm -rf $(EXEC)
	@rm -rf $(TEXEC)