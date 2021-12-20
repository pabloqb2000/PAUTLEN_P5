/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "alfa.y"

#include <stdio.h>
#include <string.h>
#include "alpha.h"
#include "sym_table.h"
#include "generacion.h"

int yylex();
void yyerror();
void error_semantico (char *error_msg);
extern FILE * out;
extern long yylin;
extern long yycol;
extern int yy_morph_error;

stable* table;
int tipo_variable;
int etiqueta = 0;
int declaracion = NONE;
int n_parametros = 0;
int n_variables_locales = 0;

#line 93 "y.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TOK_MAIN = 258,
    TOK_INT = 259,
    TOK_BOOLEAN = 260,
    TOK_ARRAY = 261,
    TOK_FUNCTION = 262,
    TOK_IF = 263,
    TOK_ELSE = 264,
    TOK_WHILE = 265,
    TOK_SCANF = 266,
    TOK_PRINTF = 267,
    TOK_RETURN = 268,
    TOK_PUNTOYCOMA = 269,
    TOK_COMA = 270,
    TOK_PARENTESISIZQUIERDO = 271,
    TOK_PARENTESISDERECHO = 272,
    TOK_CORCHETEIZQUIERDO = 273,
    TOK_CORCHETEDERECHO = 274,
    TOK_LLAVEIZQUIERDA = 275,
    TOK_LLAVEDERECHA = 276,
    TOK_ASIGNACION = 277,
    TOK_MAS = 278,
    TOK_MENOS = 279,
    TOK_DIVISION = 280,
    TOK_ASTERISCO = 281,
    TOK_AND = 282,
    TOK_OR = 283,
    TOK_NOT = 284,
    TOK_IGUAL = 285,
    TOK_DISTINTO = 286,
    TOK_MENORIGUAL = 287,
    TOK_MAYORIGUAL = 288,
    TOK_MENOR = 289,
    TOK_MAYOR = 290,
    TOK_IDENTIFICADOR = 291,
    TOK_CONSTANTE_ENTERA = 292,
    TOK_TRUE = 293,
    TOK_FALSE = 294,
    TOK_ERROR = 295
  };
#endif
/* Tokens.  */
#define TOK_MAIN 258
#define TOK_INT 259
#define TOK_BOOLEAN 260
#define TOK_ARRAY 261
#define TOK_FUNCTION 262
#define TOK_IF 263
#define TOK_ELSE 264
#define TOK_WHILE 265
#define TOK_SCANF 266
#define TOK_PRINTF 267
#define TOK_RETURN 268
#define TOK_PUNTOYCOMA 269
#define TOK_COMA 270
#define TOK_PARENTESISIZQUIERDO 271
#define TOK_PARENTESISDERECHO 272
#define TOK_CORCHETEIZQUIERDO 273
#define TOK_CORCHETEDERECHO 274
#define TOK_LLAVEIZQUIERDA 275
#define TOK_LLAVEDERECHA 276
#define TOK_ASIGNACION 277
#define TOK_MAS 278
#define TOK_MENOS 279
#define TOK_DIVISION 280
#define TOK_ASTERISCO 281
#define TOK_AND 282
#define TOK_OR 283
#define TOK_NOT 284
#define TOK_IGUAL 285
#define TOK_DISTINTO 286
#define TOK_MENORIGUAL 287
#define TOK_MAYORIGUAL 288
#define TOK_MENOR 289
#define TOK_MAYOR 290
#define TOK_IDENTIFICADOR 291
#define TOK_CONSTANTE_ENTERA 292
#define TOK_TRUE 293
#define TOK_FALSE 294
#define TOK_ERROR 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 24 "alfa.y"

	atr_info atributos;

#line 229 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



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
typedef yytype_uint8 yy_state_t;

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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
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

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


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
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   157

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  153

#define YYUNDEFTOK  2
#define YYMAXUTOK   295


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   100,   100,   104,   108,   112,   118,   119,   122,   128,
     129,   132,   135,   139,   145,   148,   151,   156,   158,   162,
     169,   174,   181,   188,   189,   192,   193,   196,   201,   202,
     205,   206,   209,   210,   213,   214,   215,   216,   219,   220,
     223,   243,   247,   249,   254,   264,   268,   274,   278,   284,
     289,   294,   298,   302,   306,   314,   322,   330,   338,   346,
     354,   362,   370,   386,   391,   395,   398,   399,   402,   403,
     406,   407,   410,   420,   429,   439,   449,   459,   473,   474,
     477,   478,   480,   483
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_MAIN", "TOK_INT", "TOK_BOOLEAN",
  "TOK_ARRAY", "TOK_FUNCTION", "TOK_IF", "TOK_ELSE", "TOK_WHILE",
  "TOK_SCANF", "TOK_PRINTF", "TOK_RETURN", "TOK_PUNTOYCOMA", "TOK_COMA",
  "TOK_PARENTESISIZQUIERDO", "TOK_PARENTESISDERECHO",
  "TOK_CORCHETEIZQUIERDO", "TOK_CORCHETEDERECHO", "TOK_LLAVEIZQUIERDA",
  "TOK_LLAVEDERECHA", "TOK_ASIGNACION", "TOK_MAS", "TOK_MENOS",
  "TOK_DIVISION", "TOK_ASTERISCO", "TOK_AND", "TOK_OR", "TOK_NOT",
  "TOK_IGUAL", "TOK_DISTINTO", "TOK_MENORIGUAL", "TOK_MAYORIGUAL",
  "TOK_MENOR", "TOK_MAYOR", "TOK_IDENTIFICADOR", "TOK_CONSTANTE_ENTERA",
  "TOK_TRUE", "TOK_FALSE", "TOK_ERROR", "$accept", "programa",
  "prog_funciones", "prog_declaraciones", "prog_inicio", "declaraciones",
  "declaracion", "clase", "clase_escalar", "tipo", "clase_vector",
  "identificadores", "funciones", "f_nombre", "f_parametros",
  "f_declaracion", "funcion", "parametros_funcion",
  "resto_parametros_funcion", "parametro_funcion", "declaraciones_funcion",
  "sentencias", "sentencia", "sentencia_simple", "bloque", "asignacion",
  "elemento_vector", "if_tok", "if_exp", "condicional", "if_else_exp",
  "while", "bucle_exp", "bucle", "lectura", "escritura", "retorno_funcion",
  "exp", "lista_expresiones", "resto_lista_expresiones", "comparacion",
  "constante", "constante_logica", "constante_entera", "identificador", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295
};
# endif

#define YYPACT_NINF (-38)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-84)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -1,    -5,    27,     8,    28,     5,   -38,   -38,    20,    29,
      11,    81,    81,   -38,    25,     8,    34,   -38,   -38,    30,
      81,    31,   -38,    33,    81,    38,   -38,   -38,   -38,   -38,
     -15,    18,   -38,    41,    45,     8,    28,   -38,   -38,    18,
     -38,     5,    11,   -38,   -38,   -38,   -38,   -38,   -38,    81,
      81,    81,    10,   -38,   -38,   -38,   -38,   129,   -38,   -38,
     -38,    16,   129,   -38,   -38,   -38,    81,    46,     8,     8,
     129,    44,    81,    81,    48,    18,    67,    65,   -38,    47,
     -38,    84,    80,   109,    90,    15,   -38,    81,    81,    81,
      81,    81,    81,    81,   129,   -38,    87,    88,     8,    66,
     129,   -38,    11,   -38,    97,     5,   -38,    76,   -38,    11,
     -38,    81,    81,    81,    81,    81,    81,   -38,    15,    15,
       3,     3,   -38,   -38,   123,    98,   105,   -38,   100,   -38,
     -38,    18,   -38,   -38,   -38,   103,   -38,   129,   129,   129,
     129,   129,   129,    81,   -38,   -38,   -38,   -38,    97,   -38,
     123,   -38,   -38
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,    18,     0,     5,     1,     0,     0,
       0,     0,     0,    83,     0,    30,     0,    33,    34,     0,
       0,     0,    38,     0,     0,     0,    39,    35,    36,    37,
       0,     0,     3,     0,     0,     0,    18,    12,    13,     0,
       4,     6,     0,     9,    11,    10,    43,    48,    51,     0,
       0,     0,    62,    82,    80,    81,    66,    52,    63,    78,
      79,     0,    53,     2,    31,    32,     0,     0,     0,     0,
      49,     0,     0,     0,     0,    24,     0,     0,    17,     0,
       7,     0,    15,     0,     0,    58,    61,     0,     0,     0,
       0,     0,     0,    69,    41,    44,     0,     0,     0,     0,
      40,    19,     0,    20,    26,    29,    22,     0,     8,     0,
      65,     0,     0,     0,     0,     0,     0,    64,    54,    55,
      56,    57,    59,    60,    71,     0,    45,    46,     0,    42,
      27,     0,    23,    28,    21,     0,    16,    72,    73,    74,
      75,    76,    77,     0,    68,    67,    47,    50,    26,    14,
      71,    25,    70
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -38,   -38,   -38,   -38,   -38,   -37,   -38,   -38,   -38,   -25,
     -38,    19,    89,   -38,   -38,   -38,   -38,   -38,   -24,    -4,
     -38,   -10,   -38,   -38,   -38,   -38,    -2,   -38,   -38,   -38,
     -38,   -38,   -38,   -38,   -38,   -38,   -38,   -12,   -38,   -21,
     -38,   -38,   -38,    23,    14
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,     5,    40,    41,    42,    43,    44,
      45,    81,    32,    33,    34,    35,    36,   103,   132,   104,
     134,    14,    15,    16,    17,    18,    56,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    57,   125,   144,
      84,    58,    59,    60,    61
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      62,    19,     1,    72,    80,    64,    74,    73,    67,    37,
      38,    39,    70,    19,    79,     6,     8,    30,     9,    10,
      11,    12,    37,    38,    48,    77,   -83,     7,   -83,    30,
      91,    92,    93,    19,    72,    31,    46,    83,    85,    86,
      89,    90,    91,    92,    13,    47,    63,    13,    65,    30,
     102,    68,    66,    69,    94,    71,    82,    75,    96,    97,
      99,   100,    76,    95,    98,   107,    19,    19,   133,    87,
      88,    89,    90,    91,    92,   118,   119,   120,   121,   122,
     123,   124,    30,    30,   101,   129,   106,   105,   128,    87,
      88,    89,    90,    91,    92,   109,    19,    49,   108,   137,
     138,   139,   140,   141,   142,    50,   102,   117,   126,   127,
      51,   131,    30,    53,   146,   145,   130,    52,    53,    54,
      55,   147,   149,    82,   151,    78,   110,   148,   136,   152,
     135,   150,    87,    88,    89,    90,    91,    92,   143,   111,
     112,   113,   114,   115,   116,     0,    87,    88,    89,    90,
      91,    92,    87,    88,    89,    90,    91,    92
};

static const yytype_int16 yycheck[] =
{
      12,     3,     3,    18,    41,    15,    31,    22,    20,     4,
       5,     6,    24,    15,    39,    20,     8,     3,    10,    11,
      12,    13,     4,     5,    10,    35,    16,     0,    18,    15,
      27,    28,    16,    35,    18,     7,    16,    49,    50,    51,
      25,    26,    27,    28,    36,    16,    21,    36,    14,    35,
      75,    20,    22,    20,    66,    17,    42,    16,    68,    69,
      72,    73,    17,    17,    20,    18,    68,    69,   105,    23,
      24,    25,    26,    27,    28,    87,    88,    89,    90,    91,
      92,    93,    68,    69,    36,    19,    21,    20,    98,    23,
      24,    25,    26,    27,    28,    15,    98,    16,    14,   111,
     112,   113,   114,   115,   116,    24,   131,    17,    21,    21,
      29,    14,    98,    37,     9,    17,   102,    36,    37,    38,
      39,    21,    19,   109,   148,    36,    17,   131,   109,   150,
     107,   143,    23,    24,    25,    26,    27,    28,    15,    30,
      31,    32,    33,    34,    35,    -1,    23,    24,    25,    26,
      27,    28,    23,    24,    25,    26,    27,    28
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    42,    43,    44,    45,    20,     0,     8,    10,
      11,    12,    13,    36,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      85,     7,    53,    54,    55,    56,    57,     4,     5,     6,
      46,    47,    48,    49,    50,    51,    16,    16,    85,    16,
      24,    29,    36,    37,    38,    39,    67,    78,    82,    83,
      84,    85,    78,    21,    62,    14,    22,    78,    20,    20,
      78,    17,    18,    22,    50,    16,    17,    62,    53,    50,
      46,    52,    85,    78,    81,    78,    78,    23,    24,    25,
      26,    27,    28,    16,    78,    17,    62,    62,    20,    78,
      78,    36,    50,    58,    60,    20,    21,    18,    14,    15,
      17,    30,    31,    32,    33,    34,    35,    17,    78,    78,
      78,    78,    78,    78,    78,    79,    21,    21,    62,    19,
      85,    14,    59,    46,    61,    84,    52,    78,    78,    78,
      78,    78,    78,    15,    80,    17,     9,    21,    60,    19,
      78,    59,    80
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    43,    44,    45,    46,    46,    47,    48,
      48,    49,    50,    50,    51,    52,    52,    53,    53,    54,
      55,    56,    57,    58,    58,    59,    59,    60,    61,    61,
      62,    62,    63,    63,    64,    64,    64,    64,    65,    65,
      66,    66,    67,    68,    69,    70,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    79,    79,
      80,    80,    81,    81,    81,    81,    81,    81,    82,    82,
      83,    83,    84,    85
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     2,     2,     2,     1,     2,     3,     1,
       1,     1,     1,     1,     5,     1,     3,     2,     0,     3,
       3,     4,     3,     2,     0,     3,     0,     2,     1,     0,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     4,     2,     3,     4,     4,     5,     2,     2,
       5,     2,     2,     2,     3,     3,     3,     3,     2,     3,
       3,     2,     1,     1,     3,     3,     1,     4,     2,     0,
       3,     0,     3,     3,     3,     3,     3,     3,     1,     1,
       1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
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
# undef YYSTACK_RELOCATE
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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
  case 2:
#line 100 "alfa.y"
                                                     {
    escribir_fin(out);
}
#line 1526 "y.tab.c"
    break;

  case 3:
#line 104 "alfa.y"
                                             {
    escribir_inicio_main(out);
}
#line 1534 "y.tab.c"
    break;

  case 4:
#line 108 "alfa.y"
                                              {
    escribir_segmento_codigo(out);
}
#line 1542 "y.tab.c"
    break;

  case 5:
#line 112 "alfa.y"
                                         {
    table = stable_init();
    escribir_subseccion_data(out);
    escribir_cabecera_bss(out);
}
#line 1552 "y.tab.c"
    break;

  case 6:
#line 118 "alfa.y"
                           {fprintf(out, ";R2:\t<declaraciones> ::= <declaracion>\n");}
#line 1558 "y.tab.c"
    break;

  case 7:
#line 119 "alfa.y"
                                         {fprintf(out, ";R3:\t<declaraciones> ::= <declaracion> <declaraciones>\n");}
#line 1564 "y.tab.c"
    break;

  case 8:
#line 122 "alfa.y"
                                                  {
        declaracion = NONE;      
        fprintf(out, ";R4:\t<declaracion> ::= <clase> <identificadores> ;\n");
    }
#line 1573 "y.tab.c"
    break;

  case 9:
#line 128 "alfa.y"
                     {fprintf(out, ";R5:\t<clase> ::= <clase_escalar>\n");}
#line 1579 "y.tab.c"
    break;

  case 10:
#line 129 "alfa.y"
                    {fprintf(out, ";R7:\t<clase> ::= <clase_vector>\n");}
#line 1585 "y.tab.c"
    break;

  case 11:
#line 132 "alfa.y"
                    {fprintf(out, ";R9:\t<clase_escalar> ::= <tipo>\n");}
#line 1591 "y.tab.c"
    break;

  case 12:
#line 135 "alfa.y"
              {
        tipo_variable = INT;
        if(declaracion != LOCAL_VARIABLE && declaracion != PARAMETER) declaracion = VARIABLE;
        fprintf(out, ";R10:\t<tipo> ::= int\n");}
#line 1600 "y.tab.c"
    break;

  case 13:
#line 139 "alfa.y"
                  {
        tipo_variable = BOOLEAN;
        if(declaracion != LOCAL_VARIABLE && declaracion != PARAMETER) declaracion = VARIABLE;
        fprintf(out, ";R11:\t<tipo> ::= boolean\n");}
#line 1609 "y.tab.c"
    break;

  case 14:
#line 145 "alfa.y"
                                                                                        {fprintf(out, ";R15:\t<clase_vector> ::= array <tipo> [<constante_entera>]\n");}
#line 1615 "y.tab.c"
    break;

  case 15:
#line 148 "alfa.y"
                               {
                    fprintf(out, ";R18:\t<identificadores> ::= <identificador>\n");
                }
#line 1623 "y.tab.c"
    break;

  case 16:
#line 151 "alfa.y"
                                                        {
                    fprintf(out, ";R19:\t<identificadores> ::= <identificador> , <identificadores>\n");
                   }
#line 1631 "y.tab.c"
    break;

  case 17:
#line 156 "alfa.y"
                             {
    fprintf(out, ";R20:\t<funciones> ::= <funcion> <funciones>\n");}
#line 1638 "y.tab.c"
    break;

  case 18:
#line 158 "alfa.y"
            {
    fprintf(out, ";R21:\t<funciones> ::=\n");}
#line 1645 "y.tab.c"
    break;

  case 19:
#line 162 "alfa.y"
                                              {
            open_ambit(table, yylval.atributos.nombre, FUNCTION*MAX_N_TIPOS + (yyvsp[-1].atributos).tipo);
            declaracion = PARAMETER;
            strcpy((yyval.atributos).nombre, yylval.atributos.nombre);
            fprintf(out, ";R22_1:\t<f_nombre> ::= function <tipo> <identificador> \n");
        }
#line 1656 "y.tab.c"
    break;

  case 20:
#line 169 "alfa.y"
                                                                  {

    declaracion = LOCAL_VARIABLE;
}
#line 1665 "y.tab.c"
    break;

  case 21:
#line 174 "alfa.y"
                                                                                           {
            declararFuncion(out, (yyvsp[-3].atributos).nombre, n_variables_locales);

            declaracion = NONE;
            fprintf(out, ";R22_3:\t<f_declaracion> ::= <f_nombre> ( <parametros_funcion> ) { <declaraciones_funcion> \n");
        }
#line 1676 "y.tab.c"
    break;

  case 22:
#line 181 "alfa.y"
                                                   {
            n_parametros = 0;
            n_variables_locales = 0;
            close_ambit(table);
            fprintf(out, ";R22_3:\t<funcion> ::= <declaraciones_funcion> <sentencias> } \n");
            }
#line 1687 "y.tab.c"
    break;

  case 23:
#line 188 "alfa.y"
                                                               {fprintf(out, ";R23:\t<parametros_funcion> ::= <parametro_funcion> <resto_parametros_funcion>\n");}
#line 1693 "y.tab.c"
    break;

  case 24:
#line 189 "alfa.y"
                     {fprintf(out, ";R24:\t<parametros_funcion> ::=\n");}
#line 1699 "y.tab.c"
    break;

  case 25:
#line 192 "alfa.y"
                                                                                    {fprintf(out, ";R25:\t<resto_parametros_funcion> ::= ; <parametro_funcion> <resto_parametros_funcion>\n");}
#line 1705 "y.tab.c"
    break;

  case 26:
#line 193 "alfa.y"
                           {fprintf(out, ";R26:\t<resto_parametros_funcion> ::=\n");}
#line 1711 "y.tab.c"
    break;

  case 27:
#line 196 "alfa.y"
                                      {
                fprintf(out, ";R27:\t<parametro_funcion> ::= <tipo> <identificador>\n");
                }
#line 1719 "y.tab.c"
    break;

  case 28:
#line 201 "alfa.y"
                                     {fprintf(out, ";R28:\t<declaraciones_funcion> ::= <declaraciones>\n");}
#line 1725 "y.tab.c"
    break;

  case 29:
#line 202 "alfa.y"
                        {fprintf(out, ";R29:\t<declaraciones_funcion> ::=\n");}
#line 1731 "y.tab.c"
    break;

  case 30:
#line 205 "alfa.y"
                      {fprintf(out, ";R30:\t<sentencias> ::= <sentencia>\n");}
#line 1737 "y.tab.c"
    break;

  case 31:
#line 206 "alfa.y"
                                 {fprintf(out, ";R31:\t<sentencias> ::= <sentencia> <sentencias>\n");}
#line 1743 "y.tab.c"
    break;

  case 32:
#line 209 "alfa.y"
                                           {fprintf(out, ";R32:\t<sentencia> ::= <sentencia_simple> ;\n");}
#line 1749 "y.tab.c"
    break;

  case 33:
#line 210 "alfa.y"
                  {fprintf(out, ";R33:\t<sentencias> ::= <bloque>\n");}
#line 1755 "y.tab.c"
    break;

  case 34:
#line 213 "alfa.y"
                             {fprintf(out, ";R34:\t<sentencia_simple> ::= <asignacion>\n");}
#line 1761 "y.tab.c"
    break;

  case 35:
#line 214 "alfa.y"
                          {fprintf(out, ";R35:\t<sentencia_simple> ::= <lectura>\n");}
#line 1767 "y.tab.c"
    break;

  case 36:
#line 215 "alfa.y"
                            {fprintf(out, ";R36:\t<sentencia_simple> ::= <escritura>\n");}
#line 1773 "y.tab.c"
    break;

  case 37:
#line 216 "alfa.y"
                                  {fprintf(out, ";R38:\t<sentencia_simple> ::= <retorno_funcion>\n");}
#line 1779 "y.tab.c"
    break;

  case 38:
#line 219 "alfa.y"
                    {fprintf(out, ";R40:\t<bloque> ::= <condicional>\n");}
#line 1785 "y.tab.c"
    break;

  case 39:
#line 220 "alfa.y"
              {fprintf(out, ";R41:\t<bloque> ::= <bucle>\n");}
#line 1791 "y.tab.c"
    break;

  case 40:
#line 223 "alfa.y"
                                             {
        int n = (yyvsp[-2].atributos).tipo / (MAX_N_TIPOS * MAX_N_CAT);
        int cat = ((yyvsp[-2].atributos).tipo / MAX_N_TIPOS) % MAX_N_CAT;
        int tipo = (yyvsp[-2].atributos).tipo % MAX_N_TIPOS;
        printf("%d, %d, %d\n", n, cat, tipo);

        if (cat == VARIABLE) {
            asignar(out, (yyvsp[-2].atributos).nombre, (yyvsp[0].atributos).es_direccion);
        } else if (cat == LOCAL_VARIABLE) {
            escribirVariableLocal(out, n);
            asignarDestinoEnPila(out, (yyvsp[0].atributos).es_direccion);
        } else if (cat == PARAMETER) {
            escribirParametro(out, n, n_parametros);
            asignarDestinoEnPila(out, (yyvsp[0].atributos).es_direccion);
        } else {
            error_semantico("No se puede asignar valores a una funcion\n");
        }

        fprintf(out, ";R43:\t<asignacion> ::= <identificador> = <exp>\n");
    }
#line 1816 "y.tab.c"
    break;

  case 41:
#line 243 "alfa.y"
                                         {
        fprintf(out, ";R44:\t<asignacion> ::= <elemento_vector> = <exp>\n");}
#line 1823 "y.tab.c"
    break;

  case 42:
#line 247 "alfa.y"
                                                                             {fprintf(out, ";R48:\t<elemento_vector> = <identificador> [<exp>]\n");}
#line 1829 "y.tab.c"
    break;

  case 43:
#line 249 "alfa.y"
                                        {
            (yyval.atributos).etiqueta = etiqueta;
            etiqueta++;
          }
#line 1838 "y.tab.c"
    break;

  case 44:
#line 254 "alfa.y"
                                         {
            (yyval.atributos).etiqueta = (yyvsp[-2].atributos).etiqueta;
            if ((yyvsp[-1].atributos).tipo != BOOLEAN){
                error_semantico("Condicional con condicion de tipo int");
                return -1;
            }
            ifthen_inicio(out, (yyvsp[-1].atributos).es_direccion, (yyvsp[-2].atributos).etiqueta);
        }
#line 1851 "y.tab.c"
    break;

  case 45:
#line 264 "alfa.y"
                                                                   {
                ifthen_fin(out, (yyvsp[-3].atributos).etiqueta);
                fprintf(out, ";R50:\t<condicional> ::= if ( <exp> ) { <sentencias> }\n");
              }
#line 1860 "y.tab.c"
    break;

  case 46:
#line 269 "alfa.y"
              {
                ifthenelse_fin(out, (yyvsp[-3].atributos).etiqueta);
                fprintf(out, ";R51:\t<condicional> ::= if ( <exp> ) { <sentencias> } else { <sentencias> }\n");
              }
#line 1869 "y.tab.c"
    break;

  case 47:
#line 274 "alfa.y"
                                                                            {
            (yyval.atributos).etiqueta = (yyvsp[-4].atributos).etiqueta; 
            ifthenelse_fin_then(out, (yyvsp[-4].atributos).etiqueta);
          }
#line 1878 "y.tab.c"
    break;

  case 48:
#line 278 "alfa.y"
                                        {
        while_inicio(out, etiqueta);
        (yyval.atributos).etiqueta = etiqueta;
        etiqueta++;
      }
#line 1888 "y.tab.c"
    break;

  case 49:
#line 284 "alfa.y"
                      {
              (yyval.atributos).etiqueta = (yyvsp[-1].atributos).etiqueta;
              while_exp_pila(out, (yyvsp[0].atributos).es_direccion, (yyvsp[-1].atributos).etiqueta);
            }
#line 1897 "y.tab.c"
    break;

  case 50:
#line 289 "alfa.y"
                                                                                      {
        while_fin(out, (yyvsp[-4].atributos).etiqueta);
        fprintf(out, ";R52:\t<bucle> ::= while ( <exp> ) { <sentencias> }\n");
      }
#line 1906 "y.tab.c"
    break;

  case 51:
#line 294 "alfa.y"
                                 {
                leer(out, (yyvsp[0].atributos).nombre, (yyvsp[0].atributos).tipo);
            }
#line 1914 "y.tab.c"
    break;

  case 52:
#line 298 "alfa.y"
                          {
                escribir(out, (yyvsp[0].atributos).es_direccion, (yyvsp[0].atributos).tipo);
            }
#line 1922 "y.tab.c"
    break;

  case 53:
#line 302 "alfa.y"
                                {
    retornarFuncion(out, (yyvsp[0].atributos).es_direccion);
    fprintf(out, ";R61:\t<retorno_funcion> ::= return <exp>\n");}
#line 1930 "y.tab.c"
    break;

  case 54:
#line 306 "alfa.y"
                            {
        if((yyvsp[-2].atributos).tipo == INT && (yyvsp[0].atributos).tipo == INT) {
            (yyval.atributos).tipo = INT;
            (yyval.atributos).es_direccion = FALSE;
            sumar(out, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);
        } else {
            error_semantico("Operandos de la suma no enteros");
        }}
#line 1943 "y.tab.c"
    break;

  case 55:
#line 314 "alfa.y"
                             {
       if((yyvsp[-2].atributos).tipo == INT && (yyvsp[0].atributos).tipo == INT) {
            (yyval.atributos).tipo = INT;
            (yyval.atributos).es_direccion = FALSE;    
            restar(out, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);
        } else {
            error_semantico("Operandos de la resta no enteros");
        }}
#line 1956 "y.tab.c"
    break;

  case 56:
#line 322 "alfa.y"
                             {
        if((yyvsp[-2].atributos).tipo == INT && (yyvsp[0].atributos).tipo == INT) {
            (yyval.atributos).es_direccion = FALSE;    
            (yyval.atributos).tipo = INT;
            dividir(out, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);
        } else {
            error_semantico("Operandos de la división no enteros");
        }}
#line 1969 "y.tab.c"
    break;

  case 57:
#line 330 "alfa.y"
                             {
        if((yyvsp[-2].atributos).tipo == INT && (yyvsp[0].atributos).tipo == INT) {
            (yyval.atributos).es_direccion = FALSE;    
            (yyval.atributos).tipo = INT;
            multiplicar(out, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);
        } else {
            error_semantico("Operandos de la multiplicacion no enteros");
        }}
#line 1982 "y.tab.c"
    break;

  case 58:
#line 338 "alfa.y"
                     {
        if((yyvsp[0].atributos).tipo == INT) {
            (yyval.atributos).es_direccion = FALSE;    
            (yyval.atributos).tipo = INT;
            cambiar_signo(out, (yyvsp[0].atributos).es_direccion);
        } else {
            error_semantico("Valor negativo no entero");
        }}
#line 1995 "y.tab.c"
    break;

  case 59:
#line 346 "alfa.y"
                     {
        if((yyvsp[-2].atributos).tipo == BOOLEAN && (yyvsp[0].atributos).tipo == BOOLEAN) {
            (yyval.atributos).es_direccion = FALSE;    
            (yyval.atributos).tipo = BOOLEAN;
            y(out, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);
        } else {
            error_semantico("Operandos de AND no booleanos");
        }}
#line 2008 "y.tab.c"
    break;

  case 60:
#line 354 "alfa.y"
                     {
        if((yyvsp[-2].atributos).tipo == BOOLEAN && (yyvsp[0].atributos).tipo == BOOLEAN) {
            (yyval.atributos).es_direccion = FALSE;    
            (yyval.atributos).tipo = BOOLEAN;
            o(out, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);
        } else {
            error_semantico("Operandos de OR no boolenanos");
        }}
#line 2021 "y.tab.c"
    break;

  case 61:
#line 362 "alfa.y"
                     {
        if((yyvsp[0].atributos).tipo == BOOLEAN) {
            (yyval.atributos).es_direccion = FALSE;    
            (yyval.atributos).tipo = BOOLEAN;
            no(out, (yyvsp[0].atributos).es_direccion);
        } else {
            error_semantico("Negacion de valor no booleano");
        }}
#line 2034 "y.tab.c"
    break;

  case 62:
#line 370 "alfa.y"
                         {
        int n = (yyvsp[0].atributos).tipo % (MAX_N_TIPOS * MAX_N_CAT);
        int cat = ((yyvsp[0].atributos).tipo / MAX_N_TIPOS) % MAX_N_TIPOS * MAX_N_CAT;
        int tipo = (yyvsp[0].atributos).tipo % MAX_N_TIPOS;

        if (cat == VARIABLE) {
            escribir_operando(out, (yyvsp[0].atributos).nombre, TRUE);
        } else if (cat == LOCAL_VARIABLE) {
            escribirVariableLocal(out, n);
        } else {
            escribirParametro(out, n, n_parametros);
        }

        (yyval.atributos).es_direccion = TRUE;   
        (yyval.atributos).tipo = tipo;
        }
#line 2055 "y.tab.c"
    break;

  case 63:
#line 386 "alfa.y"
                     {
                        (yyval.atributos).es_direccion = FALSE;    
            (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
            escribir_operando(out, (yyvsp[0].atributos).valor, FALSE);
        }
#line 2065 "y.tab.c"
    break;

  case 64:
#line 391 "alfa.y"
                                                               {
            (yyval.atributos).es_direccion = FALSE;  
            (yyval.atributos).tipo = (yyvsp[-1].atributos).tipo;
        }
#line 2074 "y.tab.c"
    break;

  case 65:
#line 395 "alfa.y"
                                                       {
            (yyval.atributos).tipo = (yyvsp[-1].atributos).tipo;
        }
#line 2082 "y.tab.c"
    break;

  case 66:
#line 398 "alfa.y"
                     {fprintf(out, ";R85:\t<exp> ::= <elemento_vector>\n");}
#line 2088 "y.tab.c"
    break;

  case 67:
#line 399 "alfa.y"
                                                                                   {fprintf(out, ";R88:\t<exp> ::= <identificador> ( <lista_expresiones> )\n");}
#line 2094 "y.tab.c"
    break;

  case 68:
#line 402 "alfa.y"
                                               {fprintf(out, ";R89:\t<lista_expresiones> ::= <exp> <resto_lista_expresiones>\n");}
#line 2100 "y.tab.c"
    break;

  case 69:
#line 403 "alfa.y"
                       {fprintf(out, ";R90:\t<lista_expresiones> ::=\n");}
#line 2106 "y.tab.c"
    break;

  case 70:
#line 406 "alfa.y"
                                                              {fprintf(out, ";R91:\t<resto_lista_expresiones> ::= , <exp> <resto_lista_expresiones>\n");}
#line 2112 "y.tab.c"
    break;

  case 71:
#line 407 "alfa.y"
                             {fprintf(out, ";R92:\t<resto_lista_expresiones> ::=\n");}
#line 2118 "y.tab.c"
    break;

  case 72:
#line 410 "alfa.y"
                               {
                if((yyvsp[-2].atributos).tipo == INT && (yyvsp[0].atributos).tipo == INT) {
                    (yyval.atributos).tipo = BOOLEAN;
                    (yyval.atributos).es_direccion = FALSE;
                    igual(out,(yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion, etiqueta);
                    (yyval.atributos).etiqueta = etiqueta;
                    etiqueta++;
                } else {
                    error_semantico("Operandos de comparación no enteros");
                }}
#line 2133 "y.tab.c"
    break;

  case 73:
#line 420 "alfa.y"
                                      {
                if((yyvsp[-2].atributos).tipo == INT && (yyvsp[0].atributos).tipo == INT) {
                    (yyval.atributos).tipo = BOOLEAN;
                    (yyval.atributos).es_direccion = FALSE;
                    distinto(out,(yyvsp[-2].atributos).es_direccion,(yyvsp[0].atributos).es_direccion,(yyval.atributos).etiqueta);
                    (yyval.atributos).etiqueta++;
                } else {
                    error_semantico("Operandos de comparación no enteros");
                }}
#line 2147 "y.tab.c"
    break;

  case 74:
#line 429 "alfa.y"
                                        {
                if((yyvsp[-2].atributos).tipo == INT && (yyvsp[0].atributos).tipo == INT) {
                    (yyval.atributos).tipo = BOOLEAN;
                    (yyval.atributos).es_direccion = FALSE;
                    menor_igual(out,(yyvsp[-2].atributos).es_direccion,(yyvsp[0].atributos).es_direccion,etiqueta);
                    (yyval.atributos).etiqueta = etiqueta;
                    etiqueta++;
                } else {
                    error_semantico("Operandos de comparación no enteros");
                }}
#line 2162 "y.tab.c"
    break;

  case 75:
#line 439 "alfa.y"
                                        {
                if((yyvsp[-2].atributos).tipo == INT && (yyvsp[0].atributos).tipo == INT) {
                    (yyval.atributos).tipo = BOOLEAN;
                    (yyval.atributos).es_direccion = FALSE;
                    mayor_igual(out,(yyvsp[-2].atributos).es_direccion,(yyvsp[0].atributos).es_direccion,etiqueta);
                    (yyval.atributos).etiqueta = etiqueta;
                    etiqueta++;
                } else {
                    error_semantico("Operandos de comparación no enteros");
                }}
#line 2177 "y.tab.c"
    break;

  case 76:
#line 449 "alfa.y"
                                    {
                if((yyvsp[-2].atributos).tipo == INT && (yyvsp[0].atributos).tipo == INT) {
                    (yyval.atributos).tipo = BOOLEAN;
                    (yyval.atributos).es_direccion = FALSE;
                    menor(out,(yyvsp[-2].atributos).es_direccion,(yyvsp[0].atributos).es_direccion,etiqueta);
                    (yyval.atributos).etiqueta = etiqueta;
                    etiqueta++;
                } else {
                    error_semantico("Operandos de comparación no enteros");
                }}
#line 2192 "y.tab.c"
    break;

  case 77:
#line 459 "alfa.y"
                                    {
                if((yyvsp[-2].atributos).tipo == INT && (yyvsp[0].atributos).tipo == INT) {
                    (yyval.atributos).tipo = BOOLEAN;
                    (yyval.atributos).es_direccion = FALSE;
                    mayor(out,(yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion,etiqueta);
                    (yyval.atributos).etiqueta = etiqueta;
                    etiqueta++;
                } else {
                    char str[128];
                    sprintf(str, "Operandos de comparación no enteros (%d y %d)", (yyvsp[-2].atributos).tipo, (yyvsp[0].atributos).tipo);
                    error_semantico(str);
                }}
#line 2209 "y.tab.c"
    break;

  case 78:
#line 473 "alfa.y"
                            {(yyval.atributos).valor = (yyvsp[0].atributos).valor; (yyval.atributos).tipo = BOOLEAN;}
#line 2215 "y.tab.c"
    break;

  case 79:
#line 474 "alfa.y"
                            {(yyval.atributos).valor = (yyvsp[0].atributos).valor; (yyval.atributos).tipo = INT; }
#line 2221 "y.tab.c"
    break;

  case 80:
#line 477 "alfa.y"
                            {(yyval.atributos).tipo = BOOLEAN; (yyval.atributos).valor = yylval.atributos.valor;}
#line 2227 "y.tab.c"
    break;

  case 81:
#line 478 "alfa.y"
                            {(yyval.atributos).tipo = BOOLEAN; (yyval.atributos).valor = yylval.atributos.valor;}
#line 2233 "y.tab.c"
    break;

  case 82:
#line 480 "alfa.y"
                                       {(yyval.atributos).tipo = INT; (yyval.atributos).valor = yylval.atributos.valor;}
#line 2239 "y.tab.c"
    break;

  case 83:
#line 483 "alfa.y"
                                 {
        if(declaracion == VARIABLE) {
            if(stable_insert(table, yylval.atributos.nombre, VARIABLE * MAX_N_TIPOS + tipo_variable) == ERROR) {
                error_semantico("El identificador ya existe.");
            } else {
                declarar_variable(out, yylval.atributos.nombre, tipo_variable, 1);
            }
        } else if (declaracion == NONE) {
            strcpy((yyval.atributos).nombre, yylval.atributos.nombre);
            (yyval.atributos).tipo = stable_search(table, yylval.atributos.nombre); 
            (yyval.atributos).es_direccion = TRUE;
        } else if (declaracion == PARAMETER) {
            if(stable_insert(table, yylval.atributos.nombre, 
                n_parametros*MAX_N_CAT*MAX_N_TIPOS + PARAMETER * MAX_N_TIPOS + tipo_variable) == ERROR) {
                error_semantico("El identificador ya existe.");
            }
            n_parametros++;
        } else if (declaracion == LOCAL_VARIABLE) {
            if(stable_insert(table, yylval.atributos.nombre,
                n_variables_locales*MAX_N_CAT*MAX_N_TIPOS + LOCAL_VARIABLE * MAX_N_TIPOS + tipo_variable) == ERROR) {
                error_semantico("El identificador ya existe.");
            }
            n_variables_locales++;
        }
    }
#line 2269 "y.tab.c"
    break;


#line 2273 "y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 509 "alfa.y"


void error_semantico (char *error_msg)
{
  fprintf(stderr,"****Error semantico en linea %ld: %s\n", yylin, error_msg);
}

void yyerror(const char * s) {
    if(!yy_morph_error) {
        fprintf(stderr, "****Error sintactico en linea: %ld, columna: %ld\n\n\t%s\n", yylin, yycol, s);
    } else {
        fprintf(stderr, "****Error morfologico\n");
    }
}
