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