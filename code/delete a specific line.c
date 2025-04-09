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

//on terminal
Step	Command	Explanation
1️⃣	nano delete_line.c	Open nano editor to write your C code
✍️	(Paste your C code)	Paste your code inside nano
💾	Ctrl + O → Enter → Ctrl + X	Save the file and exit nano
2️⃣	nano input.txt	Create the input file to test your code
✍️	(Type some lines like: Hello, World, Line 3, Line 4)	Provide sample content
💾	Ctrl + O → Enter → Ctrl + X	Save the input.txt file
3️⃣	gcc delete_line.c -o delete_line	Compile your C code into an executable
4️⃣	./delete_line	Run the program
🧾	(Enter line number when prompted)	Example: 2 to delete second line
5️⃣	cat output.txt	View the content of the updated file