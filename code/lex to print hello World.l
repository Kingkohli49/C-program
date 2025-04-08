%{
#include <stdio.h>
%}

%%
.   { printf("Hello World\n"); exit(0); }
%%

int main() {
    yylex();
    return 0;
}