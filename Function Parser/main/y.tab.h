/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    RETURN_TOK = 258,
    FUNCTION_TOK = 259,
    COMMA_TOK = 260,
    CLOSE_PAR_TOK = 261,
    OPEN_BRACES_TOK = 262,
    CLOSE_BRACES_TOK = 263,
    SEMICOLON_TOK = 264,
    ID_FUNCTION = 265,
    ID_PARAMETER = 266,
    PLUS_TOK = 267,
    MULT_TOK = 268,
    NUMBER = 269
  };
#endif
/* Tokens.  */
#define RETURN_TOK 258
#define FUNCTION_TOK 259
#define COMMA_TOK 260
#define CLOSE_PAR_TOK 261
#define OPEN_BRACES_TOK 262
#define CLOSE_BRACES_TOK 263
#define SEMICOLON_TOK 264
#define ID_FUNCTION 265
#define ID_PARAMETER 266
#define PLUS_TOK 267
#define MULT_TOK 268
#define NUMBER 269

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 23 "functionParser.y" /* yacc.c:1909  */

    char *string;
    float number

#line 87 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
