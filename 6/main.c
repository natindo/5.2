#include <stdio.h>
#include <stdlib.h>

#define swap(x,y) do \
   { unsigned char swap_temp[sizeof(x) == sizeof(y) ? (signed)sizeof(x) : -1]; \
     memcpy(swap_temp,&y,sizeof(x)); \
     memcpy(&y,&x,       sizeof(x)); \
     memcpy(&x,swap_temp,sizeof(x)); \
    } while(0)

/*
int binsearch (int a, int v[], int n) {
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (a < v[mid])
            high = mid -1;
        else if (a > v[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}
*/

int binsearch_rec (int val, int* a, size_t min, size_t max) {
    if ( max < min ) return -1;
    size_t mid = ( min + max ) / 2;  
    if ( a[mid] > val ) return bisearch(val, a, min, mid - 1 );
    if ( a[mid] < val ) return bisearch(val, a, mid + 1, max);
    if ( val == a[mid] ) return 0;
    return -1;
}

void swap1 (int v[], int i, int j) {
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

/*
void quick_sort_rec (int v[], int left, int right) {
    int i, mid;
    if (left >= right)
        return;
    swap1 (v, left, (left + right) / 2);
    mid = left;
    for (i = left + 1; i <= right; i++) {
        if (v[i] < v[left])
            swap1 (v, ++mid, i);
    swap1 (v, left, mid);
    quick_sort (v, left, mid-1);
    quick_sort (v, mid+1, right);
    }
}
*/

void quick_sort (int v[], int left, int right) {
    int i, mid;
    if (left >= right) 
        return;
    
}

int main() {

    return 0;
}
