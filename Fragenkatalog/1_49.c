/*
Das folgende Programm soll Zahlen von der Standard-Eingabe einlesen und sie in einem
Array arr speichern. Falls mindestens eine negative Zahl eingelesen wurde, soll der
maximale Index einer negativen Zahl in arr und die Zahl selbst ausgegeben werden.

Das Programm funktioniert jedoch nicht immer korrekt. Wenn z.B. die Zahlenfolge 0,
1, 2, -3, 5, 0, 1 zeilenweise eingelesen wird, tritt sehr wahrscheinlich ein Fehler auf.
Erläutern Sie am Beispiel dieser Zahlenfolge, warum ein Fehler auftritt und beschreiben
Sie, was verändert werden muss, um den Fehler zu korrigieren.
*/

//#### gegebene Funktion:
//#### lesbarer hingeschrieben!

#include "stdio.h"
#include "stdlib.h"

int main(void) {
  size_t allocated = 5;
  size_t nextfree = 0;
  long read_long;
  long *last_negative = NULL; // KORREKTUR size_t last_negative;
  long *arr = malloc(allocated * sizeof *arr); // array von Größe 5*long erstellt,

  while (scanf("%ld",&read_long) == 1) //einlesen von stdin
  {
    if (nextfree >= allocated) // das erste mal, wenn 0, 1, 2, -3, 5 eingelesen wurden und man gerade 0 eingeben hat
    {
      allocated += (allocated * 0.2) + 128;
      arr = realloc(arr,sizeof *arr * allocated); // arr ist jetzt pointer auf Anfang von arr
    }
  if (read_long < 0) // wenn negative Zahl eingelesen wird
    last_negative = arr + nextfree; //KORREKTUR: last_negative = nextfree;
  arr[nextfree++] = read_long; // read_long wird an der stelle arr[nextfree] gespeichert und nextfree hochgezählt
  }
  if (last_negative != NULL)
//KORREKTUR: printf("last negative value %ld was at index %lu\n", *(arr+last_negative), last_negative);
    printf("last negative value %ld was at index %lu\n", *last_negative, (size_t) (last_negative - arr));
  return EXIT_SUCCESS;
}

/* Wenn 5 eingelesen wird, dann ist nextfree = 5. Damit wird allocated verändert
und das array vergrößert. Man bekommt wieder einen Pointer auf das Anfang des
Arrays.

Jetzt zeigt last_negative immer noch auf den alten und damit möglicherweise auf
einen gar nicht mehr existierenden Speicherbereich
(weil realloc den Inhalt des alten Speichers in neu allokierten neuen Speicher
kopiert und den alten dann freed)

Wenn man am Ende last_negative dereferenziert, dann kann es sein, dass man nicht
-3 bekommt, sondern etwas völlig anderen, weil last_negative vielleicht nicht
mehr auf die -3 zeigt, wenn der alte Speicher schon wieder von etwas anderem
genutzt wurde.

Dieses Problem ist einfach zu lösen, indem man last_negative nicht als pointer,
sondern als Index speichert.
Für Korrektur siehe Kommentare im Programm.
 */
