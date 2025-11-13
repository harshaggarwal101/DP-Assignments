//
//  merge_sorted_lists.cpp
//  Created by HARSH AGGARWAL on 05/11/25.
//

#include <iostream>
using namespace std;

struct node {
    int val;
    node* next;
    node(int x) : val(x), next(nullptr) {}
};

node* merge_two(node* a, node* b) {
    if (!a) return b;
    if (!b) return a;
    if (a->val < b->val) {
        a->next = merge_two(a->next, b);
        return a;
    } else {
        b->next = merge_two(a, b->next);
        return b;
    }
}

int main() {
    int n1, n2, x;
    cin >> n1;
    node* a = nullptr; node* ta = nullptr;
    for (int i = 0; i < n1; i++) {
        cin >> x;
        node* p = new node(x);
        if (!a) a = p;
        else ta->next = p;
        ta = p;
    }

    cin >> n2;
    node* b = nullptr; node* tb = nullptr;
    for (int i = 0; i < n2; i++) {
        cin >> x;
        node* p = new node(x);
        if (!b) b = p;
        else tb->next = p;
        tb = p;
    }

    node* h = merge_two(a, b);
    node* t = h;
    while (t) {
        cout << t->val << " ";
        t = t->next;
    }
    return 0;
}
