//
// Created by jac on 19-2-18.
//

#include <iostream>
#include <vector>
#include <cassert>
#include <math.h>
using namespace std;

class Solution88{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int len = nums1.size();
        if (len < m+n || n == 0)
        {
            return;
        }

        int j = m+n-1;
        int k = m - 1;
        int l = n - 1;

        while( k >= 0 && l >= 0)
        {
            nums1[j--] = (nums1[k] > nums2[l]) ?  nums1[k--] : nums2[l--];
        }

        if ( k != -1 )
        {
            while ( j >= 0)
            {
                nums1[j--] == nums1[k--];
            }
        }
        else if (l != -1)
        {
            while ( j >= 0)
            {
                nums1[j--] = nums2[l--];
            }
        }
//        int k=m+n;
//        while(m>0 && n>0){
//            if(nums1[m-1] >= nums2[n-1]){
//                nums1[k-1] = nums1[m-1];
//                --k;
//                --m;
//            }
//            else{
//                nums1[k-1] = nums2[n-1];
//                --k;
//                --n;
//            }
//        }
//        while(n > 0){
//            nums1[k-1] = nums2[n-1];
//            --k;
//            --n;
//        }
    }
};