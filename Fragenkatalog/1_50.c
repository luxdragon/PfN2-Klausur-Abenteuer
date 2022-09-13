/*
n-Queens-Problem war eine dieser wunderbaren peer-teaching Aufgaben.

einführendens Video:
https://www.youtube.com/watch?v=0DeznFqrgAI

Es ist sehr zu empfehlen die entsprechenden Folien 309-327 in c_slides
verstanden zu haben um sich vorstellen zu können was passiert und die Antwort
richtig einordnen zu können.

Dort auf F.325 steht letztlich auch die Lösung:
Man nimmt ein zusätzliches Array arr und initialisiert es mit einem Wert, für 
den man festlegt, dass er für false steht. Z.B. die Größe des Schachbrettes n.
(Das ist praktisch, weil die Zeilen udn Reihen im Array dann mit 0 bis n-1 
nummeriert sind, das heißt n kann nirgendwo als Lösung auftauchen)
- Reihe i
- Spalte j

dann markiert man im Array arr[i] = j;

Damit weiß man über den Index des Arrays in welcher Zeile eine Queen steht. 
Die Zahl die dann an der Stelli im Index steht (0 =< j < n) steht für die 
zugehörige Spalte an der die Queen dann steht.

Somit lässt sich geschickt mit einem 1-D array verfolgen, wo eine Queen steht.
*/
