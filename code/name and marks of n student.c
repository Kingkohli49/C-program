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