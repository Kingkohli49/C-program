#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *source, *evenFile, *oddFile;
    int num;

    source = fopen("input.txt", "r");
    evenFile = fopen("even.txt", "w");
    oddFile = fopen("odd.txt", "w");

    if (source == NULL || evenFile == NULL || oddFile == NULL) {
        printf("Error in opening file.\n");
        exit(1);
    }

    while (fscanf(source, "%d", &num) != EOF) {
        if (num % 2 == 0)
            fprintf(evenFile, "%d\n", num);
        else
            fprintf(oddFile, "%d\n", num);
    }

    printf("Numbers separated successfully into even.txt and odd.txt\n");

    fclose(source);
    fclose(evenFile);
    fclose(oddFile);

      return 0;
}

//input.txt
1 2 3 4 5 6 7 8 9