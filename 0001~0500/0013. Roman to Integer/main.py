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
        i = 0
        while i < len(s):
           if i+1 <  len(s) and dict[s[i]] < dict[s[i+1]]:
               num += (int(dict[s[i+1]]) - int(dict[s[i]]))
               i += 1
           else:
               num += int(dict[s[i]])
           i += 1
        return num