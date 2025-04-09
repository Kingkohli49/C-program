%{
    #include<stdio.h>
    #include<string.h>
%}

%%
[A-Z] {printf("%s is a capital letter\n",yytext);}
.  {printf("%s is not capital letter\n",yytext);}
\n  ;
%%

int yywrap(){
    return 1;
}
int main(){
    printf("Enter the text:");
    yylex();
    return 0;
}

Step	Command	Purpose
1	nano capital_checker.l	Create and open the Lex file
2	(Paste your Lex code)	Paste your capital letter checking code
3	Ctrl + O, Enter, Ctrl + X	Save and exit nano editor
4	lex capital_checker.l	Generate lex.yy.c from your Lex file
5	gcc lex.yy.c -o capital_checker -ll	Compile with Lex library and create executable
6	./capital_checker	Run your compiled Lex program
7	(Type input characters)	Enter letters or any character to test
8	Ctrl + D	Send EOF to stop input and finish program