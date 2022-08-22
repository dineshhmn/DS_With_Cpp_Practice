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
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int, int> m;
            vector<int> ret;
            for (auto i=0; i<nums.size(); ++i){
                if (m.find(target - nums[i]) != m.end()){
                    ret = {m[target - nums[i]], i};
                    return ret;
                }
                else {
                    m[nums[i]] = i;
                }
            }
            return ret;
        }
};

int main(){
    Solution s;
    vector<int> nums = {2,7,11,15};
    int target = 9;
//    auto res = s.twoSum(nums, target);
//    for (int a: res) {
//        cout << a << endl;
//    }
    vector<int> nums2 = {3,2,4};
    int t2 = 6;
    auto res2 = s.twoSum(nums2, t2);
    for (int a: res2) {
        cout << a << endl;
    }
    return 0;
}