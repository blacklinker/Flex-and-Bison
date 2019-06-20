%{
#include<stdio.h>
#include<math.h>
%}

ID [_a-zA-Z]+[_a-zA-Z0-9]*
INTEGER [0-9]
FLOATS [0-9]*"."[0-9]+
HexInteger (0[xX][0-9a-fA-F]+)
separators	[ \t\n]+

%%

"if"|"else"|"main"|"void"|"return"|"static"|"private"|"public"|"typedef"|"struct" {
	 printf("A keyword: %s\n", yytext);
	 }
{ID} 	printf( "An identifier: %s\n", yytext );
[1-9]+{INTEGER}* printf("An integer: %s\n", yytext);
{HexInteger} printf("An HexInteger: %s\n", yytext);
0[0-7]+ printf("An Octal number: %s\n", yytext);
0[0-9]*[8-9]+[0-9]* printf("The digits: %s in Octal number is invalid (exceeds 8)\n", yytext);

{FLOATS} printf("A float number: %s\n", yytext);
{FLOATS}[e|E][-]?{INTEGER}+ {
	printf("A floating: %s\n", yytext);
	}
"+"|"-"|"*"|"/"|"<"|">"|"<="|">="|"="|"<"|">"|"<<"|">>" {
	printf("An operator: %s\n", yytext);
	}
"/*".*"*/"|"//".*\n {
	printf("A comment: %s\n", yytext);
	}
[ \t\n]+ {}
	
%%
int main( int argc, char **argv )
{
	++argv, --argc;
	if ( argc > 0 ) // A file on input
		yyin = fopen( argv[0], "r" );
	else // Direct keyboard input
		yyin = stdin;
	yylex();
	return 0;
}


