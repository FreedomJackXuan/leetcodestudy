//
// Created by jac on 19-3-15.
//

#include "BTree_Node.h"

BTree_Node::BTree_Node(int _t, bool _leaf) {
    t = _t;
    leaf = _leaf;
    keys = new int[2 * t - 1];
    C = new BTree_Node *[2 * t];
    n = 0;
}

void BTree_Node::traverse() {
    int i;
    for (i = 0; i < n; i++) {
        if (leaf == false)
            C[i]->traverse();
        cout<< " "<<keys[i];
    }

    if (leaf == false)
        C[i] -> traverse();
}

BTree_Node *BTree_Node::search(int k) {
    int i = 0;
    while (i < n && k > keys[i])
        i++;
    if (keys[i] == k)
        return this;
    if (leaf == true)
        return NULL;
    return C[i] -> search(k);
}

void BTree::insert(int k) {
    if (root == NULL) {
        root = new BTree_Node(t, true);
        root->keys[0] = k;
        root->n = 1;
    } else {
        if (root -> n == 2*t-1) {
            BTree_Node *s = new BTree_Node(t, false);
            s->C[0]= root;
            s->splitChild(0,root);
            int i = 0;
            if (s->keys[0] < k)
                i++;
            s->C[i]->insertNonFull(k);
            root = s;
        } else {
            root->insertNonFull(k);
        }
    }
}

void BTree_Node::insertNonFull(int k) {
    int i = n-1;
    if (leaf == true){
        while (i >= 0 && keys[i] > k){
            keys[i+1] = keys[i];
            i--;
        }
        keys[i+1] = k;
        n = n+1;
    } else {
        while (i >= 0 && keys[i] > k)
            i--;
        if (C[i+1]->n == 2*t-1) {
            splitChild(i+1,C[i+1]);
            if (keys[i+1] < k)
                i++;
        }
        C[i+1]->insertNonFull(k);
    }
}

void BTree_Node::splitChild(int i, BTree_Node *y) {
    BTree_Node *z = new BTree_Node(y->t, y->leaf);
    z->n = t-1;
    for (int j = 0; j < t-1; j++)
        z->keys[j] = y->keys[j+t];
    if (y->leaf == false) {
        for (int j = 0; j < t; ++j) {
            z->C[j] = y->C[j+t];
        }
    }
    y->n = t-1;
    for (int j = n; j >= i+1; j--) 
        C[j+1] = C[j];
    C[i+1] = z;
    for (int j = n-1; j >= i; j--) {
        keys[j+1] = keys[j];
    }
    keys[i] = y->keys[t-1];
    n = n+1;
}