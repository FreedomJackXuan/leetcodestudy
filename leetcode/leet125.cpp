
//
// Created by jac on 19-2-21.
//

#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;


class Solution125 {
public:
    bool isPalindrome(string s) {
        if (s.empty()) return true;
        int l = 0;
        int r = s.length()-1;
        while (l < r) {
            while ( !(('0' <= s[l] && s[l] <= '9') || ('a' <= s[l] && s[l] <= 'z') || ('A' <= s[l] && s[l] <= 'Z')) )
                if (l < r)
                    l++;
                else
                    break;
            while ( !(('0' <= s[r] && s[r] <= '9') || ('a' <= s[r] && s[r] <= 'z') || ('A' <= s[r] && s[r] <= 'Z')) )
                if (l < r)
                    r--;
                else
                    break;
            if (tolower(s[l]) != tolower(s[r]))
                return false;
            l++;
            r--;
        }
        return true;
    }
};