#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD 100

int main() {

    FILE *source, *deleteFile, *output;
    char word[MAX_WORD], temp[MAX_WORD];
    char deleteWords[100][MAX_WORD];
    int count[100] = {0};
    int n = 0, i, found;

    source = fopen("source.txt", "r");
    deleteFile = fopen("delete.txt", "r");
    output = fopen("output.txt", "w");

    if (source == NULL || deleteFile == NULL || output == NULL) {
        printf("Error in opening file!\n");
        exit(1);
    }

    // Reading words to be deleted
    while (fscanf(deleteFile, "%s", deleteWords[n]) != EOF) {
        n++;
    }

    // Processing source file
    while (fscanf(source, "%s", word) != EOF) {
        found = 0;
        for (i = 0; i < n; i++) {
            if (strcmp(word, deleteWords[i]) == 0) {
                count[i]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            fprintf(output, "%s ", word);
        }
    }

    fclose(source);
    fclose(deleteFile);
    fclose(output);

    printf("Words deleted and stored in output.txt\n");
    printf("Word wise match count:\n");

    for (i = 0; i < n; i++) {
        printf("%s -> %d\n", deleteWords[i], count[i]);
    }

    return 0;
}

//source.txt

This is a sample file which contains some words that need to be deleted from the file.

//delete.txt

is
file
some
deleted

