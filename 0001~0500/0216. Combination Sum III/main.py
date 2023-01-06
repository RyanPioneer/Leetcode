"""
Source: https://leetcode.com/problems/combination-sum-iii/
Date: 2023/1/2
Skill: Backtracking
Runtime: 35 ms, faster than 81.18%
Memory Usage: 13.8 MB, less than 99.14%
Time complexity:
Space complexity:
Constraints:
    2 <= k <= 9
    1 <= n <= 60
"""

from typing import List

class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        res, members = [], []

        def back_tracking(start, num, remainder):
            if num == k:
                if remainder == 0:
                    res.append(list(members))
                return
            if start > remainder: return
            for i in range(start, 10):
                members.append(i)
                back_tracking(i+1, num+1, remainder-i)
                members.pop()

        back_tracking(1, 0, n)
        return res



if __name__ == "__main__":
    s = Solution
    ans = s.combinationSum3(s, 3, 3)