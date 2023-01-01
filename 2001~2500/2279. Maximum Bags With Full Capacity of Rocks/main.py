"""
Source: https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/
Date: 2022/12/27
Skill: 
Runtime: 986 ms, faster than 81.58% 
Memory Usage: 22.3 MB, less than 49.34%
Time complexity: 
Space complexity: 
Constraints: 
    
"""

from typing import List


class Solution:
    def maximumBags(self, capacity: List[int], rocks: List[int], additionalRocks: int) -> int:
        rest, index = [0 for i in range(len(capacity))], 0
        for i in range(len(capacity)):
            rest[i] = capacity[i] - rocks[i]
        
        rest.sort()
        while index < len(capacity) and rest[index] <= additionalRocks:
            additionalRocks -= rest[index]
            index += 1
            
        return index
    
if __name__ == "__main__":
    s = Solution
    print(s.maximumBags(s, [2,3,4,5], [1,2,4,4], 2))