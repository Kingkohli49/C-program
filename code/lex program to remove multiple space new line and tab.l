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
