%{
	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>
%}

%token IDENTIFIER NUM
%token INTEGER FLOAT CHAR
%token AND OR LESSER_EQUAL GREATER_EQUAL EQUAL
%token IF ELSE WHILE BREAK
%token ADDITION SUBTRACTION MULTIPLICATION DIVISION
%token SEMICOLON COMMA
%token OPEN_PARANTHESIS CLOSE_PARANTHESIS OPEN_BRACES CLOSE_BRACES

%start program

%%
program
        :declarations function {printf("Input accepted\n");exit(0);}
        ;
declarations
        :trype variables SEMICOLON
        |
        ;
type
        :INTEGER
        |FLOAT
        |CHAR
        ;
variables
        :IDENTIFIER
        |IDENTIFIER COMMA variables
function
        :type IDENTIFIER OPEN_PARANTHESIS arguementlist CLOSE_PARANTHESIS OPEN_BRACES statements CLOSE_BRACES
        ;
argumentlist
        :variables
        ;
statements
        :expressions SEMICOLON
        ;
Expressions
        :IDENTIFIER ASSIGN expressions
        |IDENTIFIER
        |NUM
        ;
%%
#lnclude "lex.yy.c"
int main()
{
    yyin=fopen("input.c","r);
    yyparse();
    return 0;
}

