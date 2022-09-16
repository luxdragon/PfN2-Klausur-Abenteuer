f <- function(x)
{
    z <- 0
    for (y in x)
    {
        z <- z + y
    }
    z/length(x)
    #15 / 5 = 3
}
k <- f(c(1, 2, 3, 4, 5))

print(k)

#Ausgabe:
#3
