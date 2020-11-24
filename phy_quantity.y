%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <math.h>
	#include "func.h"
	#include "y.tab.h"

	/* Flex functions */
	extern int yylex(void);
	extern void yyterminate();
	void yyerror(const char *s);
%}

/* Bison declarations */

%union {
	double num;
	struct Vektor v;
}

/* Bison Token */
%token<num> NUMBER
%token<v> PG
%token<num> DIV MUL
%token<num> POW POW2 SQRT 
%token<num> END
%type<v> expr

/* Set operator precedence */
%left MUL 
%left DIV 
%right POW POW2 SQRT 

%start Input

%%

/* Bison Grammar rules */

Input:
		| Input Line
;
	
Line: 
		END			{ printf("Please enter a calculation:\n"); }
		| expr END		{ printf("Result: %s\n",eqlVektor($1)); }
;
				
expr:
		PG			{ $$ = $1; }	
		| expr DIV expr		{ $$ = v_div($1,$3); }
		| expr MUL expr		{ $$ = v_mul($1,$3); }
		| expr POW NUMBER	{ $$ = v_pow($1, $3); }
		| expr POW2		{ $$ = v_pow($1, 2); }
		| SQRT expr      	{ $$ = v_sqrt($2); }
;

%%

/* Entry point */
int main(int argc, char **argv)
{
	yyparse();
	return 0;
}

/* Display error messages */
void yyerror(const char *s)
{
	printf("ERROR: %s\n", s);
}