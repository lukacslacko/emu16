%option noyywrap
%{
#include "ir.h"
#include <cstdlib>
#include <string>
#include "y.tab.h"
#include <stdio.h>
%}
%%
[[:digit:]]+      yylval.str=new std::string(yytext); return NUM;
0x[0-9a-fA-F]+  yylval.str=new std::string(yytext); return HEXNUM;
0b[01]+	yylval.str=new std::string(yytext); return BINNUM;
==	return EQ;
!=	return NE;
>=	return GE;
\<=	return LE;
>	return GT;
\<	return LT;
[(){}+*/&|~=^;,-]     return *yytext;
byte	return BYTE;
word	return WORD;
void    return VOID;
bool	return BOOL;
true	return TRUE;
false	return FALSE;
if	return IF;
else	return ELSE;
for	return FOR;
while	return WHILE;
return	return RETURN;
pass	return PASS;
\/\/[^\n]*\n ;
[_[:alpha:]][_[:alnum:]]* yylval.node=new Node("id", {new Node(yytext)}); return ID;
[ ]|\n   ;
.  printf("Ignored: '%s'", yytext);                     ; /* ignore all the rest */
%%
