/* A Bison parser, made by GNU Bison 3.7.5.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30705

/* Bison version string.  */
#define YYBISON_VERSION "3.7.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "comp.y"

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

#line 92 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 196 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUM = 3,                        /* NUM  */
  YYSYMBOL_HEXNUM = 4,                     /* HEXNUM  */
  YYSYMBOL_BINNUM = 5,                     /* BINNUM  */
  YYSYMBOL_ID = 6,                         /* ID  */
  YYSYMBOL_BOOL = 7,                       /* BOOL  */
  YYSYMBOL_TRUE = 8,                       /* TRUE  */
  YYSYMBOL_FALSE = 9,                      /* FALSE  */
  YYSYMBOL_BYTE = 10,                      /* BYTE  */
  YYSYMBOL_WORD = 11,                      /* WORD  */
  YYSYMBOL_VOID = 12,                      /* VOID  */
  YYSYMBOL_PASS = 13,                      /* PASS  */
  YYSYMBOL_IF = 14,                        /* IF  */
  YYSYMBOL_ELSE = 15,                      /* ELSE  */
  YYSYMBOL_FOR = 16,                       /* FOR  */
  YYSYMBOL_WHILE = 17,                     /* WHILE  */
  YYSYMBOL_RETURN = 18,                    /* RETURN  */
  YYSYMBOL_EQ = 19,                        /* EQ  */
  YYSYMBOL_NE = 20,                        /* NE  */
  YYSYMBOL_GE = 21,                        /* GE  */
  YYSYMBOL_GT = 22,                        /* GT  */
  YYSYMBOL_LE = 23,                        /* LE  */
  YYSYMBOL_LT = 24,                        /* LT  */
  YYSYMBOL_25_ = 25,                       /* '='  */
  YYSYMBOL_26_ = 26,                       /* '|'  */
  YYSYMBOL_27_ = 27,                       /* '&'  */
  YYSYMBOL_28_ = 28,                       /* '^'  */
  YYSYMBOL_29_ = 29,                       /* '+'  */
  YYSYMBOL_30_ = 30,                       /* '-'  */
  YYSYMBOL_31_ = 31,                       /* '*'  */
  YYSYMBOL_32_ = 32,                       /* '/'  */
  YYSYMBOL_33_ = 33,                       /* '%'  */
  YYSYMBOL_34_ = 34,                       /* '~'  */
  YYSYMBOL_35_ = 35,                       /* '('  */
  YYSYMBOL_36_ = 36,                       /* ')'  */
  YYSYMBOL_37_ = 37,                       /* ';'  */
  YYSYMBOL_38_ = 38,                       /* ','  */
  YYSYMBOL_39_ = 39,                       /* '{'  */
  YYSYMBOL_40_ = 40,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 41,                  /* $accept  */
  YYSYMBOL_all_program = 42,               /* all_program  */
  YYSYMBOL_program = 43,                   /* program  */
  YYSYMBOL_unit = 44,                      /* unit  */
  YYSYMBOL_type = 45,                      /* type  */
  YYSYMBOL_varname = 46,                   /* varname  */
  YYSYMBOL_vardecl = 47,                   /* vardecl  */
  YYSYMBOL_fundecl = 48,                   /* fundecl  */
  YYSYMBOL_fundef = 49,                    /* fundef  */
  YYSYMBOL_arglist = 50,                   /* arglist  */
  YYSYMBOL_arg = 51,                       /* arg  */
  YYSYMBOL_argname = 52,                   /* argname  */
  YYSYMBOL_funname = 53,                   /* funname  */
  YYSYMBOL_body = 54,                      /* body  */
  YYSYMBOL_statements = 55,                /* statements  */
  YYSYMBOL_statement_semicolon = 56,       /* statement_semicolon  */
  YYSYMBOL_curly_statement = 57,           /* curly_statement  */
  YYSYMBOL_statement = 58,                 /* statement  */
  YYSYMBOL_functioncall = 59,              /* functioncall  */
  YYSYMBOL_functionname = 60,              /* functionname  */
  YYSYMBOL_params = 61,                    /* params  */
  YYSYMBOL_param = 62,                     /* param  */
  YYSYMBOL_number = 63,                    /* number  */
  YYSYMBOL_expr = 64                       /* expr  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   273

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  119

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   279


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    33,    27,     2,
      35,    36,    31,    29,    38,    30,     2,    32,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    37,
       2,    25,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    28,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,    26,    40,    34,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    61,    61,    72,    72,    74,    74,    76,    77,    78,
      79,    82,    82,    85,    86,    89,    91,    93,    94,    95,
      98,    99,   100,   102,   102,   105,   106,   110,   111,   115,
     116,   117,   118,   120,   121,   122,   125,   127,   130,   131,
     132,   135,   137,   138,   139,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NUM", "HEXNUM",
  "BINNUM", "ID", "BOOL", "TRUE", "FALSE", "BYTE", "WORD", "VOID", "PASS",
  "IF", "ELSE", "FOR", "WHILE", "RETURN", "EQ", "NE", "GE", "GT", "LE",
  "LT", "'='", "'|'", "'&'", "'^'", "'+'", "'-'", "'*'", "'/'", "'%'",
  "'~'", "'('", "')'", "';'", "','", "'{'", "'}'", "$accept",
  "all_program", "program", "unit", "type", "varname", "vardecl",
  "fundecl", "fundef", "arglist", "arg", "argname", "funname", "body",
  "statements", "statement_semicolon", "curly_statement", "statement",
  "functioncall", "functionname", "params", "param", "number", "expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,    61,   124,    38,    94,    43,
      45,    42,    47,    37,   126,    40,    41,    59,    44,   123,
     125
};
#endif

#define YYPACT_NINF (-93)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-38)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      38,   -93,   -93,   -93,     9,    38,   -93,    -3,   -93,   -93,
     -93,   -93,   -93,   -93,   -23,    38,     0,   -12,   -93,   -93,
     -93,    21,    38,   -93,    51,   -93,   -93,   -93,   -93,   -93,
      -8,    17,    18,    24,   100,    67,   100,     1,   100,   100,
     -93,    16,    -2,   -93,    84,   -93,   -93,    39,   -93,    42,
     -93,   227,   100,   100,   100,   227,   -93,   -93,   -93,   -93,
     -93,   155,    50,   100,   -93,   -93,   -93,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   173,   117,   191,   -93,   100,   227,    28,   -93,   227,
     -15,   -15,   -15,   -15,   -15,   -15,   241,   241,   241,    40,
      40,   -93,   -93,    44,   100,    44,   227,   -93,   100,    64,
     136,   -93,   -93,    44,   100,   -93,   209,    44,   -93
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     7,     8,     9,     0,     2,     3,     0,     6,     5,
       1,     4,    22,    10,     0,    17,     0,     0,    18,    21,
      20,     0,     0,    15,     0,    16,    19,    42,    43,    44,
      11,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      24,     0,    45,    33,     0,    25,    28,     0,    46,     0,
      47,    34,     0,     0,     0,    35,    59,    57,    11,    12,
      56,     0,    13,     0,    23,    26,    27,    38,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    58,     0,    48,     0,    39,    41,
      60,    61,    62,    64,    63,    65,    54,    53,    55,    49,
      50,    51,    52,     0,     0,     0,    14,    36,     0,    29,
       0,    32,    40,     0,     0,    30,     0,     0,    31
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -93,   -93,   -93,    79,   -14,    55,   -93,   -93,   -93,   -93,
      71,   -93,   -93,   -92,   -93,    53,   -93,   -93,   -93,   -93,
     -93,    -9,   -93,   -34
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,     6,     7,    42,    43,     8,     9,    17,
      18,    20,    14,    25,    44,    45,    46,    47,    48,    49,
      87,    88,    50,    51
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      55,    16,    57,    12,    60,    61,    19,    58,    16,    10,
      41,   109,    15,   111,    77,    78,    79,    80,    81,    82,
      83,   115,    62,    63,    21,   118,    22,   -37,    13,    86,
      41,    13,    37,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,    13,     1,     2,
       3,   106,    52,    53,    27,    28,    29,    30,    23,    54,
      24,     1,     2,     3,   107,    31,   108,    32,    33,    34,
     110,    79,    80,    56,    89,    85,    66,    67,    35,   113,
     116,    36,    37,    24,    11,    38,    39,    27,    28,    29,
      30,    40,    59,    26,     1,     2,     3,    65,    31,   112,
      32,    33,    34,    27,    28,    29,    30,     0,     0,     0,
       0,    35,     0,     0,    36,    37,     0,     0,    38,    39,
       0,     0,     0,     0,    64,     0,     0,    35,     0,     0,
      36,    37,     0,     0,    38,    39,    68,    69,    70,    71,
      72,    73,     0,    74,    75,    76,    77,    78,    79,    80,
       0,     0,     0,     0,   104,    68,    69,    70,    71,    72,
      73,     0,    74,    75,    76,    77,    78,    79,    80,     0,
       0,     0,     0,   114,    68,    69,    70,    71,    72,    73,
       0,    74,    75,    76,    77,    78,    79,    80,     0,     0,
       0,    84,    68,    69,    70,    71,    72,    73,     0,    74,
      75,    76,    77,    78,    79,    80,     0,     0,     0,   103,
      68,    69,    70,    71,    72,    73,     0,    74,    75,    76,
      77,    78,    79,    80,     0,     0,     0,   105,    68,    69,
      70,    71,    72,    73,     0,    74,    75,    76,    77,    78,
      79,    80,     0,     0,     0,   117,    68,    69,    70,    71,
      72,    73,     0,    74,    75,    76,    77,    78,    79,    80,
      68,    69,    70,    71,    72,    73,     0,     0,     0,     0,
      77,    78,    79,    80
};

static const yytype_int8 yycheck[] =
{
      34,    15,    36,     6,    38,    39,     6,     6,    22,     0,
      24,   103,    35,   105,    29,    30,    31,    32,    52,    53,
      54,   113,     6,    25,    36,   117,    38,    35,    31,    63,
      44,    31,    31,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    31,    10,    11,
      12,    85,    35,    35,     3,     4,     5,     6,    37,    35,
      39,    10,    11,    12,    36,    14,    38,    16,    17,    18,
     104,    31,    32,     6,   108,    25,    37,    35,    27,    15,
     114,    30,    31,    39,     5,    34,    35,     3,     4,     5,
       6,    40,    37,    22,    10,    11,    12,    44,    14,   108,
      16,    17,    18,     3,     4,     5,     6,    -1,    -1,    -1,
      -1,    27,    -1,    -1,    30,    31,    -1,    -1,    34,    35,
      -1,    -1,    -1,    -1,    40,    -1,    -1,    27,    -1,    -1,
      30,    31,    -1,    -1,    34,    35,    19,    20,    21,    22,
      23,    24,    -1,    26,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    37,    19,    20,    21,    22,    23,
      24,    -1,    26,    27,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    37,    19,    20,    21,    22,    23,    24,
      -1,    26,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    36,    19,    20,    21,    22,    23,    24,    -1,    26,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    36,
      19,    20,    21,    22,    23,    24,    -1,    26,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    36,    19,    20,
      21,    22,    23,    24,    -1,    26,    27,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    36,    19,    20,    21,    22,
      23,    24,    -1,    26,    27,    28,    29,    30,    31,    32,
      19,    20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,
      29,    30,    31,    32
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    10,    11,    12,    42,    43,    44,    45,    48,    49,
       0,    44,     6,    31,    53,    35,    45,    50,    51,     6,
      52,    36,    38,    37,    39,    54,    51,     3,     4,     5,
       6,    14,    16,    17,    18,    27,    30,    31,    34,    35,
      40,    45,    46,    47,    55,    56,    57,    58,    59,    60,
      63,    64,    35,    35,    35,    64,     6,    64,     6,    46,
      64,    64,     6,    25,    40,    56,    37,    35,    19,    20,
      21,    22,    23,    24,    26,    27,    28,    29,    30,    31,
      32,    64,    64,    64,    36,    25,    64,    61,    62,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    36,    37,    36,    64,    36,    38,    54,
      64,    54,    62,    15,    37,    54,    64,    36,    54
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    43,    43,    44,    44,    45,    45,    45,
      45,    46,    46,    47,    47,    48,    49,    50,    50,    50,
      51,    52,    53,    54,    54,    55,    55,    56,    56,    57,
      57,    57,    57,    58,    58,    58,    59,    60,    61,    61,
      61,    62,    63,    63,    63,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       2,     1,     2,     2,     4,     6,     6,     0,     1,     3,
       2,     1,     1,     3,     2,     1,     2,     2,     1,     5,
       7,     9,     5,     1,     1,     2,     4,     1,     0,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     3,     2,
       3,     3,     3,     3,     3,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* all_program: program  */
#line 61 "comp.y"
                     { 
  cout << (yyvsp[0].node)->debug() << endl; 
  EMU16 emu16;
  Compiler comp((yyvsp[0].node), nullptr, &emu16); 
  if (comp.compile()) cerr << "Ready." << endl; 
  else cerr << "There were errors." << endl;
  for (string line : emu16.code()) {
    cout << line << endl;
  } 
}
#line 1361 "y.tab.c"
    break;

  case 3: /* program: unit  */
#line 72 "comp.y"
              { (yyval.node) = n("program", {(yyvsp[0].node)}); }
#line 1367 "y.tab.c"
    break;

  case 4: /* program: program unit  */
#line 72 "comp.y"
                                                          { (yyval.node) = n("program", catnode((yyvsp[-1].node)->args, (yyvsp[0].node))); }
#line 1373 "y.tab.c"
    break;

  case 5: /* unit: fundef  */
#line 74 "comp.y"
             { (yyval.node) = n("unit", {(yyvsp[0].node)}); }
#line 1379 "y.tab.c"
    break;

  case 6: /* unit: fundecl  */
#line 74 "comp.y"
                                                 { (yyval.node) = n("unit", {(yyvsp[0].node)}); }
#line 1385 "y.tab.c"
    break;

  case 7: /* type: BYTE  */
#line 76 "comp.y"
           { (yyval.node) = n("type", {n("byte")}); }
#line 1391 "y.tab.c"
    break;

  case 8: /* type: WORD  */
#line 77 "comp.y"
           { (yyval.node) = n("type", {n("word")}); }
#line 1397 "y.tab.c"
    break;

  case 9: /* type: VOID  */
#line 78 "comp.y"
           { (yyval.node) = n("type", {n("void")}); }
#line 1403 "y.tab.c"
    break;

  case 10: /* type: type '*'  */
#line 79 "comp.y"
               { (yyval.node) = n("ptr", {(yyvsp[-1].node)}); }
#line 1409 "y.tab.c"
    break;

  case 11: /* varname: ID  */
#line 82 "comp.y"
            { (yyval.node) = (yyvsp[0].node); }
#line 1415 "y.tab.c"
    break;

  case 12: /* varname: '*' varname  */
#line 82 "comp.y"
                                       { (yyval.node) = n("deref", {(yyvsp[0].node)}); }
#line 1421 "y.tab.c"
    break;

  case 13: /* vardecl: type ID  */
#line 85 "comp.y"
            { (yyval.node) = n("vardecl", {(yyvsp[-1].node), (yyvsp[0].node)}); }
#line 1427 "y.tab.c"
    break;

  case 14: /* vardecl: type ID '=' expr  */
#line 86 "comp.y"
                       { (yyval.node) = n("vardecl_init", {n("vardecl", {(yyvsp[-3].node), (yyvsp[-2].node)}), n("varset", {(yyvsp[-2].node), (yyvsp[0].node)})}); }
#line 1433 "y.tab.c"
    break;

  case 15: /* fundecl: type funname '(' arglist ')' ';'  */
#line 89 "comp.y"
                                          { (yyval.node) = n("fundecl", {(yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-2].node)}); }
#line 1439 "y.tab.c"
    break;

  case 16: /* fundef: type funname '(' arglist ')' body  */
#line 91 "comp.y"
                                          { (yyval.node) = n("fundef", {(yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node)}); }
#line 1445 "y.tab.c"
    break;

  case 17: /* arglist: %empty  */
#line 93 "comp.y"
    { (yyval.node) = n("arglist", {}); }
#line 1451 "y.tab.c"
    break;

  case 18: /* arglist: arg  */
#line 94 "comp.y"
          { (yyval.node) = n("arglist", {(yyvsp[0].node)}); }
#line 1457 "y.tab.c"
    break;

  case 19: /* arglist: arglist ',' arg  */
#line 95 "comp.y"
                      { (yyval.node) = n("arglist", catnode((yyvsp[-2].node)->args, (yyvsp[0].node))); }
#line 1463 "y.tab.c"
    break;

  case 20: /* arg: type argname  */
#line 98 "comp.y"
                  { (yyval.node) = n("arg", {(yyvsp[-1].node), (yyvsp[0].node)}); }
#line 1469 "y.tab.c"
    break;

  case 21: /* argname: ID  */
#line 99 "comp.y"
            { (yyval.node) = (yyvsp[0].node); }
#line 1475 "y.tab.c"
    break;

  case 22: /* funname: ID  */
#line 100 "comp.y"
            { (yyval.node) = (yyvsp[0].node); }
#line 1481 "y.tab.c"
    break;

  case 23: /* body: '{' statements '}'  */
#line 102 "comp.y"
                         { (yyval.node) = (yyvsp[-1].node); }
#line 1487 "y.tab.c"
    break;

  case 24: /* body: '{' '}'  */
#line 102 "comp.y"
                                                { (yyval.node) = n("statements");}
#line 1493 "y.tab.c"
    break;

  case 25: /* statements: statement_semicolon  */
#line 105 "comp.y"
                        { (yyval.node) = n("statements", {(yyvsp[0].node)}); }
#line 1499 "y.tab.c"
    break;

  case 26: /* statements: statements statement_semicolon  */
#line 106 "comp.y"
                                     { (yyval.node) = n("statements", catnode((yyvsp[-1].node)->args, (yyvsp[0].node))); }
#line 1505 "y.tab.c"
    break;

  case 27: /* statement_semicolon: statement ';'  */
#line 110 "comp.y"
                  { (yyval.node) = (yyvsp[-1].node); }
#line 1511 "y.tab.c"
    break;

  case 28: /* statement_semicolon: curly_statement  */
#line 111 "comp.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 1517 "y.tab.c"
    break;

  case 29: /* curly_statement: IF '(' expr ')' body  */
#line 115 "comp.y"
                         { (yyval.node) = n("if", {(yyvsp[-2].node), (yyvsp[0].node)}); }
#line 1523 "y.tab.c"
    break;

  case 30: /* curly_statement: IF '(' expr ')' body ELSE body  */
#line 116 "comp.y"
                                     { (yyval.node) = n("ifelse", {(yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node)}); }
#line 1529 "y.tab.c"
    break;

  case 31: /* curly_statement: FOR '(' expr ';' expr ';' expr ')' body  */
#line 117 "comp.y"
                                              { (yyval.node) = n("for", {(yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node)}); }
#line 1535 "y.tab.c"
    break;

  case 32: /* curly_statement: WHILE '(' expr ')' body  */
#line 118 "comp.y"
                              { (yyval.node) = n("while", {(yyvsp[-2].node), (yyvsp[0].node)}); }
#line 1541 "y.tab.c"
    break;

  case 33: /* statement: vardecl  */
#line 120 "comp.y"
                   { (yyval.node) = (yyvsp[0].node); }
#line 1547 "y.tab.c"
    break;

  case 34: /* statement: expr  */
#line 121 "comp.y"
           { (yyval.node) = (yyvsp[0].node); }
#line 1553 "y.tab.c"
    break;

  case 35: /* statement: RETURN expr  */
#line 122 "comp.y"
                  { (yyval.node) = n("return", {(yyvsp[0].node)}); }
#line 1559 "y.tab.c"
    break;

  case 36: /* functioncall: functionname '(' params ')'  */
#line 125 "comp.y"
                                          { (yyval.node) = n("funcall", {(yyvsp[-3].node), (yyvsp[-1].node)}); }
#line 1565 "y.tab.c"
    break;

  case 37: /* functionname: ID  */
#line 127 "comp.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 1571 "y.tab.c"
    break;

  case 38: /* params: %empty  */
#line 130 "comp.y"
    { (yyval.node) = n("params"); }
#line 1577 "y.tab.c"
    break;

  case 39: /* params: param  */
#line 131 "comp.y"
            { (yyval.node) = n("params", {(yyvsp[0].node)}); }
#line 1583 "y.tab.c"
    break;

  case 40: /* params: params ',' param  */
#line 132 "comp.y"
                       { (yyval.node) = n("params", catnode((yyvsp[-2].node)->args, (yyvsp[0].node))); }
#line 1589 "y.tab.c"
    break;

  case 41: /* param: expr  */
#line 135 "comp.y"
            { (yyval.node) = (yyvsp[0].node); }
#line 1595 "y.tab.c"
    break;

  case 42: /* number: NUM  */
#line 137 "comp.y"
            { (yyval.num)=atoi((yyvsp[0].str)->c_str()); }
#line 1601 "y.tab.c"
    break;

  case 43: /* number: HEXNUM  */
#line 138 "comp.y"
             { (yyval.num)=strtol((yyvsp[0].str)->c_str(), NULL, 16); }
#line 1607 "y.tab.c"
    break;

  case 44: /* number: BINNUM  */
#line 139 "comp.y"
             { (yyval.num)=strtol((yyvsp[0].str)->c_str()+2, NULL, 2); }
#line 1613 "y.tab.c"
    break;

  case 45: /* expr: varname  */
#line 142 "comp.y"
              { (yyval.node) = n("varref", {(yyvsp[0].node)}); }
#line 1619 "y.tab.c"
    break;

  case 46: /* expr: functioncall  */
#line 143 "comp.y"
                   { (yyval.node) = (yyvsp[0].node); }
#line 1625 "y.tab.c"
    break;

  case 47: /* expr: number  */
#line 144 "comp.y"
             { (yyval.node) = n("number", {n(to_string((yyvsp[0].num)))}); }
#line 1631 "y.tab.c"
    break;

  case 48: /* expr: varname '=' expr  */
#line 145 "comp.y"
                       { (yyval.node) = n("varset", {(yyvsp[-2].node), (yyvsp[0].node)}); }
#line 1637 "y.tab.c"
    break;

  case 49: /* expr: expr '+' expr  */
#line 146 "comp.y"
                    { (yyval.node) = n("+", {(yyvsp[-2].node), (yyvsp[0].node)}); }
#line 1643 "y.tab.c"
    break;

  case 50: /* expr: expr '-' expr  */
#line 147 "comp.y"
                    { (yyval.node) = n("-", {(yyvsp[-2].node), (yyvsp[0].node)}); }
#line 1649 "y.tab.c"
    break;

  case 51: /* expr: expr '*' expr  */
#line 148 "comp.y"
                    { (yyval.node) = n("*", {(yyvsp[-2].node), (yyvsp[0].node)}); }
#line 1655 "y.tab.c"
    break;

  case 52: /* expr: expr '/' expr  */
#line 149 "comp.y"
                    { (yyval.node) = n("/", {(yyvsp[-2].node), (yyvsp[0].node)}); }
#line 1661 "y.tab.c"
    break;

  case 53: /* expr: expr '&' expr  */
#line 150 "comp.y"
                    { (yyval.node) = n("&", {(yyvsp[-2].node), (yyvsp[0].node)}); }
#line 1667 "y.tab.c"
    break;

  case 54: /* expr: expr '|' expr  */
#line 151 "comp.y"
                    { (yyval.node) = n("|", {(yyvsp[-2].node), (yyvsp[0].node)}); }
#line 1673 "y.tab.c"
    break;

  case 55: /* expr: expr '^' expr  */
#line 152 "comp.y"
                    { (yyval.node) = n("^", {(yyvsp[-2].node), (yyvsp[0].node)}); }
#line 1679 "y.tab.c"
    break;

  case 56: /* expr: '~' expr  */
#line 153 "comp.y"
               { (yyval.node) = n("neg", {(yyvsp[0].node)}); }
#line 1685 "y.tab.c"
    break;

  case 57: /* expr: '-' expr  */
#line 154 "comp.y"
                         { (yyval.node) = n("minus", {(yyvsp[0].node)}); }
#line 1691 "y.tab.c"
    break;

  case 58: /* expr: '(' expr ')'  */
#line 155 "comp.y"
                   { (yyval.node) = (yyvsp[-1].node); }
#line 1697 "y.tab.c"
    break;

  case 59: /* expr: '&' ID  */
#line 156 "comp.y"
             { (yyval.node) = n("addr", {(yyvsp[0].node)}); }
#line 1703 "y.tab.c"
    break;

  case 60: /* expr: expr EQ expr  */
#line 157 "comp.y"
                   { (yyval.node) = n("==", {(yyvsp[-2].node), (yyvsp[0].node)}); }
#line 1709 "y.tab.c"
    break;

  case 61: /* expr: expr NE expr  */
#line 158 "comp.y"
                   { (yyval.node) = n("!=", {(yyvsp[-2].node), (yyvsp[0].node)}); }
#line 1715 "y.tab.c"
    break;

  case 62: /* expr: expr GE expr  */
#line 159 "comp.y"
                   { (yyval.node) = n(">=", {(yyvsp[-2].node), (yyvsp[0].node)}); }
#line 1721 "y.tab.c"
    break;

  case 63: /* expr: expr LE expr  */
#line 160 "comp.y"
                   { (yyval.node) = n("<=", {(yyvsp[-2].node), (yyvsp[0].node)}); }
#line 1727 "y.tab.c"
    break;

  case 64: /* expr: expr GT expr  */
#line 161 "comp.y"
                   { (yyval.node) = n(">", {(yyvsp[-2].node), (yyvsp[0].node)}); }
#line 1733 "y.tab.c"
    break;

  case 65: /* expr: expr LT expr  */
#line 162 "comp.y"
                   { (yyval.node) = n("<", {(yyvsp[-2].node), (yyvsp[0].node)}); }
#line 1739 "y.tab.c"
    break;


#line 1743 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 165 "comp.y"

extern int yylex();
extern int yyparse();
int main() { yyparse(); }
