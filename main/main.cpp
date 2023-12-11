/**
 * Source: is.gd/GtzOuV
 * Date: 2023/12/11
 * Skill:
 * Ref:
 * Runtime: 12 ms, faster than 97.73% of C++ online submissions
 * Memory Usage: 25.12 MB, less than 95.15% of C++ online submissions
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


#define SZ(X) ((int)(X).size())
#define ll long long
typedef pair<int, int> PII;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;
const int MX = 16;
ll mod = 1337;


class RandomizedCollection {
    vector<int> nums;
    int sz = 0;
    unordered_map<int, unordered_set<int>> num2pos;
public:
    RandomizedCollection() {

    }

    bool insert(int val) {
        bool exist = num2pos[val].size() == 0;
        if (SZ(nums) < sz + 1) nums.push_back(val);
        else nums[sz++] = val;
        num2pos[val].insert(sz - 1);
        return exist;
    }

    bool remove(int val) {
        if (num2pos[val].size() == 0) return false;
        int last_element = nums.back();
        int pos = *num2pos[val].begin();
        sz--;
        nums[pos] = last_element;
        num2pos[last_element].insert(pos);
        return true;
    }

    int getRandom() {
        int idx = rand() % sz;
        return nums[idx];
    }
};