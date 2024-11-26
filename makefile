.PHONY: clean run compile
compile: main.o
		@gcc -o main main.o -lm
main.o: main.c
		@gcc -c main.c
clean:
		@rm -f main
		@rm -f *.o
run:
		@./main