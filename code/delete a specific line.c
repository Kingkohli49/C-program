#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024

int main() {
    FILE *fin, *fout;
    char line[MAX_LINE];
    int del_line, current_line = 1;

    printf("Enter the line number to delete: ");
    scanf("%d", &del_line);

    fin = fopen("input.txt", "r");
    if (fin == NULL) {
        perror("Error opening input.txt");
        return 1;
    }

    fout = fopen("output.txt", "w");
    if (fout == NULL) {
        perror("Error creating output.txt");
        fclose(fin);
        return 1;
    }

    while (fgets(line, sizeof(line), fin)) {
        if (current_line != del_line) {
            fputs(line, fout);
        }
        current_line++;
    }

    fclose(fin);
    fclose(fout);

    printf("Line %d deleted. Updated file saved as output.txt\n", del_line);

    return 0;
}


//input.txt file 
Apple
Banana
Mango
Orange
Grapes
Pineapple
Watermelon
Papaya
Guava
Litchi