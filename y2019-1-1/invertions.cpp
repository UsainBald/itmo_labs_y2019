#include <iostream>

void merge_sort(int*, int, int, long long*);
void merge(int*, int, int, long long*);

void merge(int* a, int l, int r, long long* sum) {
    int mid = (r + l) / 2;
    int x = 0, y = 0, cnt = mid - l;
    int *s = new int[r - l];
    while ((x + y) < (r - l)) {
        if (l + x >= mid) {
            s[x + y] = a[mid + y];
            y++;
            *sum += cnt;
        }
        else if (mid + y >= r) {
            s[x + y] = a[l + x];
            x++;
            cnt--;
        }
        else if (a[l + x] <= a[mid + y]) {
            s[x + y] = a[l + x];
            x++;
            cnt--;
        }
        else {
            s[x + y] = a[mid + y];
            y++;
            *sum += cnt;
        }
    }
    int j = 0;
    for (int i = l; i < r; i++) {
        a[i] = s[j++];
    }
}

void merge_sort(int* a, int l, int r, long long* sum) {
    if ((r - l) < 2) {
        return;
    }
    else {
        int mid = (r + l) / 2;
        merge_sort(a, l, mid, sum);
        merge_sort(a, mid, r, sum);
        merge(a, l, r, sum);
    }

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, x, count = 0;
    std::cin >> n;
    int *a = new int[n];
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> x;
        a[i] = x;
    }
    merge_sort(a, 0, n, &sum);
    std::cout << sum;
}