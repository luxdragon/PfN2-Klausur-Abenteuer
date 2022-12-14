/*
Hier ist mal wieder die große Frage, ob der allokierte Speicherbereich einfach
ein konstant großer ist, oder ob er jedes Mal verändert werden soll.

Das ist ja eigentlich blöd, weil allokieren/reallokieren von Speicher eine
relativ teure Operation ist.
(Außer in extrem kleinen Systemen, bei denen man den Luxus nicht hat)

hier wird strcpy und strlen genutzt

Main iteriert über argv.
strcpy kopiert den ganzen string aus dem jeweiligen argv Eintrag in den
allokierten Speicherbereich. Gleichzeitig holt man sich mit strlen die Länge des
jeweiligen Strings.
Somit kann man vom Ende bis zum Anfang des Strings iterieren und dabei die
Buchstaben ausgeben.

Der Witz ist: Dafür bräuchte man kein temp Array. Man könnte genauso schauen
wie lang der jeweilige string in argv[] ist und dann genau die gleiche Iteration
machen. Das ist in der Funktion better_sol() zu finden
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void better_sol(int argc, char *argv[]); // nicht gefragt, nur zur Demonstration

int main(int argc, char *argv[]){
  char *temp = malloc(512 * sizeof(char));
  for(size_t i = 0; i < argc; ++i){
    size_t len = strlen(argv[i]);
    temp = strcpy(temp, argv[i]);
    for(char  *ptr = temp+len; ptr >= temp; --ptr){
      printf("%c",*ptr);
    }
    printf("\n");
  }
  free(temp);
  //better_sol(argc, argv); // optional
}

void better_sol(int argc, char *argv[]){
  for(size_t i = 0; i<argc; ++i){
    size_t len = strlen(argv[i]);
    char *begin = argv[i];
    for(char *ptr = begin+len; ptr >= begin; --ptr){
      printf("%c",*ptr);
    }
    printf("\n");
  }
}
