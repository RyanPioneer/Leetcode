"""
Source: https://leetcode.com/problems/implement-stack-using-queues/
Date: 2022/12/16
Skill: 
Runtime: 29 ms, faster than 95.55% 
Memory Usage: 14.1 MB, less than 24.9%
Time complexity: 
Space complexity: 
Constraints: 
    1 <= x <= 9
    At most 100 calls will be made to push, pop, top, and empty.
    All the calls to pop and top are valid.
"""

from typing import List

class MyStack:
    
    def __init__(self):
        import queue
        self.q = queue.Queue()

    def push(self, x: int) -> None:
        self.q.put(x)
        sz = self.q.qsize()
        for i in range(sz-1):
            self.q.put(self.q.get())

    def pop(self) -> int:
        return self.q.get()

    def top(self) -> int:
        return self.q.queue[0]

    def empty(self) -> bool:
        return self.q.empty()


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()