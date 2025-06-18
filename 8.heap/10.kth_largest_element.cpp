#include "bits/stdc++.h"
using namespace std;

//using quick select, T.C:O(n), S.C:O(log(n))
int makePartition (vector<int> &arr, int low, int high) {
    int pivot = arr[high];
    int currentIndx = low - 1;
    for (int i = low; i < high; i++) {
        if (arr[i] < pivot) {
            currentIndx++;
            int temp = arr[i];
            arr[i] = arr[currentIndx];
            arr[currentIndx] = temp;
        }
    }
    int temp = arr[high];
    arr[high] = arr[currentIndx + 1];
    arr[currentIndx + 1] = temp;
    return currentIndx + 1;
}
int quickSelect (vector<int> &arr, int low, int high, int k) {
    if (k > 0 && k <= high - low + 1) {
        int pivot = makePartition (arr, low, high);
        if (pivot - low == k - 1) {
            return arr[pivot];
        } else if (pivot - low < k - 1) {
            return quickSelect (arr, pivot + 1, high, k - pivot + low - 1);
        } else {
            return quickSelect (arr, low, pivot - 1, k);
        }
    }
    return - 1;
}
int getKthLargestElement(vector<int> list, int k) {
    int n = list.size();
    return quickSelect (list, 0, n - 1, n - k + 1);
}

int main() {
    vector<int>v={4,3,4,5,2,1};
    cout<<getKthLargestElement(v,3);
}