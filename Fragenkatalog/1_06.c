//Zur Syntax:
/* sscanf(): sscanf(s1, "%s", &s2); ist eine Funktion aus <stdio.h>,
die string s2 mit s1 ersetzt. Mit sscanf() kann man die Nutzereingabe erhalten
sscanf (argv[1], "%d", &input) und man soll sie nicht mit
scanf():scanf(“%d”, &x); verwechseln, die auch für das Lesen der
Nutzereingabe zuständig ist. fscanf(FILE *ptr, "%s", &s1); ist eine Funktion
aus <stdio.h>, die Dateien liest. */

/*Beispiel von fscanf():

FILE* ptr = fopen(„datei.txt“, „r“);
    /* Assuming that abc.txt has content in below
       format
       NAME    AGE   CITY
       abc     12    hyderabad
       bef     25    delhi
       cce     65    bangalore */

char buf[100];
fscanf(ptr, „%*s %*s %s „, buf); */


/*Im Wesentlichen:
Beide Funktionen speichern die Kopie des Inhaltes aus einer Quelle in eine
andere Variable, jedoch wird bei fscanf die Quelle als ein Zeiger und bei
sscanf als eine Variable angegeben. Beide sind in der Standardbibliothek stdio.h
enthalten.

Nützlich: fscanf(stdin,…) ist äquivalent zu scanf(...) */
