"""
Source: https://leetcode.com/problems/roman-to-integer/
Date: 2022/2/18
Constraints: 
    1 <= s.length <= 15
    s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
    It is guaranteed that s is a valid roman numeral in the range [1, 3999].
    
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

"""

class Solution:
    def romanToInt(self, s: str) -> int:
        dict = {"I": 1, "V": 5, "X": 10, "L": 50, "C": 100, "D":500, "M":1000}
        num = 0
        for pos, value in enumerate(s):
            if pos+1 < len(s) and dict[s[pos]] < dict[s[pos+1]]:
                num -= dict[value]
            else:
                num += dict[value]
        return num
            