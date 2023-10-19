#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]) {
    int line_number = 0;
    FILE *fp;
    int c;

    if (argc < 2) {
        printf(": %s\n", argv[0]);
        return 1;
    }

    int arg_index = 1;
    int print_line_numbers = 0;

    if (strcmp(argv[1], "-n") == 0) {
        print_line_numbers = 1;
        arg_index = 2;
    }

  
    for (; arg_index < argc; arg_index++) {
        fp = fopen(argv[arg_index], "r");
        if (fp == NULL) {
            fprintf(stderr, ": %s\n", argv[arg_index]);
            continue;
        }

        

        c = getc(fp);
        while (c != EOF) {
            if (print_line_numbers) {
                printf("%d: ", ++line_number);
            }
            putc(c, stdout);
            if (c == '\n') {
                line_number++;
            }
            c = getc(fp);
        }

        fclose(fp);
    }

    return 0;
}

