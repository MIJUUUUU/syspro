
#include <stdio.h>
#include "copy.h"
#include <string.h>
char line[MAXLINE];
char string[5][100]
char temp  [100]

int main() {
    int len;
    int max;
    char longest = sort()
    max = 0;

for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (strlen(strings[i]) < strlen(strings[j])) {
				strcpy(temp, strings[i]);
                strcpy(strings[i], strings[j]);
                strcpy(strings[j], temp);
            }
        }
    }

    while(fgets(line,MAXLINE,stdin) != NULL) {
        len = strlen(line);

        if(len > max) {
            max = len ;
            copy(line, i);
        }
    }
 
    if(max > 0)
        printf("%s \n", i);
    return 0;
}
