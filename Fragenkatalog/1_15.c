/*
hier ist das gemeint was in der Vorlesung behandelt wurde. Siehe F.448-350.

Diese Aufgabe könnte genau so auch für andere behandelte Datentypen als
linked-lists drankommen, da diese Form der Datentypen hohes
Abstraktions-/Verallgemeinerungspotential haben.
Z.b. könnte man hier auch nach binary trees fragen.

Dateianfänge und Enden beziehen sich natürlich nur auf den Kontext der Aufgabe.
So fehlt z.B. die main-function
*/

//Die Deklarierung muss in der Header-Datei list.h erfolgen:
----------Dateianfang list.h
#ifndef LIST_H // # => Präprozessor Anweisungen, dass Header Datei nicht mehrfach kompilliert wird
#define LIST_H

typedef struct ListElem List;

// hier würde man dann weitere Protetypen für Funktionen etc. deklarieren

#endif

---------Dateiende von list.h


---------Dateianfang von list.c

// die Implementierung muss in der Datei list.c erfolgen:

#include stdio.h
#include "list.h" //es ist sehr wichtig, dass die Header-Datei hier importiert wird, NICHT VERGESSEN!

struct ListElem{
  int date;
  struct ListElem *next;
};

typedef struct ListElem List;

---------Dateiende von list.c
