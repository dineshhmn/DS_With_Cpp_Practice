//
// Created by Dinesh Hemnani on 8/21/22.
//

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isPalindrome(long int x) {
        if (x < 0) {
            return false;
        }
        if (x == 0 or x / 10 < 1){
            return true;
        }
        int l = floor(log10(x));
        int r = 0;
        while (r < l){
            double a = floor((x / (int)pow(10,l)) % 10);
            double b = floor((x % (int)pow(10,r+1)) / (int)pow(10,r));
            cout << a << b << endl;
            cout << r << l << endl;
            if (a != b) {
                return false;
            }
            r++;
            l--;
        }
        return true;
    }
};


int main(){
    Solution s;
    long int x = 121;
    auto res = s.isPalindrome(x);
    cout << "1." << res << endl;
//    x = 99999;
//    res = s.isPalindrome(x);
//    cout << "2." << res << endl;
    x = 10;
    res = s.isPalindrome(x);
    cout << "3." << res << endl;
//    x = 12345654341;
//    res = s.isPalindrome(x);
//    cout << "4." << res << endl;
//    x = -121;
//    res = s.isPalindrome(x);
//    cout << "5." << res << endl;
}