COMPILER = gcc
FLAGS =  -Wall -Werror

.PHONY: clean all

all: bin/main


-include build/*.d

bin/main: build/main.o 
	$(COMPILER) $(FLAGS)  -o $@ $^ 

build/main.o: src/main.c
	$(COMPILER) $(FLAGS) -MMD -c -o $@ $<

clean:
	rm build/*