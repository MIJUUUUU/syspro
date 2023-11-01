#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char file_name[] = "test.txt";
    FILE *file = fopen(file_name, "r");

    if (file == NULL) {
        printf("%s\n", file_name);
        return 1;
    }

    char lines[100][256];
    int line_count = 0;

    while (fgets(lines[line_count], sizeof(lines[line_count]), file) != NULL) {
        line_count++;
    }

    fclose(file);

    for (int i = line_count - 1; i >= 0; i--) {
        printf("%s", lines[i]);
    }

    return 0;
}

