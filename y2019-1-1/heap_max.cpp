#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    struct heap {
        int *tree = new int[100000];
        int heap_size = 0;

        int* get_tree() {
            return tree;
        }

        int get_size() {
            return heap_size;
        }

        void insert(int x) {
            tree[heap_size] = x;
            int child = heap_size;
            int parent = (heap_size - 1) / 2;
            while (tree[parent] < tree[child] && child > 0) {
                swap(tree[parent], tree[child]);
                child = parent;
                parent = (child - 1) / 2;
            }
            heap_size++;
        }

        int pop_max() {
            if (heap_size == 0) {
                return -1;
            }
            else {
                int max = tree[0];
                swap(tree[0], tree[heap_size - 1]);
                heap_size--;
                int parent = 0;
                int child1 = 1;
                int child2 = 2;
                while (child1 < heap_size) {
                    if (child2 >= heap_size) {
                        if (tree[child1] > tree[parent]) {
                            swap(tree[child1], tree[parent]);
                            parent = child1;
                        }
                        break;
                    }
                    else {
                        if (tree[child1] > tree[child2]) {
                            if (tree[child1] > tree[parent]) {
                                swap(tree[child1], tree[parent]);
                                parent = child1;
                            }
                            else {
                                break;
                            }
                        }
                        else if (tree[child2] > tree[parent]){
                            swap(tree[child2], tree[parent]);
                            parent = child2;
                        }
                        else {
                            break;
                        }
                    }
                    child1 = (parent * 2) + 1;
                    child2 = (parent * 2) + 2;
                }
                return max;
            }
        }
        
    };

    heap h;
    int t, n, x;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        if (n == 1) {
            cout << h.pop_max() << endl;
        }
        else {
            cin >> x;
            h.insert(x);
        }
    }
}