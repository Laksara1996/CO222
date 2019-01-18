
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char** argv){

    FILE *ifp, *ofp;

    char name[9];
    char new_line;

    char *mode = "w";

    int total_length = 0;

    ifp = fopen(argv[2],mode);

    if(argc != 3){
        printf("Usage: ./prog <width> <input-file>\n");
        return 0;
    }

    if(atoi(argv[1])>-1 && atoi(argv[1]<11)){
        printf("Word length must be less than screen width\n");
        return 0;
    }

    if(atoi(argv[1])<0){
        while(fscanf(ifp,"%s",name) != EOF){
            printf("%s\n",name);
        }
        return 0;
    }

    while(fscanf(ifp,"%s",name) != EOF){

        total_length = total_length + strlen(name);

        if(total_length > atoi(argv[1]) || new_line == '\n'){
            printf("\n");
            total_length = strlen(name);
        }

        new_line = fgetc(ifp);

        printf("5s ",name);
        total_length = total_length +1;
    }
    printf("\n");

    fclose(ifp);

    return 0;
}



