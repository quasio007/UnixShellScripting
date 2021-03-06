
/*  A Bison parser, made from parse.y
    by GNU Bison version 1.28  */

#define YYBISON 1  /* Identify Bison output.  */

#define	REAL	257
#define	UNIT	258
#define	RFUNC	259
#define	UFUNC	260
#define	EXPONENT	261
#define	MULTIPLY	262
#define	DIVIDE	263
#define	NUMDIV	264
#define	SQRT	265
#define	CUBEROOT	266
#define	MULTMINUS	267
#define	EOL	268
#define	FUNCINV	269
#define	SCANERROR	270
#define	ADD	271
#define	UNARY	272

#line 1 "parse.y"


#define YYPARSE_PARAM comm
#define YYLEX_PARAM comm

#define COMM ((struct commtype *)comm)

#include "units.h"


int err;  /* value used by parser to store return values */

#define CHECK if (err) { COMM->errorcode=err; YYABORT; }


#define MEMSIZE 100
struct unittype *memtable[MEMSIZE];
int nextunit=0;
int maxunit=0;

struct commtype {
   int location;
   char *data;
   struct unittype *result;
   int errorcode;
   char *paramname;
   struct unittype *paramvalue;
};

struct function { 
   char *name; 
   double (*func)(double); 
   int type;
}; 

#define DIMENSIONLESS 0
#define ANGLEIN 1
#define ANGLEOUT 2

struct unittype *
getnewunit()
{
  if (nextunit>=MEMSIZE) 
    return 0;
  memtable[nextunit] = (struct unittype *) 
    mymalloc(sizeof(struct unittype),"(getnewunit)");
  if (!memtable[nextunit])
    return 0;
  initializeunit(memtable[nextunit]);
  return memtable[nextunit++];
}
 

struct unittype *
makenumunit(double num,int *myerr)
{
  struct unittype *ret;
  ret=getnewunit();
  if (!ret){
    *myerr = E_PARSEMEM;
    return 0;  
  }
  ret->factor = num;
  *myerr = 0;
  return ret;
}


double 
log2(double x)
{
  return log(x)/log(2.0);
}


int
funcunit(struct unittype *theunit, struct function *fun)
{
  struct unittype angleunit;

  if (fun->type==ANGLEIN){
    err=unit2num(theunit);
    if (err==E_NOTANUMBER){
      initializeunit(&angleunit);
      angleunit.denominator[0] = dupstr("radian");
      angleunit.denominator[1] = 0;
      err = multunit(theunit, &angleunit);
      if (!err)
	err = unit2num(theunit);
    }
    if (err)
      return err;
  } else if (fun->type==ANGLEOUT || fun->type == DIMENSIONLESS) {
    if (err=unit2num(theunit))
      return err;
    
  } else 
     return E_BADFUNCTYPE;
  errno = 0;
  theunit->factor = (*(fun->func))(theunit->factor);
  if (errno)
    return E_FUNC;
  if (fun->type==ANGLEOUT) {
    theunit->numerator[0] = dupstr("radian");
    theunit->numerator[1] = 0;
  }
  return 0;
}



#line 115 "parse.y"
typedef union {
  double number;
  int integer;
  struct unittype *utype;
  struct function *dfunc;
  struct func *ufunc;
} YYSTYPE;
#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		47
#define	YYFLAG		-32768
#define	YYNTBASE	21

#define YYTRANSLATE(x) ((unsigned)(x) <= 272 ? yytranslate[x] : 27)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,    19,
    20,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
     2,     2,     2,     2,     2,     1,     3,     4,     5,     6,
     7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
    17,    18
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     2,     5,     7,     9,    12,    14,    17,    21,    25,
    29,    31,    35,    39,    41,    43,    47,    51,    54,    56,
    59,    62,    65,    68,    72,    77
};

static const short yyrhs[] = {    14,
     0,    22,    14,     0,     1,     0,    23,     0,     9,    26,
     0,    26,     0,    13,    26,     0,    23,    17,    23,     0,
    23,     9,    23,     0,    23,     8,    23,     0,     3,     0,
    24,    10,    24,     0,    19,    23,    20,     0,    24,     0,
     4,     0,    26,     7,    26,     0,    26,    13,    26,     0,
    26,    26,     0,    25,     0,    11,    25,     0,    12,    25,
     0,     5,    25,     0,     6,    25,     0,    15,     6,    25,
     0,    26,     7,    13,    26,     0,    16,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
   156,   157,   158,   161,   162,   165,   166,   167,   168,   169,
   172,   173,   176,   182,   183,   184,   185,   186,   187,   188,
   189,   190,   191,   192,   193,   196
};
#endif


#if YYDEBUG != 0 || defined (YYERROR_VERBOSE)

static const char * const yytname[] = {   "$","error","$undefined.","REAL","UNIT",
"RFUNC","UFUNC","EXPONENT","MULTIPLY","DIVIDE","NUMDIV","SQRT","CUBEROOT","MULTMINUS",
"EOL","FUNCINV","SCANERROR","ADD","UNARY","'('","')'","input","unitexpr","expr",
"numexpr","pexpr","list", NULL
};
#endif

static const short yyr1[] = {     0,
    21,    21,    21,    22,    22,    23,    23,    23,    23,    23,
    24,    24,    25,    26,    26,    26,    26,    26,    26,    26,
    26,    26,    26,    26,    26,    26
};

static const short yyr2[] = {     0,
     1,     2,     1,     1,     2,     1,     2,     3,     3,     3,
     1,     3,     3,     1,     1,     3,     3,     2,     1,     2,
     2,     2,     2,     3,     4,     1
};

static const short yydefact[] = {     0,
     3,    11,    15,     0,     0,     0,     0,     0,     0,     1,
     0,    26,     0,     0,     4,    14,    19,     6,    22,    23,
     5,    20,    21,     7,     0,     0,     2,     0,     0,     0,
     0,     0,     0,    18,    24,    13,    10,     9,     8,    12,
     0,    16,    17,    25,     0,     0,     0
};

static const short yydefgoto[] = {    45,
    14,    15,    16,    17,    34
};

static const short yypact[] = {    33,
-32768,-32768,-32768,    -7,    -7,   118,    -7,    -7,   118,-32768,
    11,-32768,    67,     7,    -1,    14,-32768,    50,-32768,-32768,
    50,-32768,-32768,    50,    -7,     6,-32768,    67,    67,    67,
    22,    84,   118,   101,-32768,-32768,-32768,    19,     2,-32768,
   118,-32768,   101,-32768,    31,    35,-32768
};

static const short yypgoto[] = {-32768,
-32768,   -10,     9,    -3,     0
};


#define	YYLAST		137


static const short yytable[] = {    18,
    19,    20,    26,    22,    23,    21,    28,    29,    24,    28,
    29,    13,    18,    28,    29,    30,    25,    37,    38,    39,
    27,    35,    30,    31,     2,    36,    28,    18,    18,    18,
    46,    42,    43,     1,    47,     2,     3,     4,     5,    40,
    44,     6,     0,     7,     8,     9,    10,    11,    12,     0,
     0,    13,     2,     3,     4,     5,    32,     0,     0,     0,
     7,     8,    33,     0,    11,    12,     0,     0,    13,     2,
     3,     4,     5,     0,     0,     0,     0,     7,     8,     9,
     0,    11,    12,     0,     0,    13,     2,     3,     4,     5,
     0,     0,     0,     0,     7,     8,    41,     0,    11,    12,
     0,     0,    13,     2,     3,     4,     5,    32,     0,     0,
     0,     7,     8,     0,     0,    11,    12,     0,     0,    13,
     2,     3,     4,     5,     0,     0,     0,     0,     7,     8,
     0,     0,    11,    12,     0,     0,    13
};

static const short yycheck[] = {     0,
     4,     5,    13,     7,     8,     6,     8,     9,     9,     8,
     9,    19,    13,     8,     9,    17,     6,    28,    29,    30,
    14,    25,    17,    10,     3,    20,     8,    28,    29,    30,
     0,    32,    33,     1,     0,     3,     4,     5,     6,    31,
    41,     9,    -1,    11,    12,    13,    14,    15,    16,    -1,
    -1,    19,     3,     4,     5,     6,     7,    -1,    -1,    -1,
    11,    12,    13,    -1,    15,    16,    -1,    -1,    19,     3,
     4,     5,     6,    -1,    -1,    -1,    -1,    11,    12,    13,
    -1,    15,    16,    -1,    -1,    19,     3,     4,     5,     6,
    -1,    -1,    -1,    -1,    11,    12,    13,    -1,    15,    16,
    -1,    -1,    19,     3,     4,     5,     6,     7,    -1,    -1,
    -1,    11,    12,    -1,    -1,    15,    16,    -1,    -1,    19,
     3,     4,     5,     6,    -1,    -1,    -1,    -1,    11,    12,
    -1,    -1,    15,    16,    -1,    -1,    19
};
#define YYPURE 1

/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "/usr/local/share/bison.simple"
/* This file comes from bison-1.28.  */

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

#ifndef YYSTACK_USE_ALLOCA
#ifdef alloca
#define YYSTACK_USE_ALLOCA
#else /* alloca not defined */
#ifdef __GNUC__
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi) || (defined (__sun) && defined (__i386))
#define YYSTACK_USE_ALLOCA
#include <alloca.h>
#else /* not sparc */
/* We think this test detects Watcom and Microsoft C.  */
/* This used to test MSDOS, but that is a bad idea
   since that symbol is in the user namespace.  */
#if (defined (_MSDOS) || defined (_MSDOS_)) && !defined (__TURBOC__)
#if 0 /* No need for malloc.h, which pollutes the namespace;
	 instead, just don't use alloca.  */
#include <malloc.h>
#endif
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
/* I don't know what this was needed for, but it pollutes the namespace.
   So I turned it off.   rms, 2 May 1997.  */
/* #include <malloc.h>  */
 #pragma alloca
#define YYSTACK_USE_ALLOCA
#else /* not MSDOS, or __TURBOC__, or _AIX */
#if 0
#ifdef __hpux /* haible@ilog.fr says this works for HPUX 9.05 and up,
		 and on HPUX 10.  Eventually we can turn this on.  */
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#endif /* __hpux */
#endif
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc */
#endif /* not GNU C */
#endif /* alloca not defined */
#endif /* YYSTACK_USE_ALLOCA not defined */

#ifdef YYSTACK_USE_ALLOCA
#define YYSTACK_ALLOC alloca
#else
#define YYSTACK_ALLOC malloc
#endif

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	goto yyacceptlab
#define YYABORT 	goto yyabortlab
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Define __yy_memcpy.  Note that the size argument
   should be passed with type unsigned int, because that is what the non-GCC
   definitions require.  With GCC, __builtin_memcpy takes an arg
   of type size_t, but it can handle unsigned int.  */

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(TO,FROM,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (to, from, count)
     char *to;
     char *from;
     unsigned int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *to, char *from, unsigned int count)
{
  register char *t = to;
  register char *f = from;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 217 "/usr/local/share/bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#ifdef __cplusplus
#define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#else /* not __cplusplus */
#define YYPARSE_PARAM_ARG YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#endif /* not __cplusplus */
#else /* not YYPARSE_PARAM */
#define YYPARSE_PARAM_ARG
#define YYPARSE_PARAM_DECL
#endif /* not YYPARSE_PARAM */

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
#ifdef YYPARSE_PARAM
int yyparse (void *);
#else
int yyparse (void);
#endif
#endif

int
yyparse(YYPARSE_PARAM_ARG)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;
  int yyfree_stacks = 0;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  if (yyfree_stacks)
	    {
	      free (yyss);
	      free (yyvs);
#ifdef YYLSP_NEEDED
	      free (yyls);
#endif
	    }
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
#ifndef YYSTACK_USE_ALLOCA
      yyfree_stacks = 1;
#endif
      yyss = (short *) YYSTACK_ALLOC (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss, (char *)yyss1,
		   size * (unsigned int) sizeof (*yyssp));
      yyvs = (YYSTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs, (char *)yyvs1,
		   size * (unsigned int) sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls, (char *)yyls1,
		   size * (unsigned int) sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 1:
#line 156 "parse.y"
{ COMM->result = makenumunit(1,&err); CHECK; YYACCEPT; ;
    break;}
case 2:
#line 157 "parse.y"
{ COMM->result = yyvsp[-1].utype; YYACCEPT; ;
    break;}
case 3:
#line 158 "parse.y"
{ YYABORT; ;
    break;}
case 4:
#line 161 "parse.y"
{yyval.utype = yyvsp[0].utype;;
    break;}
case 5:
#line 162 "parse.y"
{ invertunit(yyvsp[0].utype); yyval.utype=yyvsp[0].utype;;
    break;}
case 6:
#line 165 "parse.y"
{ yyval.utype = yyvsp[0].utype; ;
    break;}
case 7:
#line 166 "parse.y"
{ yyval.utype = yyvsp[0].utype; yyval.utype->factor *= -1; ;
    break;}
case 8:
#line 167 "parse.y"
{ err = addunit(yyvsp[-2].utype,yyvsp[0].utype); CHECK; yyval.utype=yyvsp[-2].utype;;
    break;}
case 9:
#line 168 "parse.y"
{ err = divunit(yyvsp[-2].utype, yyvsp[0].utype); CHECK; yyval.utype=yyvsp[-2].utype;;
    break;}
case 10:
#line 169 "parse.y"
{ err = multunit(yyvsp[-2].utype,yyvsp[0].utype); CHECK; yyval.utype=yyvsp[-2].utype;;
    break;}
case 11:
#line 172 "parse.y"
{ yyval.number = yyvsp[0].number;         ;
    break;}
case 12:
#line 173 "parse.y"
{ yyval.number = yyvsp[-2].number / yyvsp[0].number;    ;
    break;}
case 13:
#line 176 "parse.y"
{ yyval.utype = yyvsp[-1].utype;  ;
    break;}
case 14:
#line 182 "parse.y"
{ yyval.utype = makenumunit(yyvsp[0].number,&err); CHECK;;
    break;}
case 15:
#line 183 "parse.y"
{ yyval.utype = yyvsp[0].utype; ;
    break;}
case 16:
#line 184 "parse.y"
{ err = unitpower(yyvsp[-2].utype,yyvsp[0].utype); CHECK; yyval.utype=yyvsp[-2].utype;;
    break;}
case 17:
#line 185 "parse.y"
{ err = multunit(yyvsp[-2].utype,yyvsp[0].utype); CHECK; yyval.utype=yyvsp[-2].utype;;
    break;}
case 18:
#line 186 "parse.y"
{ err = multunit(yyvsp[-1].utype,yyvsp[0].utype); CHECK; yyval.utype=yyvsp[-1].utype;;
    break;}
case 19:
#line 187 "parse.y"
{ yyval.utype=yyvsp[0].utype; ;
    break;}
case 20:
#line 188 "parse.y"
{ err = rootunit(yyvsp[0].utype,2); CHECK; yyval.utype=yyvsp[0].utype;;
    break;}
case 21:
#line 189 "parse.y"
{ err = rootunit(yyvsp[0].utype,3); CHECK; yyval.utype=yyvsp[0].utype;;
    break;}
case 22:
#line 190 "parse.y"
{ err = funcunit(yyvsp[0].utype,yyvsp[-1].dfunc); CHECK; yyval.utype=yyvsp[0].utype;;
    break;}
case 23:
#line 191 "parse.y"
{ err = evalfunc(yyvsp[0].utype,yyvsp[-1].ufunc,0); CHECK; yyval.utype=yyvsp[0].utype;;
    break;}
case 24:
#line 192 "parse.y"
{ err = evalfunc(yyvsp[0].utype,yyvsp[-1].ufunc,1); CHECK; yyval.utype=yyvsp[0].utype;;
    break;}
case 25:
#line 194 "parse.y"
{ yyvsp[0].utype->factor *= -1;
				   err = unitpower(yyvsp[-3].utype,yyvsp[0].utype); CHECK; yyval.utype=yyvsp[-3].utype;;
    break;}
case 26:
#line 196 "parse.y"
{ err = E_PARSEMEM; CHECK; ;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 543 "/usr/local/share/bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;

 yyacceptlab:
  /* YYACCEPT comes here.  */
  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);
#ifdef YYLSP_NEEDED
      free (yyls);
#endif
    }
  return 0;

 yyabortlab:
  /* YYABORT comes here.  */
  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);
#ifdef YYLSP_NEEDED
      free (yyls);
#endif
    }
  return 1;
}
#line 202 "parse.y"


#ifndef strchr
#  ifdef NO_STRCHR
#    define strchr(a,b) index((a),(b))
#  else
     char *strchr();
#  endif
#endif /* !strchr */

double strtod();


struct function 
  realfunctions[] = { "sin", sin,  ANGLEIN,
                      "cos", cos,  ANGLEIN,
                      "tan", tan,  ANGLEIN,
                      "ln", log,   DIMENSIONLESS,
                      "log", log10, DIMENSIONLESS,
                      "log2", log2, DIMENSIONLESS,
                      "exp", exp,   DIMENSIONLESS,
                      "acos", acos, ANGLEOUT,
                      "atan", atan, ANGLEOUT,
                      "asin", asin, ANGLEOUT,
                      0, 0, 0};

struct {
  char op;
  int value;
} optable[] = { '-', MULTMINUS, 
                '*', MULTIPLY,
            	'/', DIVIDE, 
            	'|', NUMDIV, 
            	'+', ADD, 
            	'(', '(', 
            	')', ')', 
            	'^', EXPONENT, 
                '~', FUNCINV,
            	0, 0 };

struct {
  char *name;
  int value;
} strtable[] = { "sqrt", SQRT, 
                 "cuberoot", CUBEROOT, 
                 "per" , DIVIDE, 
                 "**", EXPONENT, 
                 0, 0 };

yylex(YYSTYPE *lvalp, struct commtype *comm)
{
  int length, count;
  struct unittype *output;
  char *inptr;

  char *nonunitchars = "+-*/|\t\n^ ()";
  
  if (comm->location==-1) return 0;
  inptr = comm->data + comm->location;   /* Point to start of data */

  /* Skip white space */
  while( *inptr && strchr(WHITE,*inptr)) inptr++, comm->location++;

  if (*inptr==0) {
    comm->location = -1;
    return EOL;  /* Return failure if string has ended */
  }  

  /* Look for single character ops */

  for(count=0; optable[count].op; count++){
    if (*inptr==optable[count].op) {
       comm->location++;
       return optable[count].value;
    }
  }

  /* Look for numbers */

  if (strchr(".0123456789",*inptr)){  /* prevent "nan" from being recognized */
    char *endloc;
    lvalp->number = strtod(inptr, &endloc);
    if (inptr != endloc) { 
      comm->location += (endloc-inptr);
      return REAL;
    }
  }

  /* Look for a word (function name or unit name) */

  length = strcspn(inptr,nonunitchars);   

  if (!length){  /* This shouldn't happen */
     return 0;
  }
  
  /* Look for string operators */

  for(count=0;strtable[count].name;count++){
     if (length==strlen(strtable[count].name) && 
	 0==strncmp(strtable[count].name,inptr,length)){
       comm->location += length;
       return strtable[count].value;
     }
  }

  /* Look for real function names */

  for(count=0;realfunctions[count].name;count++){
     if (length==strlen(realfunctions[count].name) && 
	 0==strncmp(realfunctions[count].name,inptr,length)){
       lvalp->dfunc = realfunctions+count;
       comm->location += length;
       return RFUNC;
     }
  }

  /* Look for function parameter */

  if (function_parameter && length==strlen(function_parameter) && 
      0==strncmp(function_parameter, inptr, length)){
      output = getnewunit();
      if (!output)
	return SCANERROR;
      unitcopy(output, parameter_value);
      lvalp->utype = output;
      comm->location += length;
      return UNIT;
  } 

  /* Look for user defined function */

  lvalp->ufunc = fnlookup(inptr,length);
  if (lvalp->ufunc){
    comm->location += length;
    return UFUNC;
  }

  /* Didn't find a special string, so treat it as unit name */

  comm->location+=length;
  if (strchr("23456789",inptr[length-1])) {  /* do exponent handling like m3 */
     count = inptr[length-1] - '0';
     length--;
  } else count=1;

  output = getnewunit();
  if (!output)
    return SCANERROR;
  output->numerator[count]=0;
  for(;count;count--){
    output->numerator[count-1] = mymalloc(length+1,"(yylex)");
    strncpy(output->numerator[count-1], inptr, length);
    output->numerator[count-1][length]=0;
  }
  lvalp->utype=output;
  return UNIT;
}


yyerror(char *s){}

void
freelist(int startunit)
{
  if (nextunit>maxunit) 
    maxunit = nextunit;
  while(nextunit>startunit){
    freeunit(memtable[--nextunit]);
    free(memtable[nextunit]);
  }
}


int
parseunit(struct unittype *output, char *input,char **errstr,int *errloc)
{
  struct commtype comm;
  int startunit;

  startunit = nextunit;
  initializeunit(output);
  comm.location = 0;
  comm.data = input;
  comm.errorcode = E_PARSE;    /* Assume parse error */
  if (yyparse(&comm)){
    if (comm.location==-1) 
      comm.location = strlen(input);
    if (errstr){
      if (smarterror && comm.errorcode==E_FUNC)
	*errstr = strerror(errno);
      else
        *errstr=errormsg[comm.errorcode];
    }
    if (errloc)
      *errloc = comm.location;
    freelist(startunit);
    return comm.errorcode;
  } else {
    if (errstr)
      *errstr = 0;
    multunit(output,comm.result);
    freeunit(comm.result);
    freelist(startunit);
    return 0;
  }
}


