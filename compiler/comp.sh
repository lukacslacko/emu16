#!/bin/bash
flex comp.l && yacc -Wcounterexamples -dtv comp.y && g++ y.tab.c lex.yy.c ir.cpp && ./a.out
