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

///on terminal
Step	Command	Purpose
1	nano vowel_checker.l	Create and open the Lex file
2	(Paste your Lex code)	Paste your code into the file
3	Ctrl + O, Enter, Ctrl + X	Save and exit nano
4	lex vowel_checker.l	Generate C code (lex.yy.c) from the Lex file
5	gcc lex.yy.c -o vowel_checker -ll	Compile the generated C code with Lex library
6	./vowel_checker	Run the final compiled program
7	(Type your input)	Provide input to check vowels/consonants
8	Ctrl + D	End input (sends EOF) and see result