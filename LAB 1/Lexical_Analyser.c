
#include<ctype.h>
#include<string.h>
#include<stdio.h>

const char* keyword []= {
    "auto", "break", "case", "char", "const", "continue", "default", "do", 
    "double", "else", "enum", "extern", "float", "for", "goto", "if", 
    "int", "long", "register", "return", "short", "signed", "sizeof", 
    "static", "struct", "switch", "typedef", "union", "unsigned", 
    "void", "volatile", "while"
};

const char* operators []= {
    "+", "-" , "/", "*", "^"
};

const char* symbols [] = {

    "(", ")", "[", "]", "{","}", ";"

};


int is_identifier(const char* str) {
    if (isalpha(str[0]) || str[0] == '_') {
        for (int i = 1; str[i] != '\0'; i++) {
            if (!isalnum(str[i]) && str[i] != '_') {
                return 0;
            }
        }
        return 1;  
    }
    return 0;  // Not an identifier
}
int main()
{
    int i;
    int is_keyword, is_operator, is_symbol;
    FILE *f;
    f = fopen("text.txt", "r");
    char x[1024];

    while (fscanf(f, " %1023s", x)==1)
    {
        printf("Token %s \n", x);
        is_symbol = 0; 
        is_operator = 0;
        is_keyword = 0;

        int num_keywords = sizeof(keyword) / sizeof(keyword[0]);
        for (i=0;i<num_keywords;i++)
        {
            if (strcmp(x,keyword[i]) == 0)
            {
                printf(" %s is keyword \n" , x);
                is_keyword = 1;
            }
            
        }

        if (!is_keyword)
        {
            int num_operators = sizeof(operators) / sizeof(operators[0]);
            for (i=0;i<num_operators;i++)
            {
                if (strcmp(x,operators[i]) == 0)
                {
                    printf(" %s is operator \n" , x);
                    is_operator =  1;
                }
            
            }
        }

        if (!is_keyword && !is_operator)
        {
            int num_symbols = sizeof(symbols) / sizeof(symbols[0]);
            for (i = 0; i < num_symbols; i++) {
                if (strcmp(x, symbols[i]) == 0) {
                    printf("  %s is a symbol\n", x);
                    is_symbol = 1;
                    break;
                }
            }
        }

        if (!is_keyword && !is_operator && !is_symbol)
        {
            if (is_identifier(x) ==  1)
            {
                printf("  %s is an Identifier \n", x);
            }
        }
    }
    
}

