#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int *counter = new int[101];
    for (int i = 0; i < 101; i++) {
        counter[i] = 0;
    }
    int x;
    while (cin >> x) {
        counter[x] = counter[x] + 1;
    }
    for (int i = 0; i < 101; i++) {
        while (counter[i] > 0) {
            cout << i << " ";
            counter[i] = counter[i] - 1;
        }
    }
}