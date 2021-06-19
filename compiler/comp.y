%{
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stdio.h>
#include "ir.h"
#include "compiler.h"
#include "emu16.h"

using namespace std;

inline void yyerror(const char *s) { std::cout << s << std::endl; }
int yylex();
using namespace std;

string* s(string ss) { return new string(ss); }
Node* n(string kind) { return new Node(kind); }
Node* n(string kind, vector<Node*> args) { return new Node(kind, args); }
%}

%union { std::string* str; int num; Node* node; }

%token<str> NUM
%token<str> HEXNUM
%token<str> BINNUM
%token<node> ID
%token BOOL
%token TRUE
%token FALSE
%token BYTE
%token WORD
%token VOID
%token PASS
%token IF
%token ELSE
%token FOR
%token WHILE
%token RETURN
%token EQ
%token NE
%token GE
%token GT
%token LE
%token LT

%type<node> type program all_program unit fundecl fundef funname arglist arg argname varname vardecl body statements statement statement_semicolon expr
%type<node> functionname functioncall params param curly_statement

%type<num> number

%right '='
%left '|' '&' '^'
%left GT LT GE LE EQ NE
%left '+' '-'
%left '*' '/' '%'
%right '~'

%%

all_program: program { 
  cout << $1->debug() << endl; 
  EMU16 emu16;
  Compiler comp($1, nullptr, &emu16); 
  if (comp.compile()) cerr << "Ready." << endl; 
  else cerr << "There were errors." << endl;
  for (string line : emu16.code()) {
    cout << line << endl;
  } 
} ;

program: unit { $$ = n("program", {$1}); } | program unit { $$ = n("program", catnode($1->args, $2)); } ;

unit: fundef { $$ = n("unit", {$1}); } | fundecl { $$ = n("unit", {$1}); };

type: BYTE { $$ = n("type", {n("byte")}); } 
    | WORD { $$ = n("type", {n("word")}); }
    | VOID { $$ = n("type", {n("void")}); }
    | type '*' { $$ = n("ptr", {$1}); }
    ;
    
varname: ID { $$ = $1; } | '*' varname { $$ = n("deref", {$2}); };

vardecl: 
    type ID { $$ = n("vardecl", {$1, $2}); }
    | type ID '=' expr { $$ = n("vardecl_init", {n("vardecl", {$1, $2}), n("varset", {$2, $4})}); }
    ;

fundecl: type funname '(' arglist ')' ';' { $$ = n("fundecl", {$1, $2, $4}); };

fundef: type funname '(' arglist ')' body { $$ = n("fundef", {$1, $2, $4, $6}); };
arglist:
    { $$ = n("arglist", {}); }
    | arg { $$ = n("arglist", {$1}); }
    | arglist ',' arg { $$ = n("arglist", catnode($1->args, $3)); }
    ;
    
arg: type argname { $$ = n("arg", {$1, $2}); };
argname: ID { $$ = $1; };
funname: ID { $$ = $1; };

body: '{' statements '}' { $$ = $2; } | '{' '}' { $$ = n("statements");};

statements:
    statement_semicolon { $$ = n("statements", {$1}); }
    | statements statement_semicolon { $$ = n("statements", catnode($1->args, $2)); }
    ;
    
statement_semicolon: 
    statement ';' { $$ = $1; }
    | curly_statement { $$ = $1; }
    ;

curly_statement:
    IF '(' expr ')' body { $$ = n("if", {$3, $5}); }
    | IF '(' expr ')' body ELSE body { $$ = n("ifelse", {$3, $5, $7}); }
    | FOR '(' expr ';' expr ';' expr ')' body { $$ = n("for", {$3, $5, $7, $9}); }
    | WHILE '(' expr ')' body { $$ = n("while", {$3, $5}); }

statement: vardecl { $$ = $1; }
    | expr { $$ = $1; }
    | RETURN expr { $$ = n("return", {$2}); }
    ;
    
functioncall: functionname '(' params ')' { $$ = n("funcall", {$1, $3}); } ;

functionname: ID { $$ = $1; };

params:
    { $$ = n("params"); }
    | param { $$ = n("params", {$1}); }
    | params ',' param { $$ = n("params", catnode($1->args, $3)); }
    ;
    
param: expr { $$ = $1; };

number: NUM { $$=atoi($1->c_str()); } 
    | HEXNUM { $$=strtol($1->c_str(), NULL, 16); } 
    | BINNUM { $$=strtol($1->c_str()+2, NULL, 2); } 
    ;

expr: varname { $$ = n("varref", {$1}); }
    | functioncall { $$ = $1; }
    | number { $$ = n("number", {n(to_string($1))}); }
    | varname '=' expr { $$ = n("varset", {$1, $3}); }
    | expr '+' expr { $$ = n("+", {$1, $3}); }
    | expr '-' expr { $$ = n("-", {$1, $3}); }
    | expr '*' expr { $$ = n("*", {$1, $3}); }
    | expr '/' expr { $$ = n("/", {$1, $3}); }
    | expr '&' expr { $$ = n("&", {$1, $3}); } 
    | expr '|' expr { $$ = n("|", {$1, $3}); } 
    | expr '^' expr { $$ = n("^", {$1, $3}); } 
    | '~' expr { $$ = n("neg", {$2}); }
    | '-' expr %prec '~' { $$ = n("minus", {$2}); }
    | '(' expr ')' { $$ = $2; }
    | '&' ID { $$ = n("addr", {$2}); }
    | expr EQ expr { $$ = n("==", {$1, $3}); } 
    | expr NE expr { $$ = n("!=", {$1, $3}); } 
    | expr GE expr { $$ = n(">=", {$1, $3}); }
    | expr LE expr { $$ = n("<=", {$1, $3}); }
    | expr GT expr { $$ = n(">", {$1, $3}); }
    | expr LT expr { $$ = n("<", {$1, $3}); }
    ;

%%
extern int yylex();
extern int yyparse();
int main() { yyparse(); }
