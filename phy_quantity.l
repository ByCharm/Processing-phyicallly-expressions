%option noyywrap
%{
	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
	#include<math.h>
	#include "func.h"
	#include "y.tab.h"
%}

space		[ \t]+
digit		[0-9]
integer		{digit}+
int_neg		[+-]?{integer}	
op_pow		(zum|Zum){space}(Quadrat)
op_sqrt		(Wurzel){space}(aus|Aus)
op		(mal|Mal|durch|Durch|{op_pow}|{op_sqrt}|hoch|Hoch)
pg		(Laenge|Masse|Zeit|Strom|Eins|Flaeche|Volumen|Druck|Geschwindigkeit|Beschleunigung|Kraft|Energie|Leistung|Spannung|Widerstand|Leitwert|Ladung|Elektrische"-"Feldstaerke|Stromdichte|Magnetische"-"Flussdichte|Magnetische"-"Feldstaerke|Leistungsdichte)

%%

[ \t]
"mal"		{ return MUL; }
"durch"         { return DIV; }
"hoch"		{ return POW; }
{op_pow}        { return POW2; }
{op_sqrt}	{ return SQRT; }
{pg}		{ yylval.v=eqlString(yytext); return PG; }
{int_neg}	{ yylval.num=atof(yytext); return NUMBER; }
[\n]            { return END; }
. 		{ yyerror("Undefined symbol"); exit(1); } 

%%