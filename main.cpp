#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int minSubArrayLen(int s, vector<int>& nums) {
    int r = 65535;
    for (int k = 0; k < nums.size(); ++k) {
        int t= 0;
        int sum = 0;
        for (int i = k; i < nums.size(); ++i) {
            if (sum < s) {
                sum += nums[i];
                t++;
                cout<<k<<" ==> "<<i<<endl;
                if (sum == s){
                    r = min(r,t);
                    break;
                }
            } else {
                break;
            }
        }
        cout<<"result == >" <<r<<endl;
    }
    return r;
}

int main() {

    vector<int> nums = {2,3,1,2,4,3};
    int t = minSubArrayLen(7,nums);
    cout<<t<<endl;

//    string s = "121";
//    int l = s[0];
////    string a = *l;
////    auto r = s.end();
////    if (*l/64 != *r/64 || *l%32 != *r%32) {
////        cout<<*l <<endl;
////    }
//
//    if (s[0] == s[2])
//        cout<< "sss" <<endl;
    return 0;
}