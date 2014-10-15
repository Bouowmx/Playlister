#include "music_library.c"

int main() {
	music_library * library = music_library_new();
	music_library_add(library, "Bad Apple!!", "Alstroemeria Records", "EXSERENS"); //Artist is the group.
	music_library_add(library, "Bad Apple!!", "Team Shanghai Alice", "Lotus Land Story");
	music_library_add(library, "Cirno's Perfect Math Class", "IOSYS", "Touhou Anthology of Ice and Snow");
	music_library_add(library, "Doll Judgment ~ The Girl who Played with People's Shapes", "Team Shanghai Alice", "Perfect Cherry Blossom");
	music_library_add(library, "Final Savage Sister Flandre S", "COOL&CREATE", "Touhou Strike");
	music_library_add(library, "Flowering Night", "Team Shanghai Alice", "Phantasmagoria of Flower View");
	music_library_add(library, "Kero⑨destiny", "Silver Forest", "Touhou Blue Sky Songs"); //The "box", if displayed, is actually the circled number 9.
	music_library_add(library, "Marisa Stole the Precious Thing", "IOSYS", "Touhou Maidens' Orchestra");
	music_library_add(library, "Night of Nights", "Unionest.NET", "Bouquet -hanataba-"); //This is usually associated with group "COOL&CREATE" instead.
	music_library_add(library, "Native Faith", "Team Shanghai Alice", "Mountain of Faith"); //This is to test linked_list_add_sorted. Note the out of ordering with the one above.
	music_library_add(library, "Tomboyish Girl in Love", "Team Shanghai Alice", "Embodiment of Scarlet Devil");
	music_library_add(library, "U.N. Owen Was Her?", "Team Shanghai Alice", "Embodiment of Scarlet Devil");
	
	//music_library_add(library, "
	music_library_print(library);
	printf("\n");
	music_library_print_artist(library, "IOSYS");
	printf("\n");
	music_library_print_letter(library, 'B');
	
	return EXIT_SUCCESS;
}

