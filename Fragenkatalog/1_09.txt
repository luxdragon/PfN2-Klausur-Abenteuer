CC?=clang //benutze Clang als Compiler, wenn vorhanden
CFLAGS=-g -Wall -Werror -O3 //Compiler-Flags, z.B. -g debug code, -Wall all warnings, -Werror interpret warnings as errors, -03 optimise code
%.o: %.c //Die Ausgabe ist program.o und die Eingabe ist program.c
	${CC} $< -c ${CFLAGS} -o $@ //$< ist die Quelle und $@ die Ausgabe, diese Zeile gibt clang program.c -c -g -Wall -Werror -03 -o program.o in die Konsole ein

/* Wenn eine program.o Datei schon vorhanden ist bekommen wir die Meldung:
program.o is already updated */
