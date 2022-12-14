/* Die Idee hinter dieser Aufgabe ist zuerst zu überprüfen, ob unser
Buchstabe überhaupt groß oder klein ist. Hier lohnt es sich einen Blick
auf die ASCII Tabelle zu werfen, wo man erkennt, dass große Buchstaben
vor kleinen geordnet sind. Das heißt, wenn wir einen großen Buchstaben haben,
dann wir es einen Integerwert haben, dass kleiner ist als der von klein "a".
Num müssen wir nur noch den Integerwert unseres Buchstabes mit dem Integerwert
entweder gross oder klein "a"s zu subtrahieren. */

// diese Funktion benutzen wenn ihr nicht mit ctype.h arbeiten wollt

int alpha_num(char c) {
    int i;
    char klein_a = 'a';
    char gross_a = 'A';
    if ((int) c >= (int) klein_a) {
        //jetzt wissen wir, dass wir einen kleinen Buchstaben haben
        i= (int) c - (int) klein_a + 1;
    } else {
        i = (int) c - (int) gross_a + 1;
    }

    return i;
}

#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>


//######## gefragte Funktion ##############
int alpha_num(int cc){

  if(isupper(cc) != 0){ // if(('A' <= cc) && (cc <= 'Z'))
    return cc-'A'+1; // 'a' steht für die Zahl 97 entsprechend ASCII-Tabelle
  }
  else if(islower(cc) != 0){ // if(('a' <= cc) && (cc <= 'z'))
    return cc-'a'+1;
  }
  else{ // optionale Fehlerbehandlung
    printf("Fehler");
    return -1;
  }
}
