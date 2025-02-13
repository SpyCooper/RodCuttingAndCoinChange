.PHONY: all, compile, run, clean

all: compile
run: compile execute

compile:
	g++ RodCuttingAndCoinChange.cc -o RodAndCoin

execute:
	./RodAndCoin

clean:
	rm RodAndCoin