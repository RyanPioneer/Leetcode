"""
Source: https://leetcode.com/problems/top-k-frequent-elements/
Date: 2022/12/7
Skill: 
Runtime: 109 ms, faster than 91.7% 
Memory Usage: 18.6 MB, less than 71.54%
Time complexity: 
Space complexity: 
Constraints: 
    1 <= nums.length <= 10^5
"""

from typing import List
from collections import defaultdict

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        myDict = defaultdict(int)
        res = []
        for i, n in enumerate(nums):
            myDict[n] += 1
        sorted_myDict = reversed(sorted(myDict.items(), key=lambda item: item[1]))
        for key, value in sorted_myDict:
            if k:
                res.append(key)
                k -= 1
        return res