/* #include <stdio.h>
#include <stdlib.h> //für EXIT_FAILURE

int *merge_arrays(const int *a, unsigned long alen, const int *b, unsigned long blen) {
  if (alen != blen) {
    fprinf(stderr, "%u ist nicht gleich $u, Programm abgebrochen.", alen, blen);
    return EXIT_FAILURE;
  }
  int *newarr = malloc(sizeof(int)*(alen+blen));
  unsigned long i = 0, j = 0;
  while (i != alen && j != blen) {
    if (a[i] = b[j]) {
      newarr[i+j] = a[i];
      i++;
      newarr[i+j] = b[i];
      j++;
    } else if (a[i] > b[j]) {
      newarr[i+j] = b[j];
      j++;
    } else {
      newarr[i+j] = a[j];
      i++;
    }
  }
  return newarr;
} */

#include <stdio.h>
#include <stdlib.h> //für EXIT_FAILURE
int *merge_arrays(const int *a, unsigned long alen, const int *b, unsigned long blen) {
  if (alen != blen) {
    fprintf(stderr, "%lu ist nicht gleich %lu, Programm abgebrochen.", alen, blen); //lu statt u
    int *err = malloc(sizeof(int));
    err[0] = 0;
    return err;
  }
  int *newarr = malloc(sizeof(int)*(alen+blen));
  unsigned long i = 0, j = 0;
  while (i != alen-1 && j != blen-1) { //vergessen hier -1 zu schreiben
    if (a[i] == b[j]) {
      newarr[i+j] = a[i];
      i++;
      newarr[i+j] = b[j];
      j++;
    } else if (a[i] > b[j]) {
      newarr[i+j] = b[j];
      j++;
    } else {
      newarr[i+j] = a[i];
      i++;
    }
  }
  return newarr;
}

int main(void) {
  int arr1[] = {1, 2, 4, 8, 16, 32};
  int arr2[] = {1, 3, 9, 27, 81, 100};
  int *arr3 = merge_arrays(arr1, 6, arr2, 6);
  for (int i = 0; i < 12; i++) {
      printf("%d\n", arr3[i]);
  }
  free(arr3); //das habe ich vergessen
  return 0;
}
