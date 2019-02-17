//
// Created by jac on 18-12-6.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;
/**
 * 给定一个整数数组，返回两个数字的索引，使它们相加到特定目标。
 * 您可以假设每个输入只有一个解决方案，并且您可能不会两次使用相同的元素。
 **/
class Solution {
public:
    vector<int> twoSum1(vector<int> &nums, int target) {
        int size = nums.size();
        vector<int> result;
        for (int i = 0; i < size; ++i) {
            for (int j = i+1; j < size; ++j) {
                if (nums[i]+nums[j] == target) {
                    result.push_back(i);
                    result.push_back(j);
                }
            }
        }
        return result;
    }

    vector<int> twoSum2(vector<int> &nums, int target) {
        map<int,int> hashmap;
        vector<int > ve;
        for (int i = 0; i < nums.size(); ++i) {
            int c = target - nums[i];
            if (hashmap.count(c)) {
                ve.push_back(hashmap[c]);
                ve.push_back(i);
            }
            hashmap[nums[i]]=i;
        }
        return ve;
    }
};