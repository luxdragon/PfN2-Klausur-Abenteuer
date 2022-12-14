/* Strcpy() kopiert einen string von einer Stelle zur anderen.
Das gleiche macht auch strdup(), jedoch alloziert diese Funktion
einen Speicherort für den Duplikat, bei strcpy() müssen wir das
selber machen. Zum Beispiel: */


#include<stdio.h>
#include<string.h> //bloß nicht vergessen

char src[] = "Hallo :D"
char dest[100];
strcpy(dest, src);
//jetzt ist dest = "Hallo :D"
free(dest);

char src[] = "Hallo :)"
char *dest;
dest = strdup(src);
//jetzt ist dest = "Hallo :)"
free(dest);
