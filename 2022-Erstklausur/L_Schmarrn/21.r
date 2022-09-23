squash_to_range <- function (x) {
  x <- x %% 2*pi
  return(x)
}
