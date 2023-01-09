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
#line 1 "syntax.y"

    #include <string>
    #include <unordered_map>
    #include "lex.yy.c"
    #include "../include/syntaxTree.hpp"
    #include "../include/ir-util.hpp"
    #include "../include/mips32-util.hpp"
    #include "../include/mips32.hpp"

    using std::string;
    using std::unordered_map;
    #define YY_NO_UNPUT
    void yyerror(const char *s);
    bool type_A_error = 0;
    bool type_B_error = 0;
    void lineinfor(void);
    Node* root_node;
    unordered_map<string,Type*> symbolTable;
    vector<TAC *> ir_tac;
    unordered_map<string, int> id_int_mapper;
    unordered_map<int, string> int_reg_mapper;
    unordered_map<string, string> param_id_reg_mapper;
    bool has_loop = false;
    extern int isError;
    #define PARSER_error_OUTPUT stdout

    mips32 mips32;


#line 100 "syntax.tab.c"

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
#ifndef YY_YY_SYNTAX_TAB_H_INCLUDED
# define YY_YY_SYNTAX_TAB_H_INCLUDED
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
    INT = 258,
    FLOAT = 259,
    CHAR = 260,
    ID = 261,
    TYPE = 262,
    STRUCT = 263,
    IF = 264,
    ELSE = 265,
    WHILE = 266,
    FOR = 267,
    RETURN = 268,
    DOT = 269,
    SEMI = 270,
    COMMA = 271,
    ASSIGN = 272,
    LT = 273,
    LE = 274,
    GT = 275,
    GE = 276,
    NE = 277,
    EQ = 278,
    PLUS = 279,
    MINUS = 280,
    MUL = 281,
    DIV = 282,
    AND = 283,
    OR = 284,
    NOT = 285,
    LP = 286,
    RP = 287,
    LB = 288,
    RB = 289,
    LC = 290,
    RC = 291,
    UNKNOWN = 292,
    UELSE = 293,
    UMINUS = 294
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 33 "syntax.y"

    Node* node;

#line 196 "syntax.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_SYNTAX_TAB_H_INCLUDED  */



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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   346

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  138

#define YYUNDEFTOK  2
#define YYMAXUTOK   294


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
      35,    36,    37,    38,    39
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    59,    59,    65,    66,    69,    70,    74,    77,    85,
      89,    90,    94,    97,   101,   102,   106,   107,   109,   110,
     111,   113,   114,   116,   120,   122,   123,   125,   126,   127,
     128,   129,   130,   131,   132,   136,   137,   140,   141,   146,
     147,   149,   150,   155,   156,   158,   163,   167,   171,   175,
     179,   183,   187,   191,   195,   199,   203,   207,   211,   215,
     220,   225,   229,   235,   241,   246,   250,   255,   259,   263,
     267
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "CHAR", "ID", "TYPE",
  "STRUCT", "IF", "ELSE", "WHILE", "FOR", "RETURN", "DOT", "SEMI", "COMMA",
  "ASSIGN", "LT", "LE", "GT", "GE", "NE", "EQ", "PLUS", "MINUS", "MUL",
  "DIV", "AND", "OR", "NOT", "LP", "RP", "LB", "RB", "LC", "RC", "UNKNOWN",
  "UELSE", "UMINUS", "$accept", "Program", "ExtDefList", "ExtDef",
  "CompFunDec", "ExtDecList", "Specifier", "StructSpecifier", "VarDec",
  "FunDec", "VarList", "ParamDec", "CompSt", "StmtList", "Stmt", "DefList",
  "Def", "DecList", "Dec", "Args", "Exp", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294
};
# endif

#define YYPACT_NINF (-71)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-4)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      91,     6,   -71,    10,    63,   -71,    91,    29,    -1,   -71,
     -71,    50,    -3,    36,   -71,   -71,    25,   -71,    42,   -71,
      59,   -71,   -71,     6,    73,    25,     6,    47,    25,   101,
     -71,   -71,    45,    61,    -2,    60,    65,   -71,   -71,   -71,
      69,    72,    74,    75,    82,    82,    82,    82,   -71,   -71,
      78,    47,   141,   -71,   -71,   -71,     6,    79,    94,   -71,
     -71,    82,   -71,   -71,     6,    64,    82,    82,    82,   103,
     283,    -5,   158,   -71,   -71,   109,   -71,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    83,   -71,    25,   283,   -71,   -71,    16,   178,   195,
     212,   232,   -71,   -71,   -71,   -71,   283,   313,   313,   313,
     313,   313,   313,    -6,    -6,    -5,    -5,   299,   299,   120,
     -71,   -71,   -71,    82,    47,    47,    82,   -71,   -71,   125,
     -71,   249,    47,    82,   -71,   266,    47,   -71
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    12,     0,     0,     2,     0,     0,     0,    13,
      16,     0,    10,    15,     1,     4,    35,     8,    16,     7,
       0,     9,     5,     0,     0,    35,     0,    25,    35,     0,
       6,    11,     0,     0,    41,     0,    39,    67,    68,    69,
      66,     0,     0,     0,     0,     0,     0,     0,    70,    28,
       0,    25,     0,    36,    18,    20,     0,     0,    22,    17,
      14,     0,    37,    38,     0,     0,     0,     0,     0,     0,
      59,    60,     0,    24,    26,     0,    27,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    23,    19,     0,    42,    40,    63,     0,    44,     0,
       0,     0,    29,    30,    58,    65,    45,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    46,    47,     0,
      21,    61,    62,     0,     0,     0,     0,    64,    43,    31,
      33,     0,     0,     0,    32,     0,     0,    34
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -71,   -71,   144,   -71,   -71,     3,     0,   -71,    -7,   -71,
      58,   -71,   145,   106,   -70,   -18,   -71,   107,   -71,    66,
     -43
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,     7,    11,    26,     9,    12,    21,
      57,    58,    49,    50,    51,    27,    28,    35,    36,    97,
      52
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       8,    69,    70,    71,    72,    18,     8,    33,    75,    75,
      53,    20,    10,    23,    19,    61,    13,   121,    94,    34,
      86,    87,    98,    99,   100,   101,    31,    90,    90,    56,
      24,    24,     2,     3,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   122,    91,
      37,    38,    39,    40,   129,   130,    41,    34,    42,    43,
      44,    62,   134,    14,    16,    22,   137,    37,    38,    39,
      40,    25,    45,    29,    30,    63,    32,    46,    47,    59,
      98,    64,    16,   131,    48,    37,    38,    39,    40,    45,
     135,    -3,     1,    56,    46,    47,    96,    60,     2,     3,
      65,    48,    54,    66,   102,    67,    68,    45,     2,     3,
      93,    92,    46,    47,    73,   105,    24,    75,   103,    48,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    55,    75,   132,    90,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      15,   120,    17,    90,   127,    75,    76,    74,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    95,    75,     0,    90,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,     0,   128,
     104,    90,    75,     0,   123,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,     0,    75,
       0,    90,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,     0,    75,   124,    90,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,     0,     0,   125,    90,    75,   126,     0,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,     0,    75,   133,    90,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,     0,
      75,     0,    90,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,     0,    75,   136,    90,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    75,     0,     0,    90,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    75,     0,     0,
       0,     0,    90,     0,     0,     0,     0,    84,    85,    86,
      87,     0,     0,     0,     0,     0,    90
};

static const yytype_int16 yycheck[] =
{
       0,    44,    45,    46,    47,     6,     6,    25,    14,    14,
      28,     8,     6,    16,    15,    17,     6,     1,    61,    26,
      26,    27,    65,    66,    67,    68,    23,    33,    33,    29,
      33,    33,     7,     8,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    32,    56,
       3,     4,     5,     6,   124,   125,     9,    64,    11,    12,
      13,     1,   132,     0,    35,    15,   136,     3,     4,     5,
       6,    35,    25,    31,    15,    15,     3,    30,    31,    34,
     123,    16,    35,   126,    37,     3,     4,     5,     6,    25,
     133,     0,     1,    93,    30,    31,    32,    36,     7,     8,
      31,    37,     1,    31,     1,    31,    31,    25,     7,     8,
      16,    32,    30,    31,    36,     6,    33,    14,    15,    37,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    32,    14,    10,    33,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
       6,    93,     7,    33,    34,    14,    15,    51,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    64,    14,    -1,    33,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    -1,   123,
      32,    33,    14,    -1,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    -1,    14,
      -1,    33,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    14,    32,    33,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    -1,    -1,    32,    33,    14,    15,    -1,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    -1,    14,    15,    33,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    -1,
      14,    -1,    33,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    -1,    14,    32,    33,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    14,    -1,    -1,    33,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    14,    -1,    -1,
      -1,    -1,    33,    -1,    -1,    -1,    -1,    24,    25,    26,
      27,    -1,    -1,    -1,    -1,    -1,    33
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     7,     8,    41,    42,    43,    44,    46,    47,
       6,    45,    48,     6,     0,    42,    35,    52,     6,    15,
      45,    49,    15,    16,    33,    35,    46,    55,    56,    31,
      15,    45,     3,    55,    48,    57,    58,     3,     4,     5,
       6,     9,    11,    12,    13,    25,    30,    31,    37,    52,
      53,    54,    60,    55,     1,    32,    46,    50,    51,    34,
      36,    17,     1,    15,    16,    31,    31,    31,    31,    60,
      60,    60,    60,    36,    53,    14,    15,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      33,    48,    32,    16,    60,    57,    32,    59,    60,    60,
      60,    60,     1,    15,    32,     6,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      50,     1,    32,    16,    32,    32,    15,    34,    59,    54,
      54,    60,    10,    15,    54,    60,    32,    54
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    40,    41,    42,    42,    43,    43,    43,    43,    44,
      45,    45,    46,    46,    47,    47,    48,    48,    49,    49,
      49,    50,    50,    51,    52,    53,    53,    54,    54,    54,
      54,    54,    54,    54,    54,    55,    55,    56,    56,    57,
      57,    58,    58,    59,    59,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     3,     3,     2,     2,     2,
       1,     3,     1,     1,     5,     2,     1,     4,     3,     4,
       3,     3,     1,     2,     4,     0,     2,     2,     1,     3,
       3,     5,     7,     5,     9,     0,     2,     3,     3,     1,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     4,     4,     3,     4,     3,     1,     1,     1,     1,
       1
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


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  *++yylsp = yylloc;

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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 59 "syntax.y"
                   {
    (yyval.node) = new Node(Node_Type::MEDIAN,"Program","",(yyloc).first_line);
    (yyval.node)->addChild({(yyvsp[0].node)});
    root_node = (yyval.node);
}
#line 1619 "syntax.tab.c"
    break;

  case 3:
#line 65 "syntax.y"
                                              {(yyval.node)=new Node(Node_Type::NOTHING,"ExtDefList","",(yyloc).first_line);}
#line 1625 "syntax.tab.c"
    break;

  case 4:
#line 66 "syntax.y"
                                              {(yyval.node)=new Node(Node_Type::MEDIAN,"ExtDefList","",(yyloc).first_line); (yyval.node)->addChild({(yyvsp[-1].node),(yyvsp[0].node)});}
#line 1631 "syntax.tab.c"
    break;

  case 5:
#line 69 "syntax.y"
                                   {printf("Error type B at Line %d: Missing specifier\n",(yyloc).first_line); type_B_error=1;}
#line 1637 "syntax.tab.c"
    break;

  case 6:
#line 70 "syntax.y"
                                   {(yyval.node)=new Node(Node_Type::MEDIAN,"ExtDef","",(yyloc).first_line); 
                                    (yyval.node)->addChild({(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)});
                                    ExtDefVisit_SES((yyval.node));
                                   }
#line 1646 "syntax.tab.c"
    break;

  case 7:
#line 74 "syntax.y"
                                   {(yyval.node)=new Node(Node_Type::MEDIAN,"ExtDef","",(yyloc).first_line); 
                                    (yyval.node)->addChild({(yyvsp[-1].node),(yyvsp[0].node)}); 
                                    ExtDefVisit_SS((yyval.node));}
#line 1654 "syntax.tab.c"
    break;

  case 8:
#line 77 "syntax.y"
                                   {(yyval.node)=new Node(Node_Type::MEDIAN,"ExtDef","",(yyloc).first_line); 
                                    (yyval.node)->addChild({(yyvsp[-1].node)->child[0], (yyvsp[-1].node)->child[1], (yyvsp[0].node)});
                                    checkReturnType((yyval.node));
                                   }
#line 1663 "syntax.tab.c"
    break;

  case 9:
#line 85 "syntax.y"
                              { (yyval.node)=new Node(Node_Type::MEDIAN,"CompFunDec","",(yyloc).first_line);
                                (yyval.node)->addChild({(yyvsp[-1].node),(yyvsp[0].node)});
                                ExtDefVisit_SFC((yyval.node));
                              }
#line 1672 "syntax.tab.c"
    break;

  case 10:
#line 89 "syntax.y"
                                              {(yyval.node)=new Node(Node_Type::MEDIAN,"ExtDecList","",(yyloc).first_line); (yyval.node)->addChild({(yyvsp[0].node)});}
#line 1678 "syntax.tab.c"
    break;

  case 11:
#line 90 "syntax.y"
                                              {(yyval.node)=new Node(Node_Type::MEDIAN,"ExtDecList","",(yyloc).first_line); (yyval.node)->addChild({(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)});}
#line 1684 "syntax.tab.c"
    break;

  case 12:
#line 94 "syntax.y"
                  {(yyval.node)=new Node(Node_Type::MEDIAN,"Specifier","",(yyloc).first_line); 
                   (yyval.node)->addChild({(yyvsp[0].node)});
                  }
#line 1692 "syntax.tab.c"
    break;

  case 13:
#line 97 "syntax.y"
                      {(yyval.node)=new Node(Node_Type::MEDIAN,"Specifier","",(yyloc).first_line); 
                       (yyval.node)->addChild({(yyvsp[0].node)});
                       }
#line 1700 "syntax.tab.c"
    break;

  case 14:
#line 101 "syntax.y"
                                              {(yyval.node)=new Node(Node_Type::MEDIAN,"StructSpecifier","",(yyloc).first_line); (yyval.node)->addChild({(yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)});}
#line 1706 "syntax.tab.c"
    break;

  case 15:
#line 102 "syntax.y"
                                              {(yyval.node)=new Node(Node_Type::MEDIAN,"StructSpecifier","",(yyloc).first_line); (yyval.node)->addChild({(yyvsp[-1].node),(yyvsp[0].node)});}
#line 1712 "syntax.tab.c"
    break;

  case 16:
#line 106 "syntax.y"
                                              {(yyval.node)=new Node(Node_Type::MEDIAN,"VarDec","",(yyloc).first_line); (yyval.node)->addChild({(yyvsp[0].node)});}
#line 1718 "syntax.tab.c"
    break;

  case 17:
#line 107 "syntax.y"
                                              {(yyval.node)=new Node(Node_Type::MEDIAN,"VarDec","",(yyloc).first_line); (yyval.node)->addChild({(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)});}
#line 1724 "syntax.tab.c"
    break;

  case 18:
#line 109 "syntax.y"
                                              {(yyval.node)=new Node(Node_Type::MEDIAN,"FunDec","",(yyloc).first_line); (yyval.node)->addChild({(yyvsp[-2].node),(yyvsp[-1].node)}); printf("Error type B at Line %d: Missing closing parenthesis ')'\n",(yyloc).first_line); type_B_error=1;}
#line 1730 "syntax.tab.c"
    break;

  case 19:
#line 110 "syntax.y"
                                              {(yyval.node)=new Node(Node_Type::MEDIAN,"FunDec","",(yyloc).first_line); (yyval.node)->addChild({(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)});FunDecVisit((yyval.node));}
#line 1736 "syntax.tab.c"
    break;

  case 20:
#line 111 "syntax.y"
                                              {(yyval.node)=new Node(Node_Type::MEDIAN,"FunDec","",(yyloc).first_line); (yyval.node)->addChild({(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)});FunDecVisit((yyval.node));}
#line 1742 "syntax.tab.c"
    break;

  case 21:
#line 113 "syntax.y"
                                                  {(yyval.node)=new Node(Node_Type::MEDIAN,"VarList","",(yyloc).first_line); (yyval.node)->addChild({(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)});}
#line 1748 "syntax.tab.c"
    break;

  case 22:
#line 114 "syntax.y"
                                              {(yyval.node)=new Node(Node_Type::MEDIAN,"VarList","",(yyloc).first_line); (yyval.node)->addChild({(yyvsp[0].node)});}
#line 1754 "syntax.tab.c"
    break;

  case 23:
#line 116 "syntax.y"
                                              {(yyval.node)=new Node(Node_Type::MEDIAN,"ParamDec","",(yyloc).first_line); (yyval.node)->addChild({(yyvsp[-1].node),(yyvsp[0].node)});}
#line 1760 "syntax.tab.c"
    break;

  case 24:
#line 120 "syntax.y"
                                              {(yyval.node)=new Node(Node_Type::MEDIAN,"CompSt","",(yyloc).first_line); (yyval.node)->addChild({(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)});}
#line 1766 "syntax.tab.c"
    break;

  case 25:
#line 122 "syntax.y"
                                              {(yyval.node)=new Node(Node_Type::NOTHING,"StmtList","",(yyloc).first_line);}
#line 1772 "syntax.tab.c"
    break;

  case 26:
#line 123 "syntax.y"
                                              {(yyval.node)=new Node(Node_Type::MEDIAN,"StmtList","",(yyloc).first_line); (yyval.node)->addChild({(yyvsp[-1].node),(yyvsp[0].node)});}
#line 1778 "syntax.tab.c"
    break;

  case 27:
#line 125 "syntax.y"
                                              {(yyval.node)=new Node(Node_Type::MEDIAN,"Stmt","",(yyloc).first_line); (yyval.node)->addChild({(yyvsp[-1].node),(yyvsp[0].node)});}
#line 1784 "syntax.tab.c"
    break;

  case 28:
#line 126 "syntax.y"
                                              {(yyval.node)=new Node(Node_Type::MEDIAN,"Stmt","",(yyloc).first_line); (yyval.node)->addChild({(yyvsp[0].node)});}
#line 1790 "syntax.tab.c"
    break;

  case 29:
#line 127 "syntax.y"
                                              {(yyval.node)=new Node(Node_Type::MEDIAN,"Stmt","",(yyloc).first_line); (yyval.node)->addChild({(yyvsp[-2].node),(yyvsp[-1].node)}); printf("Error type B at Line %d: Missing semicolon ';'\n",(yyloc).first_line); type_B_error = 1;}
#line 1796 "syntax.tab.c"
    break;

  case 30:
#line 128 "syntax.y"
                                              {(yyval.node)=new Node(Node_Type::MEDIAN,"Stmt","",(yyloc).first_line); (yyval.node)->addChild({(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)});}
#line 1802 "syntax.tab.c"
    break;

  case 31:
#line 129 "syntax.y"
                                              {(yyval.node)=new Node(Node_Type::MEDIAN,"Stmt","",(yyloc).first_line); (yyval.node)->addChild({(yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)});}
#line 1808 "syntax.tab.c"
    break;

  case 32:
#line 130 "syntax.y"
                                              {(yyval.node)=new Node(Node_Type::MEDIAN,"Stmt","",(yyloc).first_line); (yyval.node)->addChild({(yyvsp[-6].node),(yyvsp[-5].node),(yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)});}
#line 1814 "syntax.tab.c"
    break;

  case 33:
#line 131 "syntax.y"
                                              {(yyval.node)=new Node(Node_Type::MEDIAN,"Stmt","",(yyloc).first_line); (yyval.node)->addChild({(yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)});}
#line 1820 "syntax.tab.c"
    break;

  case 34:
#line 132 "syntax.y"
                                              {(yyval.node)=new Node(Node_Type::MEDIAN,"Stmt","",(yyloc).first_line); (yyval.node)->addChild({(yyvsp[-8].node),(yyvsp[-7].node),(yyvsp[-6].node),(yyvsp[-5].node),(yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)});}
#line 1826 "syntax.tab.c"
    break;

  case 35:
#line 136 "syntax.y"
                                              {(yyval.node)=new Node(Node_Type::NOTHING,"DefList","",(yyloc).first_line);}
#line 1832 "syntax.tab.c"
    break;

  case 36:
#line 137 "syntax.y"
                                              {(yyval.node)=new Node(Node_Type::MEDIAN,"DefList","",(yyloc).first_line); (yyval.node)->addChild({(yyvsp[-1].node),(yyvsp[0].node)});}
#line 1838 "syntax.tab.c"
    break;

  case 37:
#line 140 "syntax.y"
                                              {(yyval.node)=new Node(Node_Type::MEDIAN,"Def","",(yyloc).first_line); (yyval.node)->addChild({(yyvsp[-2].node),(yyvsp[-1].node)}); printf("Error type B at Line %d: Missing semicolon ';'\n",(yyloc).first_line); type_B_error=1;}
#line 1844 "syntax.tab.c"
    break;

  case 38:
#line 141 "syntax.y"
                            {(yyval.node)=new Node(Node_Type::MEDIAN,"Def","",(yyloc).first_line); 
                             (yyval.node)->addChild({(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)});
                             defVisit((yyval.node));
                            }
#line 1853 "syntax.tab.c"
    break;

  case 39:
#line 146 "syntax.y"
                                              {(yyval.node)=new Node(Node_Type::MEDIAN,"DecList","",(yyloc).first_line); (yyval.node)->addChild({(yyvsp[0].node)});}
#line 1859 "syntax.tab.c"
    break;

  case 40:
#line 147 "syntax.y"
                                              {(yyval.node)=new Node(Node_Type::MEDIAN,"DecList","",(yyloc).first_line); (yyval.node)->addChild({(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)});}
#line 1865 "syntax.tab.c"
    break;

  case 41:
#line 149 "syntax.y"
                                              {(yyval.node)=new Node(Node_Type::MEDIAN,"Dec","",(yyloc).first_line); (yyval.node)->addChild({(yyvsp[0].node)});}
#line 1871 "syntax.tab.c"
    break;

  case 42:
#line 150 "syntax.y"
                         {(yyval.node)=new Node(Node_Type::MEDIAN,"Dec","",(yyloc).first_line); 
                          (yyval.node)->addChild({(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)});
                         }
#line 1879 "syntax.tab.c"
    break;

  case 43:
#line 155 "syntax.y"
                     {(yyval.node)=new Node(Node_Type::MEDIAN,"Args","",(yyloc).first_line); (yyval.node)->addChild({(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)});}
#line 1885 "syntax.tab.c"
    break;

  case 44:
#line 156 "syntax.y"
                     {(yyval.node)=new Node(Node_Type::MEDIAN,"Args","",(yyloc).first_line); (yyval.node)->addChild({(yyvsp[0].node)});}
#line 1891 "syntax.tab.c"
    break;

  case 45:
#line 158 "syntax.y"
                    {(yyval.node)=new Node(Node_Type::MEDIAN,"Exp","",(yyloc).first_line); 
                      (yyval.node)->addChild({(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)});
                      checkRvalueInLeftSide((yyval.node));
                      checkAssignmentTypeMatching((yyval.node),(yyvsp[-2].node),(yyvsp[0].node));
                    }
#line 1901 "syntax.tab.c"
    break;

  case 46:
#line 163 "syntax.y"
                    {(yyval.node)=new Node(Node_Type::MEDIAN,"Exp","",(yyloc).first_line);
                     (yyval.node)->addChild({(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)});
                     setBoolOperatorType((yyval.node),(yyvsp[-2].node),(yyvsp[0].node));
                    }
#line 1910 "syntax.tab.c"
    break;

  case 47:
#line 167 "syntax.y"
                    {(yyval.node)=new Node(Node_Type::MEDIAN,"Exp","",(yyloc).first_line); 
                     (yyval.node)->addChild({(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)});
                     setBoolOperatorType((yyval.node),(yyvsp[-2].node),(yyvsp[0].node));
                    }
#line 1919 "syntax.tab.c"
    break;

  case 48:
#line 171 "syntax.y"
                    {(yyval.node)=new Node(Node_Type::MEDIAN,"Exp","",(yyloc).first_line); 
                     (yyval.node)->addChild({(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)});
                     setCompareOperatorType((yyval.node),(yyvsp[-2].node),(yyvsp[0].node));
                    }
#line 1928 "syntax.tab.c"
    break;

  case 49:
#line 175 "syntax.y"
                    {(yyval.node)=new Node(Node_Type::MEDIAN,"Exp","",(yyloc).first_line); 
                     (yyval.node)->addChild({(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)});
                     setCompareOperatorType((yyval.node),(yyvsp[-2].node),(yyvsp[0].node));
                    }
#line 1937 "syntax.tab.c"
    break;

  case 50:
#line 179 "syntax.y"
                    {(yyval.node)=new Node(Node_Type::MEDIAN,"Exp","",(yyloc).first_line); 
                     (yyval.node)->addChild({(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)});
                     setCompareOperatorType((yyval.node),(yyvsp[-2].node),(yyvsp[0].node));
                    }
#line 1946 "syntax.tab.c"
    break;

  case 51:
#line 183 "syntax.y"
                    {(yyval.node)=new Node(Node_Type::MEDIAN,"Exp","",(yyloc).first_line); 
                     (yyval.node)->addChild({(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)});
                     setCompareOperatorType((yyval.node),(yyvsp[-2].node),(yyvsp[0].node));
                    }
#line 1955 "syntax.tab.c"
    break;

  case 52:
#line 187 "syntax.y"
                    {(yyval.node)=new Node(Node_Type::MEDIAN,"Exp","",(yyloc).first_line); 
                     (yyval.node)->addChild({(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)});
                     setCompareOperatorType((yyval.node),(yyvsp[-2].node),(yyvsp[0].node));
                    }
#line 1964 "syntax.tab.c"
    break;

  case 53:
#line 191 "syntax.y"
                    {(yyval.node)=new Node(Node_Type::MEDIAN,"Exp","",(yyloc).first_line); 
                     (yyval.node)->addChild({(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)});
                     setCompareOperatorType((yyval.node),(yyvsp[-2].node),(yyvsp[0].node));
                    }
#line 1973 "syntax.tab.c"
    break;

  case 54:
#line 195 "syntax.y"
                    {(yyval.node)=new Node(Node_Type::MEDIAN,"Exp","",(yyloc).first_line); 
                     (yyval.node)->addChild({(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)});
                     setAlrthOperatorType((yyval.node),(yyvsp[-2].node),(yyvsp[0].node));
                    }
#line 1982 "syntax.tab.c"
    break;

  case 55:
#line 199 "syntax.y"
                    {(yyval.node)=new Node(Node_Type::MEDIAN,"Exp","",(yyloc).first_line); 
                     (yyval.node)->addChild({(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)});
                     setAlrthOperatorType((yyval.node),(yyvsp[-2].node),(yyvsp[0].node));
                    }
#line 1991 "syntax.tab.c"
    break;

  case 56:
#line 203 "syntax.y"
                    {(yyval.node)=new Node(Node_Type::MEDIAN,"Exp","",(yyloc).first_line); 
                     (yyval.node)->addChild({(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)});
                     setAlrthOperatorType((yyval.node),(yyvsp[-2].node),(yyvsp[0].node));
                    }
#line 2000 "syntax.tab.c"
    break;

  case 57:
#line 207 "syntax.y"
                    {(yyval.node)=new Node(Node_Type::MEDIAN,"Exp","",(yyloc).first_line); 
                     (yyval.node)->addChild({(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)});
                     setAlrthOperatorType((yyval.node),(yyvsp[-2].node),(yyvsp[0].node));
                    }
#line 2009 "syntax.tab.c"
    break;

  case 58:
#line 211 "syntax.y"
                    {(yyval.node)=new Node(Node_Type::MEDIAN,"Exp","",(yyloc).first_line); 
                     (yyval.node)->addChild({(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)});
                     (yyval.node)->type=(yyvsp[-1].node)->type;
                    }
#line 2018 "syntax.tab.c"
    break;

  case 59:
#line 215 "syntax.y"
                             {(yyval.node)=new Node(Node_Type::MEDIAN,"Exp","",(yyloc).first_line); 
                              (yyval.node)->addChild({(yyvsp[-1].node),(yyvsp[0].node)});
                              (yyval.node)->var=(yyvsp[0].node)->var; 
                              setAlrthOperatorType((yyval.node),(yyvsp[0].node));
                             }
#line 2028 "syntax.tab.c"
    break;

  case 60:
#line 220 "syntax.y"
                             {(yyval.node)=new Node(Node_Type::MEDIAN,"Exp","",(yyloc).first_line);
                              (yyval.node)->addChild({(yyvsp[-1].node),(yyvsp[0].node)});
                              (yyval.node)->var=(yyvsp[0].node)->var; 
                              setAlrthOperatorType((yyval.node),(yyvsp[0].node));
                             }
#line 2038 "syntax.tab.c"
    break;

  case 61:
#line 225 "syntax.y"
                       {(yyval.node)=new Node(Node_Type::MEDIAN,"Exp","",(yyloc).first_line); (yyval.node)->addChild({(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node)}); 
                        printf("Error type B at Line %d: Missing closing parenthesis ')'\n",(yyloc).first_line);
                        type_B_error = 1;
                       }
#line 2047 "syntax.tab.c"
    break;

  case 62:
#line 229 "syntax.y"
                    {checkExist_FUN((yyvsp[-3].node));
                     checkParam_FUN((yyvsp[-3].node),(yyvsp[-1].node));
                     (yyval.node)=new Node(Node_Type::MEDIAN,"Exp","",(yyloc).first_line); 
                     (yyval.node)->addChild({(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)});
                     getReturnTypeOfFunction((yyval.node),(yyvsp[-3].node));
                    }
#line 2058 "syntax.tab.c"
    break;

  case 63:
#line 235 "syntax.y"
                {checkExist_FUN((yyvsp[-2].node));
                 checkParam_FUN((yyvsp[-2].node),nullptr);
                 (yyval.node)=new Node(Node_Type::MEDIAN,"Exp","",(yyloc).first_line); 
                 (yyval.node)->addChild({(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)});
                 getReturnTypeOfFunction((yyval.node),(yyvsp[-2].node));
                 }
#line 2069 "syntax.tab.c"
    break;

  case 64:
#line 241 "syntax.y"
                     {(yyval.node)=new Node(Node_Type::MEDIAN,"Exp","",(yyloc).first_line);
                      (yyval.node)->addChild({(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)});
		              checkExists_Array((yyvsp[-3].node));
                      getArrayType((yyval.node),(yyvsp[-3].node),(yyvsp[-1].node));
                     }
#line 2079 "syntax.tab.c"
    break;

  case 65:
#line 246 "syntax.y"
                  {(yyval.node)=new Node(Node_Type::MEDIAN,"Exp","",(yyloc).first_line); 
                   (yyval.node)->addChild({(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)});
                   checkTypeOfDot((yyval.node),(yyvsp[-2].node),(yyvsp[0].node));
                  }
#line 2088 "syntax.tab.c"
    break;

  case 66:
#line 250 "syntax.y"
            {(yyval.node)=new Node(Node_Type::MEDIAN,"Exp","",(yyloc).first_line); 
            (yyval.node)->addChild({(yyvsp[0].node)});
            checkExists_ID((yyvsp[0].node));
            idToExp((yyval.node),(yyvsp[0].node));
            }
#line 2098 "syntax.tab.c"
    break;

  case 67:
#line 255 "syntax.y"
            {(yyval.node)=new Node(Node_Type::MEDIAN,"Exp","",(yyloc).first_line); 
             (yyval.node)->addChild({(yyvsp[0].node)});
             (yyval.node)->var = Type::getPrimitiveINT();
            }
#line 2107 "syntax.tab.c"
    break;

  case 68:
#line 259 "syntax.y"
            {(yyval.node)=new Node(Node_Type::MEDIAN,"Exp","",(yyloc).first_line); 
             (yyval.node)->addChild({(yyvsp[0].node)});
             (yyval.node)->var = Type::getPrimitiveFLOAT();
            }
#line 2116 "syntax.tab.c"
    break;

  case 69:
#line 263 "syntax.y"
            {(yyval.node)=new Node(Node_Type::MEDIAN,"Exp","",(yyloc).first_line); 
            (yyval.node)->addChild({(yyvsp[0].node)}); 
            (yyval.node)->var = Type::getPrimitiveCHAR();
            }
#line 2125 "syntax.tab.c"
    break;

  case 70:
#line 267 "syntax.y"
               {type_A_error = 1;}
#line 2131 "syntax.tab.c"
    break;


#line 2135 "syntax.tab.c"

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
  *++yylsp = yyloc;

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

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp, yylsp);
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
#line 269 "syntax.y"

void yyerror(const char *s){
    // if (type_B_error){
        // printf("------------------------------\n");
        // printf("Error type B at Line %d: \n",yylineno);
        // printf("------------------------------\n");
    // }
	// printf("ERROR: %s at symbol '%s' on line %d\n", s, yytext, yylineno);
}
