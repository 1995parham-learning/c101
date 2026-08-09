# In The Name Of God
# ========================================
# [] File Name : Makefile
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================

P=libHelloJNI.so
OBJ=HelloJNI.o
LIB=
MLIB=

ifdef LIB
CFLAGS=-Wall -O0 -g -std=gnu11 \
       $(shell pkg-config --cflags $(LIB))
LDLIBS=$(shell pkg-config --libs $(LIB)) $(MLIB)
else
CFLAGS=-Wall -O0 -g -std=gnu11
LDLIBS=$(MLIB)
endif
ASFLAGS=-Wall -O0 -g

# Resolve the running JDK's include dir from javac on PATH instead of a
# hardcoded, version- and arch-specific path.
JAVA_HOME:=$(shell dirname $$(dirname $$(readlink -f $$(command -v javac))))
CFLAGS+=-I"$(JAVA_HOME)/include" -I"$(JAVA_HOME)/include/linux" -fPIC

$(P): $(OBJ)
	$(CC) -shared -o $(P) $(OBJ) $(LDLIBS)
HelloJNI.o: HelloJNI.h

HelloJNI.class: HelloJNI.java
	javac HelloJNI.java

# javah was removed in JDK 10+; javac -h generates the JNI header directly.
HelloJNI.h: HelloJNI.java
	javac -h . HelloJNI.java

.PHONY: clean
clean:
	rm -f $(OBJ) $(P) HelloJNI.h HelloJNI.class
