CC = gcc
CFLAGS = -Wall -g
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
MAIN = ipr

all: $(MAIN)

$(MAIN): $(OBJS)
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)

.PHONY: clean
clean:
	rm -f $(OBJS) $(MAIN)