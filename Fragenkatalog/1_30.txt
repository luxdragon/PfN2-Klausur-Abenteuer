void reverse_lines(FILE *fpin) {
    char buffer[1024];
    while(fgets(buffer, 1024, fpin)!=NULL) {
        reverse_string(buffer, 1024);
        printf("%s", buffer);
    }
}


/*
Die Idee ist sich ein temporäres Array zu erstellen, in welchem man mit fgets
die jeweilige Zeile speichern kann.
fgets wird in einer while-Schleife so lange aufgerufen, bis fgets NULL
zurückgibt.
In der while-Schleife muss man die tatsächliche Zeilenlänge bestimmen und lässt
sich den line string von reverse_string (hier wegen vollständigkeit auch
implementiert) umdrehen.
Anschließend muss man line nur noch printen.

Nach der Funktion reverse_string war nicht gefragt.
Es war keine Fehlerbehandlung gefragt.

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//#### zusätzliche bereits gegebene Funktion #### 
void reverse_string(char *str, size_t len){
  char temp;
  for(size_t i = 0; i<len/2; ++i){
    temp = str[i];
    str[i] = str[len-2-i]; //dass es hier von len-2-i anstatt von len-1-i losgeht ist wichtig, da man ja nicht das \n an den Anfang möchte. Wenn man das übersieht wird die Ausgabe unschön
    str[len-2-i] = temp;
  }
}

//#### gefragte Funktion(en) ####
void reverse_lines(FILE *fpin){
  char *line = malloc(1024 * sizeof(char));
  while(fgets(line, 1024, fpin) != NULL){
    size_t len = strlen(line); //man braucht hier eine Methode um an die aktuelle Länger der line zu kommen, sonst funktioniert (meine Implementierung vom reverse_string) nicht
    reverse_string(line, len);
    printf("%s", line);
  }
  free(line);
}

//#### main-fkt zum testen #####

int main(void){
char *filename = "text.txt";
FILE *ptr = fopen(filename, "r");
reverse_lines(ptr);
fclose(ptr);

/*
//testen von reverse_string
char s[] = "Stefan hat die Macht";
size_t s_len = 20;
reverse_string(s, s_len);
printf("%s\n", s);
*/
}
