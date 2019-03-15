//
// Created by jac on 19-3-15.
//

#ifndef LEETCODE_BTREE_NODE_H
#define LEETCODE_BTREE_NODE_H

/*
 * B-Tree定义：
 * 1）所有叶子处于同一水平。
 * 2）B树由术语最小度't'定义。 t的值取决于磁盘块大小。
 * 3）除root之外的每个节点必须至少包含t-1个key。 Root可能包含最少1个key。
 * 4）所有节点（包括根）最多可包含2t - 1个key。
 * 5）节点的子节点数等于其中的键数加1。
 * 6）节点的所有key按递增顺序排序。 两个键k1和k2之间的子包含范围为k1和k2的所有键。
 * 7）B-Tree从根增长和缩小，这与二进制搜索树不同。 二元搜索树向下生长，也从向下收缩。
 * 8）与其他平衡二进制搜索树一样，搜索，插入和删除的时间复杂度为O（Logn）。
 * */

#include <iostream>
using namespace std;

template <class T, int M>
class BTree_Node {
public:
    BTree_Node(int _t, bool _leaf);
    void traverse(); //用于遍历以此节点为根的子树中的所有节点的函数
    BTree_Node *search(int k); //用于搜索以此节点为根的子树中的键的函数
    void insertNonFull(int k);
    void splitChild(int i, BTree_Node *y);

private:
    bool leaf; //如果是叶子节点的话为真, 其他情况false
    int *keys; // 键值
    int t; //最小度数
    BTree_Node **C;//一系列子指针
    int n; //当前键数
    friend class BTree<T,M>;
};

template <class T, int M>
class BTree{
public:
    BTree(int _t){
        root == NULL;
        t = _t;
    }

    void traverse(){
        if (root != NULL)
            root->traverse();
    }

    BTree_Node *search(int k){
        return (root == NULL) ? NULL: root->traverse();
    }

    void insert(int k);

private:
    BTree_Node *root;
    int t;//
};

#endif //LEETCODE_BTREE_NODE_H
