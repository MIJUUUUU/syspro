#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[32] = "Do you like Linux?";
    char *ptr, *p;
    ptr = (char *)malloc(32);

    if (ptr == NULL) {
        perror("malloc");
        exit(1);
    }

    memcpy(ptr, str, strlen(str) + 1); // 문자열 끝에 NULL 문자까지 복사
    printf("%s\n", ptr);

    memset(ptr + 12, 'l', 1);
    printf("%s\n", ptr);

    p = (char *)memchr(ptr, 'l', 18);
    
    if (p != NULL) {
        printf("%s\n", p);
    } else {
        printf("Character 'l' not found in the first 18 characters.\n");
    }

    // memmove를 사용하면 기존의 str 배열에 새로운 문자열이 복사되므로,
    // ptr에 할당된 동적 메모리는 더 이상 필요하지 않습니다.
    free(ptr);

    memmove(str + 12, str + 7, 10);
    printf("%s\n", str);

    return 0;
}

