CC=gcc
CFLAGS=-g -Wall -Wextra -std=c11

BINS_DIR=bin

all: $(BINS_DIR)/01 $(BINS_DIR)/02 $(BINS_DIR)/04

$(BINS_DIR)/01: 01.c
	@mkdir -p $(BINS_DIR)
	$(CC) $(CFLAGS) 01.c -o $(BINS_DIR)/01
$(BINS_DIR)/02: 02.c
	@mkdir -p $(BINS_DIR)
	$(CC) $(CFLAGS) 02.c -o $(BINS_DIR)/02
$(BINS_DIR)/04: 04.c
	@mkdir -p $(BINS_DIR)
	$(CC) $(CFLAGS)  04.c -o $(BINS_DIR)/04

clean:
	-rm -rf $(BINS_DIR)
