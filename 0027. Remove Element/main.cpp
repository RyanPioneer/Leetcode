#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) { //elements can be returned in any order.
        vector<int> ans;
        int sz = 0;
        for (auto i:nums) {
            if (i != val) {
                ans.push_back(i);
                sz++;
            }
        }
        nums = ans;
        return sz;
    }
};