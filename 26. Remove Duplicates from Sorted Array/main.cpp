#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int num=0;
        int min = -101;
        vector<int> ans;
        for (auto i:nums) {
            if (i > min) {
                ans.push_back(i);
                min = i;
                num++;
            }
        }
        nums = ans;
        return num;
    }
};

int main () {
    vector<int> nums;
    int a;
    while (cin>>a) {
        nums.push_back(a);
    }
    Solution s;
    cout<<s.removeDuplicates(nums)<<endl;
    for (auto i:nums) 
        cout<<i<<endl;
}