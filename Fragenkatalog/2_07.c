/*
Haben wir in der Vorlesung einfach nie behandelt (glaube ich)

ab Folie 98 in numerical.pdf

f ist unimodal mit Minimum x_min in [l,r] wenn f folgende Bedingungen erfüllt:

- l <= x_min <= r

weiter muss gelten:

- für alle x1, x2, l <= x1 < x2 < x_min gilt f(x1) > f(x2) > f(x_min) (also monoton fallend)

- für alle x3, x4, x_min < x3 < x4 <= r gilt f(x_min) < f(x3) < f(x4) (also monoton steigend)

Außerdem:

- f ist unimodal in Intervall [l,r], wenn es ein x_min gibt, sodass f unimodal
mit Minimum x_min in [l,r] ist*

* das ist irgendwie eine komische Aussage, soll heißen es muss ein x_min in
[l,r] geben?


=> f hat also nur genau ein Minimum im gegebenen Intervall


Die Bedingungen kurzgesagt:
1) es existiert nur ein Minimum x_min zwischen l und r.
2) Für alle x<x_min und für alle x>x_min gilt f(x)>f(x_min).
*/
