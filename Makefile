all:
	gcc -O2 -o main main.c readInput.c registerItem.c reset.c printResults.c requestSale.c completeSale.c expireID.c

	./main
# main: src/*.c makefile
# 	gcc -O2 -o main main.c readInput.c printResults.c
# clean:
# 	rm main
