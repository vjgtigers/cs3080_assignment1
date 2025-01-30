// Author: Vaughn Gugger
// Date: Jan 30, 2025
// Class: CS3080_s25
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    printf("Hello, World!\n");
    if (argc < 5) {
        printf("Missing arguments\n");
    }

    char *fileName = argv[1];
    int itemNum = atoi(argv[2]);
    int range = atoi(argv[3]);
    int seed = atoi(argv[4]);
    printf("test %s\n", fileName);

    FILE *dataFile = fopen(fileName, "w");

    if (dataFile == NULL) {
        printf("file open failure\n");
        return 0;
    }

    srand(seed);
    int num = 0;
    for (int i = 0; i < itemNum; ++i) {
        num = rand() % range;
        fprintf(dataFile, "%d\n", num);
    }
    fclose(dataFile);
    dataFile = NULL;
    dataFile = fopen(fileName, "r");
    if (dataFile == NULL) {
        printf("file open failure\n");
        return 0;
    }
    char number[100];
    int rowAmmount = 1;
    while(fgets(number, 100, dataFile)) {

        //to remove \n when reading from the file
        int newLine = strcspn(number, "\n");
        number[newLine] = '\0';

        printf("%s \t", number);
        if(rowAmmount == 5) {
            printf("\n");
            rowAmmount = 1;
        }
        else {
            rowAmmount += 1;
        }
    }
    fclose(dataFile);
    return 0;
}
