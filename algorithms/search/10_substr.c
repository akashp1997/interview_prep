#include <stdio.h>
#include <string.h>

int search_util(char *total, char *substr) {
    if(*total=='\0' && *substr!='\0') return 0;
    if(*substr=='\0') return 1;

    if(*total==*substr) return search_util(total+1, substr+1);
    return 0;
}

int search(char *total, char *substr) {
    if(*total=='\0') return 0;
    if(*total==*substr && search_util(total, substr)) return 1;
    return search(total+1, substr);
}

int main() {
    char total[] = "geeksforgeeks";
    char substr[] = "geeke";
    printf("%d\n", search(total, substr));
    return 0;
}
