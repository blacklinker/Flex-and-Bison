%{
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void yyerror(char *msg);
int yylex(void);
%}
%union {
	int I;
}
%token <I> VAL 
%type <I> E T F
%%

S:E	{printf("%d\n",$1);}
;
E:
E'+'T	{$$ = $1+$3;}
|E'-'T	{$$ = $1-$3;}
|T		{$$ = $1;}
;
T:
T'*'F	{$$ = $1*$3;}
|T'/'F	{if ($3 == 0) {yyerror("division by zero!");} $$=$1/$3;}
|T'^'F	{$$=pow($1,$3);}
|T'<'F	{if($1>$3){$$ = $3;} else {$$ = $1;}}
|T'>'F  {if($1>$3){$$ = $1;} else {$$ = $3;}}
|F	    {$$=$1;}
;
F:
'('E')'	{$$ = $2;}
|'-'F	    {$$ = -$2;}
|VAL	    {$$ = $1;}
;

%%
void yyerror(char *msg){
	fprintf(stderr,"%s\n",msg);
	exit(1);
}
int main(void){
    printf("A caluculator\n");
	yyparse();	
	return 0;
}
