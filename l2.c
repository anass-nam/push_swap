#include <stdio.h>
#include <stdlib.h>

int ceilIndex(int arr[], int T[], int l, int r, int key) {
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (arr[T[m]] >= key)
            r = m;
        else
            l = m;
    }

    return r;
}

int lis(int arr[], int n) {
    int *tailIndices = (int*) malloc(n * sizeof(int));
    int *prevIndices = (int*) malloc(n * sizeof(int));
    int len = 1; // length of LIS

    tailIndices[0] = 0;
    prevIndices[0] = -1;

    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[tailIndices[0]]) {
            tailIndices[0] = i;
        } else if (arr[i] > arr[tailIndices[len-1]]) {
            prevIndices[i] = tailIndices[len-1];
            tailIndices[len++] = i;
        } else {
            int pos = ceilIndex(arr, tailIndices, -1, len-1, arr[i]);
            prevIndices[i] = tailIndices[pos-1];
            tailIndices[pos] = i;
        }
    }

    int *lisIndices = (int*) malloc(len * sizeof(int));
    int k = tailIndices[len-1];
    for (int i = len-1; i >= 0; i--) {
        lisIndices[i] = k;
        k = prevIndices[k];
    }

    printf("LIS: ");
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[lisIndices[i]]);
    }
    printf("\n");

    free(tailIndices);
    free(prevIndices);
    free(lisIndices);

    return len;
}

int main() {
    int arr[] = {-4,4,1,2,-6,6,-2,-1,0,5,11,8,7,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Length of LIS is %d\n", lis(arr, n));
    return 0;
}

