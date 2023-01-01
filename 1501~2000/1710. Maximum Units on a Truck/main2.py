"""
Source: https://leetcode.com/problems/maximum-units-on-a-truck/
Date: 2022/12/27
Skill: 
Runtime: 151 ms, faster than 98.55% 
Memory Usage: 14.3 MB, less than 82.83%
Time complexity: 
Space complexity: 
Constraints: 
    
"""

from typing import List

class Solution:
    def maximumUnits(self, boxTypes: List[List[int]], truckSize: int) -> int:
        boxTypes.sort(key = lambda x:x[1], reverse = True)
        res = 0
        for box in boxTypes:
            res += box[1]*min(box[0], truckSize)
            if box[0] >= truckSize:
                break
            else:
                truckSize -= box[0]
        
        return res