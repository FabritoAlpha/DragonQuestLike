# Makefile du projet.
# Définition des répertoires de travail.
SRC=./src
LIB=./lib
OBJ=./obj
BIN=./bin

#Compilateur gcc

CC=gcc

all: test

test: $(OBJ)/test.o $(OBJ)/test.o
	$(CC) $(OBJ)/test.o $(OBJ)/test.o -o $(BIN)/test -lm

$(OBJ)/test.o: $(LIB)/test.h $(SRC)/test.c
	$(CC) -c $(SRC)/test.c -o $(OBJ)/test.o -lm

$(OBJ)/test.o: $(SRC)/test2.c
	$(CC) -c $(SRC)/test2.c $(OBJ)/test.o -lm
