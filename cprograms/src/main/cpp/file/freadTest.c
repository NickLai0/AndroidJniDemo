#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "test/text.dat"

int main(void) {

    FILE *file = fopen(FILENAME, "wb");
    if (file == NULL) {
        printf("Can not open file: %s", FILENAME);
        exit(1);
    }
    char a[] = {'a', 'b', 'c', 'd', '\0'}, b;
    fwrite(a, sizeof(char), strlen(a), file);
    fclose(file);

    file = fopen(FILENAME, "rb");
    if (file == NULL) {
        printf("Can not open file: %s", FILENAME);
        exit(2);
    }
    fseek(file, -3 * sizeof(char), SEEK_END);
    fread(&b, sizeof(char), 1, file);
    //I expected: a. But the result is b.
    printf("%c\n", b);
    fclose(file);

    return 0;
}