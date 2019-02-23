//
// Created by jac on 19-2-23.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution209 {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int l = 0, r = -1;
        int sum = 0, res = nums.size() + 1;
        while (l < nums.size()) {
            if (r < nums.size()&&sum < s )
                sum += nums[++r];
            else
                sum -= nums[l++];
            if (sum >= s) {
                 res = min(res, r-l+1);
            }
        }
        if (res == nums.size() + 1)
            return 0;
        return res;

//        if (nums.size() == 0)
//            return 0;
//        int r = 65535;
//        for (int k = 0; k < nums.size(); ++k) {
//            int t= 0;
//            int sum = 0;
//            for (int i = k; i < nums.size(); ++i) {
//                if (sum < s) {
//                    sum += nums[i];
//                    t++;
//                    if (sum == s){
//                        r = min(r,t);
//                        break;
//                    }
//                } else {
//                    break;
//                }
//            }
//        }
//        if (r == 65535) {
//            return 0;
//        }
//        return r;
    }
};