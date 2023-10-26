#include <stdio.h>
#include "store.h"

int main(int argc, char* argv[])
{

struct store rec;
FILE *fp;
if (argc != 2) {
fprintf(stderr, "How to use: %s Filename\n", argv[0]);
exit(1);
}
fp = fopen(argv[1],"wb");
printf("--- Goods qurey ---\n");
printf("%-2s %-9s %-6s %3s %2s\n", "Id", "Name","Category","extired date","stock");
while (scanf("%d %s %s %f %d", &rec.id, &rec.name,&rec.cate,&rec.date,&rec.stock) == 5) 
    fwrite(&rec,sizeof(rec),1,fp);

fclose(fp);
exit(0);
}
