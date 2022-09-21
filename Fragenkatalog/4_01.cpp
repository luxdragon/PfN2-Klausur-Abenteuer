/* threads.pdf Folie 6

Thread ist ein unabhängiger Stream von Instruktionen der vom OS
eingeplant werden kann. Dabei können mehrere Threads gleichzeitig laufen,
das OS muss sie nur kennen um sie managen zu können.

Aus der sicht des Programmierenden:
Thread kann als Funktion gesehen werden, welche unabhängig von
ihrem Haupt-Programm läuft

Wenn min. 2 dieser Funktionen nebeneinander/unabhängig voneinander laufen,
dann ist das Programm "multi-threaded"

Threads greifen alle auf einen geteilten Speicher zu (meist um zu lesen),
haben aber auch einen eigenen Programmteil, der die einzelnen Threads
koordiniert
Darstellung Folie 7 */
