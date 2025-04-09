%{
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int yylex();
void yyerror(const char *s);
%}

%token NUMBER
%left '+' '-'
%left '*' '/'
%right UMINUS

%%
statement: exp                     { printf("Result: %d\n", $1); }
         ;

exp: exp '+' exp     { $$ = $1 + $3; }
          | exp '-' exp     { $$ = $1 - $3; }
          | exp '*' exp     { $$ = $1 * $3; }
          | exp '/' exp     { 
                if ($3 == 0) {
                    yyerror("Division by zero");
                    YYABORT;
                }
                $$ = $1 / $3; 
            }
          | '(' exp ')'            { $$ = $2; }
          | '-' exp                 {$$=-$2;}
          | NUMBER                        { $$ = $1; }
          ;
%%

int yylex() {
    int c;
    while ((c = getchar()) == ' ' || c == '\t');
    
    if (isdigit(c)) {
        ungetc(c, stdin);
        scanf("%d", &yylval);
        return NUMBER;
    }
    
    if (c == '\n')
        return 0;
        
    return c;
}

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main() {
    printf("Enter an arithmetic exp:\n");
    yyparse();
    return 0;
}



//on terminal
Step	Command	Explanation
1	nano calc.y	Create and save your code in a file
2	yacc -d calc.y	Convert Yacc file to C (y.tab.c, y.tab.h)
3	gcc y.tab.c -o calc	Compile to executable named calc
4	./calc	Run the compiled calculator
5	Type expressions	Evaluate arithmetic inputs like 3 + 5 * 2

