#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COLUMN_SIZE 15
#define FILE_OPEN_ERROR -1
#define STRING_SIZE 100

int main() {

    FILE* f = fopen("input.txt", "r");
    FILE* buffer = fopen("buffer.txt", "w+");

    if (f == NULL || buffer == NULL) {
        printf("Error with open file\n");
        return FILE_OPEN_ERROR;
    }

    char col1[COLUMN_SIZE], col2[COLUMN_SIZE], col3[COLUMN_SIZE], str[STRING_SIZE], c;
    char* pstr;

    while (!feof(f)) {
        pstr = fgets(str, sizeof(str), f);

        sscanf(str, "%s %s %s", col1, col2, col3);
        fprintf(buffer, "%s %s %s\n", col3, col1, col2);
    }

    fseek(buffer, 0, SEEK_SET);
    f = freopen("input.txt", "w", f);

    while((c = fgetc(buffer)) != EOF) {
        fputc(c, f);
    }

    fclose(f);
    fclose(buffer);
    remove("buffer.txt");

    return 0;
}