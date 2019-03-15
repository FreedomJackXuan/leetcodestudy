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