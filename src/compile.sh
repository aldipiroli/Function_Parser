clear
cd main
lex functionParser.l
yacc --verbose --debug -d functionParser.y
gcc lex.yy.c y.tab.c -o functionParser -w 
./functionParser
