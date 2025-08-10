/*
 * @lc app=leetcode id=3635 lang=cpp
 *
 * [3635] Earliest Finish Time for Land and Water Rides II
 */

// @lc code=start

#define ll long long

class Solution {
   public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        int n = landStartTime.size(), m = waterStartTime.size();
        int earliestLandFinish = INT_MAX, earliestWaterFinish = INT_MAX;
        for (int i = 0; i < n; i++) {
            earliestLandFinish =
                min(earliestLandFinish, landStartTime[i] + landDuration[i]);
        }
        for (int i = 0; i < m; i++) {
            earliestWaterFinish =
                min(earliestWaterFinish, waterStartTime[i] + waterDuration[i]);
        }

        return min(helper(landStartTime, landDuration, earliestWaterFinish),
                   helper(waterStartTime, waterDuration, earliestLandFinish));
    }

    int helper(vector<int>& startTime, vector<int>& duration, int finishTime) {
        int res = INT_MAX;
        for (int i = 0; i < startTime.size(); i++) {
            int start = max(startTime[i], finishTime);
            int end = start + duration[i];
            res = min(res, end);
        }
        return res;
    }
};
// @lc code=end
