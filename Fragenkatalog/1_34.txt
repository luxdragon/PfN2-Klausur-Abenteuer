/*
Die Idee in diesem Programm ist, sich mit getc() jedes Zeichen zu holen
und anzuschauen, auf das ein erstellter filepointer zeigt. 
Außerdem wird ein Array dist erstellt, dass die Verteilung speichert.
Dabei ist es wichtig darauf zu achten, dass alle Einträge 0 sind, da ja noch
kein Buchstabe eingelesen/gefunden wurde.
Der Pointer ptr wird in einer while Schleife so lange hochgezählt bis das Ende
des files (EOF) erreicht ist.
Der der jeweils gefundene charakter c wird durch eine Zahl in der ASCII Tabelle 
repräsentiert. An dieser Stelle im array dist wird gezählt, also beim finden
finden von c wird an der entsprechenden Stelle dist[c] hochgezählt.
So erhält man die Verteilung über eine ganze Datei, inklusive aller \n oder
sonstigen Zeichen.

Die ASCII-Tabelle umfasst 255 Zeichen. Also genauso viele Zeichen wie man mit
im Typ unsigned char darstellen kann. Dieses Limit ist als Makro UCHAR_MAX
aus limits.h bereits vorhanden und kann genutzt werden.
*/

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

size_t *chardist_file(const char *filename){
  FILE *ptr = fopen(filename, "r");
  size_t *dist = calloc(UCHAR_MAX, sizeof(size_t)); //calloc initialisiert das array direkt zu 0
  char c = getc(ptr);
  while(c != EOF){
    dist[c]++;
    c = getc(ptr);
  }
  return dist;
}


//#### main und Hilfsfunktionen

void show_dist_arr(size_t *arr);

int main(void){
  char *filename = "1_34.c";
  size_t *dist = chardist_file(filename);
  show_dist_arr(dist);
  free(dist);
}

void show_dist_arr(size_t *arr){
  for(size_t i = 0; i <UCHAR_MAX; ++i){
    printf("%ld\t%c\t%ld\n",i, i<' ' ? '-': i, arr[i]);
  }
}
