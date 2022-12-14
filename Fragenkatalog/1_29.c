/*
Die Idee bei dieser Aufgabe ist über das char array mit den DNA-Sequenz zu
iterieren und dabei Fallunterscheidungen für jeden Buchstaben zu prüfen.
Das wird über eine seperate Funktion mit switch case Anweisungen gelöst.
Man muss natürlich zusätzlich darauf achten, dass die Zeichen in der Sequenz
umgekehrt werden sollen. Dies wird über eine temporäre Variable und Iteration
wie in Aufgabe 1_28 erreicht.
Nur wird hier über die Länge (len+1)/2 iteriert um die ungerade Fälle zu
berücksichtigen:

- so werden bei einem Array der Länge 8; (8+1)/2 = 4.5 -> 4 (wird als
ganzzahliger Typ abgerundet) immer noch alle Elemente richtig getauscht.

- außerdem werden bei einem Array ungerader Länge z.B 7
(7+1)/2 = 4 alle Elemente richtig getauscht. Das Element in der Mitte tauscht
in diesem Fall mit sich selber.

Es wird keine Fehlermedlung gefordert.
*/

#include<stdio.h>

//#### gefragte Funktion(en) #####
char compl_b(char c){
  switch(c){
    case 'a':
      return 't';
      break;
    case 'c':
      return 'g';
      break;
    case 'g':
      return 'c';
      break;
    case 't':
      return 'a';
      break;
    default:
      return '#'; // für den Fall, dass eine fehlerhaftes Zeichen vorhanden ist
      break;
  }
}

void rev_compl_DNA(char *seq, size_t len){
  for(size_t i = 0; i < (len+1)/2; i++){ //(len+1)/2 ist wichtig um auch die ungerade Fälle zu berücksichtigen
    char temp = seq[i];
    seq[i] = compl_b(seq[len-1-i]);
    seq[len-1-i] = compl_b(temp);
  }
}


//##### main und Hilfsfunktionen ####
void show_char_arr(char *arr, size_t len);


int main(void){
  char dna_arr[] = "acgttgca";
  size_t len = 8;

  rev_compl_DNA(dna_arr, len);
  show_char_arr(dna_arr, len);

  char dna_arr_2[] = "acgttgc";
  size_t len_2 = 7;
  rev_compl_DNA(dna_arr_2, len_2);
  show_char_arr(dna_arr_2, len_2);

}

void show_char_arr(char *arr, size_t len){
  printf("[ ");
  for(size_t i = 0; i < len; ++i){
    printf("%c ", arr[i]);
  }
  printf("]\n");
}
