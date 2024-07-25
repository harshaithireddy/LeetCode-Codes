/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void Merge(int A[], int low, int mid, int high){
    int i = low;
    int j = mid+1;
    int B[100000];
    int x = 0;

    while(i<=mid && j<=high){
        if(A[i] < A[j])
            B[x++] = A[i++];
        else
            B[x++] = A[j++];
    }

    while(i<=mid)
        B[x++] = A[i++];

    while(j<=high)
        B[x++] = A[j++];

    for(i=low; i<=high; i++){
        A[i] = B[i-low];
    }
}

void MergeSort(int A[], int low, int high){
    if(low < high){
        int mid = (low + high) >> 1;
        MergeSort(A, low, mid);
        MergeSort(A, mid+1, high);
        Merge(A, low, mid, high);
    }
}


int* sortArray(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    MergeSort(nums, 0, numsSize-1);
    return nums;
}