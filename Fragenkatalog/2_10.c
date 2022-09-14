/*
Ganz knapp: Eine Matrix wird nach verschiedenen Kriterien in beliebig viele 
kleinere Matritzen zerlegt, welche dann einzeln berechnet werden um dann zum
Ergebnis der Anfangsmatrix zusammengeführt werden.

Für die Kriterien und die Skizze:
Cpp_slides.pdf ab Folie 88
Skizze auf F.89


Die Beschleunigung der Laufzeit wird erreicht, wenn die Untermetrizen klein
genug sind um dann im cache berechnet zu werden => sehr schnell
Dies wäre mit der ursprünglichen großen Matrix nicht möglich


Die Matrixmultiplikation ist nur eine Möglichkeit der Anwendung 
des devide and conquer Prinzips


(es bedeutet auch nicht wie in der VL falsch behauptet Teile und Herrsche,
sondern Teile und Erobere. Hat mich hart getriggered)

*/
