"""
Source: https://leetcode.com/problems/sort-the-people/
Date: 2022/12/7
Skill: 
Runtime: 232 ms, faster than 69.23% 
Memory Usage: 14.4 MB, less than 88.49%
Time complexity: 
Space complexity: 
Constraints: 
    All the values of heights are distinct.
"""

from typing import List

class Solution:
    def sortPeople(self, names: List[str], heights: List[int]) -> List[str]:
        myDict = dict()
        for i in range(len(names)):
            myDict[heights[i]] = names[i]
        index = 0
        for i in reversed(sorted(myDict)):
            names[index] = myDict[i]
            index += 1
        return names