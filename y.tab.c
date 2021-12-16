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

#line 90 "y.tab.c"

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
#line 21 "alfa.y"

	atr_info atributos;

#line 226 "y.tab.c"

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   151

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  148

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
       0,    95,    95,    99,   104,   105,   108,   113,   114,   117,
     120,   123,   128,   131,   134,   139,   142,   147,   152,   156,
     161,   162,   165,   166,   169,   174,   175,   178,   179,   182,
     183,   186,   187,   188,   189,   192,   193,   196,   200,   204,
     206,   215,   220,   227,   231,   235,   239,   244,   248,   252,
     256,   264,   272,   280,   288,   296,   304,   312,   320,   325,
     330,   334,   337,   338,   341,   342,   345,   346,   349,   359,
     368,   378,   388,   398,   410,   411,   414,   415,   417,   420
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
  "prog_inicio", "declaraciones", "declaracion", "clase", "clase_escalar",
  "tipo", "clase_vector", "identificadores", "funciones", "f_nombre",
  "f_declaracion", "funcion", "parametros_funcion",
  "resto_parametros_funcion", "parametro_funcion", "declaraciones_funcion",
  "sentencias", "sentencia", "sentencia_simple", "bloque", "asignacion",
  "elemento_vector", "if_exp", "condicional", "if_else_exp", "while",
  "bucle_exp", "bucle", "lectura", "escritura", "retorno_funcion", "exp",
  "lista_expresiones", "resto_lista_expresiones", "comparacion",
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

#define YYPACT_NINF (-31)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-44)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       1,     3,    27,    69,   -31,   -31,   -31,   -31,    73,    39,
      69,    12,   -31,   -31,   -31,    61,    73,     5,    35,     5,
      39,   -31,   -31,    78,    79,    56,    62,    83,    84,    12,
      16,    16,    81,     5,    89,   -31,   -31,    93,    88,   -31,
     107,    16,   100,   -31,   -31,   -31,   -31,    21,    73,   105,
     -31,   -31,    12,   -31,    87,   -31,    16,   -31,   -31,    16,
      16,    16,   -31,   -31,   -31,    33,   -31,   -31,   -31,    -9,
      33,   -31,   -31,   -31,    16,    98,   113,    33,   114,    16,
      16,    12,   118,   122,   -31,   -31,   -31,    33,    97,   120,
      44,   -31,    16,    16,    16,    16,    16,    16,    16,    33,
       5,     5,     5,    85,    33,   -31,   119,    73,   -31,   -31,
      16,    16,    16,    16,    16,    16,   -31,    44,    44,    -7,
      -7,   -31,   -31,    10,   121,   123,   124,   125,   -31,    69,
     122,    33,    33,    33,    33,    33,    33,    16,   -31,   -31,
     131,   -31,   -31,   -31,   -31,   -31,    10,   -31
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     3,     1,    10,    11,     0,    16,
       4,     0,     7,     9,     8,     0,     0,     0,     0,     0,
      16,     5,    79,     0,    13,     0,     0,     0,     0,     0,
       0,     0,     0,    27,     0,    30,    31,     0,     0,    35,
       0,     0,     0,    36,    32,    33,    34,     0,    21,     0,
      15,     6,     0,    78,     0,    17,     0,    44,    47,     0,
       0,     0,    76,    77,    62,    48,    59,    74,    75,    58,
      49,     2,    28,    29,     0,     0,     0,    45,     0,     0,
       0,     0,     0,    23,    19,    14,    12,    40,     0,     0,
      54,    57,     0,     0,     0,     0,     0,     0,    65,    38,
       0,     0,     0,     0,    37,    24,     0,     0,    20,    61,
       0,     0,     0,     0,     0,     0,    60,    50,    51,    52,
      53,    55,    56,    67,     0,     0,     0,     0,    39,    26,
      23,    68,    69,    70,    71,    72,    73,     0,    64,    63,
      41,    42,    46,    25,    18,    22,    67,    66
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -31,   -31,   -31,   -10,   -31,   -31,   -31,    -6,   -31,    90,
     127,   -31,   -31,   -31,   -31,    11,    36,   -31,   -11,   -31,
     -31,   -31,   -31,   -14,   -31,   -31,   -31,   -31,   -31,   -31,
     -31,   -31,   -31,   -30,   -31,     2,   -31,   -31,   -31,   126,
      -5
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     9,    10,    11,    12,    13,    14,    23,
      17,    18,    19,    20,    82,   108,    83,   144,    32,    33,
      34,    35,    36,    64,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    65,   124,   138,    89,    66,    67,    68,
      69
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      21,    70,    15,    37,     1,    37,    24,    98,    49,    79,
      26,    77,    47,    27,    47,    28,    29,    30,    31,    37,
      96,    97,    72,     4,    58,   137,    87,     5,    47,    88,
      90,    91,    59,    92,    93,    94,    95,    96,    97,    79,
      60,    22,    81,    80,    99,    61,    16,    24,    22,   103,
     104,    48,    22,    53,    62,    63,    92,    93,    94,    95,
      96,    97,   117,   118,   119,   120,   121,   122,   123,    94,
      95,    96,    97,     6,     7,     8,   105,     6,     7,    25,
     131,   132,   133,   134,   135,   136,    37,    37,    37,   125,
     126,   127,    51,    53,    52,    47,    47,    47,    55,    56,
      57,    81,    71,    73,   128,    75,    86,   146,    92,    93,
      94,    95,    96,    97,   109,    74,    76,    78,   100,   143,
      92,    93,    94,    95,    96,    97,    84,   110,   111,   112,
     113,   114,   115,   101,   102,   106,   107,   116,   139,   129,
     -43,   145,    85,   130,   140,   141,   142,    50,   147,     0,
       0,    54
};

static const yytype_int16 yycheck[] =
{
      10,    31,     8,    17,     3,    19,    11,    16,    19,    18,
      16,    41,    17,     8,    19,    10,    11,    12,    13,    33,
      27,    28,    33,    20,    29,    15,    56,     0,    33,    59,
      60,    61,    16,    23,    24,    25,    26,    27,    28,    18,
      24,    36,    48,    22,    74,    29,     7,    52,    36,    79,
      80,    16,    36,    37,    38,    39,    23,    24,    25,    26,
      27,    28,    92,    93,    94,    95,    96,    97,    98,    25,
      26,    27,    28,     4,     5,     6,    81,     4,     5,    18,
     110,   111,   112,   113,   114,   115,   100,   101,   102,   100,
     101,   102,    14,    37,    15,   100,   101,   102,    36,    16,
      16,   107,    21,    14,    19,    17,    19,   137,    23,    24,
      25,    26,    27,    28,    17,    22,     9,    17,    20,   129,
      23,    24,    25,    26,    27,    28,    21,    30,    31,    32,
      33,    34,    35,    20,    20,    17,    14,    17,    17,    20,
       9,   130,    52,   107,    21,    21,    21,    20,   146,    -1,
      -1,    25
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    42,    43,    20,     0,     4,     5,     6,    44,
      45,    46,    47,    48,    49,    48,     7,    51,    52,    53,
      54,    44,    36,    50,    81,    18,    48,     8,    10,    11,
      12,    13,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    81,    16,    59,
      51,    14,    15,    37,    80,    36,    16,    16,    81,    16,
      24,    29,    38,    39,    64,    74,    78,    79,    80,    81,
      74,    21,    59,    14,    22,    17,     9,    74,    17,    18,
      22,    48,    55,    57,    21,    50,    19,    74,    74,    77,
      74,    74,    23,    24,    25,    26,    27,    28,    16,    74,
      20,    20,    20,    74,    74,    81,    17,    14,    56,    17,
      30,    31,    32,    33,    34,    35,    17,    74,    74,    74,
      74,    74,    74,    74,    75,    59,    59,    59,    19,    20,
      57,    74,    74,    74,    74,    74,    74,    15,    76,    17,
      21,    21,    21,    44,    58,    56,    74,    76
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    43,    44,    44,    45,    46,    46,    47,
      48,    48,    49,    50,    50,    51,    51,    52,    53,    54,
      55,    55,    56,    56,    57,    58,    58,    59,    59,    60,
      60,    61,    61,    61,    61,    62,    62,    63,    63,    64,
      65,    66,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    75,    75,    76,    76,    77,    77,
      77,    77,    77,    77,    78,    78,    79,    79,    80,    81
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     2,     1,     2,     3,     1,     1,     1,
       1,     1,     5,     1,     3,     2,     0,     3,     6,     3,
       2,     0,     3,     0,     2,     1,     0,     1,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     4,
       3,     5,     5,     5,     2,     2,     5,     2,     2,     2,
       3,     3,     3,     3,     2,     3,     3,     2,     1,     1,
       3,     3,     1,     4,     2,     0,     3,     0,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     1,     1,     1
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
#line 95 "alfa.y"
                                                                          {
    escribir_fin(out);
}
#line 1516 "y.tab.c"
    break;

  case 3:
#line 99 "alfa.y"
                                         {
    table = stable_init();
    escribir_cabecera_bss(out);
}
#line 1525 "y.tab.c"
    break;

  case 4:
#line 104 "alfa.y"
                           {escribir_segmento_codigo(out); fprintf(out, ";R2:\t<declaraciones> ::= <declaracion>\n");}
#line 1531 "y.tab.c"
    break;

  case 5:
#line 105 "alfa.y"
                                         {escribir_segmento_codigo(out); fprintf(out, ";R3:\t<declaraciones> ::= <declaracion> <declaraciones>\n");}
#line 1537 "y.tab.c"
    break;

  case 6:
#line 108 "alfa.y"
                                                  {        
        fprintf(out, ";R4:\t<declaracion> ::= <clase> <identificadores> ;\n");
    }
#line 1545 "y.tab.c"
    break;

  case 7:
#line 113 "alfa.y"
                     {fprintf(out, ";R5:\t<clase> ::= <clase_escalar>\n");}
#line 1551 "y.tab.c"
    break;

  case 8:
#line 114 "alfa.y"
                    {fprintf(out, ";R7:\t<clase> ::= <clase_vector>\n");}
#line 1557 "y.tab.c"
    break;

  case 9:
#line 117 "alfa.y"
                    {fprintf(out, ";R9:\t<clase_escalar> ::= <tipo>\n");}
#line 1563 "y.tab.c"
    break;

  case 10:
#line 120 "alfa.y"
              {
        tipo_variable = INT;
        fprintf(out, ";R10:\t<tipo> ::= int\n");}
#line 1571 "y.tab.c"
    break;

  case 11:
#line 123 "alfa.y"
                  {
        tipo_variable = BOOLEAN;
        fprintf(out, ";R11:\t<tipo> ::= boolean\n");}
#line 1579 "y.tab.c"
    break;

  case 12:
#line 128 "alfa.y"
                                                                                        {fprintf(out, ";R15:\t<clase_vector> ::= array <tipo> [<constante_entera>]\n");}
#line 1585 "y.tab.c"
    break;

  case 13:
#line 131 "alfa.y"
                               {
                    fprintf(out, ";R18:\t<identificadores> ::= <identificador>\n");
                }
#line 1593 "y.tab.c"
    break;

  case 14:
#line 134 "alfa.y"
                                                        {
                    fprintf(out, ";R19:\t<identificadores> ::= <identificador> , <identificadores>\n");
                   }
#line 1601 "y.tab.c"
    break;

  case 15:
#line 139 "alfa.y"
                             {
    escribir_inicio_main(out);
    fprintf(out, ";R20:\t<funciones> ::= <funcion> <funciones>\n");}
#line 1609 "y.tab.c"
    break;

  case 16:
#line 142 "alfa.y"
            {
    escribir_inicio_main(out);
    fprintf(out, ";R21:\t<funciones> ::=\n");}
#line 1617 "y.tab.c"
    break;

  case 17:
#line 147 "alfa.y"
                                              {
            open_ambit(table, yylval.atributos.nombre, FUNCTION);
            fprintf(out, ";R22_1:\t<f_nombre> ::= function <tipo> <identificador> \n");
            }
#line 1626 "y.tab.c"
    break;

  case 18:
#line 152 "alfa.y"
                                                                                                                                  {
            fprintf(out, ";R22_3:\t<f_declaracion> ::= <f_nombre> ( <parametros_funcion> ) { <declaraciones_funcion> \n");
            }
#line 1634 "y.tab.c"
    break;

  case 19:
#line 156 "alfa.y"
                                                   {
            close_ambit(table);
            fprintf(out, ";R22_3:\t<funcion> ::= <declaraciones_funcion> <sentencias> } \n");
            }
#line 1643 "y.tab.c"
    break;

  case 20:
#line 161 "alfa.y"
                                                               {fprintf(out, ";R23:\t<parametros_funcion> ::= <parametro_funcion> <resto_parametros_funcion>\n");}
#line 1649 "y.tab.c"
    break;

  case 21:
#line 162 "alfa.y"
                     {fprintf(out, ";R24:\t<parametros_funcion> ::=\n");}
#line 1655 "y.tab.c"
    break;

  case 22:
#line 165 "alfa.y"
                                                                                    {fprintf(out, ";R25:\t<resto_parametros_funcion> ::= ; <parametro_funcion> <resto_parametros_funcion>\n");}
#line 1661 "y.tab.c"
    break;

  case 23:
#line 166 "alfa.y"
                           {fprintf(out, ";R26:\t<resto_parametros_funcion> ::=\n");}
#line 1667 "y.tab.c"
    break;

  case 24:
#line 169 "alfa.y"
                                      {
                fprintf(out, ";R27:\t<parametro_funcion> ::= <tipo> <identificador>\n");
                }
#line 1675 "y.tab.c"
    break;

  case 25:
#line 174 "alfa.y"
                                     {fprintf(out, ";R28:\t<declaraciones_funcion> ::= <declaraciones>\n");}
#line 1681 "y.tab.c"
    break;

  case 26:
#line 175 "alfa.y"
                        {fprintf(out, ";R29:\t<declaraciones_funcion> ::=\n");}
#line 1687 "y.tab.c"
    break;

  case 27:
#line 178 "alfa.y"
                      {fprintf(out, ";R30:\t<sentencias> ::= <sentencia>\n");}
#line 1693 "y.tab.c"
    break;

  case 28:
#line 179 "alfa.y"
                                 {fprintf(out, ";R31:\t<sentencias> ::= <sentencia> <sentencias>\n");}
#line 1699 "y.tab.c"
    break;

  case 29:
#line 182 "alfa.y"
                                           {fprintf(out, ";R32:\t<sentencia> ::= <sentencia_simple> ;\n");}
#line 1705 "y.tab.c"
    break;

  case 30:
#line 183 "alfa.y"
                  {fprintf(out, ";R33:\t<sentencias> ::= <bloque>\n");}
#line 1711 "y.tab.c"
    break;

  case 31:
#line 186 "alfa.y"
                             {fprintf(out, ";R34:\t<sentencia_simple> ::= <asignacion>\n");}
#line 1717 "y.tab.c"
    break;

  case 32:
#line 187 "alfa.y"
                          {fprintf(out, ";R35:\t<sentencia_simple> ::= <lectura>\n");}
#line 1723 "y.tab.c"
    break;

  case 33:
#line 188 "alfa.y"
                            {fprintf(out, ";R36:\t<sentencia_simple> ::= <escritura>\n");}
#line 1729 "y.tab.c"
    break;

  case 34:
#line 189 "alfa.y"
                                  {fprintf(out, ";R38:\t<sentencia_simple> ::= <retorno_funcion>\n");}
#line 1735 "y.tab.c"
    break;

  case 35:
#line 192 "alfa.y"
                    {fprintf(out, ";R40:\t<bloque> ::= <condicional>\n");}
#line 1741 "y.tab.c"
    break;

  case 36:
#line 193 "alfa.y"
              {fprintf(out, ";R41:\t<bloque> ::= <bucle>\n");}
#line 1747 "y.tab.c"
    break;

  case 37:
#line 196 "alfa.y"
                                             {
        asignar(out, (yyvsp[-2].atributos).nombre, (yyvsp[0].atributos).es_direccion);
        fprintf(out, ";R43:\t<asignacion> ::= <identificador> = <exp>\n");
    }
#line 1756 "y.tab.c"
    break;

  case 38:
#line 200 "alfa.y"
                                               {
              fprintf(out, ";R44:\t<asignacion> ::= <elemento_vector> = <exp>\n");}
#line 1763 "y.tab.c"
    break;

  case 39:
#line 204 "alfa.y"
                                                                             {fprintf(out, ";R48:\t<elemento_vector> = <identificador> [<exp>]\n");}
#line 1769 "y.tab.c"
    break;

  case 40:
#line 206 "alfa.y"
                                           {
            if ((yyvsp[0].atributos).tipo != BOOLEAN){
              error_semantico("Condicional con condicion de tipo int");
              return -1;
            }
            ifthen_inicio(out, (yyvsp[0].atributos).es_direccion, etiqueta);
            etiqueta++;
          }
#line 1782 "y.tab.c"
    break;

  case 41:
#line 215 "alfa.y"
                                                                                         {
                ifthen_fin(out, etiqueta);
                etiqueta++;
                fprintf(out, ";R50:\t<condicional> ::= if ( <exp> ) { <sentencias> }\n");
              }
#line 1792 "y.tab.c"
    break;

  case 42:
#line 221 "alfa.y"
              {
                ifthenelse_fin(out, etiqueta);
                etiqueta++;
                fprintf(out, ";R51:\t<condicional> ::= if ( <exp> ) { <sentencias> } else { <sentencias> }\n");
              }
#line 1802 "y.tab.c"
    break;

  case 43:
#line 227 "alfa.y"
                                                                                        {
            ifthenelse_fin_then(out, etiqueta);
            etiqueta++;
          }
#line 1811 "y.tab.c"
    break;

  case 44:
#line 231 "alfa.y"
                                        {
        while_inicio(out, etiqueta);
      }
#line 1819 "y.tab.c"
    break;

  case 45:
#line 235 "alfa.y"
                     {
              while_exp_pila(out, (yyvsp[0].atributos).es_direccion, etiqueta);
            }
#line 1827 "y.tab.c"
    break;

  case 46:
#line 239 "alfa.y"
                                                                                      {
        while_fin(out, etiqueta);
        fprintf(out, ";R52:\t<bucle> ::= while ( <exp> ) { <sentencias> }\n");
      }
#line 1836 "y.tab.c"
    break;

  case 47:
#line 244 "alfa.y"
                                 {
                leer(out, (yyvsp[0].atributos).nombre, (yyvsp[0].atributos).tipo);
            }
#line 1844 "y.tab.c"
    break;

  case 48:
#line 248 "alfa.y"
                          {
                escribir(out, (yyvsp[0].atributos).es_direccion, (yyvsp[0].atributos).tipo);
            }
#line 1852 "y.tab.c"
    break;

  case 49:
#line 252 "alfa.y"
                                {
    retornarFuncion(out, (yyvsp[0].atributos).es_direccion);
    fprintf(out, ";R61:\t<retorno_funcion> ::= return <exp>\n");}
#line 1860 "y.tab.c"
    break;

  case 50:
#line 256 "alfa.y"
                             {
        if((yyvsp[-2].atributos).tipo == INT && (yyvsp[0].atributos).tipo == INT) {
            (yyval.atributos).tipo = INT;
            (yyval.atributos).es_direccion = FALSE;
            sumar(out, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);
        } else {
            error_semantico("Operandos de la suma no enteros");
        }}
#line 1873 "y.tab.c"
    break;

  case 51:
#line 264 "alfa.y"
                             {
       if((yyvsp[-2].atributos).tipo == INT && (yyvsp[0].atributos).tipo == INT) {
            (yyval.atributos).tipo = INT;
            (yyval.atributos).es_direccion = FALSE;    
            restar(out, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);
        } else {
            error_semantico("Operandos de la resta no enteros");
        }}
#line 1886 "y.tab.c"
    break;

  case 52:
#line 272 "alfa.y"
                             {
        if((yyvsp[-2].atributos).tipo == INT && (yyvsp[0].atributos).tipo == INT) {
            (yyval.atributos).es_direccion = FALSE;    
            (yyval.atributos).tipo = INT;
            dividir(out, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);
        } else {
            error_semantico("Operandos de la división no enteros");
        }}
#line 1899 "y.tab.c"
    break;

  case 53:
#line 280 "alfa.y"
                             {
        if((yyvsp[-2].atributos).tipo == INT && (yyvsp[0].atributos).tipo == INT) {
            (yyval.atributos).es_direccion = FALSE;    
            (yyval.atributos).tipo = INT;
            multiplicar(out, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);
        } else {
            error_semantico("Operandos de la multiplicacion no enteros");
        }}
#line 1912 "y.tab.c"
    break;

  case 54:
#line 288 "alfa.y"
                     {
        if((yyvsp[0].atributos).tipo == INT) {
            (yyval.atributos).es_direccion = FALSE;    
            (yyval.atributos).tipo = INT;
            cambiar_signo(out, (yyvsp[0].atributos).es_direccion);
        } else {
            error_semantico("Valor negativo no entero");
        }}
#line 1925 "y.tab.c"
    break;

  case 55:
#line 296 "alfa.y"
                     {
        if((yyvsp[-2].atributos).tipo == BOOLEAN && (yyvsp[0].atributos).tipo == BOOLEAN) {
            (yyval.atributos).es_direccion = FALSE;    
            (yyval.atributos).tipo = BOOLEAN;
            y(out, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);
        } else {
            error_semantico("Operandos de AND no booleanos");
        }}
#line 1938 "y.tab.c"
    break;

  case 56:
#line 304 "alfa.y"
                     {
        if((yyvsp[-2].atributos).tipo == BOOLEAN && (yyvsp[0].atributos).tipo == BOOLEAN) {
            (yyval.atributos).es_direccion = FALSE;    
            (yyval.atributos).tipo = BOOLEAN;
            o(out, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);
        } else {
            error_semantico("Operandos de OR no boolenanos");
        }}
#line 1951 "y.tab.c"
    break;

  case 57:
#line 312 "alfa.y"
                     {
        if((yyvsp[0].atributos).tipo == BOOLEAN) {
            (yyval.atributos).es_direccion = FALSE;    
            (yyval.atributos).tipo = BOOLEAN;
            no(out, (yyvsp[0].atributos).es_direccion);
        } else {
            error_semantico("Negacion de valor no booleano");
        }}
#line 1964 "y.tab.c"
    break;

  case 58:
#line 320 "alfa.y"
                     {
            (yyval.atributos).es_direccion = TRUE;    
            (yyval.atributos).tipo = stable_search(table, (yyvsp[0].atributos).nombre);
            escribir_operando(out, (yyvsp[0].atributos).nombre, TRUE);
        }
#line 1974 "y.tab.c"
    break;

  case 59:
#line 325 "alfa.y"
                     {
            (yyval.atributos).es_direccion = FALSE;    
            (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
            escribir_operando(out, (yyvsp[0].atributos).valor, FALSE);
        }
#line 1984 "y.tab.c"
    break;

  case 60:
#line 330 "alfa.y"
                                                               {
            (yyval.atributos).es_direccion = FALSE;  
            (yyval.atributos).tipo = (yyvsp[-1].atributos).tipo;
        }
#line 1993 "y.tab.c"
    break;

  case 61:
#line 334 "alfa.y"
                                                       {
            (yyval.atributos).tipo = (yyvsp[-1].atributos).tipo;
        }
#line 2001 "y.tab.c"
    break;

  case 62:
#line 337 "alfa.y"
                     {fprintf(out, ";R85:\t<exp> ::= <elemento_vector>\n");}
#line 2007 "y.tab.c"
    break;

  case 63:
#line 338 "alfa.y"
                                                                                   {fprintf(out, ";R88:\t<exp> ::= <identificador> ( <lista_expresiones> )\n");}
#line 2013 "y.tab.c"
    break;

  case 64:
#line 341 "alfa.y"
                                               {fprintf(out, ";R89:\t<lista_expresiones> ::= <exp> <resto_lista_expresiones>\n");}
#line 2019 "y.tab.c"
    break;

  case 65:
#line 342 "alfa.y"
                       {fprintf(out, ";R90:\t<lista_expresiones> ::=\n");}
#line 2025 "y.tab.c"
    break;

  case 66:
#line 345 "alfa.y"
                                                              {fprintf(out, ";R91:\t<resto_lista_expresiones> ::= , <exp> <resto_lista_expresiones>\n");}
#line 2031 "y.tab.c"
    break;

  case 67:
#line 346 "alfa.y"
                             {fprintf(out, ";R92:\t<resto_lista_expresiones> ::=\n");}
#line 2037 "y.tab.c"
    break;

  case 68:
#line 349 "alfa.y"
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
#line 2052 "y.tab.c"
    break;

  case 69:
#line 359 "alfa.y"
                                      {
                if((yyvsp[-2].atributos).tipo == INT && (yyvsp[0].atributos).tipo == INT) {
                    (yyval.atributos).tipo = BOOLEAN;
                    (yyval.atributos).es_direccion = FALSE;
                    distinto(out,(yyvsp[-2].atributos).es_direccion,(yyvsp[0].atributos).es_direccion,(yyval.atributos).etiqueta);
                    (yyval.atributos).etiqueta++;
                } else {
                    error_semantico("Operandos de comparación no enteros");
                }}
#line 2066 "y.tab.c"
    break;

  case 70:
#line 368 "alfa.y"
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
#line 2081 "y.tab.c"
    break;

  case 71:
#line 378 "alfa.y"
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
#line 2096 "y.tab.c"
    break;

  case 72:
#line 388 "alfa.y"
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
#line 2111 "y.tab.c"
    break;

  case 73:
#line 398 "alfa.y"
                                    {
                if((yyvsp[-2].atributos).tipo == INT && (yyvsp[0].atributos).tipo == INT) {
                    (yyval.atributos).tipo = BOOLEAN;
                    (yyval.atributos).es_direccion = FALSE;
                    mayor(out,(yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion,etiqueta);
                    (yyval.atributos).etiqueta = etiqueta;
                    etiqueta++;
                } else {
                    error_semantico("Operandos de comparación no enteros");
                }}
#line 2126 "y.tab.c"
    break;

  case 74:
#line 410 "alfa.y"
                            {(yyval.atributos).valor = (yyvsp[0].atributos).valor; (yyval.atributos).tipo = BOOLEAN;}
#line 2132 "y.tab.c"
    break;

  case 75:
#line 411 "alfa.y"
                            {(yyval.atributos).valor = (yyvsp[0].atributos).valor; (yyval.atributos).tipo = INT; }
#line 2138 "y.tab.c"
    break;

  case 76:
#line 414 "alfa.y"
                            {(yyval.atributos).tipo = BOOLEAN; (yyval.atributos).valor = yylval.atributos.valor;}
#line 2144 "y.tab.c"
    break;

  case 77:
#line 415 "alfa.y"
                            {(yyval.atributos).tipo = BOOLEAN; (yyval.atributos).valor = yylval.atributos.valor;}
#line 2150 "y.tab.c"
    break;

  case 78:
#line 417 "alfa.y"
                                       {(yyval.atributos).tipo = INT; (yyval.atributos).valor = yylval.atributos.valor;}
#line 2156 "y.tab.c"
    break;

  case 79:
#line 420 "alfa.y"
                                 {
    if(stable_insert(table, yylval.atributos.nombre, tipo_variable) == ERROR) {
        error_semantico("El identificador ya existe.");
    }

    declarar_variable(out, yylval.atributos.nombre, tipo_variable, 1);}
#line 2167 "y.tab.c"
    break;


#line 2171 "y.tab.c"

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
#line 428 "alfa.y"


void error_semantico (char *error_msg)
{
  fprintf(stderr,"****Error semantico en linea %ld: %s\n", yylin, error_msg);
}

void yyerror(const char * s) {
    if(!yy_morph_error) {
        printf("****Error sintactico en linea: %ld, columna: %ld\n\n\t%s\n", yylin, yycol, s);
    } else {
        printf("****Error morfologico\n");
    }
}
