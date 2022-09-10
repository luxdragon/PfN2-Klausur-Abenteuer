void reverse_array(int *arr, size_t len)
{
    for(int i = 0; i< (int) len/2; i++) {
        int a = arr[i];
        int b = arr[len-i-1];
        arr[i] = b;
        arr[len-i-1] = a;
    }
}

//getestet mit:
#include <stdio.h>

int reverse_array(int *arr, size_t len)
{
    for(int i = 0; i< (int) len/2; i++) {
        int a = arr[i];
        int b = arr[len-i-1];
        arr[i] = b;
        arr[len-i-1] = a;
    }
}

int main()
{
    int words[] = {1,2,3,4,5};
    reverse_array(words, 5);
    for (int i=0; i<5; i++) {
        printf("%d\t", words[i]);
    }


    return 0;
}
