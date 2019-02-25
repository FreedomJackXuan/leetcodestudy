//
// Created by jac on 19-2-25.
//

#include <iostream>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        string res = "";
        int map[256]={0};
        for (auto &c : t) {
            map[c]++;
        }

        int len = s.size()+1;
        int count = t.size();
        int l = 0, r = 0;
        int beg = -1;
        while (r < s.size()) {
            map[s[r]]--;
            if (map[s[r]] >= 0)
                count--;
            r++;
            if (count == 0){
                while (map[s[l]] < 0){
                    map[s[l]]++;
                    l++;
                }
                if (r - l < len){
                    len = r-l;
                    beg = l;
                }
                map[s[l++]]++;
                count++;
            }
        }
        if (len == s.size()+1)
            return "";
        return s.substr(beg,len);
    }
};