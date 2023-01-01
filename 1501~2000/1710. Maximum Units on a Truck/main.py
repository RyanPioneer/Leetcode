"""
Source: https://leetcode.com/problems/maximum-units-on-a-truck/
Date: 2022/12/27
Skill: 
Runtime: 157 ms, faster than 94.98% 
Memory Usage: 14.5 MB, less than 32.83%
Time complexity: 
Space complexity: 
Constraints: 
    
"""

from typing import List
from collections import defaultdict

class Solution:
    def maximumUnits(self, boxTypes: List[List[int]], truckSize: int) -> int:
        res, dict, mySet = 0, defaultdict(int), set()
        for i in range(len(boxTypes)):
            dict[boxTypes[i][1]] += boxTypes[i][0]
            mySet.add(boxTypes[i][1])
        
        sortedSet = reversed(sorted(mySet))
        for val in sortedSet:
            if dict[val] >= truckSize:
                res += val*truckSize
                break
            else:
                res += val*dict[val]
                truckSize -= dict[val]
                
        return res
    
if __name__ == "__main__":
    s = Solution
    print(s.maximumUnits(s, [[5,10],[2,5],[4,7],[3,9]], 10))