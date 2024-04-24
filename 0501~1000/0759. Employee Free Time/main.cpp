/**
 * Source: is.gd/A1L4tP
 * Date: 2024/4/24
 * Skill:
 * Ref:
 * Runtime: 21 ms, faster than 44.04% of C++ online submissions
 * Memory Usage: 16.37 MB, less than 22.93% of C++ online submissions
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



class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};


class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        map<int, int> mp;
        for (auto &i : schedule) {
            for (auto &j: i) {
                mp[j.start]++;
                mp[j.end]--;
            }
        }

        vector<Interval> res;
        int curBusy = 0, time = 0;

        for (auto &i : mp) {
            if (curBusy == 0 && time > 0) {
                Interval j = Interval(time, i.first);
                res.push_back(j);
            }
            curBusy += i.second;
            time = i.first;
        }

        return res;
    }
};