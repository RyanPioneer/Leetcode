"""
Source: https://leetcode.com/problems/number-of-pairs-of-strings-with-concatenation-equal-to-target/description/
Date: 2023/1/6
Skill:
Runtime: 69 ms, faster than 66.74%
Memory Usage: 13.9 MB, less than 73.31%
Time complexity:
Space complexity:
Constraints:

"""

from typing import List
from collections import defaultdict

class Solution:
    def numOfPairs(self, nums: List[str], target: str) -> int:
        res, myDict = 0, defaultdict(int)
        for num in nums:
            myDict[num] += 1

        for key, value in myDict.items():
            if key == target[0:len(key)] and target[len(key):] in myDict:
                if key == target[len(key):]: res += myDict[key] * (myDict[key]-1)
                else: res += myDict[key] * myDict[target[len(key):]]

        return res