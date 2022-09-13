/* Diese Aufgabe verlangt das Verstehen von Padding - schaut euch dazu
Videos an, aber kurzgefasst: ein 64-bit Prozessor liest pro Schritt immer
8-Bytes und ein veralteter 32-bit Prozessor 4-Bytes pro Schritt und der
Compiler versuch die Variablen so zu gruppieren, dass jede Variable in einem
Schritt gelesen wird (sonst wird die Laufzeit deutlich verlängert). z.B. mit
einem 32-bit Prozessor würden wir, wenn wir 2 Chars (je 1 Byte) und einen
Integer (4 Bytes) in einem Struct hätten, die ersten zwei Bytes nach den
Chars leer lassen, um den Integer dann in einem Schritt komplett zu lesen. */ 


typedef struct
{
    unsigned int year;  //4 Bytes
    unsigned char day;  //1 Byte
    unsigned char month; //1 Byte
    unsigned char hours; //1 Byte
    unsigned char minutes; //1 Byte
} Time; //einfach die Reihenfolge ändern
