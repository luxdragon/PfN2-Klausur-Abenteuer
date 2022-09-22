/* Die Idee ist zuerst die Datei zu öffnen und dann Zeile für Zeile zu lesen,
wir nehmen an, dass die Zeilen niemals länger als 1024 Zeichen sind. Wir kopieren
jede Zeile des Dokuments in unseren Buffer und lesen die drei Zahlen einfach mit
sscanf ab */

long sum_of_lines(const char *progname, const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp==NULL) {
        fprintf(stderr, "%s: cannot open file %s\n", progname, filename);
        return EXIT_FAILURE;
    }
    char buff[1024]; //Ähm, wahrscheinlich nicht die effizienteste Lösung, aber sie funktioniert (getestet)
	long summe = 0;
	long a, b, c;
	while(fgets(buff, 1024, fp)!=NULL) {
		sscanf(buff, "%ld %ld %ld", &a, &b, &c); //warum funktioniert das hier?
		summe += (a+b+c);
	}
    fclose(fp);
	return summe;
}

//Tutor fragen: Wie funktioniert sscanf beim ablesen von Variablen aus Strings?
//Antwort: Die Funktion ist so aufgebaut, dass sie die Leerzeichen ignoriert, weil
// "   3" als eine Zahl gelesen wird.
