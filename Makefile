# Makefile du projet pour les pc de l'univ.
# Définition des répertoires de travail.
SRC=./src
LIB=./lib
OBJ=./obj
BIN=./bin
TEST=./test

#Définition de la
SDL_DIR=${HOME}/SDL2
SDL_LIB_DIR=${SDL_DIR}/lib
SDL_INC_DIR=${SDL_DIR}/include

LIBS=-L${SDL_LIB_DIR} -lSDL2 -lSDL2_image -lSDL2_ttf -lm
INCS=-I${SDL_INC_DIR}
PROG=sdl_test

#Compilateur gcc

CC=gcc
FLAGS=-Wall
CFLAGS=$(FLAGS) -g

all: DragonQuest

DragonQuest: $(OBJ)/main.o $(OBJ)/sdl2_fonctions.o $(OBJ)/images.o $(OBJ)/jeu.o $(OBJ)/menu.o $(OBJ)/monde.o $(OBJ)/entitee.o $(OBJ)/affichage.o $(OBJ)/deplacements.o $(OBJ)/interactions.o
	$(CC) $(CFLAGS) $^ -o $(BIN)/$@ $(LIBS) $(INCS)

$(OBJ)/main.o: $(SRC)/main.c $(LIB)/jeu.h $(LIB)/sdl2_fonctions.h $(LIB)/images.h
	$(CC) $(CFLAGS) -c ./$< -o $@ $(LIBS) $(INCS)

$(OBJ)/sdl2_fonctions.o: $(SRC)/sdl2_fonctions.c $(LIB)/sdl2_fonctions.h
	$(CC) $(CFLAGS) -c ./$< -o $@ $(LIBS) $(INCS)

$(OBJ)/images.o: $(SRC)/images.c $(LIB)/images.h
	$(CC) $(CFLAGS) -c ./$< -o $@ $(LIBS) $(INCS)

$(OBJ)/jeu.o: $(SRC)/jeu.c $(LIB)/jeu.h
	$(CC) $(CFLAGS) -c ./$< -o $@ $(LIBS) $(INCS)

$(OBJ)/menu.o: $(SRC)/menu.c $(LIB)/menu.h
	$(CC) $(CFLAGS) -c ./$< -o $@ $(LIBS) $(INCS)

$(OBJ)/monde.o: $(SRC)/monde.c $(LIB)/monde.h
	$(CC) $(CFLAGS) -c ./$< -o $@ $(INCS)

$(OBJ)/entitee.o: $(SRC)/entitee.c $(LIB)/entitee.h
	$(CC) $(CFLAGS) -c ./$< -o $@ $(INCS)

$(OBJ)/affichage.o: $(SRC)/affichage.c $(LIB)/affichage.h
	$(CC) $(CFLAGS) -c ./$< -o $@ $(INCS)

$(OBJ)/deplacements.o: $(SRC)/deplacements.c $(LIB)/deplacements.h
	$(CC) $(CFLAGS) -c ./$< -o $@ $(INCS)

$(OBJ)/interactions.o: $(SRC)/interactions.c $(LIB)/interactions.h
	$(CC) $(CFLAGS) -c ./$< -o $@ $(INCS)

entitee: test_entitee

test_entitee: $(OBJ)/test_entitee.o $(OBJ)/entitee.o
	$(CC) $(CFLAGS) ./$^ -o $(BIN)/$@

$(OBJ)/test_entitee.o: $(TEST)/test_entitee.c $(LIB)/entitee.h
	$(CC) $(FLAGS) -c ./$< -o $@

monde: test_monde

test_monde: $(OBJ)/test_monde.o $(OBJ)/monde.o $(OBJ)/entitee.o
	$(CC) $(CFLAGS) ./$^ -o $(BIN)/$@

$(OBJ)/test_monde.o: $(TEST)/test_monde.c $(LIB)/monde.h
	$(CC) $(FLAGS) -c ./$< -o $@

jeu: test_jeu

test_jeu: $(OBJ)/test_jeu.o $(OBJ)/jeu.o $(OBJ)/monde.o $(OBJ)/entitee.o
	$(CC) $(CFLAGS) ./$^ -o $(BIN)/$@ $(LIBS)

$(OBJ)/test_jeu.o: $(TEST)/test_jeu.c $(LIB)/jeu.h
	$(CC) $(FLAGS) -c ./$< -o $@  $(LIBS)

clean:
	rm -rf $(OBJ)/*.o
	rm -ff $(BIN)/*
