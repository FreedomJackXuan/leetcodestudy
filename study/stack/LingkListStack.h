//
// Created by jac on 19-2-28.
//

#ifndef LEETCODE_LLSTACK_H
#define LEETCODE_LLSTACK_H

#include <iostream>
#include <list>
using namespace std;

template <class T>
class LLStack{
private:
    list<T> lst;
public:
    LLStack(){

    }

    void clear(){
        lst.clear();
    }

    bool isEmpty() const {
        return lst.empty();
    }

    T &topEl(){
        return lst.back();
    }

    T pop(){
        T el = lst.back();
        lst.pop_back();
        return el;
    }

    void push(const T & el){
        lst.push_back(el);
    }
};

#endif //LEETCODE_LLSTACK_H
