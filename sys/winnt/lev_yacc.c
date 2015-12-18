/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "util/lev_comp.y" /* yacc.c:339  */

/*	SCCS Id: @(#)lev_yacc.c	3.4	2000/01/17	*/
/*	Copyright (c) 1989 by Jean-Christophe Collet */
/* NetHack may be freely redistributed.  See license for details. */

/*
 * This file contains the Level Compiler code
 * It may handle special mazes & special room-levels
 */

#define LEVEL_COMPILER	1	/* Enable definition of internal structures */

/* In case we're using bison in AIX.  This definition must be
 * placed before any other C-language construct in the file
 * excluding comments and preprocessor directives (thanks IBM
 * for this wonderful feature...).
 *
 * Note: some cpps barf on this 'undefined control' (#pragma).
 * Addition of the leading space seems to prevent barfage for now,
 * and AIX will still see the directive.
 */
#ifdef _AIX
 #pragma alloca		/* keep leading space! */
#endif

#include "hack.h"
#include "sp_lev.h"

#define MAX_REGISTERS	10
#define ERR		(-1)
/* many types of things are put in chars for transference to NetHack.
 * since some systems will use signed chars, limit everybody to the
 * same number for portability.
 */
#define MAX_OF_TYPE	128

#define New(type)		\
	(type *) memset((genericptr_t)alloc(sizeof(type)), 0, sizeof(type))
#define NewTab(type, size)	(type **) alloc(sizeof(type *) * size)
#define Free(ptr)		free((genericptr_t)ptr)

extern void FDECL(yyerror, (const char *));
extern void FDECL(yywarning, (const char *));
extern int NDECL(yylex);
int NDECL(yyparse);

extern int FDECL(get_artifact_id, (char *));
extern int FDECL(get_floor_type, (CHAR_P));
extern int FDECL(get_room_type, (char *));
extern int FDECL(get_trap_type, (char *));
extern int FDECL(get_monster_id, (char *,CHAR_P));
extern int FDECL(get_object_id, (char *,CHAR_P));
extern boolean FDECL(check_monster_char, (CHAR_P));
extern boolean FDECL(check_object_char, (CHAR_P));
extern char FDECL(what_map_char, (CHAR_P));
extern void FDECL(scan_map, (char *));
extern void NDECL(wallify_map);
extern boolean NDECL(check_subrooms);
extern void FDECL(check_coord, (int,int,const char *));
extern void NDECL(store_part);
extern void NDECL(store_room);
extern void FDECL(store_place_list, (int,int,int,const struct coord *));
extern boolean FDECL(write_level_file, (char *,splev *,specialmaze *));
extern void FDECL(free_rooms, (splev *));

static struct reg {
	int x1, y1;
	int x2, y2;
}		current_region;

static struct coord current_coord, current_align;

static struct size {
	int height;
	int width;
}		current_size;

char tmpmessage[256];
digpos *tmppass[32];
char *tmpmap[ROWNO];

digpos *tmpdig[MAX_OF_TYPE];
region *tmpreg[MAX_OF_TYPE];
lev_region *tmplreg[MAX_OF_TYPE];
door *tmpdoor[MAX_OF_TYPE];
drawbridge *tmpdb[MAX_OF_TYPE];
walk *tmpwalk[MAX_OF_TYPE];
lev_region *tmprndlreg[MAX_REGISTERS];

room_door *tmprdoor[MAX_OF_TYPE];
trap *tmptrap[MAX_OF_TYPE];
monster *tmpmonst[MAX_OF_TYPE];
object *tmpobj[MAX_OF_TYPE];
altar *tmpaltar[MAX_OF_TYPE];
lad *tmplad[MAX_OF_TYPE];
stair *tmpstair[MAX_OF_TYPE];
gold *tmpgold[MAX_OF_TYPE];
engraving *tmpengraving[MAX_OF_TYPE];
fountain *tmpfountain[MAX_OF_TYPE];
sink *tmpsink[MAX_OF_TYPE];
pool *tmppool[MAX_OF_TYPE];

mazepart *tmppart[10];
room *tmproom[MAXNROFROOMS*2];
corridor *tmpcor[MAX_OF_TYPE];

static specialmaze maze;
static splev special_lev;
static lev_init init_lev;

static char olist[MAX_REGISTERS], mlist[MAX_REGISTERS];
static struct coord plist[MAX_REGISTERS];

int n_olist = 0, n_mlist = 0, n_plist = 0;

unsigned int nrndlreg = 0;
unsigned int nlreg = 0, nreg = 0, ndoor = 0, ntrap = 0, nmons = 0, nobj = 0;
unsigned int ndb = 0, nwalk = 0, npart = 0, ndig = 0, nlad = 0, nstair = 0;
unsigned int naltar = 0, ncorridor = 0, nrooms = 0, ngold = 0, nengraving = 0;
unsigned int nfountain = 0, npool = 0, nsink = 0, npass = 0;

static int lev_flags = 0;

unsigned int max_x_map, max_y_map;

static xchar in_room;

extern int fatal_error;
extern int want_warnings;
extern const char *fname;


#line 199 "y_tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y_tab.h".  */
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
    CHAR = 258,
    INTEGER = 259,
    BOOLEAN = 260,
    PERCENT = 261,
    MESSAGE_ID = 262,
    MAZE_ID = 263,
    LEVEL_ID = 264,
    LEV_INIT_ID = 265,
    GEOMETRY_ID = 266,
    NOMAP_ID = 267,
    OBJECT_ID = 268,
    COBJECT_ID = 269,
    MONSTER_ID = 270,
    TRAP_ID = 271,
    DOOR_ID = 272,
    DRAWBRIDGE_ID = 273,
    MAZEWALK_ID = 274,
    WALLIFY_ID = 275,
    REGION_ID = 276,
    FILLING = 277,
    RANDOM_OBJECTS_ID = 278,
    RANDOM_MONSTERS_ID = 279,
    RANDOM_PLACES_ID = 280,
    ALTAR_ID = 281,
    LADDER_ID = 282,
    STAIR_ID = 283,
    NON_DIGGABLE_ID = 284,
    NON_PASSWALL_ID = 285,
    ROOM_ID = 286,
    PORTAL_ID = 287,
    TELEPRT_ID = 288,
    BRANCH_ID = 289,
    LEV = 290,
    CHANCE_ID = 291,
    CORRIDOR_ID = 292,
    GOLD_ID = 293,
    ENGRAVING_ID = 294,
    FOUNTAIN_ID = 295,
    POOL_ID = 296,
    SINK_ID = 297,
    NONE = 298,
    RAND_CORRIDOR_ID = 299,
    DOOR_STATE = 300,
    LIGHT_STATE = 301,
    CURSE_TYPE = 302,
    ENGRAVING_TYPE = 303,
    DIRECTION = 304,
    RANDOM_TYPE = 305,
    O_REGISTER = 306,
    M_REGISTER = 307,
    P_REGISTER = 308,
    A_REGISTER = 309,
    ALIGNMENT = 310,
    LEFT_OR_RIGHT = 311,
    CENTER = 312,
    TOP_OR_BOT = 313,
    ALTAR_TYPE = 314,
    UP_OR_DOWN = 315,
    SUBROOM_ID = 316,
    NAME_ID = 317,
    FLAGS_ID = 318,
    FLAG_TYPE = 319,
    MON_ATTITUDE = 320,
    MON_ALERTNESS = 321,
    MON_APPEARANCE = 322,
    CONTAINED = 323,
    OBJFLAG_TYPE = 324,
    OBJFLAGS_ID = 325,
    RANDOMREGION_ID = 326,
    R_REGISTER = 327,
    STRING = 328,
    MAP_ID = 329
  };
#endif
/* Tokens.  */
#define CHAR 258
#define INTEGER 259
#define BOOLEAN 260
#define PERCENT 261
#define MESSAGE_ID 262
#define MAZE_ID 263
#define LEVEL_ID 264
#define LEV_INIT_ID 265
#define GEOMETRY_ID 266
#define NOMAP_ID 267
#define OBJECT_ID 268
#define COBJECT_ID 269
#define MONSTER_ID 270
#define TRAP_ID 271
#define DOOR_ID 272
#define DRAWBRIDGE_ID 273
#define MAZEWALK_ID 274
#define WALLIFY_ID 275
#define REGION_ID 276
#define FILLING 277
#define RANDOM_OBJECTS_ID 278
#define RANDOM_MONSTERS_ID 279
#define RANDOM_PLACES_ID 280
#define ALTAR_ID 281
#define LADDER_ID 282
#define STAIR_ID 283
#define NON_DIGGABLE_ID 284
#define NON_PASSWALL_ID 285
#define ROOM_ID 286
#define PORTAL_ID 287
#define TELEPRT_ID 288
#define BRANCH_ID 289
#define LEV 290
#define CHANCE_ID 291
#define CORRIDOR_ID 292
#define GOLD_ID 293
#define ENGRAVING_ID 294
#define FOUNTAIN_ID 295
#define POOL_ID 296
#define SINK_ID 297
#define NONE 298
#define RAND_CORRIDOR_ID 299
#define DOOR_STATE 300
#define LIGHT_STATE 301
#define CURSE_TYPE 302
#define ENGRAVING_TYPE 303
#define DIRECTION 304
#define RANDOM_TYPE 305
#define O_REGISTER 306
#define M_REGISTER 307
#define P_REGISTER 308
#define A_REGISTER 309
#define ALIGNMENT 310
#define LEFT_OR_RIGHT 311
#define CENTER 312
#define TOP_OR_BOT 313
#define ALTAR_TYPE 314
#define UP_OR_DOWN 315
#define SUBROOM_ID 316
#define NAME_ID 317
#define FLAGS_ID 318
#define FLAG_TYPE 319
#define MON_ATTITUDE 320
#define MON_ALERTNESS 321
#define MON_APPEARANCE 322
#define CONTAINED 323
#define OBJFLAG_TYPE 324
#define OBJFLAGS_ID 325
#define RANDOMREGION_ID 326
#define R_REGISTER 327
#define STRING 328
#define MAP_ID 329

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 135 "util/lev_comp.y" /* yacc.c:355  */

	int	i;
	char*	map;
	struct {
		xchar room;
		xchar wall;
		xchar door;
	} corpos;

#line 397 "y_tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 414 "y_tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   490

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  81
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  130
/* YYNRULES -- Number of rules.  */
#define YYNRULES  244
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  518

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   329

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      75,    76,     2,     2,    73,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    74,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    77,     2,    78,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    79,    80
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   174,   174,   175,   178,   179,   182,   183,   186,   213,
     250,   263,   271,   291,   292,   296,   299,   306,   310,   316,
     317,   320,   337,   338,   341,   352,   366,   380,   383,   384,
     387,   388,   391,   399,   400,   403,   418,   434,   444,   448,
     454,   472,   491,   494,   500,   510,   516,   525,   531,   536,
     542,   547,   553,   554,   557,   558,   559,   560,   561,   562,
     563,   564,   565,   566,   567,   568,   569,   570,   573,   582,
     596,   595,   622,   623,   626,   640,   641,   644,   645,   648,
     649,   652,   665,   669,   675,   676,   679,   685,   701,   714,
     720,   721,   724,   725,   728,   729,   732,   743,   751,   759,
     770,   776,   783,   792,   799,   808,   816,   815,   825,   826,
     829,   830,   831,   832,   833,   834,   835,   836,   837,   838,
     839,   840,   841,   842,   843,   844,   845,   846,   847,   848,
     849,   853,   852,   888,   889,   892,   896,   900,   904,   908,
     915,   918,   928,   927,   963,   972,   982,   991,   994,   997,
    1002,  1010,  1014,  1020,  1024,  1030,  1041,  1045,  1051,  1052,
    1055,  1062,  1061,  1082,  1083,  1086,  1099,  1116,  1158,  1172,
    1178,  1195,  1213,  1212,  1242,  1241,  1270,  1269,  1296,  1305,
    1295,  1329,  1328,  1355,  1358,  1364,  1368,  1388,  1404,  1417,
    1430,  1445,  1460,  1526,  1544,  1561,  1579,  1580,  1584,  1587,
    1588,  1592,  1595,  1596,  1602,  1603,  1609,  1617,  1620,  1630,
    1634,  1637,  1641,  1647,  1648,  1649,  1650,  1656,  1657,  1660,
    1661,  1664,  1665,  1666,  1672,  1673,  1676,  1685,  1696,  1707,
    1716,  1725,  1734,  1735,  1742,  1753,  1765,  1768,  1769,  1773,
    1776,  1784,  1785,  1788,  1799
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CHAR", "INTEGER", "BOOLEAN", "PERCENT",
  "MESSAGE_ID", "MAZE_ID", "LEVEL_ID", "LEV_INIT_ID", "GEOMETRY_ID",
  "NOMAP_ID", "OBJECT_ID", "COBJECT_ID", "MONSTER_ID", "TRAP_ID",
  "DOOR_ID", "DRAWBRIDGE_ID", "MAZEWALK_ID", "WALLIFY_ID", "REGION_ID",
  "FILLING", "RANDOM_OBJECTS_ID", "RANDOM_MONSTERS_ID", "RANDOM_PLACES_ID",
  "ALTAR_ID", "LADDER_ID", "STAIR_ID", "NON_DIGGABLE_ID",
  "NON_PASSWALL_ID", "ROOM_ID", "PORTAL_ID", "TELEPRT_ID", "BRANCH_ID",
  "LEV", "CHANCE_ID", "CORRIDOR_ID", "GOLD_ID", "ENGRAVING_ID",
  "FOUNTAIN_ID", "POOL_ID", "SINK_ID", "NONE", "RAND_CORRIDOR_ID",
  "DOOR_STATE", "LIGHT_STATE", "CURSE_TYPE", "ENGRAVING_TYPE", "DIRECTION",
  "RANDOM_TYPE", "O_REGISTER", "M_REGISTER", "P_REGISTER", "A_REGISTER",
  "ALIGNMENT", "LEFT_OR_RIGHT", "CENTER", "TOP_OR_BOT", "ALTAR_TYPE",
  "UP_OR_DOWN", "SUBROOM_ID", "NAME_ID", "FLAGS_ID", "FLAG_TYPE",
  "MON_ATTITUDE", "MON_ALERTNESS", "MON_APPEARANCE", "CONTAINED",
  "OBJFLAG_TYPE", "OBJFLAGS_ID", "RANDOMREGION_ID", "R_REGISTER", "','",
  "':'", "'('", "')'", "'['", "']'", "STRING", "MAP_ID", "$accept", "file",
  "levels", "level", "maze_level", "room_level", "level_def", "lev_init",
  "walled", "flags", "flag_list", "messages", "message", "rreg_init",
  "init_rreg", "rooms", "roomlist", "corridors_def", "random_corridors",
  "corridors", "corridor", "corr_spec", "aroom", "subroom_def", "room_def",
  "roomfill", "room_pos", "subroom_pos", "room_align", "room_size",
  "room_details", "room_detail", "room_name", "room_chance", "room_door",
  "$@1", "room_door_infos", "room_door_info", "secret", "door_wall",
  "door_pos", "maze_def", "filling", "regions", "aregion",
  "map_definition", "map_geometry", "h_justif", "v_justif", "reg_init",
  "init_reg", "object_list", "monster_list", "place_list", "$@2",
  "map_details", "map_detail", "monster_detail", "$@3", "monster_infos",
  "monster_info", "object_detail", "object_desc", "$@4", "object_where",
  "object_infos", "object_flags", "obj_flag_list", "curse_state",
  "monster_id", "enchantment", "optional_name", "door_detail", "$@5",
  "door_infos", "door_info", "trap_detail", "drawbridge_detail",
  "mazewalk_detail", "wallify_detail", "ladder_detail", "stair_detail",
  "stair_region", "$@6", "rndlevregion", "$@7", "portal_region", "$@8",
  "teleprt_region", "$@9", "$@10", "branch_region", "$@11",
  "teleprt_detail", "lev_region", "fountain_detail", "sink_detail",
  "pool_detail", "diggable_detail", "passwall_detail", "region_detail",
  "altar_detail", "gold_detail", "engraving_detail", "monster_c",
  "object_c", "m_name", "o_name", "trap_name", "room_type", "prefilled",
  "coordinate", "door_state", "light_state", "alignment", "altar_type",
  "p_register", "r_register", "o_register", "m_register", "a_register",
  "place", "monster", "object", "string", "amount", "chance",
  "engraving_type", "coord", "region", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,    44,    58,    40,    41,    91,    93,   328,
     329
};
# endif

#define YYPACT_NINF -393

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-393)))

#define YYTABLE_NINF -107

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     121,    -2,     2,   120,  -393,   121,  -393,  -393,    97,    97,
     111,   111,  -393,  -393,   119,   184,   184,  -393,   122,  -393,
     132,   124,   190,   190,    42,   126,  -393,   197,   128,  -393,
     190,   164,  -393,  -393,  -393,   132,   130,   129,    80,  -393,
     131,  -393,  -393,   164,  -393,   133,  -393,   198,  -393,   135,
     136,   140,   142,  -393,   160,  -393,    65,  -393,  -393,   125,
    -393,    16,  -393,   134,   203,   208,    56,    56,  -393,  -393,
    -393,   180,  -393,    39,    39,  -393,  -393,   145,   146,   147,
     -16,   148,  -393,     4,  -393,   214,  -393,  -393,   149,  -393,
    -393,   150,  -393,   153,  -393,   154,   155,  -393,   222,   222,
     222,   222,   156,   157,   158,   159,   161,   162,   163,   165,
     166,   167,   168,  -393,  -393,  -393,  -393,  -393,  -393,  -393,
    -393,  -393,  -393,  -393,  -393,  -393,  -393,  -393,   127,   203,
     208,     8,   230,   234,   169,   170,   171,  -393,   172,   173,
     174,   175,   176,   177,   178,   179,  -393,  -393,  -393,  -393,
    -393,  -393,  -393,  -393,  -393,  -393,  -393,  -393,  -393,  -393,
    -393,  -393,  -393,  -393,  -393,  -393,  -393,  -393,   181,   203,
     208,    82,    82,   182,  -393,  -393,   185,  -393,   186,   187,
      23,    90,    90,   252,    43,    90,    90,    90,    90,   111,
     189,  -393,  -393,  -393,  -393,  -393,  -393,   258,  -393,   191,
    -393,   188,   192,   123,    90,    90,   193,    90,    35,   193,
     193,    15,    15,    15,   260,  -393,  -393,  -393,  -393,   194,
     196,   259,   199,    13,    32,    66,  -393,  -393,   200,  -393,
     201,   202,   204,  -393,  -393,  -393,   207,  -393,  -393,  -393,
     209,   210,  -393,  -393,  -393,  -393,  -393,   211,   212,   213,
     215,   216,  -393,  -393,   218,   219,   220,   267,   221,   223,
     206,   270,  -393,  -393,  -393,  -393,  -393,  -393,  -393,   224,
      81,    83,   225,    11,  -393,   226,   227,  -393,  -393,  -393,
     228,   229,  -393,  -393,  -393,   231,  -393,   123,   271,   272,
     117,   235,    90,   101,   232,   283,     8,     8,    15,    90,
     239,   250,   233,    82,   247,   304,   236,   237,   238,   240,
     242,    82,  -393,   312,   245,  -393,   315,   248,   273,  -393,
    -393,   316,    67,   319,    69,    90,   251,   249,   253,  -393,
     255,  -393,   256,  -393,  -393,  -393,  -393,  -393,   257,  -393,
     261,  -393,  -393,  -393,  -393,   262,  -393,   321,   263,  -393,
     265,   322,    15,    15,    15,    15,   266,   268,    84,   269,
      88,   274,   275,  -393,  -393,  -393,   276,  -393,   277,  -393,
    -393,   137,   278,  -393,   324,    68,   111,  -393,   279,  -393,
     123,   284,    56,   329,   107,   285,   286,  -393,  -393,    41,
     330,  -393,   125,   287,   336,  -393,   339,   288,    44,  -393,
     289,  -393,    90,  -393,  -393,   290,   340,   291,  -393,  -393,
    -393,  -393,    15,   292,  -393,   341,   294,   295,   296,   111,
     297,  -393,  -393,  -393,   298,   299,    88,   300,   302,   111,
    -393,  -393,   301,    89,  -393,    44,   293,  -393,  -393,   111,
    -393,   305,   326,  -393,   342,  -393,  -393,   313,  -393,  -393,
     127,   306,  -393,   345,   306,  -393,  -393,   307,  -393,  -393,
    -393,  -393,  -393,   347,   308,   309,  -393,   310,   359,  -393,
     311,  -393,    21,  -393,   317,  -393,   318,   378,   380,  -393,
    -393,  -393,  -393,  -393,  -393,   320,   323,    58,  -393,   325,
    -393,  -393,   327,    10,    45,  -393,  -393,   111,  -393,  -393,
     111,  -393,  -393,  -393,  -393,   328,   331,   331,  -393,  -393,
      45,    26,  -393,  -393,   331,  -393,  -393,  -393
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     0,     3,     4,     6,     7,    15,    15,
       0,     0,     1,     5,     0,    11,    11,   236,     0,    10,
       0,     0,    19,    19,     0,    18,    16,     0,     0,    22,
      19,     0,    82,    83,    81,     0,     0,     0,    26,    20,
       0,    87,     8,    84,    94,     0,    17,     0,    21,     0,
       0,     0,     0,    23,    33,    27,    28,    52,    52,     0,
      85,   108,    88,     0,     0,     0,     0,     0,    32,     9,
      30,    31,    29,    39,    38,    90,    91,     0,     0,     0,
       0,     0,    95,    86,   100,     0,   235,    24,   101,   234,
      25,   103,   209,     0,   208,     0,     0,    34,   239,   239,
     239,   239,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    53,    54,    55,    56,    57,    58,    59,
      60,    67,    62,    63,    64,    61,    65,    66,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   169,     0,     0,
       0,     0,     0,     0,     0,     0,   109,   110,   111,   112,
     113,   114,   115,   123,   124,   125,   126,   117,   118,   119,
     120,   122,   129,   130,   116,   121,   127,   128,     0,     0,
       0,     0,     0,     0,   240,   140,     0,   141,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    93,    92,    89,    96,    99,   233,     0,    97,   105,
     232,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   102,   104,   219,   220,     0,
       0,     0,     0,     0,     0,     0,    75,    76,     0,   216,
       0,     0,     0,   214,   215,   213,     0,    69,   237,   238,
       0,     0,   187,   189,   188,    68,   152,   150,     0,     0,
       0,     0,   217,   218,     0,     0,     0,     0,     0,     0,
       0,     0,   172,   185,   190,   191,   176,   178,   181,     0,
       0,     0,     0,     0,   200,     0,     0,   201,   199,   197,
       0,     0,   198,   196,   207,     0,   206,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    45,     0,     0,    47,     0,     0,     0,    36,
      35,     0,     0,     0,     0,     0,     0,     0,     0,   223,
       0,   221,     0,   222,   171,   194,   241,   242,     0,   151,
       0,   107,    98,   174,   161,     0,   168,     0,     0,   170,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   205,   142,   204,     0,   203,     0,   202,
     166,     0,   226,   228,     0,     0,     0,   243,     0,   163,
       0,     0,     0,     0,     0,     0,     0,   179,   182,     0,
       0,    49,     0,     0,     0,    51,     0,     0,     0,   229,
       0,   230,     0,    77,    78,     0,     0,     0,   225,   224,
     193,   195,     0,   162,   167,     0,   210,     0,     0,     0,
     183,    13,    14,    12,     0,     0,     0,     0,     0,     0,
      79,    80,     0,     0,   131,     0,     0,   231,   175,     0,
     164,     0,     0,   192,     0,   173,   177,     0,   180,    44,
       0,    42,    46,     0,    42,    37,   145,   146,   144,   133,
      70,   227,   165,     0,   211,     0,   184,     0,     0,    41,
       0,    40,     0,   143,   132,    72,     0,     0,     0,    48,
      43,    50,   154,   153,   155,     0,     0,     0,   134,    71,
     244,   212,     0,     0,     0,   136,   137,     0,   138,   135,
       0,    73,   186,   157,   156,     0,   158,   158,   139,    74,
       0,     0,   148,   149,   158,   159,   160,   147
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -393,  -393,   383,  -393,  -393,  -393,  -393,   369,  -393,   382,
     354,    36,  -393,  -393,  -393,  -393,   343,  -393,  -393,  -393,
    -393,   138,  -393,  -393,  -393,   -62,  -393,  -393,  -393,   -31,
     344,  -393,  -393,  -393,  -393,  -393,  -393,  -393,  -393,  -393,
     -38,  -393,  -393,   357,  -393,  -393,  -393,    14,   -45,  -393,
    -393,   -72,   -68,  -108,  -393,  -393,  -393,   332,  -393,  -393,
    -393,   333,   314,  -393,  -393,  -393,   334,  -393,  -393,   -86,
    -344,  -392,  -393,  -393,  -393,  -393,   335,  -393,  -393,  -393,
    -393,   337,  -393,  -393,  -393,  -393,  -393,  -393,  -393,  -393,
    -393,  -393,  -393,  -393,  -200,   338,  -393,  -393,  -393,  -393,
    -393,   348,   349,   350,  -393,  -393,  -393,  -393,  -393,   -65,
    -393,  -178,  -281,  -167,   -79,  -393,  -393,  -393,  -393,  -393,
    -393,  -393,   217,   205,   -10,  -393,    91,  -393,  -127,   -32
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,     6,     7,     8,    22,   423,    15,
      26,    29,    30,    38,    53,    54,    55,    69,    70,    71,
      97,   222,    56,    57,    58,   469,   314,   317,   393,   397,
      73,   113,   114,   115,   116,   475,   489,   501,   228,   405,
     432,     9,    34,    42,    43,    44,    45,    77,   193,    61,
      82,    87,    90,   198,   249,    83,   146,   117,   459,   474,
     488,   118,   175,   400,   457,   473,   119,   247,   485,   486,
     506,   512,   150,   379,   413,   440,   120,   152,   153,   154,
     155,   121,   157,   307,    84,   378,   158,   308,   159,   309,
     420,   160,   310,   448,   262,   122,   123,   124,   162,   163,
     164,   125,   126,   127,   281,   276,   368,   364,   285,    93,
     443,   236,   254,   219,   332,   410,   233,   234,   277,   282,
     333,   199,    91,    88,    94,   240,   176,   338,   235,   263
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      18,    19,    95,   232,   200,   220,   326,   241,   242,   243,
     244,   266,   267,   268,   503,   319,    86,    98,    99,   100,
     101,   134,   135,   136,   137,   138,   255,   256,   226,   259,
     103,   139,   140,   141,   142,    89,   143,   144,   145,    78,
      79,    80,   106,   107,   108,    32,   421,   238,   430,   503,
     260,   196,    98,    99,   100,   101,   102,   194,   131,    31,
     504,   132,   195,   274,   275,   103,    39,   104,   482,   515,
     260,   483,    10,   227,   112,   105,    11,   106,   107,   108,
     109,   110,   279,   197,   280,   229,   221,    81,   230,   484,
     257,   422,    33,   239,   431,   504,    51,   215,   343,   414,
     484,   111,   216,    49,    50,   516,    92,   231,   329,   112,
     261,    51,   330,   331,   335,   513,   284,   363,   408,   367,
      12,   344,   517,   495,   496,   497,    52,   409,   217,     1,
       2,   312,   218,   315,   391,    17,   348,    17,   395,   229,
     229,    52,   230,   230,   356,    17,    17,   370,    17,   336,
     507,   337,   385,   386,   387,   388,   313,   456,   316,   392,
      14,   231,   231,   396,   197,   197,   514,   329,   252,   200,
     200,   330,   331,   253,   258,    40,    41,   264,   265,   245,
     415,    75,    76,   377,   191,   192,   403,   404,   341,   342,
      17,   178,   179,    20,    21,    24,    25,    28,    27,    35,
      36,    63,    37,    47,    68,    59,    86,    85,    48,    64,
      65,    89,   438,    62,    66,   286,    67,    96,   128,   168,
     129,   130,   169,   170,   434,   133,   171,   172,   174,   173,
     180,   181,   182,   183,   201,   184,   185,   186,   202,   187,
     188,   189,   190,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   458,   237,   221,   246,   223,
     224,   225,   248,   272,  -106,   269,   250,   270,   257,   271,
     251,   302,   273,   287,   306,   327,   328,   290,   288,   289,
     291,   305,   292,   293,   294,   295,   296,   340,   345,   297,
     298,   299,   300,   301,   303,   334,   304,   311,   318,   346,
     322,   339,   324,   321,   325,   323,   347,   349,   350,   351,
     352,   353,   365,   354,   369,   355,   357,   416,   358,   359,
     362,   360,   361,   366,   371,   381,   384,   372,   407,   375,
     376,   373,   374,   417,   424,   380,   382,   377,   383,   389,
     427,   390,   394,   428,   436,   441,   465,   398,   464,   470,
     402,   476,   412,   399,   401,   406,   445,   415,   418,   419,
     426,   429,   433,   435,   480,   439,   411,   442,   444,   437,
     447,   461,   450,   466,   449,   453,   452,   455,   463,   468,
     472,   477,   478,   491,   492,    23,   479,   481,    13,    46,
     487,    16,   471,   493,   490,   451,   494,   460,   500,    72,
      60,   510,    74,   502,   511,   467,   425,   505,   498,   446,
       0,   320,     0,   177,     0,   147,   148,   149,   151,   454,
     156,   161,     0,     0,     0,     0,     0,     0,   278,   462,
       0,   165,   166,   167,     0,     0,     0,     0,     0,     0,
       0,   283,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   499,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   508,     0,     0,
     509
};

static const yytype_int16 yycheck[] =
{
      10,    11,    67,   181,   131,   172,   287,   185,   186,   187,
     188,   211,   212,   213,     4,     4,     3,    13,    14,    15,
      16,    17,    18,    19,    20,    21,   204,   205,     5,   207,
      26,    27,    28,    29,    30,     3,    32,    33,    34,    23,
      24,    25,    38,    39,    40,     3,     5,     4,     4,     4,
      35,    43,    13,    14,    15,    16,    17,   129,    74,    23,
      50,    77,   130,    50,    51,    26,    30,    28,    47,    43,
      35,    50,    74,    50,    70,    36,    74,    38,    39,    40,
      41,    42,    50,    75,    52,    50,    75,    71,    53,    79,
      75,    50,    50,    50,    50,    50,    31,   169,   298,   380,
      79,    62,   170,    23,    24,    79,    50,    72,    50,    70,
      75,    31,    54,    55,   292,   507,    50,    50,    50,    50,
       0,   299,   514,    65,    66,    67,    61,    59,    46,     8,
       9,    50,    50,    50,    50,    79,   303,    79,    50,    50,
      50,    61,    53,    53,   311,    79,    79,   325,    79,    48,
     494,    50,   352,   353,   354,   355,    75,    68,    75,    75,
      63,    72,    72,    75,    75,    75,   510,    50,    45,   296,
     297,    54,    55,    50,   206,    11,    12,   209,   210,   189,
      73,    56,    57,    76,    57,    58,    49,    50,   296,   297,
      79,   100,   101,    74,    10,    73,    64,     7,    74,    73,
       3,     3,    74,    73,    44,    74,     3,    73,    79,    74,
      74,     3,   412,    80,    74,   225,    74,    37,    73,     5,
      74,    74,    73,    73,   402,    77,    73,    73,     6,    74,
      74,    74,    74,    74,     4,    74,    74,    74,     4,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    73,   433,     4,    75,    69,    74,
      74,    74,     4,     4,    73,     5,    78,    73,    75,    73,
      78,     4,    73,    73,     4,     4,     4,    73,    77,    77,
      73,    75,    73,    73,    73,    73,    73,     4,    49,    74,
      74,    73,    73,    73,    73,    60,    73,    73,    73,    49,
      73,    69,    73,    77,    73,    77,    73,    60,     4,    73,
      73,    73,   322,    73,   324,    73,     4,   382,    73,     4,
       4,    73,    49,     4,    73,     4,     4,    78,     4,    73,
      73,    78,    77,     4,     4,    73,    73,    76,    73,    73,
       4,    73,    73,     4,     4,     4,     4,    73,    22,     4,
      73,     4,    73,    78,    78,    77,    60,    73,    73,    73,
      73,    73,    73,    73,     5,    73,   376,    73,    73,    78,
      73,    78,    73,    60,    76,    73,    76,    76,    73,    73,
      73,    73,    73,     5,     4,    16,    76,    76,     5,    35,
      73,     9,   454,    73,    76,   426,    73,   435,    73,    56,
      43,    73,    58,    76,    73,   450,   392,   493,   487,   419,
      -1,   273,    -1,    99,    -1,    83,    83,    83,    83,   429,
      83,    83,    -1,    -1,    -1,    -1,    -1,    -1,   223,   439,
      -1,    83,    83,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   224,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   487,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   497,    -1,    -1,
     500
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,     9,    82,    83,    84,    85,    86,    87,   122,
      74,    74,     0,    83,    63,    90,    90,    79,   205,   205,
      74,    10,    88,    88,    73,    64,    91,    74,     7,    92,
      93,    92,     3,    50,   123,    73,     3,    74,    94,    92,
      11,    12,   124,   125,   126,   127,    91,    73,    79,    23,
      24,    31,    61,    95,    96,    97,   103,   104,   105,    74,
     124,   130,    80,     3,    74,    74,    74,    74,    44,    98,
      99,   100,    97,   111,   111,    56,    57,   128,    23,    24,
      25,    71,   131,   136,   165,    73,     3,   132,   204,     3,
     133,   203,    50,   190,   205,   190,    37,   101,    13,    14,
      15,    16,    17,    26,    28,    36,    38,    39,    40,    41,
      42,    62,    70,   112,   113,   114,   115,   138,   142,   147,
     157,   162,   176,   177,   178,   182,   183,   184,    73,    74,
      74,    74,    77,    77,    17,    18,    19,    20,    21,    27,
      28,    29,    30,    32,    33,    34,   137,   138,   142,   147,
     153,   157,   158,   159,   160,   161,   162,   163,   167,   169,
     172,   176,   179,   180,   181,   182,   183,   184,     5,    73,
      73,    73,    73,    74,     6,   143,   207,   143,   207,   207,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    57,    58,   129,   132,   133,    43,    75,   134,   202,
     209,     4,     4,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    73,   132,   133,    46,    50,   194,
     194,    75,   102,    74,    74,    74,     5,    50,   119,    50,
      53,    72,   192,   197,   198,   209,   192,     4,     4,    50,
     206,   192,   192,   192,   192,   205,    69,   148,     4,   135,
      78,    78,    45,    50,   193,   192,   192,    75,   210,   192,
      35,    75,   175,   210,   210,   210,   175,   175,   175,     5,
      73,    73,     4,    73,    50,    51,   186,   199,   204,    50,
      52,   185,   200,   203,    50,   189,   205,    73,    77,    77,
      73,    73,    73,    73,    73,    73,    73,    74,    74,    73,
      73,    73,     4,    73,    73,    75,     4,   164,   168,   170,
     173,    73,    50,    75,   107,    50,    75,   108,    73,     4,
     102,    77,    73,    77,    73,    73,   193,     4,     4,    50,
      54,    55,   195,   201,    60,   192,    48,    50,   208,    69,
       4,   134,   134,   175,   192,    49,    49,    73,   194,    60,
       4,    73,    73,    73,    73,    73,   194,     4,    73,     4,
      73,    49,     4,    50,   188,   205,     4,    50,   187,   205,
     192,    73,    78,    78,    77,    73,    73,    76,   166,   154,
      73,     4,    73,    73,     4,   175,   175,   175,   175,    73,
      73,    50,    75,   109,    73,    50,    75,   110,    73,    78,
     144,    78,    73,    49,    50,   120,    77,     4,    50,    59,
     196,   205,    73,   155,   193,    73,   190,     4,    73,    73,
     171,     5,    50,    89,     4,   128,    73,     4,     4,    73,
       4,    50,   121,    73,   192,    73,     4,    78,   175,    73,
     156,     4,    73,   191,    73,    60,   205,    73,   174,    76,
      73,   110,    76,    73,   205,    76,    68,   145,   192,   139,
     121,    78,   205,    73,    22,     4,    60,   129,    73,   106,
       4,   106,    73,   146,   140,   116,     4,    73,    73,    76,
       5,    76,    47,    50,    79,   149,   150,    73,   141,   117,
      76,     5,     4,    73,    73,    65,    66,    67,   195,   205,
      73,   118,    76,     4,    50,   150,   151,   151,   205,   205,
      73,    73,   152,   152,   151,    43,    79,   152
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    81,    82,    82,    83,    83,    84,    84,    85,    86,
      87,    88,    88,    89,    89,    90,    90,    91,    91,    92,
      92,    93,    94,    94,    95,    95,    96,    96,    97,    97,
      98,    98,    99,   100,   100,   101,   101,   102,   103,   103,
     104,   105,   106,   106,   107,   107,   108,   108,   109,   109,
     110,   110,   111,   111,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   113,   114,
     116,   115,   117,   117,   118,   119,   119,   120,   120,   121,
     121,   122,   123,   123,   124,   124,   125,   126,   126,   127,
     128,   128,   129,   129,   130,   130,   131,   131,   131,   131,
     131,   132,   132,   133,   133,   134,   135,   134,   136,   136,
     137,   137,   137,   137,   137,   137,   137,   137,   137,   137,
     137,   137,   137,   137,   137,   137,   137,   137,   137,   137,
     137,   139,   138,   140,   140,   141,   141,   141,   141,   141,
     142,   142,   144,   143,   145,   145,   146,   146,   146,   146,
     147,   148,   148,   149,   149,   150,   151,   151,   152,   152,
     152,   154,   153,   155,   155,   156,   157,   158,   159,   160,
     161,   162,   164,   163,   166,   165,   168,   167,   170,   171,
     169,   173,   172,   174,   174,   175,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   185,   185,   186,
     186,   186,   187,   187,   188,   188,   189,   189,   190,   190,
     191,   191,   191,   192,   192,   192,   192,   193,   193,   194,
     194,   195,   195,   195,   196,   196,   197,   197,   198,   199,
     200,   201,   202,   202,   203,   204,   205,   206,   206,   207,
     207,   208,   208,   209,   210
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     1,     1,     2,     1,     1,     5,     7,
       3,     0,    13,     1,     1,     0,     3,     3,     1,     0,
       2,     3,     0,     2,     3,     3,     0,     1,     1,     2,
       1,     1,     1,     0,     2,     5,     5,     7,     2,     2,
      12,    12,     0,     2,     5,     1,     5,     1,     5,     1,
       5,     1,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       0,    11,     0,     2,     2,     1,     1,     1,     1,     1,
       1,     5,     1,     1,     1,     2,     3,     1,     2,     5,
       1,     1,     1,     1,     0,     2,     3,     3,     6,     3,
       1,     1,     3,     1,     3,     1,     0,     4,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,    10,     0,     2,     2,     2,     2,     2,     3,
       2,     2,     0,     9,     1,     1,     0,     7,     5,     5,
       3,     3,     1,     1,     1,     1,     1,     1,     0,     2,
       2,     0,     7,     0,     2,     2,     6,     7,     5,     1,
       5,     5,     0,     8,     0,     9,     0,     8,     0,     0,
       8,     0,     6,     0,     2,     1,    10,     3,     3,     3,
       3,     3,     8,     7,     5,     7,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     2,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     7,     4,     4,
       4,     4,     1,     1,     1,     1,     1,     1,     1,     0,
       1,     1,     1,     5,     9
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 8:
#line 187 "util/lev_comp.y" /* yacc.c:1646  */
    {
			unsigned i;

			if (fatal_error > 0) {
				(void) fprintf(stderr,
				"%s : %d errors detected. No output created!\n",
					fname, fatal_error);
			} else {
				maze.flags = (yyvsp[-3].i);
				(void) memcpy((genericptr_t)&(maze.init_lev),
						(genericptr_t)&(init_lev),
						sizeof(lev_init));
				maze.numpart = npart;
				maze.parts = NewTab(mazepart, npart);
				for(i=0;i<npart;i++)
				    maze.parts[i] = tmppart[i];
				if (!write_level_file((yyvsp[-4].map), (splev *)0, &maze)) {
					yyerror("Can't write output file!!");
					exit(EXIT_FAILURE);
				}
				npart = 0;
			}
			Free((yyvsp[-4].map));
		  }
#line 1904 "y_tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 214 "util/lev_comp.y" /* yacc.c:1646  */
    {
			unsigned i;

			if (fatal_error > 0) {
			    (void) fprintf(stderr,
			      "%s : %d errors detected. No output created!\n",
					fname, fatal_error);
			} else {
				special_lev.flags = (long) (yyvsp[-5].i);
				(void) memcpy(
					(genericptr_t)&(special_lev.init_lev),
					(genericptr_t)&(init_lev),
					sizeof(lev_init));
				special_lev.nroom = nrooms;
				special_lev.rooms = NewTab(room, nrooms);
				for(i=0; i<nrooms; i++)
				    special_lev.rooms[i] = tmproom[i];
				special_lev.ncorr = ncorridor;
				special_lev.corrs = NewTab(corridor, ncorridor);
				for(i=0; i<ncorridor; i++)
				    special_lev.corrs[i] = tmpcor[i];
				if (check_subrooms()) {
				    if (!write_level_file((yyvsp[-6].map), &special_lev,
							  (specialmaze *)0)) {
					yyerror("Can't write output file!!");
					exit(EXIT_FAILURE);
				    }
				}
				free_rooms(&special_lev);
				nrooms = 0;
				ncorridor = 0;
			}
			Free((yyvsp[-6].map));
		  }
#line 1943 "y_tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 251 "util/lev_comp.y" /* yacc.c:1646  */
    {
			if (index((yyvsp[0].map), '.'))
			    yyerror("Invalid dot ('.') in level name.");
			if ((int) strlen((yyvsp[0].map)) > 8)
			    yyerror("Level names limited to 8 characters.");
			(yyval.map) = (yyvsp[0].map);
			special_lev.nrmonst = special_lev.nrobjects = 0;
			n_mlist = n_olist = 0;
		  }
#line 1957 "y_tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 263 "util/lev_comp.y" /* yacc.c:1646  */
    {
			/* in case we're processing multiple files,
			   explicitly clear any stale settings */
			(void) memset((genericptr_t) &init_lev, 0,
					sizeof init_lev);
			init_lev.init_present = FALSE;
			(yyval.i) = 0;
		  }
#line 1970 "y_tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 272 "util/lev_comp.y" /* yacc.c:1646  */
    {
			init_lev.init_present = TRUE;
			init_lev.fg = what_map_char((char) (yyvsp[-10].i));
			if (init_lev.fg == INVALID_TYPE)
			    yyerror("Invalid foreground type.");
			init_lev.bg = what_map_char((char) (yyvsp[-8].i));
			if (init_lev.bg == INVALID_TYPE)
			    yyerror("Invalid background type.");
			init_lev.smoothed = (yyvsp[-6].i);
			init_lev.joined = (yyvsp[-4].i);
			if (init_lev.joined &&
			    init_lev.fg != CORR && init_lev.fg != ROOM)
			    yyerror("Invalid foreground type for joined map.");
			init_lev.lit = (yyvsp[-2].i);
			init_lev.walled = (yyvsp[0].i);
			(yyval.i) = 1;
		  }
#line 1992 "y_tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 296 "util/lev_comp.y" /* yacc.c:1646  */
    {
			(yyval.i) = 0;
		  }
#line 2000 "y_tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 300 "util/lev_comp.y" /* yacc.c:1646  */
    {
			(yyval.i) = lev_flags;
			lev_flags = 0;	/* clear for next user */
		  }
#line 2009 "y_tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 307 "util/lev_comp.y" /* yacc.c:1646  */
    {
			lev_flags |= (yyvsp[-2].i);
		  }
#line 2017 "y_tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 311 "util/lev_comp.y" /* yacc.c:1646  */
    {
			lev_flags |= (yyvsp[0].i);
		  }
#line 2025 "y_tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 321 "util/lev_comp.y" /* yacc.c:1646  */
    {
			int i, j;

			i = (int) strlen((yyvsp[0].map)) + 1;
			j = (int) strlen(tmpmessage);
			if (i + j > 255) {
			   yyerror("Message string too long (>256 characters)");
			} else {
			    if (j) tmpmessage[j++] = '\n';
			    (void) strncpy(tmpmessage+j, (yyvsp[0].map), i - 1);
			    tmpmessage[j + i - 1] = 0;
			}
			Free((yyvsp[0].map));
		  }
#line 2044 "y_tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 342 "util/lev_comp.y" /* yacc.c:1646  */
    {
			if(special_lev.nrobjects) {
			    yyerror("Object registers already initialized!");
			} else {
			    special_lev.nrobjects = n_olist;
			    special_lev.robjects = (char *) alloc(n_olist);
			    (void) memcpy((genericptr_t)special_lev.robjects,
					  (genericptr_t)olist, n_olist);
			}
		  }
#line 2059 "y_tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 353 "util/lev_comp.y" /* yacc.c:1646  */
    {
			if(special_lev.nrmonst) {
			    yyerror("Monster registers already initialized!");
			} else {
			    special_lev.nrmonst = n_mlist;
			    special_lev.rmonst = (char *) alloc(n_mlist);
			    (void) memcpy((genericptr_t)special_lev.rmonst,
					  (genericptr_t)mlist, n_mlist);
			  }
		  }
#line 2074 "y_tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 366 "util/lev_comp.y" /* yacc.c:1646  */
    {
			tmproom[nrooms] = New(room);
			tmproom[nrooms]->name = (char *) 0;
			tmproom[nrooms]->parent = (char *) 0;
			tmproom[nrooms]->rtype = 0;
			tmproom[nrooms]->rlit = 0;
			tmproom[nrooms]->xalign = ERR;
			tmproom[nrooms]->yalign = ERR;
			tmproom[nrooms]->x = 0;
			tmproom[nrooms]->y = 0;
			tmproom[nrooms]->w = 2;
			tmproom[nrooms]->h = 2;
			in_room = 1;
		  }
#line 2093 "y_tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 392 "util/lev_comp.y" /* yacc.c:1646  */
    {
			tmpcor[0] = New(corridor);
			tmpcor[0]->src.room = -1;
			ncorridor = 1;
		  }
#line 2103 "y_tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 404 "util/lev_comp.y" /* yacc.c:1646  */
    {
			tmpcor[ncorridor] = New(corridor);
			tmpcor[ncorridor]->src.room = (yyvsp[-2].corpos).room;
			tmpcor[ncorridor]->src.wall = (yyvsp[-2].corpos).wall;
			tmpcor[ncorridor]->src.door = (yyvsp[-2].corpos).door;
			tmpcor[ncorridor]->dest.room = (yyvsp[0].corpos).room;
			tmpcor[ncorridor]->dest.wall = (yyvsp[0].corpos).wall;
			tmpcor[ncorridor]->dest.door = (yyvsp[0].corpos).door;
			ncorridor++;
			if (ncorridor >= MAX_OF_TYPE) {
				yyerror("Too many corridors in level!");
				ncorridor--;
			}
		  }
#line 2122 "y_tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 419 "util/lev_comp.y" /* yacc.c:1646  */
    {
			tmpcor[ncorridor] = New(corridor);
			tmpcor[ncorridor]->src.room = (yyvsp[-2].corpos).room;
			tmpcor[ncorridor]->src.wall = (yyvsp[-2].corpos).wall;
			tmpcor[ncorridor]->src.door = (yyvsp[-2].corpos).door;
			tmpcor[ncorridor]->dest.room = -1;
			tmpcor[ncorridor]->dest.wall = (yyvsp[0].i);
			ncorridor++;
			if (ncorridor >= MAX_OF_TYPE) {
				yyerror("Too many corridors in level!");
				ncorridor--;
			}
		  }
#line 2140 "y_tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 435 "util/lev_comp.y" /* yacc.c:1646  */
    {
			if ((unsigned) (yyvsp[-5].i) >= nrooms)
			    yyerror("Wrong room number!");
			(yyval.corpos).room = (yyvsp[-5].i);
			(yyval.corpos).wall = (yyvsp[-3].i);
			(yyval.corpos).door = (yyvsp[-1].i);
		  }
#line 2152 "y_tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 445 "util/lev_comp.y" /* yacc.c:1646  */
    {
			store_room();
		  }
#line 2160 "y_tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 449 "util/lev_comp.y" /* yacc.c:1646  */
    {
			store_room();
		  }
#line 2168 "y_tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 455 "util/lev_comp.y" /* yacc.c:1646  */
    {
			tmproom[nrooms] = New(room);
			tmproom[nrooms]->parent = (yyvsp[-1].map);
			tmproom[nrooms]->name = (char *) 0;
			tmproom[nrooms]->rtype = (yyvsp[-9].i);
			tmproom[nrooms]->rlit = (yyvsp[-7].i);
			tmproom[nrooms]->filled = (yyvsp[0].i);
			tmproom[nrooms]->xalign = ERR;
			tmproom[nrooms]->yalign = ERR;
			tmproom[nrooms]->x = current_coord.x;
			tmproom[nrooms]->y = current_coord.y;
			tmproom[nrooms]->w = current_size.width;
			tmproom[nrooms]->h = current_size.height;
			in_room = 1;
		  }
#line 2188 "y_tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 473 "util/lev_comp.y" /* yacc.c:1646  */
    {
			tmproom[nrooms] = New(room);
			tmproom[nrooms]->name = (char *) 0;
			tmproom[nrooms]->parent = (char *) 0;
			tmproom[nrooms]->rtype = (yyvsp[-9].i);
			tmproom[nrooms]->rlit = (yyvsp[-7].i);
			tmproom[nrooms]->filled = (yyvsp[0].i);
			tmproom[nrooms]->xalign = current_align.x;
			tmproom[nrooms]->yalign = current_align.y;
			tmproom[nrooms]->x = current_coord.x;
			tmproom[nrooms]->y = current_coord.y;
			tmproom[nrooms]->w = current_size.width;
			tmproom[nrooms]->h = current_size.height;
			in_room = 1;
		  }
#line 2208 "y_tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 491 "util/lev_comp.y" /* yacc.c:1646  */
    {
			(yyval.i) = 1;
		  }
#line 2216 "y_tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 495 "util/lev_comp.y" /* yacc.c:1646  */
    {
			(yyval.i) = (yyvsp[0].i);
		  }
#line 2224 "y_tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 501 "util/lev_comp.y" /* yacc.c:1646  */
    {
			if ( (yyvsp[-3].i) < 1 || (yyvsp[-3].i) > 5 ||
			    (yyvsp[-1].i) < 1 || (yyvsp[-1].i) > 5 ) {
			    yyerror("Room position should be between 1 & 5!");
			} else {
			    current_coord.x = (yyvsp[-3].i);
			    current_coord.y = (yyvsp[-1].i);
			}
		  }
#line 2238 "y_tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 511 "util/lev_comp.y" /* yacc.c:1646  */
    {
			current_coord.x = current_coord.y = ERR;
		  }
#line 2246 "y_tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 517 "util/lev_comp.y" /* yacc.c:1646  */
    {
			if ( (yyvsp[-3].i) < 0 || (yyvsp[-1].i) < 0) {
			    yyerror("Invalid subroom position !");
			} else {
			    current_coord.x = (yyvsp[-3].i);
			    current_coord.y = (yyvsp[-1].i);
			}
		  }
#line 2259 "y_tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 526 "util/lev_comp.y" /* yacc.c:1646  */
    {
			current_coord.x = current_coord.y = ERR;
		  }
#line 2267 "y_tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 532 "util/lev_comp.y" /* yacc.c:1646  */
    {
			current_align.x = (yyvsp[-3].i);
			current_align.y = (yyvsp[-1].i);
		  }
#line 2276 "y_tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 537 "util/lev_comp.y" /* yacc.c:1646  */
    {
			current_align.x = current_align.y = ERR;
		  }
#line 2284 "y_tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 543 "util/lev_comp.y" /* yacc.c:1646  */
    {
			current_size.width = (yyvsp[-3].i);
			current_size.height = (yyvsp[-1].i);
		  }
#line 2293 "y_tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 548 "util/lev_comp.y" /* yacc.c:1646  */
    {
			current_size.height = current_size.width = ERR;
		  }
#line 2301 "y_tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 574 "util/lev_comp.y" /* yacc.c:1646  */
    {
			if (tmproom[nrooms]->name)
			    yyerror("This room already has a name!");
			else
			    tmproom[nrooms]->name = (yyvsp[0].map);
		  }
#line 2312 "y_tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 583 "util/lev_comp.y" /* yacc.c:1646  */
    {
			if (tmproom[nrooms]->chance)
			    yyerror("This room already assigned a chance!");
			else if (tmproom[nrooms]->rtype == OROOM)
			    yyerror("Only typed rooms can have a chance!");
			else if ((yyvsp[0].i) < 1 || (yyvsp[0].i) > 99)
			    yyerror("The chance is supposed to be percentile.");
			else
			    tmproom[nrooms]->chance = (yyvsp[0].i);
		   }
#line 2327 "y_tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 596 "util/lev_comp.y" /* yacc.c:1646  */
    {
			/* ERR means random here */
			if ((yyvsp[-2].i) == ERR && (yyvsp[0].i) != ERR) {
		     yyerror("If the door wall is random, so must be its pos!");
			    tmprdoor[ndoor] = (struct room_door *)0;
			} else {
			    tmprdoor[ndoor] = New(room_door);
			    tmprdoor[ndoor]->secret = (yyvsp[-6].i);
			    tmprdoor[ndoor]->mask = (yyvsp[-4].i);
			    tmprdoor[ndoor]->wall = (yyvsp[-2].i);
			    tmprdoor[ndoor]->pos = (yyvsp[0].i);
			    tmprdoor[ndoor]->arti_key = 0;
			}
		  }
#line 2346 "y_tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 611 "util/lev_comp.y" /* yacc.c:1646  */
    {
			if (tmprdoor[ndoor]) {
			    ndoor++;
			    if (ndoor >= MAX_OF_TYPE) {
				    yyerror("Too many doors in room!");
				    ndoor--;
			    }
			}
		  }
#line 2360 "y_tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 627 "util/lev_comp.y" /* yacc.c:1646  */
    {
			int token = get_artifact_id((yyvsp[0].map));
			if (token == ERR) {
			    char ebuf[100];
			    Sprintf(ebuf, "Undefined artifact key \"%s\"", (yyvsp[0].map));
			    yyerror(ebuf);
			}
			else if (tmprdoor[ndoor])
			    tmprdoor[ndoor]->arti_key = token;
		  }
#line 2375 "y_tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 653 "util/lev_comp.y" /* yacc.c:1646  */
    {
			maze.filling = (schar) (yyvsp[0].i);
			if (index((yyvsp[-2].map), '.'))
			    yyerror("Invalid dot ('.') in level name.");
			if ((int) strlen((yyvsp[-2].map)) > 8)
			    yyerror("Level names limited to 8 characters.");
			(yyval.map) = (yyvsp[-2].map);
			in_room = 0;
			n_plist = n_mlist = n_olist = 0;
		  }
#line 2390 "y_tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 666 "util/lev_comp.y" /* yacc.c:1646  */
    {
			(yyval.i) = get_floor_type((char)(yyvsp[0].i));
		  }
#line 2398 "y_tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 670 "util/lev_comp.y" /* yacc.c:1646  */
    {
			(yyval.i) = -1;
		  }
#line 2406 "y_tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 680 "util/lev_comp.y" /* yacc.c:1646  */
    {
			store_part();
		  }
#line 2414 "y_tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 686 "util/lev_comp.y" /* yacc.c:1646  */
    {
			tmppart[npart] = New(mazepart);
			tmppart[npart]->halign = 1;
			tmppart[npart]->valign = 1;
			tmppart[npart]->nrobjects = 0;
			tmppart[npart]->nloc = 0;
			tmppart[npart]->nrmonst = 0;
			tmppart[npart]->xsize = 1;
			tmppart[npart]->ysize = 1;
			tmppart[npart]->map = (char **) alloc(sizeof(char *));
			tmppart[npart]->map[0] = (char *) alloc(1);
			tmppart[npart]->map[0][0] = STONE;
			max_x_map = COLNO-1;
			max_y_map = ROWNO;
		  }
#line 2434 "y_tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 702 "util/lev_comp.y" /* yacc.c:1646  */
    {
			tmppart[npart] = New(mazepart);
			tmppart[npart]->halign = (yyvsp[-1].i) % 10;
			tmppart[npart]->valign = (yyvsp[-1].i) / 10;
			tmppart[npart]->nrobjects = 0;
			tmppart[npart]->nloc = 0;
			tmppart[npart]->nrmonst = 0;
			scan_map((yyvsp[0].map));
			Free((yyvsp[0].map));
		  }
#line 2449 "y_tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 715 "util/lev_comp.y" /* yacc.c:1646  */
    {
			(yyval.i) = (yyvsp[-2].i) + ((yyvsp[0].i) * 10);
		  }
#line 2457 "y_tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 733 "util/lev_comp.y" /* yacc.c:1646  */
    {
			if (tmppart[npart]->nrobjects) {
			    yyerror("Object registers already initialized!");
			} else {
			    tmppart[npart]->robjects = (char *)alloc(n_olist);
			    (void) memcpy((genericptr_t)tmppart[npart]->robjects,
					  (genericptr_t)olist, n_olist);
			    tmppart[npart]->nrobjects = n_olist;
			}
		  }
#line 2472 "y_tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 744 "util/lev_comp.y" /* yacc.c:1646  */
    {
			if (tmppart[npart]->nlocset)
			    yyerror("Location registers already initialized!");
			else
			    store_place_list(npart, 0, n_plist, plist);
			n_plist = 0;
		  }
#line 2484 "y_tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 752 "util/lev_comp.y" /* yacc.c:1646  */
    {
			if ((yyvsp[-3].i) >= MAX_REGISTERS)
			    yyerror("Register Index overflow!");
			else
			    store_place_list(npart, (yyvsp[-3].i), n_plist, plist);
			n_plist = 0;
		  }
#line 2496 "y_tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 760 "util/lev_comp.y" /* yacc.c:1646  */
    {
			if (tmppart[npart]->nrmonst) {
			    yyerror("Monster registers already initialized!");
			} else {
			    tmppart[npart]->rmonst = (char *) alloc(n_mlist);
			    (void) memcpy((genericptr_t)tmppart[npart]->rmonst,
					  (genericptr_t)mlist, n_mlist);
			    tmppart[npart]->nrmonst = n_mlist;
			}
		  }
#line 2511 "y_tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 771 "util/lev_comp.y" /* yacc.c:1646  */
    {
			/* nothing */
		  }
#line 2519 "y_tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 777 "util/lev_comp.y" /* yacc.c:1646  */
    {
			if (n_olist < MAX_REGISTERS)
			    olist[n_olist++] = (yyvsp[0].i);
			else
			    yyerror("Object list too long!");
		  }
#line 2530 "y_tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 784 "util/lev_comp.y" /* yacc.c:1646  */
    {
			if (n_olist < MAX_REGISTERS)
			    olist[n_olist++] = (yyvsp[-2].i);
			else
			    yyerror("Object list too long!");
		  }
#line 2541 "y_tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 793 "util/lev_comp.y" /* yacc.c:1646  */
    {
			if (n_mlist < MAX_REGISTERS)
			    mlist[n_mlist++] = (yyvsp[0].i);
			else
			    yyerror("Monster list too long!");
		  }
#line 2552 "y_tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 800 "util/lev_comp.y" /* yacc.c:1646  */
    {
			if (n_mlist < MAX_REGISTERS)
			    mlist[n_mlist++] = (yyvsp[-2].i);
			else
			    yyerror("Monster list too long!");
		  }
#line 2563 "y_tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 809 "util/lev_comp.y" /* yacc.c:1646  */
    {
			if (n_plist < MAX_REGISTERS)
			    plist[n_plist++] = current_coord;
			else
			    yyerror("Location list too long!");
		  }
#line 2574 "y_tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 816 "util/lev_comp.y" /* yacc.c:1646  */
    {
			if (n_plist < MAX_REGISTERS)
			    plist[n_plist++] = current_coord;
			else
			    yyerror("Location list too long!");
		  }
#line 2585 "y_tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 853 "util/lev_comp.y" /* yacc.c:1646  */
    {
			tmpmonst[nmons] = New(monster);
			tmpmonst[nmons]->x = current_coord.x;
			tmpmonst[nmons]->y = current_coord.y;
			tmpmonst[nmons]->class = (yyvsp[-4].i);
			tmpmonst[nmons]->peaceful = -1; /* no override */
			tmpmonst[nmons]->asleep = -1;
			tmpmonst[nmons]->align = - MAX_REGISTERS - 2;
			tmpmonst[nmons]->name.str = 0;
			tmpmonst[nmons]->appear = 0;
			tmpmonst[nmons]->appear_as.str = 0;
			tmpmonst[nmons]->chance = (yyvsp[-6].i);
			tmpmonst[nmons]->id = NON_PM;
			if (!in_room)
			    check_coord(current_coord.x, current_coord.y,
					"Monster");
			if ((yyvsp[-2].map)) {
			    int token = get_monster_id((yyvsp[-2].map), (char) (yyvsp[-4].i));
			    if (token == ERR)
				yywarning(
			      "Invalid monster name!  Making random monster.");
			    else
				tmpmonst[nmons]->id = token;
			    Free((yyvsp[-2].map));
			}
		  }
#line 2616 "y_tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 880 "util/lev_comp.y" /* yacc.c:1646  */
    {
			if (++nmons >= MAX_OF_TYPE) {
			    yyerror("Too many monsters in room or mazepart!");
			    nmons--;
			}
		  }
#line 2627 "y_tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 893 "util/lev_comp.y" /* yacc.c:1646  */
    {
			tmpmonst[nmons]->name.str = (yyvsp[0].map);
		  }
#line 2635 "y_tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 897 "util/lev_comp.y" /* yacc.c:1646  */
    {
			tmpmonst[nmons]->peaceful = (yyvsp[0].i);
		  }
#line 2643 "y_tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 901 "util/lev_comp.y" /* yacc.c:1646  */
    {
			tmpmonst[nmons]->asleep = (yyvsp[0].i);
		  }
#line 2651 "y_tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 905 "util/lev_comp.y" /* yacc.c:1646  */
    {
			tmpmonst[nmons]->align = (yyvsp[0].i);
		  }
#line 2659 "y_tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 909 "util/lev_comp.y" /* yacc.c:1646  */
    {
			tmpmonst[nmons]->appear = (yyvsp[-1].i);
			tmpmonst[nmons]->appear_as.str = (yyvsp[0].map);
		  }
#line 2668 "y_tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 916 "util/lev_comp.y" /* yacc.c:1646  */
    {
		  }
#line 2675 "y_tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 919 "util/lev_comp.y" /* yacc.c:1646  */
    {
			/* 1: is contents of preceeding object with 2 */
			/* 2: is a container */
			/* 0: neither */
			tmpobj[nobj-1]->containment = 2;
		  }
#line 2686 "y_tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 928 "util/lev_comp.y" /* yacc.c:1646  */
    {
			tmpobj[nobj] = New(object);
			tmpobj[nobj]->class = (yyvsp[-2].i);
			tmpobj[nobj]->corpsenm = NON_PM;
			tmpobj[nobj]->curse_state = -1;
			tmpobj[nobj]->name.str = 0;
			tmpobj[nobj]->chance = (yyvsp[-4].i);
			tmpobj[nobj]->id = -1;
			tmpobj[nobj]->oflags = 0;
			if ((yyvsp[0].map)) {
			    int token = get_object_id((yyvsp[0].map), (yyvsp[-2].i));
			    if (token == ERR)
#ifdef RANDOM_DRAGON_SCALES
			    	if (!strcmp((yyvsp[0].map), "dragon scales"))
					tmpobj[nobj]->id = RND_DRAGON_SCALES;
				else if(!strcmp((yyvsp[0].map), "dragon scale mail"))
					tmpobj[nobj]->id = RND_DRAGON_SCALE_MAIL;
				else
#endif
					yywarning(
					"Illegal object name!  Making random object.");
			     else
				tmpobj[nobj]->id = token;
			    Free((yyvsp[0].map));
			}
		  }
#line 2717 "y_tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 955 "util/lev_comp.y" /* yacc.c:1646  */
    {
			if (++nobj >= MAX_OF_TYPE) {
			    yyerror("Too many objects in room or mazepart!");
			    nobj--;
			}
		  }
#line 2728 "y_tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 964 "util/lev_comp.y" /* yacc.c:1646  */
    {
			tmpobj[nobj]->containment = 0;
			tmpobj[nobj]->x = current_coord.x;
			tmpobj[nobj]->y = current_coord.y;
			if (!in_room)
			    check_coord(current_coord.x, current_coord.y,
					"Object");
		  }
#line 2741 "y_tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 973 "util/lev_comp.y" /* yacc.c:1646  */
    {
			tmpobj[nobj]->containment = 1;
			/* random coordinate, will be overridden anyway */
			tmpobj[nobj]->x = -MAX_REGISTERS-2;
			tmpobj[nobj]->y = -MAX_REGISTERS-2;
		  }
#line 2752 "y_tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 982 "util/lev_comp.y" /* yacc.c:1646  */
    {
			tmpobj[nobj]->spe = -127;
	/* Note below: we're trying to make as many of these optional as
	 * possible.  We clearly can't make curse_state, enchantment, and
	 * monster_id _all_ optional, since ",random" would be ambiguous.
	 * We can't even just make enchantment mandatory, since if we do that
	 * alone, ",random" requires too much lookahead to parse.
	 */
		  }
#line 2766 "y_tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 992 "util/lev_comp.y" /* yacc.c:1646  */
    {
		  }
#line 2773 "y_tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 995 "util/lev_comp.y" /* yacc.c:1646  */
    {
		  }
#line 2780 "y_tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 998 "util/lev_comp.y" /* yacc.c:1646  */
    {
		  }
#line 2787 "y_tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 1003 "util/lev_comp.y" /* yacc.c:1646  */
    {
		   	if (nobj > 0)
		   	   tmpobj[nobj-1]->oflags = (yyvsp[0].i);
			else yyerror("Need an object before object flags!");
		  }
#line 2797 "y_tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 1011 "util/lev_comp.y" /* yacc.c:1646  */
    {
		     (yyval.i) = ((yyvsp[-2].i) | (yyvsp[0].i));
		  }
#line 2805 "y_tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 1015 "util/lev_comp.y" /* yacc.c:1646  */
    {
		     (yyval.i) = (yyvsp[0].i);
		  }
#line 2813 "y_tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 1021 "util/lev_comp.y" /* yacc.c:1646  */
    {
			tmpobj[nobj]->curse_state = -1;
		  }
#line 2821 "y_tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 1025 "util/lev_comp.y" /* yacc.c:1646  */
    {
			tmpobj[nobj]->curse_state = (yyvsp[0].i);
		  }
#line 2829 "y_tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 1031 "util/lev_comp.y" /* yacc.c:1646  */
    {
			int token = get_monster_id((yyvsp[0].map), (char)0);
			if (token == ERR)	/* "random" */
			    tmpobj[nobj]->corpsenm = NON_PM - 1;
			else
			    tmpobj[nobj]->corpsenm = token;
			Free((yyvsp[0].map));
		  }
#line 2842 "y_tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 1042 "util/lev_comp.y" /* yacc.c:1646  */
    {
			tmpobj[nobj]->spe = -127;
		  }
#line 2850 "y_tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 1046 "util/lev_comp.y" /* yacc.c:1646  */
    {
			tmpobj[nobj]->spe = (yyvsp[0].i);
		  }
#line 2858 "y_tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 1053 "util/lev_comp.y" /* yacc.c:1646  */
    {
		  }
#line 2865 "y_tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 1056 "util/lev_comp.y" /* yacc.c:1646  */
    {
			tmpobj[nobj]->name.str = (yyvsp[0].map);
		  }
#line 2873 "y_tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 1062 "util/lev_comp.y" /* yacc.c:1646  */
    {
			tmpdoor[ndoor] = New(door);
			tmpdoor[ndoor]->x = current_coord.x;
			tmpdoor[ndoor]->y = current_coord.y;
			tmpdoor[ndoor]->mask = (yyvsp[-2].i);
			tmpdoor[ndoor]->arti_key = 0;
			if(current_coord.x >= 0 && current_coord.y >= 0 &&
			   tmpmap[current_coord.y][current_coord.x] != DOOR &&
			   tmpmap[current_coord.y][current_coord.x] != SDOOR)
			    yyerror("Door decl doesn't match the map");
		  }
#line 2889 "y_tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 1074 "util/lev_comp.y" /* yacc.c:1646  */
    {
			if (++ndoor >= MAX_OF_TYPE) {
			    yyerror("Too many doors in mazepart!");
			    ndoor--;
			}
		  }
#line 2900 "y_tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 1087 "util/lev_comp.y" /* yacc.c:1646  */
    {
			int token = get_artifact_id((yyvsp[0].map));
			if (token == ERR) {
			    char ebuf[100];
			    Sprintf(ebuf, "Undefined artifact key \"%s\"", (yyvsp[0].map));
			    yyerror(ebuf);
			}
			else
			    tmpdoor[ndoor]->arti_key = token;
		  }
#line 2915 "y_tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 1100 "util/lev_comp.y" /* yacc.c:1646  */
    {
			tmptrap[ntrap] = New(trap);
			tmptrap[ntrap]->x = current_coord.x;
			tmptrap[ntrap]->y = current_coord.y;
			tmptrap[ntrap]->type = (yyvsp[-2].i);
			tmptrap[ntrap]->chance = (yyvsp[-4].i);
			if (!in_room)
			    check_coord(current_coord.x, current_coord.y,
					"Trap");
			if (++ntrap >= MAX_OF_TYPE) {
				yyerror("Too many traps in room or mazepart!");
				ntrap--;
			}
		  }
#line 2934 "y_tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 1117 "util/lev_comp.y" /* yacc.c:1646  */
    {
		        int x, y, dir;

			tmpdb[ndb] = New(drawbridge);
			x = tmpdb[ndb]->x = current_coord.x;
			y = tmpdb[ndb]->y = current_coord.y;
			/* convert dir from a DIRECTION to a DB_DIR */
			dir = (yyvsp[-2].i);
			switch(dir) {
			case W_NORTH: dir = DB_NORTH; y--; break;
			case W_SOUTH: dir = DB_SOUTH; y++; break;
			case W_EAST:  dir = DB_EAST;  x++; break;
			case W_WEST:  dir = DB_WEST;  x--; break;
			default:
			    yyerror("Invalid drawbridge direction");
			    break;
			}
			tmpdb[ndb]->dir = dir;
			if (current_coord.x >= 0 && current_coord.y >= 0 &&
			    !IS_WALL(tmpmap[y][x])) {
			    char ebuf[60];
			    Sprintf(ebuf,
				    "Wall needed for drawbridge (%02d, %02d)",
				    current_coord.x, current_coord.y);
			    yyerror(ebuf);
			}

			if ( (yyvsp[0].i) == D_ISOPEN )
			    tmpdb[ndb]->db_open = 1;
			else if ( (yyvsp[0].i) == D_CLOSED )
			    tmpdb[ndb]->db_open = 0;
			else
			    yyerror("A drawbridge can only be open or closed!");
			ndb++;
			if (ndb >= MAX_OF_TYPE) {
				yyerror("Too many drawbridges in mazepart!");
				ndb--;
			}
		   }
#line 2978 "y_tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 1159 "util/lev_comp.y" /* yacc.c:1646  */
    {
			tmpwalk[nwalk] = New(walk);
			tmpwalk[nwalk]->x = current_coord.x;
			tmpwalk[nwalk]->y = current_coord.y;
			tmpwalk[nwalk]->dir = (yyvsp[0].i);
			nwalk++;
			if (nwalk >= MAX_OF_TYPE) {
				yyerror("Too many mazewalks in mazepart!");
				nwalk--;
			}
		  }
#line 2994 "y_tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 1173 "util/lev_comp.y" /* yacc.c:1646  */
    {
			wallify_map();
		  }
#line 3002 "y_tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 1179 "util/lev_comp.y" /* yacc.c:1646  */
    {
			tmplad[nlad] = New(lad);
			tmplad[nlad]->x = current_coord.x;
			tmplad[nlad]->y = current_coord.y;
			tmplad[nlad]->up = (yyvsp[0].i);
			if (!in_room)
			    check_coord(current_coord.x, current_coord.y,
					"Ladder");
			nlad++;
			if (nlad >= MAX_OF_TYPE) {
				yyerror("Too many ladders in mazepart!");
				nlad--;
			}
		  }
#line 3021 "y_tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 1196 "util/lev_comp.y" /* yacc.c:1646  */
    {
			tmpstair[nstair] = New(stair);
			tmpstair[nstair]->x = current_coord.x;
			tmpstair[nstair]->y = current_coord.y;
			tmpstair[nstair]->up = (yyvsp[0].i);
			if (!in_room)
			    check_coord(current_coord.x, current_coord.y,
					"Stairway");
			nstair++;
			if (nstair >= MAX_OF_TYPE) {
				yyerror("Too many stairs in room or mazepart!");
				nstair--;
			}
		  }
#line 3040 "y_tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 1213 "util/lev_comp.y" /* yacc.c:1646  */
    {
			tmplreg[nlreg] = New(lev_region);
			tmplreg[nlreg]->in_islev = (yyvsp[0].i);
			tmplreg[nlreg]->inarea.x1 = current_region.x1;
			tmplreg[nlreg]->inarea.y1 = current_region.y1;
			tmplreg[nlreg]->inarea.x2 = current_region.x2;
			tmplreg[nlreg]->inarea.y2 = current_region.y2;
		  }
#line 3053 "y_tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 1222 "util/lev_comp.y" /* yacc.c:1646  */
    {
			tmplreg[nlreg]->del_islev = (yyvsp[-2].i);
			tmplreg[nlreg]->delarea.x1 = current_region.x1;
			tmplreg[nlreg]->delarea.y1 = current_region.y1;
			tmplreg[nlreg]->delarea.x2 = current_region.x2;
			tmplreg[nlreg]->delarea.y2 = current_region.y2;
			if((yyvsp[0].i))
			    tmplreg[nlreg]->rtype = LR_UPSTAIR;
			else
			    tmplreg[nlreg]->rtype = LR_DOWNSTAIR;
			tmplreg[nlreg]->rname.str = 0;
			nlreg++;
			if (nlreg >= MAX_OF_TYPE) {
				yyerror("Too many levregions in mazepart!");
				nlreg--;
			}
		  }
#line 3075 "y_tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 1242 "util/lev_comp.y" /* yacc.c:1646  */
    {
		   	if ((unsigned) (yyvsp[-3].i) != nrndlreg)
			    yyerror("Wrong random region number!");
			tmprndlreg[nrndlreg] = New(lev_region);
			tmprndlreg[nrndlreg]->in_islev = (yyvsp[0].i);
			tmprndlreg[nrndlreg]->inarea.x1 = current_region.x1;
			tmprndlreg[nrndlreg]->inarea.y1 = current_region.y1;
			tmprndlreg[nrndlreg]->inarea.x2 = current_region.x2;
			tmprndlreg[nrndlreg]->inarea.y2 = current_region.y2;
		  }
#line 3090 "y_tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 1253 "util/lev_comp.y" /* yacc.c:1646  */
    {
		   	tmprndlreg[nrndlreg]->del_islev = (yyvsp[0].i);
			tmprndlreg[nrndlreg]->delarea.x1 = current_region.x1;
			tmprndlreg[nrndlreg]->delarea.y1 = current_region.y1;
			tmprndlreg[nrndlreg]->delarea.x2 = current_region.x2;
			tmprndlreg[nrndlreg]->delarea.y2 = current_region.y2;
			tmprndlreg[nrndlreg]->rtype = 0;
			tmprndlreg[nrndlreg]->rname.str = (char *)0;
			nrndlreg++;
			if (nrndlreg >= MAX_REGISTERS) {
				yyerror("Too many random regions!");
				nrndlreg--;
			}
		  }
#line 3109 "y_tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 1270 "util/lev_comp.y" /* yacc.c:1646  */
    {
			tmplreg[nlreg] = New(lev_region);
			tmplreg[nlreg]->in_islev = (yyvsp[0].i);
			tmplreg[nlreg]->inarea.x1 = current_region.x1;
			tmplreg[nlreg]->inarea.y1 = current_region.y1;
			tmplreg[nlreg]->inarea.x2 = current_region.x2;
			tmplreg[nlreg]->inarea.y2 = current_region.y2;
		  }
#line 3122 "y_tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 1279 "util/lev_comp.y" /* yacc.c:1646  */
    {
			tmplreg[nlreg]->del_islev = (yyvsp[-2].i);
			tmplreg[nlreg]->delarea.x1 = current_region.x1;
			tmplreg[nlreg]->delarea.y1 = current_region.y1;
			tmplreg[nlreg]->delarea.x2 = current_region.x2;
			tmplreg[nlreg]->delarea.y2 = current_region.y2;
			tmplreg[nlreg]->rtype = LR_PORTAL;
			tmplreg[nlreg]->rname.str = (yyvsp[0].map);
			nlreg++;
			if (nlreg >= MAX_OF_TYPE) {
				yyerror("Too many levregions in mazepart!");
				nlreg--;
			}
		  }
#line 3141 "y_tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 1296 "util/lev_comp.y" /* yacc.c:1646  */
    {
			tmplreg[nlreg] = New(lev_region);
			tmplreg[nlreg]->in_islev = (yyvsp[0].i);
			tmplreg[nlreg]->inarea.x1 = current_region.x1;
			tmplreg[nlreg]->inarea.y1 = current_region.y1;
			tmplreg[nlreg]->inarea.x2 = current_region.x2;
			tmplreg[nlreg]->inarea.y2 = current_region.y2;
		  }
#line 3154 "y_tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 1305 "util/lev_comp.y" /* yacc.c:1646  */
    {
			tmplreg[nlreg]->del_islev = (yyvsp[0].i);
			tmplreg[nlreg]->delarea.x1 = current_region.x1;
			tmplreg[nlreg]->delarea.y1 = current_region.y1;
			tmplreg[nlreg]->delarea.x2 = current_region.x2;
			tmplreg[nlreg]->delarea.y2 = current_region.y2;
		  }
#line 3166 "y_tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 1313 "util/lev_comp.y" /* yacc.c:1646  */
    {
			switch((yyvsp[0].i)) {
			case -1: tmplreg[nlreg]->rtype = LR_TELE; break;
			case 0: tmplreg[nlreg]->rtype = LR_DOWNTELE; break;
			case 1: tmplreg[nlreg]->rtype = LR_UPTELE; break;
			}
			tmplreg[nlreg]->rname.str = 0;
			nlreg++;
			if (nlreg >= MAX_OF_TYPE) {
				yyerror("Too many levregions in mazepart!");
				nlreg--;
			}
		  }
#line 3184 "y_tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 1329 "util/lev_comp.y" /* yacc.c:1646  */
    {
			tmplreg[nlreg] = New(lev_region);
			tmplreg[nlreg]->in_islev = (yyvsp[0].i);
			tmplreg[nlreg]->inarea.x1 = current_region.x1;
			tmplreg[nlreg]->inarea.y1 = current_region.y1;
			tmplreg[nlreg]->inarea.x2 = current_region.x2;
			tmplreg[nlreg]->inarea.y2 = current_region.y2;
		  }
#line 3197 "y_tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 1338 "util/lev_comp.y" /* yacc.c:1646  */
    {
			tmplreg[nlreg]->del_islev = (yyvsp[0].i);
			tmplreg[nlreg]->delarea.x1 = current_region.x1;
			tmplreg[nlreg]->delarea.y1 = current_region.y1;
			tmplreg[nlreg]->delarea.x2 = current_region.x2;
			tmplreg[nlreg]->delarea.y2 = current_region.y2;
			tmplreg[nlreg]->rtype = LR_BRANCH;
			tmplreg[nlreg]->rname.str = 0;
			nlreg++;
			if (nlreg >= MAX_OF_TYPE) {
				yyerror("Too many levregions in mazepart!");
				nlreg--;
			}
		  }
#line 3216 "y_tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 1355 "util/lev_comp.y" /* yacc.c:1646  */
    {
			(yyval.i) = -1;
		  }
#line 3224 "y_tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 1359 "util/lev_comp.y" /* yacc.c:1646  */
    {
			(yyval.i) = (yyvsp[0].i);
		  }
#line 3232 "y_tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 1365 "util/lev_comp.y" /* yacc.c:1646  */
    {
			(yyval.i) = 0;
		  }
#line 3240 "y_tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 1369 "util/lev_comp.y" /* yacc.c:1646  */
    {
/* This series of if statements is a hack for MSC 5.1.  It seems that its
   tiny little brain cannot compile if these are all one big if statement. */
			if ((yyvsp[-7].i) <= 0 || (yyvsp[-7].i) >= COLNO)
				yyerror("Region out of level range!");
			else if ((yyvsp[-5].i) < 0 || (yyvsp[-5].i) >= ROWNO)
				yyerror("Region out of level range!");
			else if ((yyvsp[-3].i) <= 0 || (yyvsp[-3].i) >= COLNO)
				yyerror("Region out of level range!");
			else if ((yyvsp[-1].i) < 0 || (yyvsp[-1].i) >= ROWNO)
				yyerror("Region out of level range!");
			current_region.x1 = (yyvsp[-7].i);
			current_region.y1 = (yyvsp[-5].i);
			current_region.x2 = (yyvsp[-3].i);
			current_region.y2 = (yyvsp[-1].i);
			(yyval.i) = 1;
		  }
#line 3262 "y_tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 1389 "util/lev_comp.y" /* yacc.c:1646  */
    {
			tmpfountain[nfountain] = New(fountain);
			tmpfountain[nfountain]->x = current_coord.x;
			tmpfountain[nfountain]->y = current_coord.y;
			if (!in_room)
			    check_coord(current_coord.x, current_coord.y,
					"Fountain");
			nfountain++;
			if (nfountain >= MAX_OF_TYPE) {
			    yyerror("Too many fountains in room or mazepart!");
			    nfountain--;
			}
		  }
#line 3280 "y_tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 1405 "util/lev_comp.y" /* yacc.c:1646  */
    {
			tmpsink[nsink] = New(sink);
			tmpsink[nsink]->x = current_coord.x;
			tmpsink[nsink]->y = current_coord.y;
			nsink++;
			if (nsink >= MAX_OF_TYPE) {
				yyerror("Too many sinks in room!");
				nsink--;
			}
		  }
#line 3295 "y_tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 1418 "util/lev_comp.y" /* yacc.c:1646  */
    {
			tmppool[npool] = New(pool);
			tmppool[npool]->x = current_coord.x;
			tmppool[npool]->y = current_coord.y;
			npool++;
			if (npool >= MAX_OF_TYPE) {
				yyerror("Too many pools in room!");
				npool--;
			}
		  }
#line 3310 "y_tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 1431 "util/lev_comp.y" /* yacc.c:1646  */
    {
			tmpdig[ndig] = New(digpos);
			tmpdig[ndig]->x1 = current_region.x1;
			tmpdig[ndig]->y1 = current_region.y1;
			tmpdig[ndig]->x2 = current_region.x2;
			tmpdig[ndig]->y2 = current_region.y2;
			ndig++;
			if (ndig >= MAX_OF_TYPE) {
				yyerror("Too many diggables in mazepart!");
				ndig--;
			}
		  }
#line 3327 "y_tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 1446 "util/lev_comp.y" /* yacc.c:1646  */
    {
			tmppass[npass] = New(digpos);
			tmppass[npass]->x1 = current_region.x1;
			tmppass[npass]->y1 = current_region.y1;
			tmppass[npass]->x2 = current_region.x2;
			tmppass[npass]->y2 = current_region.y2;
			npass++;
			if (npass >= 32) {
				yyerror("Too many passwalls in mazepart!");
				npass--;
			}
		  }
#line 3344 "y_tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 1461 "util/lev_comp.y" /* yacc.c:1646  */
    {
			tmpreg[nreg] = New(region);
			tmpreg[nreg]->x1 = current_region.x1;
			tmpreg[nreg]->y1 = current_region.y1;
			tmpreg[nreg]->x2 = current_region.x2;
			tmpreg[nreg]->y2 = current_region.y2;
			tmpreg[nreg]->rlit = (yyvsp[-3].i);
			tmpreg[nreg]->rtype = (yyvsp[-1].i);
			if((yyvsp[0].i) & 1) tmpreg[nreg]->rtype += MAXRTYPE+1;
			tmpreg[nreg]->rirreg = (((yyvsp[0].i) & 2) != 0);
			if(current_region.x1 > current_region.x2 ||
			   current_region.y1 > current_region.y2)
			   yyerror("Region start > end!");
			if(tmpreg[nreg]->rtype == VAULT &&
			   (tmpreg[nreg]->rirreg ||
			    (tmpreg[nreg]->x2 - tmpreg[nreg]->x1 != 1) ||
			    (tmpreg[nreg]->y2 - tmpreg[nreg]->y1 != 1)))
				yyerror("Vaults must be exactly 2x2!");
			if(want_warnings && !tmpreg[nreg]->rirreg &&
			   current_region.x1 > 0 && current_region.y1 > 0 &&
			   current_region.x2 < (int)max_x_map &&
			   current_region.y2 < (int)max_y_map) {
			    /* check for walls in the room */
			    char ebuf[60];
			    register int x, y, nrock = 0;

			    for(y=current_region.y1; y<=current_region.y2; y++)
				for(x=current_region.x1;
				    x<=current_region.x2; x++)
				    if(IS_ROCK(tmpmap[y][x]) ||
				       IS_DOOR(tmpmap[y][x])) nrock++;
			    if(nrock) {
				Sprintf(ebuf,
					"Rock in room (%02d,%02d,%02d,%02d)?!",
					current_region.x1, current_region.y1,
					current_region.x2, current_region.y2);
				yywarning(ebuf);
			    }
			    if (
		!IS_ROCK(tmpmap[current_region.y1-1][current_region.x1-1]) ||
		!IS_ROCK(tmpmap[current_region.y2+1][current_region.x1-1]) ||
		!IS_ROCK(tmpmap[current_region.y1-1][current_region.x2+1]) ||
		!IS_ROCK(tmpmap[current_region.y2+1][current_region.x2+1])) {
				Sprintf(ebuf,
				"NonRock edge in room (%02d,%02d,%02d,%02d)?!",
					current_region.x1, current_region.y1,
					current_region.x2, current_region.y2);
				yywarning(ebuf);
			    }
			} else if(tmpreg[nreg]->rirreg &&
		!IS_ROOM(tmpmap[current_region.y1][current_region.x1])) {
			    char ebuf[60];
			    Sprintf(ebuf,
				    "Rock in irregular room (%02d,%02d)?!",
				    current_region.x1, current_region.y1);
			    yyerror(ebuf);
			}
			nreg++;
			if (nreg >= MAX_OF_TYPE) {
				yyerror("Too many regions in mazepart!");
				nreg--;
			}
		  }
#line 3412 "y_tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 1527 "util/lev_comp.y" /* yacc.c:1646  */
    {
			tmpaltar[naltar] = New(altar);
			tmpaltar[naltar]->x = current_coord.x;
			tmpaltar[naltar]->y = current_coord.y;
			tmpaltar[naltar]->align = (yyvsp[-2].i);
			tmpaltar[naltar]->shrine = (yyvsp[0].i);
			if (!in_room)
			    check_coord(current_coord.x, current_coord.y,
					"Altar");
			naltar++;
			if (naltar >= MAX_OF_TYPE) {
				yyerror("Too many altars in room or mazepart!");
				naltar--;
			}
		  }
#line 3432 "y_tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 1545 "util/lev_comp.y" /* yacc.c:1646  */
    {
			tmpgold[ngold] = New(gold);
			tmpgold[ngold]->x = current_coord.x;
			tmpgold[ngold]->y = current_coord.y;
			tmpgold[ngold]->amount = (yyvsp[-2].i);
			if (!in_room)
			    check_coord(current_coord.x, current_coord.y,
					"Gold");
			ngold++;
			if (ngold >= MAX_OF_TYPE) {
				yyerror("Too many golds in room or mazepart!");
				ngold--;
			}
		  }
#line 3451 "y_tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 1562 "util/lev_comp.y" /* yacc.c:1646  */
    {
			tmpengraving[nengraving] = New(engraving);
			tmpengraving[nengraving]->x = current_coord.x;
			tmpengraving[nengraving]->y = current_coord.y;
			tmpengraving[nengraving]->engr.str = (yyvsp[0].map);
			tmpengraving[nengraving]->etype = (yyvsp[-2].i);
			if (!in_room)
			    check_coord(current_coord.x, current_coord.y,
					"Engraving");
			nengraving++;
			if (nengraving >= MAX_OF_TYPE) {
			    yyerror("Too many engravings in room or mazepart!");
			    nengraving--;
			}
		  }
#line 3471 "y_tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 1581 "util/lev_comp.y" /* yacc.c:1646  */
    {
			(yyval.i) = - MAX_REGISTERS - 1;
		  }
#line 3479 "y_tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 1589 "util/lev_comp.y" /* yacc.c:1646  */
    {
			(yyval.i) = - MAX_REGISTERS - 1;
		  }
#line 3487 "y_tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 1597 "util/lev_comp.y" /* yacc.c:1646  */
    {
			(yyval.map) = (char *) 0;
		  }
#line 3495 "y_tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 1604 "util/lev_comp.y" /* yacc.c:1646  */
    {
			(yyval.map) = (char *) 0;
		  }
#line 3503 "y_tab.c" /* yacc.c:1646  */
    break;

  case 206:
#line 1610 "util/lev_comp.y" /* yacc.c:1646  */
    {
			int token = get_trap_type((yyvsp[0].map));
			if (token == ERR)
				yyerror("Unknown trap type!");
			(yyval.i) = token;
			Free((yyvsp[0].map));
		  }
#line 3515 "y_tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 1621 "util/lev_comp.y" /* yacc.c:1646  */
    {
			int token = get_room_type((yyvsp[0].map));
			if (token == ERR) {
				yywarning("Unknown room type!  Making ordinary room...");
				(yyval.i) = OROOM;
			} else
				(yyval.i) = token;
			Free((yyvsp[0].map));
		  }
#line 3529 "y_tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 1634 "util/lev_comp.y" /* yacc.c:1646  */
    {
			(yyval.i) = 0;
		  }
#line 3537 "y_tab.c" /* yacc.c:1646  */
    break;

  case 211:
#line 1638 "util/lev_comp.y" /* yacc.c:1646  */
    {
			(yyval.i) = (yyvsp[0].i);
		  }
#line 3545 "y_tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 1642 "util/lev_comp.y" /* yacc.c:1646  */
    {
			(yyval.i) = (yyvsp[-2].i) + ((yyvsp[0].i) << 1);
		  }
#line 3553 "y_tab.c" /* yacc.c:1646  */
    break;

  case 216:
#line 1651 "util/lev_comp.y" /* yacc.c:1646  */
    {
			current_coord.x = current_coord.y = -MAX_REGISTERS-2;
		  }
#line 3561 "y_tab.c" /* yacc.c:1646  */
    break;

  case 223:
#line 1667 "util/lev_comp.y" /* yacc.c:1646  */
    {
			(yyval.i) = - MAX_REGISTERS - 1;
		  }
#line 3569 "y_tab.c" /* yacc.c:1646  */
    break;

  case 226:
#line 1677 "util/lev_comp.y" /* yacc.c:1646  */
    {
			if ( (yyvsp[-1].i) >= MAX_REGISTERS )
				yyerror("Register Index overflow!");
			else {
				current_coord.x = -1;
				current_coord.y = - (yyvsp[-1].i) - 1;
			}
		  }
#line 3582 "y_tab.c" /* yacc.c:1646  */
    break;

  case 227:
#line 1686 "util/lev_comp.y" /* yacc.c:1646  */
    {
			if ( (yyvsp[-4].i) >= MAX_REGISTERS || (yyvsp[-1].i) >= MAX_REGISTERS )
				yyerror("Register Index overflow!");
			else {
				current_coord.x = - (yyvsp[-4].i) - 1;
				current_coord.y = - (yyvsp[-1].i) - 1;
			}
		  }
#line 3595 "y_tab.c" /* yacc.c:1646  */
    break;

  case 228:
#line 1697 "util/lev_comp.y" /* yacc.c:1646  */
    {
			if ( (yyvsp[-1].i) < 0 || (yyvsp[-1].i) >= nrndlreg )
				yyerror("Register Index overflow!");
			else {
				current_coord.x = -MAX_REGISTERS-1;
				current_coord.y = - (yyvsp[-1].i) - 1;
			}
		  }
#line 3608 "y_tab.c" /* yacc.c:1646  */
    break;

  case 229:
#line 1708 "util/lev_comp.y" /* yacc.c:1646  */
    {
			if ( (yyvsp[-1].i) >= MAX_REGISTERS )
				yyerror("Register Index overflow!");
			else
				(yyval.i) = - (yyvsp[-1].i) - 1;
		  }
#line 3619 "y_tab.c" /* yacc.c:1646  */
    break;

  case 230:
#line 1717 "util/lev_comp.y" /* yacc.c:1646  */
    {
			if ( (yyvsp[-1].i) >= MAX_REGISTERS )
				yyerror("Register Index overflow!");
			else
				(yyval.i) = - (yyvsp[-1].i) - 1;
		  }
#line 3630 "y_tab.c" /* yacc.c:1646  */
    break;

  case 231:
#line 1726 "util/lev_comp.y" /* yacc.c:1646  */
    {
			if ( (yyvsp[-1].i) >= 3 )
				yyerror("Register Index overflow!");
			else
				(yyval.i) = - (yyvsp[-1].i) - 1;
		  }
#line 3641 "y_tab.c" /* yacc.c:1646  */
    break;

  case 233:
#line 1736 "util/lev_comp.y" /* yacc.c:1646  */
    {
			current_coord.x = (char)-1;
			current_coord.y = (char)-1;
		  }
#line 3650 "y_tab.c" /* yacc.c:1646  */
    break;

  case 234:
#line 1743 "util/lev_comp.y" /* yacc.c:1646  */
    {
			if (check_monster_char((char) (yyvsp[0].i)))
				(yyval.i) = (yyvsp[0].i) ;
			else {
				yyerror("Unknown monster class!");
				(yyval.i) = ERR;
			}
		  }
#line 3663 "y_tab.c" /* yacc.c:1646  */
    break;

  case 235:
#line 1754 "util/lev_comp.y" /* yacc.c:1646  */
    {
			char c = (yyvsp[0].i);
			if (check_object_char(c))
				(yyval.i) = c;
			else {
				yyerror("Unknown char class!");
				(yyval.i) = ERR;
			}
		  }
#line 3677 "y_tab.c" /* yacc.c:1646  */
    break;

  case 239:
#line 1773 "util/lev_comp.y" /* yacc.c:1646  */
    {
			(yyval.i) = 100;	/* default is 100% */
		  }
#line 3685 "y_tab.c" /* yacc.c:1646  */
    break;

  case 240:
#line 1777 "util/lev_comp.y" /* yacc.c:1646  */
    {
			if ((yyvsp[0].i) <= 0 || (yyvsp[0].i) > 100)
			    yyerror("Expected percentile chance.");
			(yyval.i) = (yyvsp[0].i);
		  }
#line 3695 "y_tab.c" /* yacc.c:1646  */
    break;

  case 243:
#line 1789 "util/lev_comp.y" /* yacc.c:1646  */
    {
			if (!in_room && !init_lev.init_present &&
			    ((yyvsp[-3].i) < 0 || (yyvsp[-3].i) > (int)max_x_map ||
			     (yyvsp[-1].i) < 0 || (yyvsp[-1].i) > (int)max_y_map))
			    yyerror("Coordinates out of map range!");
			current_coord.x = (yyvsp[-3].i);
			current_coord.y = (yyvsp[-1].i);
		  }
#line 3708 "y_tab.c" /* yacc.c:1646  */
    break;

  case 244:
#line 1800 "util/lev_comp.y" /* yacc.c:1646  */
    {
/* This series of if statements is a hack for MSC 5.1.  It seems that its
   tiny little brain cannot compile if these are all one big if statement. */
			if ((yyvsp[-7].i) < 0 || (yyvsp[-7].i) > (int)max_x_map)
				yyerror("Region out of map range!");
			else if ((yyvsp[-5].i) < 0 || (yyvsp[-5].i) > (int)max_y_map)
				yyerror("Region out of map range!");
			else if ((yyvsp[-3].i) < 0 || (yyvsp[-3].i) > (int)max_x_map)
				yyerror("Region out of map range!");
			else if ((yyvsp[-1].i) < 0 || (yyvsp[-1].i) > (int)max_y_map)
				yyerror("Region out of map range!");
			current_region.x1 = (yyvsp[-7].i);
			current_region.y1 = (yyvsp[-5].i);
			current_region.x2 = (yyvsp[-3].i);
			current_region.y2 = (yyvsp[-1].i);
		  }
#line 3729 "y_tab.c" /* yacc.c:1646  */
    break;


#line 3733 "y_tab.c" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
                  yystos[*yyssp], yyvsp);
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
#line 1818 "util/lev_comp.y" /* yacc.c:1906  */


/*lev_comp.y*/
