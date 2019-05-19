COMPILER = gcc
FLAGS =  -Wall -Werror

.PHONY: clean all clean-test

all: bin/main

test: bin/main-test

-include build/*.d

bin/main: build/main.o build/rec.o build/compare.o build/read.o build/mark.o
	$(COMPILER) $(FLAGS)  -o $@ $^ 

build/main.o: src/main.c
	$(COMPILER) $(FLAGS) -MMD -c -o $@ $<

build/rec.o: src/rec.c
	$(COMPILER) $(FLAGS) -MMD -c -o $@ $<

build/compare.o: src/compare.c
	$(COMPILER) $(FLAGS) -MMD -c -o $@ $<

build/read.o: src/read.c	
	$(COMPILER) $(FLAGS) -MMD -c -o $@ $<

build/mark.o: src/mark.c	
	$(COMPILER) $(FLAGS) -MMD -c -o $@ $<



-include test/*.d

bin/main-test: build-test/main-test.o build-test/compare.o build-test/test.o
	$(COMPILER) $(FLAGS) -o $@ $^

build-test/main-test.o: test/main-test.c
	$(COMPILER) -I thirdparty -I src $(FLAGS) -MMD -c -o $@ $<

build-test/test.o: test/test.c
	$(COMPILER) -I thirdparty -I src $(FLAGS) -MMD -c -o $@ $<

build-test/compare.o: src/compare.c
	$(COMPILER) -I thirdparty -I src $(FLAGS) -MMD -c -o $@ $<

clean:
	rm build/*

clean-test:
	rm build-test/*

