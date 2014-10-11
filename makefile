all: linked_list.c music_library.c song.c
	gcc -o music_library.elf music_library.c
	./music_library.elf

linked_list: linked_list.c
	gcc -o linked_list.elf linked_list.c
	./linked_list.elf

song: song.c
	gcc -o song.elf song.c
	./song.elf

test: test.c
	gcc -o test.elf -pedantic-errors -std=c99 test.c
	./test.elf

clean:
	rm -f *.elf
	rm -f *.o
	rm -f *.stackdump
