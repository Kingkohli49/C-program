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

//on terminal
🔢 Step	📝 Description	💻 Terminal Command
1	Create Lex file	nano count.l
Paste your code into the file, save with Ctrl + O, press Enter, then Ctrl + X	(Your Lex code)
2	Generate C file using Lex	flex count.l
3	Compile the generated C file	gcc lex.yy.c -o count -lfl
4	Run the program (you'll type or paste text directly)	./count
📥 Type a few lines and hit Ctrl+D to end input	*(e.g., type: Hello World\n\tTab test)
5	✅ See the output counts	(It prints line, tab, and space counts)