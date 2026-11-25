CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
SHARED_FLAGS = -fPIC -shared

.PHONY: all clean

all: lib1/libimplement.so lib2/libimplement.so pr1/pr1 pr2/pr2

lib1/libimplement.so: lib1/implement.c include/contracts.h
	$(CC) $(CFLAGS) $(SHARED_FLAGS) $< -lm -o $@

lib2/libimplement.so: lib2/implement.c include/contracts.h
	$(CC) $(CFLAGS) $(SHARED_FLAGS) $< -lm -o $@

pr1/pr1: pr1/main.c include/contracts.h lib1/libimplement.so
	$(CC) $(CFLAGS) $< -Llib1 -limplement -Wl,-rpath,'$$ORIGIN/../lib1' -lm -o $@

pr2/pr2: pr2/main.c
	$(CC) $(CFLAGS) $< -o $@ -ldl

clean:
	rm -f lib1/libimplement.so lib2/libimplement.so pr1/pr1 pr2/pr2