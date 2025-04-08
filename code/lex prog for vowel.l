%{
#include <stdio.h>
%}

%%
[aeiouAEIOU]    { printf("%s is a Vowel\n", yytext); }
[a-zA-Z]        { printf("%s is a Consonant\n", yytext); }
.               {printf("%s is not a Alphabet\n",yytext);} 
\n              ;
%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter text:\n");
    yylex();
    return 0;
}