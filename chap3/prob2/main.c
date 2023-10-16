#include <stdio.h>
#include <string.h>

#define MAXLINE 100

void copy(char from[], char to[]) {
    int i = 0;
    while ((to[i] = from[i]) != '\0') {
        i++;
    }
}

int main() {
    char lines[5][MAXLINE];
    int lengths[5]; 
    int i, j;

 
    for (i = 0; i < 5; i++) {
        gets(lines[i]);
        lengths[i] = strlen(lines[i]);
    }

  
    for (i = 0; i < 5; i++) {
        for (j = i + 1; j < 5; j++) {
            if (lengths[i] < lengths[j]) {
              
                int tempLength = lengths[i];
                lengths[i] = lengths[j];
                lengths[j] = tempLength;

                char tempLine[MAXLINE];
                copy(lines[i], tempLine);
                copy(lines[j], lines[i]);
                copy(tempLine, lines[j]);
            }
        }
    }

    for (i = 0; i < 5; i++) {
        printf("%s\n", lines[i]);
    }

    return 0;
}

