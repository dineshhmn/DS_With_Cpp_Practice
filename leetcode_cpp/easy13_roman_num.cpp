//
// Created by Dinesh Hemnani on 8/22/22.
//

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <unordered_map>
#include <string>
using namespace std;

unordered_map<char, int> char_dict = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
};

vector<char> chack_back = {'I','X','C'};

class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        int l = 0, sum = 0;
        int a,b = 0;
        string ch;
        while (l < n){
            if (l + 1 >= n){
                ch = s.substr(l, n-l);
            }
            else{
                ch = s.substr(l, 2);
                a = char_dict[ch[0]];
                b = char_dict[ch[1]];
            }
            if (ch.size() == 2 and a < b){
                sum += b - a;
                l+=2;
            }
            else{
                sum += char_dict[ch[0]];
                l+=1;
            }
        }
        return sum;
    }
};

int main(){
    Solution s;
    cout << s.romanToInt("III") << endl;
    cout << s.romanToInt("LVIII") << endl;
    cout << s.romanToInt("MCMXCIV") << endl;
    cout << s.romanToInt("") << endl;
};