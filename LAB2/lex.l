
%{
int COMMENT=0;
%}
digits [0-9]*
special_symbols ","|";"|"."
identifier [a-zA-Z][a-zA-Z0-9]*

%%
[int|char] {printf("\n\t%s is a keyword", yytext);}
{special_symbols} { printf("\n\t%s is a special symbol", yytext); }
{digits} {printf("\n\t%s is a digit", yytext);}
{identifier} {printf("\n\t%s is an identifier", yytext);}
[+|-] {printf("\n\t%s is an operator", yytext);}
%%


int main(int argc, char **argv)
{
    FILE *file;
    file=fopen("var.c","r");
    if(!file)
    {
        printf("could not open the file");
        exit(0);
    }
    yyin=file;
    yylex();
    printf("\n");
    return(0);
}
int yywrap()
{
    return(1);
}

// Compile By
// lex lex.l
// gcc lex.yy.c
// ./a.out