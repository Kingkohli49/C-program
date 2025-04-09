#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    int n, i;
    char name[50];
    int marks;

    fp = fopen("student.txt", "w");

    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    printf("Enter number of students: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf("%s", name);
        printf("Enter marks of student %d: ", i + 1);
        scanf("%d", &marks);

        fprintf(fp, "Name: %s Marks: %d\n", name, marks);
    }

    printf("Data stored successfully in student.txt\n");

    fclose(fp);

     return 0;
}


// on termianl

Step	Terminal Command	Description
1	nano student_writer.c	Create and open the C file
2	(Paste your C code inside)	Add your full code
3	Ctrl + O, Enter, Ctrl + X	Save and exit nano
4	gcc student_writer.c -o student_writer	Compile the code using GCC
5	./student_writer	Run the executable
6	(Provide input as asked)	Enter number of students, names, and marks
7	cat student.txt	View the contents of the output file
