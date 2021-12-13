#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1000

int countOccurrences(FILE *fptr, char *word, int reg);

int main() {
    FILE *fptr;
    const char *path = "test.txt";
    char *word_up = "PbS";
    int wCount;
    fptr = fopen(path, "r");
    if (fptr == NULL) {
        printf("Unable to open file.\n");
        printf("Please check you have read/write previleges.\n");

        exit(EXIT_FAILURE);
    }
    wCount = countOccurrences(fptr, word_up, 0);
    printf("'%s' is found %d times in file.", word_up, wCount);

    fclose(fptr);
    return 0;
}

int countOccurrences(FILE *fptr, char *word, int reg) {
    char str[BUFFER_SIZE];
    char *pos;
    int index, count;
    count = 0;
    while ((fgets(str, BUFFER_SIZE, fptr)) != NULL)
    {
        index = 0;
        while ((pos = strstr(str + index, word)) != NULL)
        {
            index = (pos - str) + 1;
            count++;
        }
    }
    return count;
}
