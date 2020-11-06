BIN     = ./bin
LIB     = ./lib
OBJ     = ./obj
SRC     = ./src
MAIN    = ./src/main
INCLUDE = ./include
SRC_LIB = ./src/lib

# SUB_DIRS =
LIB_FILES  = $(OBJ)/gsi_person.o
MAIN_FILES = $(BIN)/gsi

EXS   = c
EXH   = h
CC    = gcc
FLAGS = -O3 -Wall -std=c99
LIBS  = -L $(LIB) -lm -lgsi -lcemdutil

all: dirs libgsi $(MAIN_FILES)

libgsi: dirs $(LIB_FILES)
	ar -rcs $(LIB)/libgsi.a $(LIB_FILES)

dirs:
	mkdir -p $(BIN) $(LIB) $(OBJ)
	# mkdir -p $(SUB_DIRS)

clean:
	rm -rf $(BIN)
	rm -rf $(OBJ)
	rm -rf $(LIB)/libgsi.a

$(OBJ)/%.o: $(SRC_LIB)/%.$(EXS) $(INCLUDE)/%.$(EXH)
	$(CC) $(FLAGS) -c $< -I $(INCLUDE) -o $@

$(BIN)/%: $(MAIN)/%.$(EXS)
	$(CC) $(FLAGS) $< -I $(INCLUDE) $(LIBS) -o $@