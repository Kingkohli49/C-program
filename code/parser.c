//Recursive decent parser
#include <stdio.h>
#include <stdlib.h>  // Needed for exit
#include <string.h>

const char *input;
int i = 0;

void E();
void E_();
void T();
void T_();
void F();

void error() {
    printf("❌ Invalid Expression\n");
    exit(1);
}

void match(char expected) {
    if (input[i] == expected) {
        i++;
    } else {
        error();
    }
}

void E() {
    T();
    E_();
}

void E_() {
    if (input[i] == '+') {
        i++;
        T();
        E_();
    }
    // else ε
}

void T() {
    F();
    T_();
}

void T_() {
    if (input[i] == '*') {
        i++;
        F();
        T_();
    }
    // else ε
}

void F() {
    if (input[i] == '(') {
        i++;
        E();
        if (input[i] == ')') {
            i++;
        } else {
            error();
        }
    } else if (input[i] == 'i' && input[i+1] == 'd') {
        i += 2;
    } else {
        error();
    }
}

int main() {
    char buffer[100];
    printf("Enter expression (use 'id' for identifiers): ");
    fgets(buffer, sizeof(buffer), stdin);
    
    // Remove newline
    buffer[strcspn(buffer, "\n")] = '\0';

    input = buffer;
    E();

    if (input[i] == '\0') {
        printf("✅ Valid Expression\n");
    } else {
        error();
    }

    return 0;
}

//Shift reducing parser 
#include <stdio.h>
#include <string.h>

char stack[100];
int top = -1;
char input[100];
int i = 0;

void shift() {
    stack[++top] = input[i++];
    stack[top+1] = '\0';
    printf("SHIFT\t\tStack: %s\tInput: %s\n", stack, &input[i]);
}

void reduce() {
    if (top >= 1 && stack[top - 1] == 'a' && stack[top] == 'b') {
        stack[top - 1] = 'S';
        top--;
        stack[top+1] = '\0';
        printf("REDUCE (S → ab)\t\tStack: %s\tInput: %s\n", stack, &input[i]);
    }
}

int main() {
    printf("Enter input string (like ab): ");
    scanf("%s", input);

    printf("\n--- SHIFT REDUCE PARSING ---\n");

    while (input[i] != '\0') {
        shift();
        reduce();
    }

    // Final reduction if possible
    reduce();

    if (strcmp(stack, "S") == 0) {
        printf("\n✅ Input string is successfully parsed.\n");
    } else {
        printf("\n❌ Parsing failed.\n");
    }

    return 0;
}