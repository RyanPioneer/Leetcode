/*
 * @lc app=leetcode id=3656 lang=cpp
 *
 * [3656] Determine if a Simple Graph Exists
 */

// @lc code=start
#define ll long long
class Solution {
   public:
    bool simpleGraphExists(vector<int>& degrees) {
        priority_queue<int> pq;
        sort(degrees.rbegin(), degrees.rend());
        int nodeNum = 0, num = 0;
        for (int i = 0; i < degrees.size(); i++) {
            while (!pq.empty() && pq.top() == i) {
                num--;
                pq.pop();
            }
        }
    }
};
// @lc code=end
