signals: signals.c
	gcc -o signals signals.c

run: signals
	./signals
