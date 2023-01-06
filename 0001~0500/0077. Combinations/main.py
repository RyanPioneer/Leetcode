"""
Source: https://leetcode.com/problems/combinations/
Date: 2023/1/2
Skill: Backtracking
Runtime: 83 ms, faster than 97.80%
Memory Usage: 15.9 MB, less than 51.65%
Time complexity:
Space complexity:
Constraints:
    1 <= n <= 20
    1 <= k <= n
"""

from typing import List

class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        res, members = [], []

        def back_tracking(start, num):
            if num == k:
                res.append(list(members))
                return
            for i in range(start, n+1):
                if n-i+1 < k-num: break
                members.append(i)
                back_tracking(i+1, num+1)
                members.pop()

        back_tracking(1, 0)
        return res


if __name__ == "__main__":
    s = Solution
    ans = s.combine(s, 3, 3)