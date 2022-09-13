/* Der Präprocessor entfernt die Kommentare, substituiert Macros und fügt den Code
aus angehängten Bibliotheken zu (wir erhalten program.i), dieser wird dann in
program.s übersetzt (die Ausgabe hängt vom Prozessor ab, diese Datei enthält
low-level Anweisungen in Assembly), wo die Syntax überprüft wird. Program.s
wird dann vom Assembler in maschinelles Code übersetzt (program.o), der Linker
verbindet dann noch Aufrufe der Funktionen mit ihren Definitionen (und es wird
program.x ausgegeben, dieses kann dann ausgeführt werden). */

//Einschritt-Kompilierung: gcc -o hello.x hello.c

//Siehe Seite 30 im C-Skript.
