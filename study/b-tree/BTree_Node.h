//
// Created by jac on 19-3-15.
//

#ifndef LEETCODE_BTREE_NODE_H
#define LEETCODE_BTREE_NODE_H

/*
 * B-Tree定义：
 * 1：除了叶节点之外,根节点至少有两个子树
 * 2：每个非根非叶节点都有k-1个键值和k个指向子树的指针(其中celi(m / 2) <= k <= m  celi表示取上界)
 * 3：每个叶节点都有k-1个键值(其中 celi(m / 2) <= k <= m)
 * 4：所有的叶节点在同一层
 * */

//struct BTNode{
//    int num; //当前节点数数量
//    int dim;
//    int *keys;
//    BTNode *parent;
//    BTNode ** childs;
//    BTNode(){}
//
//};
#include <iostream>
using namespace std;

template <class T, int M>
class BTree_Node {
public:
    BTree_Node(int _t, bool _leaf);
    void traverse(); //用于遍历以此节点为根的子树中的所有节点的函数
    BTree_Node *search(int k); //用于搜索以此节点为根的子树中的键的函数

private:
    bool leaf; //如果是叶子节点的话为真, 其他情况false
    int *keys; // 键值
    int t; //最小度数（定义键数范围）
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

private:
    BTree_Node *root;
    int t;//
};

#endif //LEETCODE_BTREE_NODE_H
