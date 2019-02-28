//
// Created by jac on 19-2-28.
//

#ifndef LEETCODE_ARRAYSTACK_H
#define LEETCODE_ARRAYSTACK_H

#include <iostream>
#include <vector>
using namespace std;
template <class T, int capacity = 30>
class ArrayStack {
private:
    vector<T> pool;
public:
    ArrayStack(){
        pool.reserve(capacity);
    }
    void clear(){
        pool.clear();
    }
    bool isEmpty() const {
        return pool.empty();
    }
    T &toPEL(){
        return pool.back();
    }
    T pop(){
        T el = pool.back();
        pool.pop_back();
        return el;
    }
    void push(const T &el){
        pool.push_back(el);
    }
};


#endif //LEETCODE_ARRAYSTACK_H
