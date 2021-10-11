main: main.c
		gcc -o main main.c -I.
main2: main2.c
		gcc -o main2 main2.c -I.
processes: processes.c
		gcc -o processes processes.c -I.