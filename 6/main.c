#include <stdio.h>
#include <stdlib.h>

//macros swap
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

//binsearch with req

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

//quickSort without req

void quickSort(int *arr, int elements) {

  #define  MAX_LEVELS  300

  int  piv, beg[MAX_LEVELS], end[MAX_LEVELS], i=0, L, R, swap ;

  beg[0]=0; end[0]=elements;
    while (i>=0) {
        L=beg[i]; R=end[i]-1;
        if (L<R) {
            piv=arr[L];
            while (L<R) {
                while (arr[R]>=piv && L<R)
                    R--; 
                if (L<R) 
                    arr[L++]=arr[R];
                while (arr[L]<=piv && L<R) 
                    L++;    
                if (L<R) 
                    arr[R--]=arr[L];
            }
            arr[L]=piv;
            beg[i+1]=L+1;
            end[i+1]=end[i];
            end[i++]=L;

            if (end[i]-beg[i]>end[i-1]-beg[i-1]) {
            swap=beg[i];
            beg[i]=beg[i-1];
            beg[i-1]=swap;
            swap=end[i];
            end[i]=end[i-1];
            end[i-1]=swap;
        }
        }
        else {
        i--; 
        }
    }
}

//Radix sort

int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void RadixSort(int arr[], int n, int exp) {
    int output[n]; 
    int i, count[10] = {0};

    for (i = 0; i < n; i++)
        count[ (arr[i]/exp)%10 ]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--) {
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }

    for (i = 0; i < n; i++)
        arr[i] = output[i];

}

void radixsort(int arr[], int n) {
    int m = getMax(arr, n);
    for (int exp = 1; m/exp > 0; exp *= 10)
        RadixSort(arr, n, exp);
}

//MergeSort

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
 
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    
    return 0;
}
