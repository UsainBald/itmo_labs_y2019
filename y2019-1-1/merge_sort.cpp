#include <iostream>

using namespace std;

void merge(int*, int, int);
void merge_sort(int*, int, int);


void merge(int* array, int l, int r) {
    int *arr = new int[r - l];
    int i = 0; int j = 0;
    int mid = (l + r) / 2; 
    while (i + j < r - l) {
        if (l + i >= mid) {
            arr[i + j] = array[mid + j];
            j++;
        }
        else if (mid + j >= r) {
            arr[i + j] = array[l + i];
            i++;
        }
        else if (array[l + i] < array[mid + j]) {
            arr[i + j] = array[l + i];
            i++;
        }
        else {
            arr[i + j] = array[mid + j];
            j++;
        }
    }
    int t = 0;
    for (int i = l; i < r; i++) {
        array[i] = arr[t];
        t++;
    }
}


void merge_sort(int* array, int left, int right) {
    if (right - left < 2) {
        return;
    }
    int mid = (left + right) / 2;
    merge_sort(array, left, mid);
    merge_sort(array, mid, right);
    merge(array, left, right);
}


int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i] = x;
    }
    merge_sort(a, 0, n);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}