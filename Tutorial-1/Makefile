# Makefile for CMPT300 Tutorial Sample Programs

#Variables

CC=gcc
CFLAGS=-Wall -g
LDFLAGS=
BIN=bin
SRC=src

all: SampleA SampleB SampleC

SampleA: $(BIN)/SampleA

SampleB: $(BIN)/SampleB

SampleC: $(BIN)/SampleC

$(BIN)/SampleA: $(SRC)/SampleA.c
	$(CC) $(CFLAGS) $(SRC)/SampleA.c -o $(BIN)/SampleA

$(BIN)/SampleB: $(SRC)/SampleB.c
	$(CC) $(CFLAGS) $(SRC)/SampleB.c -o $(BIN)/SampleB

$(BIN)/SampleC: $(SRC)/SampleC.c
	$(CC) $(CFLAGS) $(SRC)/SampleC.c -o $(BIN)/SampleC

clean:
	rm $(BIN)/*