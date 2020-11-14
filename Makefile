BIN     = ./bin
LIB     = ./lib
OBJ     = ./obj
SRC     = ./src
MAIN    = ./src/main
INCLUDE = ./include

EXS   = c
CC    = gcc
FLAGS = -O3 -Wall -std=c99
LIBS  = -L $(LIB) -lm -lgsi

PERSON   = $(OBJ)/gsi/person.o
EVENT    = $(OBJ)/gsi/event.o
THING    = $(OBJ)/gsi/thing.o
GSI      = $(OBJ)/gsi/gsi.o
NEW_GAME = $(OBJ)/stories/new_game/console_default.o

SUB_DIRS   = $(OBJ)/gsi $(OBJ)/stories/new_game
LIB_FILES  = $(PERSON) $(EVENT) $(THING) $(GSI) $(NEW_GAME)
MAIN_FILES = $(BIN)/app

all: dirs libgsi $(MAIN_FILES)

libgsi: dirs $(LIB_FILES)
	ar -rcs $(LIB)/libgsi.a $(LIB_FILES) $(OBJ)/cemdutil/*.o

dirs:
	mkdir -p $(BIN) $(LIB) $(OBJ)
	mkdir -p $(SUB_DIRS)

clean:
	rm -rf $(BIN)
	rm -rf $(LIB)
	rm -rf $(OBJ)/gsi $(OBJ)/stories

$(OBJ)/%.o: $(SRC)/%.$(EXS)
	$(CC) $(FLAGS) -c $< -I $(INCLUDE) -o $@

$(BIN)/%: $(MAIN)/%.$(EXS)
	$(CC) $(FLAGS) $< -I $(INCLUDE) $(LIBS) -o $@