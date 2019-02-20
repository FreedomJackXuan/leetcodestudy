//
// Created by jac on 19-2-18.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
//    [3,2,1,5,6,4]
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        if (nums.size() == 0) return 0;
        int i = 0, j = nums.size() - 1;
        k = nums.size() - k;
        int l = i, r = j;
        while (true) {
            int tar = nums[i];
            while (i < j) {
                while (i < j && nums[j] >= tar)
                    j--;
                nums[i] = nums[j];
                while (i < j && nums[i] <= tar)
                    i++;
                nums[j] = nums[i];
            }
            nums[i] = tar;
            if (i == k)
                return nums[i];
            else if ( i < k) {
                l = ++i;
                j = r;
            } else {
                r = --j;
                i = l;
            }
        }
    }
};