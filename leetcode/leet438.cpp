//
// Created by jac on 19-2-24.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution438 {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int m[256] = {0};
        for (auto &c : p )
            m[c]++;
        int l = 0, r = 0, q = p.size();
        while (r < s.size()) {
            m[s[r]]--;
            if (m[s[r]] >= 0)
                q--;
            r++;
            while (q == 0) {
                if (r - l == p.size())
                    res.push_back(l);
                if (m[s[l]] == 0)
                    q++;
                m[s[l++]]++;
            }
        }
        return res;
    }
};