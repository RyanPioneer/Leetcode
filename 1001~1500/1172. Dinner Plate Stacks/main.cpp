/**
 * Source: https://rb.gy/45iag
 * Date: 2023/9/15
 * Skill:
 * Runtime: 1184 ms, faster than 25.98% of C++ online submissions
 * Memory Usage: 619.04 MB, less than 11.02% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <numeric>
#include <tuple>
#include <stack>

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
typedef pair<ULL, ULL> PULL;


class DinnerPlates {
    int capacity;
    vector<stack<int>> stacks;
    map<int, int> id2push, id2pop;
public:
    DinnerPlates(int cap) {
        capacity = cap;
    }

    void push(int val) {
        if (id2push.empty()) {
            stack<int> s;
            s.push(val);
            stacks.push_back(s);
            if (capacity - 1 > 0)
                id2push[stacks.size() - 1] = capacity - 1;
            id2pop[stacks.size() - 1] = 1;
        } else {
            auto it = begin(id2push);
            id2pop[it->first]++;
            stacks[it->first].push(val);
            if (it->second > 1)
                it->second--;
            else
                id2push.erase(it);
        }
    }

    int pop() {
        if (id2pop.empty())
            return -1;
        auto it = prev(end(id2pop));
        id2push[it->first]++;
        int num = stacks[it->first].top();
        stacks[it->first].pop();
        if (it->second > 1)
            it->second--;
        else
            id2pop.erase(it);
        return num;
    }

    int popAtStack(int index) {
        if (index >= stacks.size() || stacks[index].empty())
            return -1;
        auto it = id2pop.find(index);
        if (it->second > 1)
            it->second--;
        else
            id2pop.erase(it);
        int num = stacks[index].top();
        stacks[index].pop();
        id2push[index]++;
        return num;
    }
};


int main() {
//    Solution s;
    vector<int> nums{1,1,3,3};
    vector<vector<int>> arr{{2,9,10}, {3,7,15}, {5,12,12}, {15,20,10}, {19,24,8}};
}