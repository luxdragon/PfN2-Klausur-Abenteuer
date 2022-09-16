sumsq <- function (x) {
  s <- 0
  for (a in x) {
    s = s + a * a
    }
    return (s)
}

cat("Ergebnis: ",sumsq(numbers))

# Effizientere Variante:
a <- c(1, 2, 3)
print(a*a)
s <- sum(a*a)
print(s)

#Ausgabe:
#1 4 9
#14
