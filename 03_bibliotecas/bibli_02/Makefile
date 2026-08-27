all: test

main.o: main.c matrix_utils.h
	gcc -c main.c

matrix_utils.o: matrix_utils.c matrix_utils.h
	gcc -c matrix_utils.c

scopel_exe: main.o matrix_utils.o
	gcc main.o matrix_utils.o -o scopel_exe

test: scopel_exe
	for i in 1 2 3; do ./scopel_exe < ../../Casos/$$i/entrada.txt > ../../output_test/saida$$i.txt; done

clean:
	rm -rf *.o
	rm -rf scopel_exe