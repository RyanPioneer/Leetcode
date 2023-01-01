"""
Source: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
Date: 2022/12/27
Skill: Binary Search
Runtime: 950 ms, faster than 64.76% 
Memory Usage: 17.1 MB, less than 81.94%
Time complexity: 
Space complexity: 
Constraints: 
    
"""

from typing import List

class Solution:
    def shipWithinDays(self, weights: List[int], days: int) -> int:
        left, right = max(weights), sum(weights)
        
        def check_available(cap):
            day, index = days, 0
            while day:
                day -= 1
                cur_cap = cap
                while index < len(weights) and cur_cap >= weights[index]:
                    cur_cap -= weights[index]
                    index += 1
                if index == len(weights): return True
            
            return False
        
        while left != right:
            mid = (left+right)//2
            if check_available(mid):
                right = mid
            else:
                left = mid+1
        
        return right