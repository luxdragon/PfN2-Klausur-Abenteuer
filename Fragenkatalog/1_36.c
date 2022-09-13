/* Die Deklaration char *s = „this is a string“ ist read-only und kann nicht
modifiziert werden (weil der Speicherort von s in der ausführbaren Datei liegt),
um solche String zu modifizieren müssen wir sie entweder mit strcpy(), strdup()
duplizieren oder mit char s[] = „this is a string“ initialisieren. */
