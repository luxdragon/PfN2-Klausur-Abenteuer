/* Die Frage wurde im Tutorium beantwortet. Schreiben wir die Anweisungen um:*/

char c = 'a';
char *cptr;
*cptr = c; //hier wird der Zeiger derefenziert!! Deshalb ist dieser Ausdruck richtige

unsigned long u;
u = 42;
unsigned long *uptr = u; //Der Zeiger soll gleich u sein, u ist aber keine Adresse
//äquivalent zu: uptr = u;
