#include <iostream>
template <typename T> //das hätte ich fast vergessen

static T distribute_elements(T *buf, T *a, size_t len) {
    size_t sidx = 0, lidx = len - 1, pivot = a[len-1];
    for (size_t idx = 0; idx < len - 1; idx++)
        if (a[idx] < pivot)
            buf[sidx++] = a[idx];
        else
            buf[lidx--] = a[idx];
    for (size_t idx = 0; idx < len; idx++) a[idx] = buf[idx];
        a[lidx] = pivot;
    return lidx;
}

void quicksort(T *a, T *buf, size_t len) {
    if (len > 1) {
        size_t pivotidx = distribute_elements(buf, a, len);
        quicksort(a, buf, pivotidx);
        quicksort(a+pivotidx+1, buf+pivotidx+1, len - (pivotidx + 1));
    }
}

void quicksort_all(T *a, size_t len) {
    T *buf = new T[len*sizeof(*buf)];
    quicksort(a, buf, len);
    delete[] buf;
}
