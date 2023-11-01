#include <stdio.h>
#include <stdlib.h>

int main() {
    char file_name[] = "test.txt"; 
    FILE *file = fopen(file_name, "r");

    if (file == NULL) {
        printf("%s\n", file_name);
        return 1;
    }

    char line[256];

    while (1) {
        printf("File read success\n");
		printf("Total Line : 4\n");
        printf("You can choose 1 ~ 4 Line\n");
        printf("Pls 'Enter' the line to select : ");
        char user_input[256];
        fgets(user_input, sizeof(user_input), stdin);
        
        if (user_input[0] == '*'){
            int i = 1;

            while (fgets(line, sizeof(line), file) != NULL) {
                printf("%s", line);
				
                i++;
            }
			break;
       }else if (strchr(user_input, ',') != NULL) {
		   int fst,sec;
             if(sscanf(user_input, "%d,%d",&fst,&sec)){
					 if(fst >=1 && sec >=1){
					 fseek(file, 0, SEEK_SET);
                    int i = 1;
                    while (fgets(line, sizeof(line), file) != NULL) {
                        if (i == fst || i==sec) {
                            printf("%s", line);
                         
                        }
                        i++;
                    }
				
					}
            
			 }
			 break;
        } else if (strchr(user_input, '-') != NULL) {
            int start, end;
            if (sscanf(user_input, "%d-%d", &start, &end) == 2) {
                if (start >= 1 && end >= 1) {
                    fseek(file, 0, SEEK_SET);
                    int i = 1;
                    while (fgets(line, sizeof(line), file) != NULL) {
                        if (i >= start && i <= end) {
                            printf(" %s", line);
							
                        }
                        i++;
                    }
                }
			
            } 
			break;
        } else {
            int num = atoi(user_input);
            if (num >= 1) {
                fseek(file, 0, SEEK_SET); 
               int i=1; 
                while (fgets(line, sizeof(line), file) != NULL) {
                     if (i==num) {   
                        printf("%s", line);
                        
                    }
                    i++;
                }
				break;
			
            }
			
        }
		
		}
	

	
    fclose(file);
    return 0;
}

