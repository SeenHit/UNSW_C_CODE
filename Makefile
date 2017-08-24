main: main.o studentRecord.o studentLL.o
	gcc -g -o main main.o studentRecord.o studentLL.o

main.o : main.c studentRecord.h studentLL.h
	gcc -g -Wall -Werror -c main.c

studentRecord.o : studentRecord.c studentRecord.h
	gcc -g -Wall -Werror -c studentRecord.c

studentLL.o : studentLL.c studentLL.h studentRecord.h
	gcc -g -Wall -Werror -c studentLL.c

clean:
	rm -f main main.o studentRecord.o studentLL.o core

