//
// Created by jac on 19-2-28.
//
#include <iostream>
#include <sstream>
#include <set>

using namespace std;
class Solution202 {
public:
    bool isHappy(int n) {
        while(n!=1)
        {
            n=sum_num(n);
            if(n==4)
                return false;
        }
        return true;
    }
    int sum_num(int num) {
        int t=0;
        int c=0;
        while(num)
        {
            t=num%10;
            c=c+t*t;
            num=num/10;
        }
        return c;
    }
};