//
// Created by jac on 19-2-17.
//
#include <iostream>
#include <vector>

using namespace std;
class Solution26{
public:
    int removeDuplicates(vector<int> &nums) {
        int k = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[k] != nums[i]) {
                k++;
                nums[k] = nums[i];
            }
        }
        return k;
    }
};