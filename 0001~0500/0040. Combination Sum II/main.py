"""
Source: https://leetcode.com/problems/combination-sum-ii/description/
Date: 2023/1/1
Skill: Backtracking
Runtime: 44 ms, faster than 97.93%
Memory Usage: 14 MB, less than 59.86%
Time complexity: 
Space complexity: 
Constraints: 
    1 <= candidates[i] <= 50
"""

from typing import List

class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        res, members, sz = [], [], len(candidates)

        def backTracking(start, remainder):
            if remainder == 0:
                res.append(list(members)) #! Important!
                return
            for i in range(start, sz):
                if candidates[i] > remainder: return #! Important!
                if i>start and candidates[i] == candidates[i-1]: continue
                members.append(candidates[i])
                backTracking(i+1, remainder-candidates[i])
                members.pop()

        candidates.sort()
        backTracking(0, target)
        return res

if __name__ == "__main__":
    s = Solution
    ans = s.combinationSum2(s, [2,5,2,1,2], 5)