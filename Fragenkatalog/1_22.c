/* In dieser Aufgabe ist Fehlerbehandlung nicht explizit gefragt */

#include<stdio.h>

int main(void){
  int x,y;
  printf("Gib zwei positive ganze Zahlen nacheinander ein:\n");
  scanf("%d", &x); // scannt die Zalen aus dem Terminal und speichert sie an der Adresse der jeweiligen Variable
  scanf("%d", &y);
  printf("\n");

  printf("%d\n", x+y);
  printf("%d\n", x*y);

  if(x > y){ // nötige geforderte Fallunterscheidung für positive Differenz bzw. Quotient
    printf("%d\n", x-y);
    printf("%f\n”",(float) x/y); //hier muss ein typecast passieren
  }
  else{
    printf("%d\n", y-x);
    printf("%f\n",(float) y/x); //hier muss ein typecast passieren
  }
}

//noch eine Implementierung mit sscanf und mit der Fehlerbehandlung

#include <stdio.h>

int main(int argc, char *argv[]) {
	int i, j;
	if (argc != 3 || sscanf(argv[1], "%u", &i) != 1 || sscanf(argv[2], "%u", &j) != 1) {
		fprintf(stderr, "Error, correct input: %s <pos. integer> <pos. integer>", argv[0]);
	}
	printf("%u\n", i+j);
	printf("%u\n", i*j);
	if (i>=j) {
        printf("%u\n", i-j);
	} else {
        printf("%u\n", j-i);
    }
    printf("%f\n", (float) i/j);
    return 0;
}
