# Makefile du projet pour les pc personnels.
# Définition des répertoires de travail.
SRC=./src
LIB=./lib
OBJ=./obj
BIN=./bin
TEST=./test
LIBS = `sdl2-config --libs` -lSDL2_ttf -lm
INCLUDES = -I./SDL2_ttf -I./SDL2_image

#Compilateur gcc

CC=gcc
CFLAGS= -W -Wall -g -std=c99 -g `sdl2-config --cflags `

all: DragonQuest

DragonQuest: $(OBJ)/main.o $(OBJ)/sdl2_fonctions.o $(OBJ)/images.o $(OBJ)/jeu.o $(OBJ)/monde.o $(OBJ)/entitee.o $(OBJ)/menu.o $(OBJ)/deplacements.o $(OBJ)/interactions.o
	$(CC) $(CFLAGS) $(INCLUDES) $^ -o $(BIN)/$@ $(LIBS)

$(OBJ)/main.o: $(SRC)/main.c $(SRC)/jeu.c $(LIB)/jeu.h $(LIB)/sdl2_fonctions.h $(LIB)/images.h
	$(CC) $(CFLAGS) -c ./$< -o $@ $(LIBS)

$(OBJ)/menu.o: $(SRC)/menu.c $(LIB)/menu.h
	$(CC) $(CFLAGS) -c ./$< -o $@ $(LIBS)

$(OBJ)/sdl2_fonctions.o: $(SRC)/sdl2_fonctions.c $(LIB)/sdl2_fonctions.h
	$(CC) $(CFLAGS) -c ./$< -o $@ $(LIBS)

$(OBJ)/images.o: $(SRC)/images.c $(LIB)/images.h
	$(CC) $(CFLAGS) -c ./$< -o $@ $(LIBS)

$(OBJ)/jeu.o: $(SRC)/jeu.c $(LIB)/jeu.h
	$(CC) $(CFLAGS) -c ./$< -o $@ $(LIBS)

$(OBJ)/monde.o: $(SRC)/monde.c $(LIB)/monde.h
	$(CC) $(CFLAGS) -c ./$< -o $@ $(LIBS)

$(OBJ)/entitee.o: $(SRC)/entitee.c $(LIB)/entitee.h
	$(CC) $(CFLAGS) -c ./$< -o $@ $(LIBS)

$(OBJ)/deplacements.o: $(SRC)/deplacements.c $(LIB)/deplacements.h
	$(CC) $(CFLAGS) -c ./$< -o $@ $(LIBS)

$(OBJ)/interactions.o: $(SRC)/interactions.c $(LIB)/interactions.h
	$(CC) $(CFLAGS) -c ./$< -o $@ $(LIBS)

entitee: test_entitee

test_entitee: $(OBJ)/test_entitee.o $(OBJ)/entitee.o
	$(CC) $(CFLAGS) ./$^ -o $(BIN)/$@ $(LIBS)

$(OBJ)/test_entitee.o: $(TEST)/test_entitee.c $(LIB)/entitee.h
	$(CC) $(CFLAGS) -c ./$< -o $@  $(LIBS)

monde: test_monde

test_monde: $(OBJ)/test_monde.o $(OBJ)/monde.o $(OBJ)/entitee.o
	$(CC) $(CFLAGS) ./$^ -o $(BIN)/$@ $(LIBS)

$(OBJ)/test_monde.o: $(TEST)/test_monde.c $(LIB)/monde.h
	$(CC) $(CFLAGS) -c ./$< -o $@  $(LIBS)

jeu: test_jeu

test_jeu: $(OBJ)/test_jeu.o $(OBJ)/jeu.o $(OBJ)/monde.o $(OBJ)/entitee.o
	$(CC) $(CFLAGS) ./$^ -o $(BIN)/$@ $(LIBS)

$(OBJ)/test_jeu.o: $(TEST)/test_jeu.c $(LIB)/jeu.h
	$(CC) $(CFLAGS) -c ./$< -o $@  $(LIBS)

clean:
	rm -rf $(OBJ)/*.o
	rm -rf $(BIN)/*
