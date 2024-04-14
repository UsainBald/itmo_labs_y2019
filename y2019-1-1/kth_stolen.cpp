#include <iostream>
#include <vector>

int partition(std::vector<int>& mas, int l, int r) {
  std::swap(mas[l + rand() % (r - l)], mas[r]);
  int x = mas[r];
  int i = l-1;
  for (int j = l; j <= r; j++) {
    if (mas[j] <= x)
      std::swap(mas[++i],mas[j]);
  }
  return i;
}

int nth(std::vector<int> mas, int n) {
  int l = 0, r = mas.size() - 1;
  for(;;) {
    int pos = partition(mas,l,r);
    if (pos < n)
      l = pos + 1;
    else if (pos > n)
      r = pos - 1;
    else return mas[n];
  }
}

int main() {
    srand(time(0));
    int n, x;
    std::cin >> n;
    std::vector<int> a;

    for (int i = 0; i < n; i++) {
        std::cin >> x;
        a.push_back(x);
    }
    std::cout << nth(a, 3) << std::endl;

    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " ";
    }

}