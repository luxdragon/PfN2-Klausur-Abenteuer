/* CC?=clang //wenn es Clang gibt, wir der als Compiler ausgewählt
CFLAGS=-g -Wall -Werror -03 //das sind die extra Parameter -g steht für Wallgrind/Debugging, -Wall für die Angabe von Warnungen, Werror macht alle Warnungen zu Fehlern und -03 optimisiert den Code
%.o: %.c //Wenn wir make program.o eingeben wird eine Datei program.o aus program.c erstellt und zwar mit dem folgenden Befehl:
	${CC} $< -c ${CFLAGS} -o $@ //zuerst wird der Name des Compilers angegeben, dann die Quelldatei (program.c), dann die oben angegebenen Flags, -o für Output und dann die Zieldatei (program.o)
*/

// Der ausgeführte Befehl ist clang program.c -c -g -Wall -Werror -03 -o program.o
