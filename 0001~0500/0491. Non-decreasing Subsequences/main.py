"""
Source: https://leetcode.com/problems/non-decreasing-subsequences/
Date: 2023/1/20
Skill:
Ref:
Runtime: 233 ms, faster than 72.97%
Memory Usage: 22.7 MB, less than 26.41%
Time complexity:
Space complexity:
Constraints:
    -100 <= nums[i] <= 100
"""

from typing import List, Optional
from collections import defaultdict

class Solution:
    def findSubsequences(self, nums: List[int]) -> List[List[int]]:
        res, sequence, sz = set(), [], len(nums)

        def backtrack(index):
            if index == sz:
                if len(sequence) >= 2:
                    res.add(tuple(sequence))
                return
            if len(sequence) == 0 or sequence[-1] <= nums[index]:
                sequence.append(nums[index])
                backtrack(index+1)
                sequence.pop()

            backtrack(index + 1)

        backtrack(0)
        return res

if __name__ == "__main__":
    s = Solution
    nums = [0,-5]
    print(s.findSubsequences(s, nums))