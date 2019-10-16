Implement ```atoi``` which converts a string to an integer.

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned.

**Note:**

* Only the space character ' ' is considered as whitespace character.
* Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [-2^31,  2^31 - 1]. If the numerical value is out of the range of representable values, INT_MAX (2^31 - 1) or INT_MIN (-2^31) is returned.

**Example 1:**
```
Input: "42"
Output: 42
```
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

**Example 1:**
```
Input: 121
Output: true
```
**Example 2:**
```
Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
```
**Example 3:**
```
Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
```

# Complete

Runtime: **8 ms**, faster than **80.74%** of C online submissions for Palindrome Number.

Memory Usage: **7.1 MB**, less than **85.71%** of C online submissions for Palindrome Number.