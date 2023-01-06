"""
Source: https://leetcode.com/problems/delete-columns-to-make-sorted/
Date: 2023/1/3
Skill:
Runtime: 151 ms, faster than 83.79%
Memory Usage: 14.7 MB, less than 61.89%
Time complexity:
Space complexity:
Constraints:

"""

from typing import List

class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        rows, cols, res = len(strs), len(strs[0]), 0
        for i in range(cols):
            for j in range(1, rows):
                if strs[j][i] < strs[j-1][i]:
                    res += 1
                    break

        return res

if __name__ == "__main__":
    s = Solution