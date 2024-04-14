#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n, x, k, l, r, left, right, mid, l_ind, r_ind;
    cin >> n;
    int *a = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> x;
        a[i] = x;
    }
    sort(a, &(a[n]));
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> l >> r;
        left = -1;
        right = n;
        while (right - left > 1) {
            mid = (left + right) / 2;
            if (a[mid] < l) {
                left = mid;
            }
            else {
                right = mid;
            }
        }
        l_ind = left + 1;
        left = -1;
        right = n;
        while (right - left > 1) {
            mid = (left + right) / 2;
            if (a[mid] > r) {
                right = mid;
            }
            else {
                left = mid;
            }
        }
        r_ind = right - 1;
        cout << r_ind - l_ind + 1 << " ";
    }
}