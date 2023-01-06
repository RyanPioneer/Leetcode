"""
Source: https://leetcode.com/problems/combinations/
Date: 2023/1/2
Skill: Iterative
Runtime: 84 ms, faster than 97.54%
Memory Usage: 15.8 MB, less than 96.24%
Time complexity:
Space complexity:
Constraints:
    1 <= n <= 20
    1 <= k <= n
"""

from typing import List

class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        res, comb = [], [i for i in range(1, k+1)]
        res.append(list(comb))
        while 1:
            index = k-1
            while index >= 0 and comb[index] >= n-(k-index)+1: index -= 1
            if index == -1: return res
            comb[index] += 1
            while index+1 < k:
                index += 1
                comb[index] = comb[index-1]+1
            res.append(list(comb))


if __name__ == "__main__":
    s = Solution
    ans = s.combine(s, 3, 3)