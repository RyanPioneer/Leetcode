"""
Source: https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/
Date: 2022/12/1
Skill: 
Runtime: 74 ms, faster than 54.80%
Memory Usage: 13.9 MB, less than 65.08%
Time complexity: 
Space complexity: 
Constraints: 

"""

from typing import List

class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        num = max(candies) - extraCandies
        return [candy >= num for candy in candies]