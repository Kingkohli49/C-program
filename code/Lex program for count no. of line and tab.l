%{
    #include<stdio.h>
    int lc=0,tc=0,sc=0;
%}

%%
[\n] {lc++;}
[ ] {sc++;}
[\t] {tc++;}
%%

int yywrap(){
    return 1;
}
int main(){
    printf("Enter the sentence:\n");
    yylex();
    printf("No. of lines: %d\n",lc);
    printf("No. of tabs: %d\n",tc);
    printf("No. of spaces: %d\n",sc);
}