%{
    #include<stdio.h>
%}

%%
[ \t]+          { fputc(' ', yyout); }     
\n+             { fputc(' ', yyout); }     
.               { fputc(yytext[0], yyout); } 
%%

int yywrap(){
    return 1;
}
int main(){
    extern FILE *yyout, *yyin;
    yyin=fopen("input.txt","r");
    yyout=fopen("output.txt","w");
    yylex();
    fclose(yyin);
    fclose(yyout);
    return 0;
}


on terminal

🔢 Step	📝 Description	💻 Terminal Command
1	Create Lex file	nano clean.l
Paste your Lex code, then save (Ctrl + O, Enter, Ctrl + X)	(Your code here)
2	Generate C file from Lex file	flex clean.l
3	Compile the generated C file	gcc lex.yy.c -o clean -lfl
4	Create input file (optional)	nano input.txt
Write some messy text with extra spaces, tabs, newlines, etc., and save	*(Example: Hello World\n\tThis is\ttext)
5	Run the program	./clean
6	See the cleaned output	cat output.txt