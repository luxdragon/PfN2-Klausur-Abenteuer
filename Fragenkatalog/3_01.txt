/*
  std::cin << wert;

  einen Wert nach cin zu geben ergint keinen Sinn und ist deswegen auch
  syntaktisch verboten

  Einen String von cin in wert zu speichern, ist natürlich möglich
  Ich hoffe es ist die Korrektur die gemeint ist.

  Ansonsten könnte noch gemeint sein, dass wert initialisiert und nach cout
  gegeben werden soll

*/
 #include<iostream>
 #include<string>

int main(void){
  std::string wert;
  std::cin >> wert;
}
