all: linked_list.c music_library.c song.c
	gcc -o music_library.elf music_library.c
	./music_library.elf

clean:
	rm -f *.o

