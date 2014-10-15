#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

int main() {
    setlocale(LC_ALL, "ja_JP.UTF-8");
    wchar_t c = L'エ';
	wchar_t s[] = L"エボラちゃん";
    wprintf(L"%lc\n", c);
	wprintf(L"%ls\n", s);
	printf("Success.\n");
	//The following will cause a segmentation fault when the code above is run for some unknown reason(s).
	/*printf("%lu\n", sizeof(char));
	printf("Success.\n");
	printf("%lu\n", sizeof(wchar_t));*/
    return EXIT_SUCCESS;
}

