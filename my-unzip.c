#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    // not enough parameters
    if(argc == 1){
        printf("my-unzip: file1 [file2 ...]\n");
        exit(1);
    }
    FILE *pfile;
    int amount;
    char character;

    // loop through files
    for(int i=1; i < argc; i++){
        if((pfile = fopen(argv[i], "rb")) == NULL){
            printf("my-unzip: cannot open file\n");
            exit(1);
        }
        // read number of characters
        while((fread(&amount, sizeof(int), 1, pfile)) == 1){
            // read character
            fread(&character, sizeof(char), 1, pfile);
            // print "amount" characters
            for(int j = 0; j < amount; j++){
                printf("%c", character);
            }
        }
        fclose(pfile);
    }
    return 0;
}