# Makefile du projet.
# Définition des répertoires de travail.
SRC=./src
LIB=./lib
OBJ=./obj
BIN=./bin

#Compilateur gcc

CC=gcc
CFLAGS= -Wall

all: DragonQuest

DragonQuest: $(OBJ)/main.o
	$(CC) $(CFLAGS) $^ -o $(BIN)/$@ -lm

$(OBJ)/main.o: $(SRC)/main.c 
	$(CC) $(CFLAGS) -c ./$< -o $@ -lm

$(OBJ)/jeu.o: $(SRC)/jeu.c $(LIB)/jeu.h
	$(CC) $(CFLAGS) -c ./$< -o $@ -lm

$(OBJ)/monde.o: $(SRC)/monde.c $(LIB)/monde.h
	$(CC) $(CFLAGS) -c ./$< -o $@ -lm

$(OBJ)/entitee.o: $(SRC)/entitee.c $(LIB)/entitee.h
	$(CC) $(CFLAGS) -c ./$< -o $@ -lm

entitee: test_entitee

test_entitee: $(OBJ)/test_entitee.o 
	$(CC) $(CFLAGS) -c ./$< -o $@ -lm

$(OBJ)/test_entitee.o: $(SRC)/test_entitee.c
	$(CC) $(CFLAGS) -c ./$< -o $@  -lm

monde: test_monde

test_monde: $(OBJ)/test_monde.o 
	$(CC) $(CFLAGS) -c ./$< -o $@ -lm

$(OBJ)/test_monde.o: $(SRC)/test_monde.c
	$(CC) $(CFLAGS) -c ./$< -o $@  -lm

jeu: test_jeu

test_jeu: $(OBJ)/test_jeu.o 
	$(CC) $(CFLAGS) -c ./$< -o $@ -lm

$(OBJ)/test_jeu.o: $(SRC)/test_jeu.c
	$(CC) $(CFLAGS) -c ./$< -o $@  -lm