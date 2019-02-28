//
// Created by jac on 19-2-25.
//
#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> r(nums1.begin(),nums1.end());
//        for (int i = 0; i < nums1.size(); i++){
//            r.insert(nums1[i]);
//        }
        set<int> res;
        for (int j = 0; j < nums2.size(); ++j) {
            if (r.find(nums2[j]) != r.end())
                res.insert(nums2[j]);
        }
        vector<int> rv;
        for (set<int>::iterator it = res.begin(); it!=res.end(); it++)
            rv.push_back(*it);
        return rv;
    }
};