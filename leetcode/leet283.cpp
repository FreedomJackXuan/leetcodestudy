//
// Created by jac on 19-2-17.
//
#include <iostream>
#include <vector>

using namespace std;
class Solution283{
public:
    void moveZeroes(vector <int> &nums) {
        if (nums.size() <= 1) return;
        int j = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i]) {
                nums[j++] = nums[i];
            }
        }

        for (int i = j; i < nums.size(); ++i) {
                nums[i] = 0;
        }
    }
};
