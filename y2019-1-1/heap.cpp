#include <iostream>
#include <vector>

using namespace std;

int main() {
    struct heap {
        int *tree = new int[1000];
        int heap_size = 0;

        int hsize() {
            return heap_size;
        }

        int* get_tree() {
            return tree;
        }

        int get_min() {
            if (heap_size != 0) {
                return tree[0];
            }
        }

        void insert(int x) {
            tree[heap_size] = x;
            int parent = (heap_size - 1) / 2;
            int child = heap_size;
            while (parent > 0 && tree[child] < tree[parent]) {    
                swap(tree[child], tree[parent]);
                child = parent;
                parent = (parent - 1) / 2;
            }
            heap_size++;
        }

        int pop_min() {
            int min = tree[0]; 
            swap(tree[0], tree[heap_size - 1]);
            heap_size--;
            int parent = 0;
            while (true) {
                int child1 = 2 * parent + 1;
                int child2 = 2 * parent + 2;
                if (child2 > heap_size) {
                    if (child1 > heap_size) {
                        break;
                    }
                    else if (tree[child1] >= tree[parent]) {
                        break;
                    }
                    else {
                        swap(tree[child1], tree[parent]);
                        parent = child1;
                    }
                }
                else if (tree[child1] < tree[child2]) {
                    if (tree[parent] > tree[child1]) {
                        swap(tree[parent], tree[child1]);
                        parent = child1;
                    }
                    else {
                        break;
                    }
                }
                else {
                    if (tree[parent] > tree[child2]) {
                        swap(tree[parent], tree[child2]);
                        parent = child2;
                    }
                    else {
                        break;
                    }
                }
            }
            return min;
        }
    };
    
    heap h;
    int n;
    cin >> n;
    int x, num;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x == 1) {
            cout << h.pop_min();
        }
        else {
            cin >> num;
            h.insert(num);
        }
    }
}