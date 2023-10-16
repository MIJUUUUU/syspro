#include <stdio.h>
#include "copy.h"

int main() {
    char lines[5][MAX_LINE_LENGTH];
    int numLines = 5;

    printf("Enter 5 lines of text:\n");

    int i = 0;
    while (i < numLines) {
        printf("Enter line %d: ", i + 1);
        fgets(lines[i], MAX_LINE_LENGTH, stdin);
        i++;
    }

    sortLines(lines, numLines);

    printf("\nSorted lines:\n");
    for (int j = 0; j < numLines; j++) {
        printf("%s", lines[j]);
    }

    return 0;
}

