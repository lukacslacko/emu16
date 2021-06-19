/* A Bison parser, made by GNU Bison 3.7.5.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    NUM = 258,                     /* NUM  */
    HEXNUM = 259,                  /* HEXNUM  */
    BINNUM = 260,                  /* BINNUM  */
    ID = 261,                      /* ID  */
    BOOL = 262,                    /* BOOL  */
    TRUE = 263,                    /* TRUE  */
    FALSE = 264,                   /* FALSE  */
    BYTE = 265,                    /* BYTE  */
    WORD = 266,                    /* WORD  */
    VOID = 267,                    /* VOID  */
    PASS = 268,                    /* PASS  */
    IF = 269,                      /* IF  */
    ELSE = 270,                    /* ELSE  */
    FOR = 271,                     /* FOR  */
    WHILE = 272,                   /* WHILE  */
    RETURN = 273,                  /* RETURN  */
    EQ = 274,                      /* EQ  */
    NE = 275,                      /* NE  */
    GE = 276,                      /* GE  */
    GT = 277,                      /* GT  */
    LE = 278,                      /* LE  */
    LT = 279                       /* LT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define NUM 258
#define HEXNUM 259
#define BINNUM 260
#define ID 261
#define BOOL 262
#define TRUE 263
#define FALSE 264
#define BYTE 265
#define WORD 266
#define VOID 267
#define PASS 268
#define IF 269
#define ELSE 270
#define FOR 271
#define WHILE 272
#define RETURN 273
#define EQ 274
#define NE 275
#define GE 276
#define GT 277
#define LE 278
#define LT 279

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 22 "comp.y"
 std::string* str; int num; Node* node; 

#line 118 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
