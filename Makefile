CC=gcc
CFLAGS=-g -Wall
TARGET=mp2_20200901
OBJS=mp2_20200901.c
LIBS += -lm

$(TARGET) : $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS)

clean:
	rm mp2_20200901