# Makefile for CMPT300 Tutorial Sample Programs

#Variables

CC=gcc
CFLAGS=-Wall -g -DUSE_LOCKS 
BIN=bin
SRC=src
LDFLAGS=-lpthread

all: Samples

Samples: $(BIN)/Sample $(BIN)/SampleB $(BIN)/SampleC

$(BIN)/Sample: $(SRC)/Sample.c
	$(CC) $(CFLAGS) $(SRC)/Sample.c -o $(BIN)/Sample $(LDFLAGS) 

$(BIN)/SampleB: $(SRC)/SampleB.c
	$(CC) $(CFLAGS) -O0 $(SRC)/SampleB.c -o $(BIN)/SampleB $(LDFLAGS) 

$(BIN)/SampleC: $(SRC)/SampleC.c
	$(CC) $(CFLAGS) -O0 $(SRC)/SampleC.c -o $(BIN)/SampleC $(LDFLAGS) 

clean:
	rm $(BIN)/*