//
// Created by jac on 19-2-23.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution344 {
public:
    void reverseString(vector<char>& s) {
        if (s.size() < 1) return;
        int i = 0;
        int j = s.size()-1;
        while ( i < s.size() / 2) {
            char tmp =s[j];
            s[j] = s[i];
            s[i] = tmp;
            j--;
            i++;
        }
    }
};