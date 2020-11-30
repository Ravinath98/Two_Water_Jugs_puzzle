# Two_Water_Jugs_puzzle
using of recursion

Given two jugs, one of which can accommodate ​a litres of water and the other ​b litres of
water, determine the number of steps required to obtain exactly ​c litres of water in one of
the vessels.

At the beginning both vessels are empty. The following operations are counted as 'steps':

● emptying a vessel,
● filling a vessel,
● pouring water from one jug to the other, without spilling, until one of the jugs is either
  full or empty.
  
Input : 

Three positive integers a, b, c, not larger than 40000 separated by spaces

Output :

The steps that are required to obtain ​c litres in the following format, or ​-1 if this is
impossible

Example 1:
Input: 3 5 4
Output: (0, 0) > (3, 0) > (0, 3) > (3, 3) > (1, 5) > (1, 0) > (0, 1) > (3, 1) > (0, 4)
