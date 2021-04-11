#include <stdio.h>
#include <stdlib.h>

#define swap(x,y) do \
   { unsigned char swap_temp[sizeof(x) == sizeof(y) ? (signed)sizeof(x) : -1]; \
     memcpy(swap_temp,&y,sizeof(x)); \
     memcpy(&y,&x,       sizeof(x)); \
     memcpy(&x,swap_temp,sizeof(x)); \
    } while(0)

 #define swap(t,x,y) {t temp = x; x = y; y = temp;}


 int main(void) {
     int ai=1, bi=2;
     printf("Initial: ai=%d, bi=%d\n", ai, bi);
     swap(int, ai, bi);
     printf("Swapped: ai=%d, bi=%d\n", ai, bi);

     float af=1.0, bf=2.0;
     printf("Initial: af=%f, bf=%f\n", af, bf);
     swap(float, af, bf);
     printf("Swapped: af=%f, bf=%f\n", af, bf);

     return 0;
 }

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

#define MAX_LEVELS  1000

#define MAX_LEVELS  48

int quickSort(int *arr, size_t elements) {
    size_t beg[MAX_LEVELS], end[MAX_LEVELS], L, R;
    int i = 0;

    beg[0] = 0;
    end[0] = elements;
    while (i >= 0) {
        L = beg[i];
        R = end[i];
        if (R - L > 1) {
            size_t M = L + ((R - L) >> 1);
            int piv = arr[M];
            arr[M] = arr[L];

            if (i == MAX_LEVELS - 1)
                return -1;
            R--;
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
            M = L + 1;
            while (L > beg[i] && arr[L - 1] == piv)
                L--;
            while (M < end[i] && arr[M] == piv)
                M++;
            if (L - beg[i] > end[i] - M) {
                beg[i + 1] = M;
                end[i + 1] = end[i];
                end[i++] = L;
            } else {
                beg[i + 1] = beg[i];
                end[i + 1] = L;
                beg[i++] = M;
            }
        } else {
            i--;
        }
    }
    return 0;
}

int main() {
    
    return 0;
}
