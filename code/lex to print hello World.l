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

// on terminal
Step	Command	Purpose
1	nano hello_world.l	Create and open the file
2	(Paste your Lex code into this file)	This includes %{...%}, %%, and main()
3	Ctrl + O, Enter, Ctrl + X	Save and exit nano
4	flex hello_world.l	Generate lex.yy.c using Flex
5	gcc lex.yy.c -o hello	Compile the generated C file
6	./hello	Run the program
7	(Type any character and press Enter)	Triggers the rule and prints Hello World


// extar code if upper wala na ho to 
%{
#include <stdio.h>
#include <stdlib.h>
%}

%%

.   { printf("Hello World\n"); exit(0); }

%%

int main() {
    yylex();
    return 0;
}
