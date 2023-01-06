"""
Source: https://leetcode.com/problems/maximum-ice-cream-bars/
Date: 2023/1/6
Skill: Counting Sort
Runtime: 1595 ms, faster than 43.45%
Memory Usage: 28.1 MB, less than 17.54%
Time complexity:
Space complexity:
Constraints:

"""

from typing import List

class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        res, costsFrequency = 0, [0 for _ in range(max(costs)+1)]
        for i in range(len(costs)):
            costsFrequency[costs[i]] += 1

        for i in range(len(costsFrequency)):
            if i > coins: return res
            if costsFrequency[i] == 0: continue
            if coins >= i*costsFrequency[i]:
                res += costsFrequency[i]
                coins -= i*costsFrequency[i]
            else:
                return res + coins//i

        return res