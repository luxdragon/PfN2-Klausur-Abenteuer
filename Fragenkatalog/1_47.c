/* Die zweite Funktion ist richtig, weil die dynamische Speicherplatzzuweisung
garantiert, dass die Struktur und der Zeiger auf die Struktur auch nach dem
Verlauf der Funktion immer noch existieren. Die Struktur in der ersten Funktion
existiert, sofort nach der Ausgabe des Zeigers, nicht mehr, also ist der Zeiger
illegal, es sei denn wir würden static vor der Funktion schreiben. */
