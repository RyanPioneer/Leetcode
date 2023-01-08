"""
Source: https://leetcode.com/problems/min-stack/
Date: 2023/1/7
Skill: Consider each node in the stack having a minimum value.
Ref:
Runtime: 59 ms, faster than 91.88%
Memory Usage: 18.5 MB, less than 14.41%
Time complexity:
Space complexity:
Constraints:
    You must implement a solution with O(1) time complexity for each function.
    Methods pop, top and getMin operations will always be called on non-empty stacks.
"""

from typing import List, Optional
import  math

class MinStack:

    def __init__(self):
        self.stack = []

    def push(self, val: int) -> None:
        if self.stack and self.stack[-1][1] < val: self.stack.append([val, self.stack[-1][1]])
        else: self.stack.append([val, val])

    def pop(self) -> None:
        self.stack.pop()

    def top(self) -> int:
        return self.stack[-1][0]

    def getMin(self) -> int:
        return self.stack[-1][1]

# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()