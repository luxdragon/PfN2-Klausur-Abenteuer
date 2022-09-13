size_t quersumme(size_t n) {
    size_t quersumme = 0;
    if (n < 10) {
        quersumme = n;
    } else {
        while (n > 10) {
            //wir addieren den Modul, äquivalent zur Ziffer zu der Quersumme
            quersumme += n % 10;
            n -= n % 10;
            n /= 10;
            //und entfernen die rechteste Ziffer bevor wir mit 10 Teilen
        }
        //bis nur noch eine Ziffer bleibt
        quersumme += n;
    }
    return quersumme;
}
