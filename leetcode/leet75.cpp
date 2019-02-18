//
// Created by jac on 19-2-18.
//

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution75{
public:
    void sortColors(vector<int>& nums) {
        int x = -1;
        int z = nums.size();

        //三鹿快排
        for (int i = 0; i < z;){
            if (nums[i] == 1) {
                i++;
            }
            else if (nums[i] == 2) {
                swap(nums[i], nums[--z]);
            }
            else {
                assert(nums[i] == 0);
                swap(nums[++x], nums[i++]);
            }
        }
    }
};