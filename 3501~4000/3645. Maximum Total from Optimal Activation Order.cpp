/*
 * @lc app=leetcode id=3645 lang=cpp
 *
 * [3645] Maximum Total from Optimal Activation Order
 */

// @lc code=start
#define ll long long
class Solution {
   public:
    long long maxTotal(vector<int>& value, vector<int>& limit) {
        priority_queue<pair<int, int>> pq;
        priority_queue<int, vector<int>, greater<int>> visited;

        for (int i = 0; i < value.size(); i++) {
            pq.push({-limit[i], value[i]});
        }
        long long res = 0, num = 0, nextNum;
        while (!pq.empty()) {
            auto [l, v] = pq.top();
            pq.pop();
            if (num < -l) {
                res += v;
                num++;
                visited.push(-l);
            }
            nextNum = num;
            while (!visited.empty() && visited.top() <= nextNum) {
                visited.pop();
                num--;
            }
            while (!pq.empty() && -pq.top().first <= nextNum) {
                pq.pop();
            }
        }
        return res;
    }
};
// @lc code=end
