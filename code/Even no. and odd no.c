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


 //on terminal 
 Step	Command	Explanation
1️⃣	nano even_odd.c	Create and open the file in nano text editor
✍️	(Paste your C program)	Paste the code from your message
💾	Ctrl + O → Enter → Ctrl + X	Save and exit nano
2️⃣	nano input.txt	Create the input file
✍️	(Paste this)
1 2 3 4 5 6 7 8 9	Your input numbers
💾	Ctrl + O → Enter → Ctrl + X	Save and exit
3️⃣	gcc even_odd.c -o even_odd	Compile the program
4️⃣	./even_odd	Run the program
5️⃣	cat even.txt	View the even numbers output file
6️⃣	cat odd.txt	View the odd numbers output file
