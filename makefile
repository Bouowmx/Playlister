all: linked_list.c music_library.c song.c test.c
	gcc -o test.elf test.c
	./test.elf

linked_list: linked_list.c
	gcc -o linked_list.elf linked_list.c
	./linked_list.elf

song: song.c
	gcc -o song.elf song.c
	./song.elf

test: test.c
	gcc -o test.elf test.c
	./test.elf

test_locale: test_locale.c
	gcc -o test_locale.elf -pedantic-errors -std=c99 test_locale.c
	./test_locale.elf

clean:
	rm -f *.elf
	rm -f *.o
	rm -f *.stackdump

