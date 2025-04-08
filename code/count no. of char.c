#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    FILE *fin;
    char line[1000];
    int cno = 0, lno = 0, words = 0;

    fin = fopen("s1.txt", "r");
    if (fin == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), fin) != NULL) {
        int len = strlen(line);

        lno++;  // Count every line including blank ones

        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
            len--;
        }

        cno += len;

        int inWord = 0;
        for (int i = 0; i < len; i++) {
            if (isspace(line[i])) {
                if (inWord) {
                    words++;
                    inWord = 0;
                }
            } else {
                inWord = 1;
            }
        }
        if (inWord) {
            words++;
        }
    }

    fclose(fin);

    printf("Number of Characters: %d\n", cno);
    printf("Number of Words:      %d\n", words);
    printf("Number of Lines:      %d\n", lno);

    return 0;
}


for s.txt 
This is a sample file.
It contains multiple lines.

Each line has some words.
Count them properly.