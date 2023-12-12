/**
 * Source: is.gd/GtzOuV
 * Date: 2023/12/12
 * Skill:
 * Ref:
 * Runtime: 198 ms, faster than 33.06% of C++ online submissions
 * Memory Usage: 108.10 MB, less than 30.83% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *
 */


#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <numeric>
#include <tuple>
#include <stack>
#include <bitset>
#include <functional>
#include <list>


using namespace std;


class RandomizedCollection {
    vector<int> nums;
    int sz = 0, cap = 0;
    unordered_map<int, unordered_set<int>> num2pos;
public:
    RandomizedCollection() {
    }

    bool insert(int val) {
        bool exist = num2pos[val].size() == 0;
        if (cap < sz + 1) {
            nums.push_back(val);
            cap++;
        } else {
            nums[sz] = val;
        }
        sz++;
        num2pos[val].insert(sz - 1);
        return exist;
    }

    bool remove(int val) {
        if (num2pos[val].size() == 0) return false;
        int last_element = nums[--sz];
        int pos = *num2pos[val].begin();
        num2pos[val].erase(pos);
        if (sz > 0 && pos != sz) {
            nums[pos] = last_element;
            num2pos[last_element].erase(sz);
            num2pos[last_element].insert(pos);
        }
        return true;
    }

    int getRandom() {
        if (sz == 0) return nums[0];
        int idx = rand() % sz;
        return nums[idx];
    }
};