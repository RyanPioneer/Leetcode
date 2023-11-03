/**
 * Source: t.ly/24CPr
 * Date: 2023/11/3
 * Skill:
 * Runtime: 206 ms, faster than 94.49% of C++ online submissions
 * Memory Usage: 110.30 MB, less than 66.39% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */


class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        set<int> dry;
        vector<int> res(rains.size(), -1);
        unordered_map<int, int> last_day_rain;
        for (int i = 0; i < rains.size(); i++) {
            if (rains[i] == 0) {
                dry.insert(i);
                res[i] = 1;
            } else {
                if (last_day_rain.find(rains[i]) != last_day_rain.end()) {
                    if (dry.empty() || last_day_rain[rains[i]] > *dry.rbegin()) {
                        return {};
                    }
                    int day = *dry.upper_bound(last_day_rain[rains[i]]);
                    dry.erase(day);
                    res[day] = rains[i];
                }
                last_day_rain[rains[i]] = i;
            }
        }
        return res;
    }
};


int main() {
    Solution s;
}