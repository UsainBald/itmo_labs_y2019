#include <iostream>

using namespace std;

struct Node {
    int x;
    int y;
    Node* left;
    Node* right;

    Node(int val) {
        x = val;
        y = rand() * rand();
        left = nullptr;
        right = nullptr;
    }
};

void split(Node* t, Node*& l, Node*& r, int val) {
    if (t == nullptr) {
        l = nullptr;
        r = nullptr;
        return;
    }
    if (val < t->x) {
        split(t->left, l, t->left, val);
        r = t;
    }
    else {
        split(t->right, t->right, r, val);
        l = t;
    }
}

void merge(Node*& t, Node* l, Node* r) {
    if (l == nullptr) {
        t = r;
        return;
    }
    if (r == nullptr) {
        t = l;
        return;
    }
    if (l->y < r->y) {
        merge(l->right, l->right, r);
        t = l;
    }
    else {
        merge(r->left, l, r->left);
        t = r;
    }
}

void insert(Node*& t, Node* v) {
    if (t == nullptr) {
        t = v;
        return;
    }
    if (v->y < t->y) {
        if (v->x < t->x) {
            insert(t->left, v);
        }
        else {
            insert(t->right, v);
        }
        return;
    }
    split(t, v->left, v->right, v->x);
    t = v;
}

bool exists(Node*& t, int val) {
    if (t == nullptr) {
        return false;
    }
    if (t->x == val) {
        return true;
    }
    if (val < t->x) {
        return exists(t->left, val);
    }
    else {
        return exists(t->right, val);
    }
}

Node* prev(Node*& t, int val) {
    Node* cur = t;
    Node* prev = nullptr;
    while (cur != nullptr) {
        if (val <= cur->x) {
            cur = cur->left; 
        }
        else {
            prev = cur;
            cur = cur->right;
        }
    }
    return prev;
}

Node* next(Node*& t, int val) {
    Node* cur = t;
    Node* succ = nullptr;
    while (cur != nullptr) {
        if (val < cur->x) {
            succ = cur;
            cur = cur->left;
        }
        else {
            cur = cur->right;
        }
    }
    return succ;
}

void delete_node(Node*& t, int val) {
    if (t == nullptr) {
        return;
    }
    if (val < t->x) {
        delete_node(t->left, val);
    }
    else if (val > t->x) {
        delete_node(t->right, val);
    }
    else {
        merge(t, t->left, t->right);
    }
}

signed main() {
    Node* tree = nullptr;
    Node* v;
    string s;
    int x;
    while (cin >> s) {
        if (s == "insert") {
            cin >> x;
            v = new Node(x);
            if (!exists(tree, x)) {
                insert(tree, v);
            }
        }
        else if (s == "exists") {
            cin >> x;
            if (exists(tree, x) == true) {
                cout << "true" << endl;
            }
            else {
                cout << "false" << endl;
            }
        }
        else if (s == "next") {
            cin >> x;
            Node* ans = next(tree, x);
            if (ans == nullptr) {
                cout << "none" << endl;
            }
            else {
                cout << ans->x << endl;
            }
        }
        else if (s == "prev") {
            cin >> x;
            Node* ans = prev(tree, x);
            if (ans == nullptr) {
                cout << "none" << endl;
            }
            else {
                cout << ans->x << endl;
            }
        }
        else if (s == "delete") {
            cin >> x;
            if (exists(tree, x)) {
                delete_node(tree, x);
            }
        }
    }
}