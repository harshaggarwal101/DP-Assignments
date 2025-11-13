//
//  reverse_list.cpp
//  Created by HARSH AGGARWAL on 05/11/25.
//

#include <iostream>
using namespace std;

struct node {
    int val;
    node* next;
    node(int x) : val(x), next(nullptr) {}
};

node* revlist(node* h) {
    if (!h || !h->next) return h;
    node* nh = revlist(h->next);
    h->next->next = h;
    h->next = nullptr;
    return nh;
}

int main() {
    int n, x;
    cin >> n;
    node* head = nullptr;
    node* tail = nullptr;

    for (int i = 0; i < n; i++) {
        cin >> x;
        node* p = new node(x);
        if (!head) head = p;
        else tail->next = p;
        tail = p;
    }

    head = revlist(head);

    node* t = head;
    while (t) {
        cout << t->val << " ";
        t = t->next;
    }
    return 0;
}
