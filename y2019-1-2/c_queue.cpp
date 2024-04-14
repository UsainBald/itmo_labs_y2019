#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    struct queue {
        int *a = new int[100001];
        int *ids = new int[100001];
        int h = 0, t = 0;

        void add(int id) {
            a[t] = id;
            ids[id] = t++;
        }

        void remove_first() {
            h++;
        }

        void remove_last() {
            t--;
        }

        int get_queue(int id) {
            return ids[id] - h;
        }

        int get_first_id() {
            return a[h];
        }
    };

    queue q;
    int n, x, id;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> x;
        if (x == 1) {
            std::cin >> id;
            q.add(id);
        }
        else if (x == 2) {
            q.remove_first();
        }
        else if (x == 3) {
            q.remove_last();
        }
        else if (x == 4) {
            std::cin >> id;
            std::cout << q.get_queue(id) << std::endl;
        }
        else if (x == 5) {
            std::cout << q.get_first_id() << std::endl;
        }
    }
}