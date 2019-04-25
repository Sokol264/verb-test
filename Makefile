COMPILER = gcc
FLAGS =  -Wall -Werror

.PHONY: clean all

all: bin/main


-include build/*.d

bin/main: build/main.o build/rec.o build/compare.o
	$(COMPILER) $(FLAGS)  -o $@ $^ 

build/main.o: src/main.c
	$(COMPILER) $(FLAGS) -MMD -c -o $@ $<

build/rec.o: src/rec.c
	$(COMPILER) $(FLAGS) -MMD -c -o $@ $<

build/compare.o: src/compare.c
	$(COMPILER) $(FLAGS) -MMD -c -o $@ $<
	
clean:
	rm build/*