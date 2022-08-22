//
// Created by Dinesh Hemnani on 8/21/22.
//

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <unordered_map>

using namespace std;

void work_vec(vector<int> &j){
    int l =0;
    int r =j.size()-1;
    int t = 0;
    int ctr = 0;
    while (l<r)
    {
        t = j[l];
        j[l] = j[r];
        j[r] = t;
        l++;
        r--;
        ctr++;
    }
    cout << ctr << endl;
}

unordered_map<char,int> dict_vec(vector<char> &j) {
    unordered_map<char, int> ret;
    for (int a=0; a<j.size(); ++a){
        ret.insert({j[a],a});
    }
    return ret;
}

int main(){
    vector<char> x = {'1','2','3','4','5','6','7','8','9'};
//    work_vec(x);
//    for (int i: x){
//        cout << i;
//    }
//    cout << endl;
    auto m = dict_vec(x);
    for(const auto& key_value: m){
        cout << key_value.first << key_value.second << endl;
    }
    cout << m.at('3') << "using methods" << endl; // access value by key
    if (m.find('22') == m.end()){
        cout << "exists" << endl;
    }
    else{
        cout << "not found" << endl;
    }
}