//
// Created by jac on 19-2-28.
//

/*
 * 大数做运算
 * */

#include <iostream>
#include <sstream>
#include "LingkListStack.h"
using namespace std;

class BigNumberCollector{
public:
    BigNumberCollector(){
        llStack = new LLStack<char>();
    }

    void addingLargeNumbers(string l1, string l2){
        LLStack<char> *ll1 = new LLStack<char>();
        for (auto &l : l1) {
            ll1->push(l);
        }
        LLStack<char> *ll2 = new LLStack<char>();
        for (auto &l : l2){
            ll2->push(l);
        }
        int carry = 0;
        stringstream ss;
        while (!ll1->isEmpty() || !ll2->isEmpty()) {
            ss << ll1->pop();
            int s1, s2;
            ss >> s1;
            ss.clear();
            ss << ll2->pop();
            ss >> s2;
            ss.clear();
            int sum = s1 + s2+carry;
            cout<<sum<<endl;
            string res;
            ss << sum;
            ss >> res;
            ss.clear();
            if (res.size() == 1) {
                llStack->push(1);
                carry = 0;
            }
            else {
                llStack->push(res[1]);
                ss << res[0];
                ss >> carry;
                ss.clear();
            }
        }
        while (!ll1->isEmpty()){
            if (carry != 0) {
                int t;
                ss << ll1->pop();
                ss >> t;
                ss.clear();
                int sum = t + carry;
                string res;
                ss << sum;
                ss >> res;
                ss.clear();
                if (res.size() == 1) {
                    llStack->push(1);
                    carry = 0;
                }
                else {
                    llStack->push(res[1]);
                    ss << res[0];
                    ss >> carry;
                    ss.clear();
                }
            } else {
                llStack->push(ll1->pop());
            }
        }
        while (!ll2->isEmpty()) {
            if (carry != 0) {
                int t;
                ss << ll2->pop();
                ss >> t;
                ss.clear();
                int sum = t + carry;
                string res;
                ss << sum;
                ss >> res;
                ss.clear();
                if (res.size() == 1) {
                    llStack->push(1);
                    carry = 0;
                }
                else {
                    llStack->push(res[1]);
                    ss << res[0];
                    ss >> carry;
                    ss.clear();
                }
            } else {
                llStack->push(ll2->pop());
            }
        }
        if (carry != 0){
            char s;
            ss << carry;
            ss >> s;
            ss.clear();
            llStack->push(s);
        }
        while (!llStack->isEmpty()) {
            cout<<llStack->pop();
        }
        cout<<endl;
    }

private:
    LLStack<char> *llStack;
};

int test1(){
    BigNumberCollector *b = new BigNumberCollector();
    string s1 = "11111111111111111111";
    string s2 = "88888888888888888889";
    b->addingLargeNumbers(s1,s2);
    return 0;
}