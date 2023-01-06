"""
Source: https://leetcode.com/problems/combination-sum/description/
Date: 2023/1/1
Skill: Backtracking
Runtime: 53 ms, faster than 95.55%
Memory Usage: 13.9 MB, less than 64.87%
Time complexity:
Space complexity:
Constraints:
    1 <= candidates[i] <= 30
    All elements of candidates are distinct.
"""

from typing import List

class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        res, members, sz = [], [], len(candidates)
        candidates.sort()

        def back_tracking(index, remainder):
            if remainder == 0:
                res.append(list(members))
                return
            for i in range(index, sz):
                if candidates[i] > remainder: break
                members.append(candidates[i])
                back_tracking(i, remainder-candidates[i])
                members.pop()

        back_tracking(0, target)
        return res

# if __name__ == "__main__":
#     s = Solution
#     ans = s.combinationSum2(s, [2,5,2,1,2], 5)