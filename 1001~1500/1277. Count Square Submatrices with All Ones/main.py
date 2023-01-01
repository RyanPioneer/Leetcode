"""
Source: https://leetcode.com/problems/count-square-submatrices-with-all-ones/description/
Date: 2022/12/24
Skill: Dynamic Programming
Ref: https://leetcode.com/problems/count-square-submatrices-with-all-ones/solutions/441620/dp-with-figure-explanation/?orderBy=most_votes
Runtime: 654 ms, faster than 85.27% 
Memory Usage: 16.1 MB, less than 96.99%
Time complexity: 
Space complexity: 
Constraints: 
    1 <= arr.length <= 300
"""

from typing import List

class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        for i in range(1, len(matrix)):
            for j in range(1, len(matrix[0])):
                matrix[i][j] *= min(matrix[i-1][j-1], matrix[i][j-1], matrix[i-1][j]) + matrix[i][j]
        
        return sum(map(sum, matrix))
    
"""
    Basically, map(sum, input) will return a list 
    with the sums across all your rows, then, 
    the outer most sum will add up that list.
"""