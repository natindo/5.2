#include <stdio.h>
#include <math.h>

//#define swap(t,x,y) \
//{t temp = y; \
//y = x; \
//x = temp;}

//void binsearch( int arr[], int max, int key) {
//    int mid;
//    if (max <= 0) {
//        printf("The number %d was not found in array\n", key);
//        return;
//    }
//    mid = max/2;
//    if (key == arr[mid])
//        printf("Search = %d\nThis element was found \n", key);
//    else if (key > arr[mid])
//        binsearch(arr + mid + 1, max - mid - 1, key);
//    else if (key < arr[mid])
//        binsearch(arr, mid, key);
//}
#define  MAX_LEVELS  300

void quickSort(int *arr, int elements) {


    int  piv, beg[MAX_LEVELS], end[MAX_LEVELS], i = 0, L, R, swap;

    beg[0] = 0;
    end[0] = elements;
    while (i >= 0) {
        L = beg[i];
        R = end[i] - 1;
        if (L < R) {
            piv = arr[L];
            while (L < R) {
                while (arr[R] >= piv && L < R)
                    R--;
                if (L < R)
                    arr[L++] = arr[R];
                while (arr[L] <= piv && L < R)
                    L++;
                if (L < R)
                    arr[R--] = arr[L];
            }
            arr[L] = piv;
            beg[i+1] = L+1;
            end[i+1] = end[i];
            end[i++] = L;
            if (end[i] - beg[i] > end[i-1] - beg[i-1]) {
                swap = beg[i];
                beg[i] = beg[i-1];
                beg[i-1] = swap;
                swap = end[i];
                end[i] = end[i-1];
                end[i-1] = swap;
            }
        }
        else i--;
    }
}




int main() {
    int array[] = {1, 7, 3, 9, 10, 6, 12, 5, 2, 8, 11};
    quickSort(array, 11);
    for (int i = 0; i <= 10; ++i) {
        printf("%4d", array[i]);
    }
    return 0;
}