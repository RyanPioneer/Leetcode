"""
Source: https://leetcode.com/problems/maximum-ice-cream-bars/
Date: 2023/1/6
Skill:
Runtime: 907 ms, faster than 59.95%
Memory Usage: 27.9 MB, less than 61.26%
Time complexity:
Space complexity:
Constraints:

"""

from typing import List

class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        costs.sort()
        index = 0
        while index < len(costs):
            if coins >= costs[index]:
                index += 1
                coins -= costs[index]
            else:
                break

        return index