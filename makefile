# Makefile du projet.


# Définition des répertoires de travail.

SRC = ./src
BIN = ./bin

# Nom de l'executable
BINTEST = $(BIN)/test

#Compilateur gcc

CC = gcc


do:$(BINTEST)
	
$(BINTEST)
	$(CC) -c $(SRC)/test.c -o $(BINTEST)
	
