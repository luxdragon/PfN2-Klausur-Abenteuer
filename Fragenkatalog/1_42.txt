/*
Die Idee ist den Fall des empty strings direkt am Anfang zu behandeln, damit man
ihn im folgenden ignorieren kann.

Es werden zwei Variablen eingeführt die sozusagen den run tracken:
- current_run tracked immer den aktuellen run
- longest_run -> wird dann aktualisiert, wenn der current_run größer ist als
der letzte gefundene longest_run

Dann geht man über das Array und schaut ob dem aktuellen Zeichen noch eines
folgt, das ihm gleicht.

Wenn nein ist current_run = 1. Wenn ja wird der current_run hochgezählt.

Es ist wichtig nicht zu vergessen, dass current_run zurückgesetzt werden muss,
wenn ein run vorbei ist.

Am Ende wird der longest_run zurückgegeben
*/


//#### gefragte Funktion ####

#include<stdio.h>

size_t longest_run(const char *seq, size_t len){
  size_t current_run = 1;
  size_t longest_run = 1;

  if(len == 0){ // Fall empty String
    return 0;
  }

  for(size_t i = 1; i < len; ++i){
    if(seq[i] == seq[i-1]){ // entweder ein run wird gefunden, also muss current_run hochgezählt werden (else für diese Fallunterscheidung weiter unten)
      current_run++;
      if(current_run > longest_run){ //wenn der current_run größer ist als der letzte longest_run, dann gibt es einen neuen longest_run
        longest_run = current_run;
      }
    }
    else{ // oder es wird kein run mehr gefunden (oder ein eventuell ein neuer run begonnen), also muss man mit dem zählen neu beginnen
      current_run = 1;
    }
  }
  return longest_run;
}


//#### main und Hilfsfunktionen
int main(void){
  printf("Sequenz\tlongest_run\n");

  char *seq1 = "agacgatagatatcg";
  size_t len1= 15;
  printf("%s\t%ld\n",seq1, longest_run(seq1, len1));

  char *seq2 = "aag";
  size_t len2 = 3;
  printf("%s\t%ld\n",seq2, longest_run(seq2, len2));

  char *seq3 = "agagaaa";
  size_t len3 = 7;
  printf("%s\t%ld\n",seq3, longest_run(seq3, len3));

  char *seq4 = "aggggagaaa";
  size_t len4 = 10;
  printf("%s\t%ld\n",seq4, longest_run(seq4, len4));

  char *seq5 = "ggagaac";
  size_t len5 = 7;
  printf("%s\t%ld\n",seq5, longest_run(seq5, len5));
}



size_t longest_run(const char *seq, size_t len){
	size_t current_run=1;
	if(len ==0){
		return 0;
		}
	for(i=1;i<len(seq);i++){
		If(seq[i]==seq[i-1])
			current_run += 1;
		Else
			If (Current_run>longest_run)
				Longest_run ==current_run;
	}
return longest_run;
}
