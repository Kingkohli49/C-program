%{
#include <stdio.h>
#include <stdlib.h>

int yylex();
void yyerror(const char *s) {
    fprintf(stderr, "Invalid string\n");
}
%}

%token ZERO ONE OTHER
%start S

%%

S: ZERO Rest ZERO   { printf("✅ Valid string: Starts with 0 and ends with 0\n"); }
 | ONE  Rest ONE    { printf("✅ Valid string: Starts with 1 and ends with 1\n"); }
 ;

Rest:
      /* empty */
    | Rest ZERO
    | Rest ONE
    | Rest OTHER
    ;

%%

int yyparse();

int main() {
    printf("Enter a string:\n");
    yyparse();
    return 0;
}


// 2 wala by P.K 
%{
#include <stdio.h>
#include <stdlib.h>
int yylex();
void yyerror(const char *s) {
    fprintf(stderr, "Invalid string");
}
%}

%token ZERO ONE OTHER
%start S

%%
S: ZERO Rest ZERO   { printf("Valid string: Starts with 0 and ends with 0\n"); }
 | ONE Rest ONE     { printf("Valid string: Starts with 1 and ends with 1\n"); }
 ;

Rest: 
    | Rest ZERO
    | Rest ONE
    | Rest OTHER
    ;
%%

int yylex() {
    char c = getchar();
    switch(c) {
        case '0': return ZERO;
        case '1': return ONE;
        case '\n': return 0;  
        default: return OTHER;
    }
}



int main() {
    printf("Enter a string :\n");
    yyparse();
    return 0;

}

//on termianl 


Step	Command	Description
1	nano binary_check.y	 Create and save your Yacc code
2	yacc -d binary_check.y	Generate y.tab.c and y.tab.h
3	gcc y.tab.c -o binary_check	Compile the code into an executable
4	./binary_check	Run the program
5	Input a string	Type string like 0110 or 1001
Let me know if you want:

A version using separate Lex (.l) and Yacc (.y) files,

Or a version that reads from a file instead of stdin.