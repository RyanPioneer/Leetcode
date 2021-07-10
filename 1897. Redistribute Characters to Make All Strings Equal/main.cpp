// Source: https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal/
// Date: 2021/7/10
// Hint: Characters are independent—only the frequency of characters matters.
// Hint: It is possible to distribute characters if all characters can be divided equally 
// among all strings.

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int nums[26] = {0};
    bool makeEqual(vector<string>& words) {
        int len = words.size();
        for(auto i:words) {
            for(auto j:i)
            nums[j-'a']++;
        }
        for(int i=0; i<26; i++) {
            if(nums[i]%len != 0)
                return false;
        }
        return true;
    }
};

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();