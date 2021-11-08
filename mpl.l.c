%{
    #include<stdio.h>
    #include "y.tab.h"
    #include<stdlib.h>
    #include "mytable.h"
%}
letter [a-zA-Z]
digit [0-9]
%%
"+"              return ADDITION;
"-"              return SUBTRACTION;
"*"              return MULTIPLICATION;
"/"              return DIVISION;
"and"            return AND;
"or"             return OR;
"<="             return LESSER_EQUAL;
">="             return GREATER_EQUAL;
"=="             return EQUAL;
"if"             return IF;
"else"           return ELSE;
"while"          return WHILE;
"break"          return BREAK;
"int"            return INTEGER;
"float"          return FLOAT;
"char"           return CHAR;
{letter}({letter}|{digit})* return IDENTIFIER;
{digit}+ return NUM;
";" return SEMICOLON;
"," return COMMA;
"(" return OPEN_PARANTHESIS;
")" return CLOSE_PARANTHESIS;
"{" return OPEN_BRACES;
"}" return CLOSE_BRACES;
.;
[ \n] ;
%%
