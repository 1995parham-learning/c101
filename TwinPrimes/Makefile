# In The Name Of God
# ========================================
# [] File Name : Makefile
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================

P=TwinPrimes
OBJ=main.o
LIB=
MLIB=-lm

ifdef LIB
CFLAGS=-Wall -O0 -g -std=gnu11 \
       $(shell pkg-config --cflags $(LIB))
LDLIBS=$(shell pkg-config --libs $(LIB)) $(MLIB)
else
CFLAGS=-Wall -O0 -g -std=gnu11
LDLIBS=$(MLIB)
endif
ASFLAGS=-Wall -O0 -g

$(P): $(OBJ)
	$(CC) -o $(P) $(OBJ) $(LDLIBS)

.PHONY: clean
clean:
	rm $(OBJ) $(P)
