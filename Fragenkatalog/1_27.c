// Quelle: https://www.geeksforgeeks.org/difference-structure-union-c/
// (GeeksforGeeks finde ich wirklich sehr nützlich)
/*

Die Unterschiede:
1. Speichergröße (bei Structs ist die Größe größer oder gleich der Summe der Membervariablen, bei Unions ist die Größe gleich der Größe der größten Membervariable)
2. Spiecher (bei Structs hat jede Membervariable einen separaten Speicherplatz, bei Unions wird der Spiecherplatz geteilt)
3. Änderung der Werte (in Unions kann das verändern von Variablen zur Änderung von anderen führen, aber nicht bei Structs)
4. Zugang (bei Unions kann nur eine Membervariable gleichzeitig zugegriffen werden)
5. Initialisierung (bei Structs können wir mehrere Variablen gleichzeitig initalisieren, bei Unions aber nur die erste)
*/
