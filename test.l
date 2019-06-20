%option noyywrap
%{
#include <stdio.h>
#include <stdlib.h>
#include "test.tab.h"
void yyerror(char*);
%}
%%
[0-9]+     {yylval.I=atoi(yytext); return VAL;}
[-+()*/><]           {return yytext[0];}
[ \t\f\v\n]                            {;}
%%