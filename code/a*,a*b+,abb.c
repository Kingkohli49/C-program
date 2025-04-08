/*#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to check if the string matches a*
bool is_a_star(const char *str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] != 'a') {
            return false;
        }
    }
    return true; // Can be empty or all 'a's
}

// Function to check if the string matches a*b+
bool is_a_star_b_plus(const char *str) {
    int i = 0;
    
    // Count all 'a's (zero or more)
    while (str[i] == 'a') {
        i++;
    }

    // There should be at least one 'b'
    int bCount = 0;
    while (str[i] == 'b') {
        i++;
        bCount++;
    }

    // Return true if there are only 'a's followed by one or more 'b's and nothing else
    return (str[i] == '\0' && bCount > 0);
}

// Function to check if the string is exactly "abb"
bool is_exact_abb(const char *str) {
    return strcmp(str, "abb") == 0;
}

int main() {
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    if (is_a_star(str)) {
        printf("The string is accepted by the pattern a*\n");
    } else if (is_a_star_b_plus(str)) {
        printf("The string is accepted by the pattern a*b+\n");
    } else if (is_exact_abb(str)) {
        printf("The string is accepted by the pattern abb\n");
    } else {
        printf("The string does not match any of the given patterns.\n");
    }

    return 0;
}*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

bool astar(const char *str){
    for(int i=0;str[i]!='\0';i++){
        if(str[i]!='a'){
            return false;
        }
    }
    return true;
}
bool astarbplus(const char *str){
    int i=0;
    while(str[i]=='a') i++;
    if(str[i]!='b'){
        return false;
    }
    while(str[i]=='b') i++;
    if(str[i]=='\0') return true;
    return false;
}
bool abb(const char *str){
    return (strcmp(str,"abb")==0)&&astarbplus(str);
}

int main(){
    char str[100];
    printf("Enter a string: ");
    scanf("%s",&str);

    if(abb(str)){
        printf("String accepted under rule: exact match 'abb' also a*b+");
    }
    else if(astar(str)){
        printf("String accepted under rule: a*");
    }
    else if(astarbplus(str)){
        printf("String accepted under rule: a*b+");
    }
    else{
        printf("String not recognized");
    }
}