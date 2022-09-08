//hierzu findet man in den Folien:
typedef int bool;
#define true 1;
#define false 0;

//oder

typedef char bool;
#define true 1;
#define false 0;


//aber die wahrscheinlich gewollte Lösung ist (kann man auch mit char machen):
typedef int bool;
const bool true = 1;
const bool false = 0;
