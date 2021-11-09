%{
	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>
	void yyerror(const char *str)
{
    fprintf(stderr, "error: %s\n", str);
}
int yywrap()
{
    return 1;
}
main()
{
    yyparse();
}

%}

%token IDENTIFIER DIGIT
%token INTEGER FLOAT CHAR
%token AND OR LESSER_EQUAL GREATER_EQUAL EQUAL ASSIGNMENT
%token IF ELSE WHILE BREAK
%token ADDITION SUBTRACTION MULTIPLICATION DIVISION
%token SEMICOLON COMMA
%token OPEN_PARANTHESIS CLOSE_PARANTHESIS OPEN_BRACES CLOSE_BRACES
%start program

%%
program
        :(declarations function {printf("Input accepted\n");exit(0);}
        ;
declarations
        :type variables SEMICOLON
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
expressions
        :IDENTIFIER ASSIGNMENT expressions
        |IDENTIFIER
        |DIGIT
        ;
