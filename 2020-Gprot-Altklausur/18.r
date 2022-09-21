#mit mathematischer Umformung bekommen wir m = a1*a2*a3...*an
# Es müsste doch sowas wie m <- prod(a) gegebene
b <- 0
for (y in a) {
  b <- b * y
}
