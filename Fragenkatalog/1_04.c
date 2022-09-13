a) vptr++; //falsch, void Zeiger kann man nicht inkremetieren (siehe Seite 80 im Skript)
b) cmp = vptr == wptr;  // richtig
c) vsize = sizeof(*vptr); //falsch, einen Void Zeiger kann man nicht dereferenzieren (siehe Seite 80)
d) s = wptr; //richtig, den Void-Zeiger kann man in jeden anderen Zeiger umwandeln (siehe Seite 80)
e) s = vptr – 1; //falsch, void Zeiger kann man nicht inkrementieren
f) vptr = malloc(ssize * sizeof *s); //richtig

//Tutor fragen!
