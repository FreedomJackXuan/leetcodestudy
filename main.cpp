#include <iostream>
#include <cstring>

using namespace std;
int main() {
    string s = "121";
    int l = s[0];
//    string a = *l;
//    auto r = s.end();
//    if (*l/64 != *r/64 || *l%32 != *r%32) {
//        cout<<*l <<endl;
//    }

    if (s[0] == s[2])
        cout<< "sss" <<endl;
    return 0;
}