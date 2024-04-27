/**
 * Source: t.ly/jDxng
 * Date: 2024/4/27
 * Skill:
 * Ref:
 * Runtime: 296 ms, faster than 36.99% of C++ online submissions
 * Memory Usage: 152.56 MB, less than 38.15% of C++ online submissions
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


class MaxStack {
    list<int> List;
    map<int, vector<list<int>::iterator>> mp;
public:
    MaxStack() {

    }

    void push(int x) {
        List.push_back(x);
        mp[x].push_back(prev(end(List)));
    }

    int pop() {
        int num = -1;
        if (!List.empty()) {
            list<int>::iterator it = prev(end(List));
            num = *it;
            mp[num].pop_back();
            List.pop_back();
            if (mp[num].size() == 0) mp.erase(num);
        }
        return num;
    }

    int top() {
        return *prev(end(List));
    }

    int peekMax() {
        return prev(end(mp))->first;
    }

    int popMax() {
        int num = prev(end(mp))->first;
        List.erase(prev(end(mp))->second.back());
        mp[num].pop_back();
        if (mp[num].size() == 0) mp.erase(num);
        return num;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */