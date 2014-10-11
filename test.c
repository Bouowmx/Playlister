#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

int main() {
    setlocale(LC_ALL, "");
    wchar_t c = L'\u30a8';
	wchar_t s[] = L"\u30a8\u30dc\u30e9\u3061\u3083\u3093";
    wprintf(L"%lc\n", c);
	wprintf(L"%ls\n", s);
	printf("Success.\n");
	//The following will cause a segmentation fault when the code above is run.
	/*printf("%lu\n", sizeof(char));
	printf("Success.\n");
	printf("%lu\n", sizeof(wchar_t));*/
    return EXIT_SUCCESS;
}

