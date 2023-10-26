#include <stdio.h> 
#include "store.h"

int main(int argc, char* argv[]) 
{ 
struct store rec;
FILE *fp;
if (argc != 2) { 
fprintf(stderr, "How to use: %s FileName\n", argv[0]);
return 1; 
}
if ((fp = fopen(argv[1], "rb")) == NULL ) {
fprintf(stderr, "Error Open File\n");
return 2;
}

printf("%2s %9s  %6s %3s %2s\n", "Id", "Name", "Category","expired date", "stock");
while (fread(&rec, sizeof(rec), 1, fp) > 0) 
if (rec.id != 0)
printf("%2d %9s %6s %3f %2d\n", rec.id, rec.name, rec.cate,rec.date,rec.stock);

fclose(fp);
return 0;
} 
