COMPILER = gcc
FLAGS =  -Wall -Werror

.PHONY: clean all

all: bin/main

test: bin/main-test

-include build/*.d

bin/main: build/main.o build/rec.o build/compare.o build/read.o
	$(COMPILER) $(FLAGS)  -o $@ $^ 

build/main.o: src/main.c
	$(COMPILER) $(FLAGS) -MMD -c -o $@ $<

build/rec.o: src/rec.c
	$(COMPILER) $(FLAGS) -MMD -c -o $@ $<

build/compare.o: src/compare.c
	$(COMPILER) $(FLAGS) -MMD -c -o $@ $<

build/read.o: src/read.c	
	$(COMPILER) $(FLAGS) -MMD -c -o $@ $<

-include test/*.d

bin/main-test: test/main-test.o test/compare.o test/test.o
	$(COMPILER) $(FLAGS) -o $@ $^

test/main-test.o: test/main-test.c
	$(COMPILER) -I thirdparty -I src $(FLAGS) -MMD -c -o $@ $<

test/test.o: test/test.c
	$(COMPILER) -I thirdparty -I src $(FLAGS) -MMD -c -o $@ $<

test/compare.o: src/compare.c
	$(COMPILER) -I thirdparty -I src $(FLAGS) -MMD -c -o $@ $<

clean:
	rm build/*