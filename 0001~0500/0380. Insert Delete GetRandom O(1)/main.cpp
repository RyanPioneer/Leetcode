/** 
 * Source: https://leetcode.com/problems/insert-delete-getrandom-o1/
 * Date: 2022/11/29
 * Skill: 
 * Runtime: 211 ms, faster than 99.51% 
 * Memory Usage:  97.6 MB, less than 6.20%
 * Time complexity: 
 * Space complexity: 
 * Constraints: 
 *      At most 2 * 10^5 calls will be made to insert, remove, and getRandom.
 */

#include <iostream>
#include <vector>
#include <random>   /* 亂數函式庫 */
#include <ctime>
#include <unordered_map> 
#include <string>
using namespace std;


class RandomizedSet {
public:
    unordered_map<int, int> mymap;
    vector<int> nums;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (mymap.find(val) == mymap.end()) {
            nums.push_back(val);
            mymap[val] = nums.size()-1;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if (mymap.find(val) != mymap.end()) {
            nums[mymap[val]] = nums[nums.size()-1];
            mymap[nums[nums.size()-1]] = mymap[val];
            nums.pop_back();
            mymap.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main() {
    RandomizedSet s;
    string str;
    int val;
    while (1) {
        cin >> str;
        if (str == "i") {
            cin >> val;
            cout << s.insert(val) << endl;
        } else if (str == "r") {
            cin >> val;
            cout << s.remove(val) << endl;
        } else {
            cout << s.getRandom() << endl;
        }
    }
    
}

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();