all: linked_list.c song.c tunez.c
	gcc -o tunez.elf tunez.c

clean:
	rm -f *.o

