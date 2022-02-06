/*You are given an integer num. Rearrange the digits of num such that its value is minimized and it does not contain any leading zeros.

Return the rearranged number with minimal value.

Note that the sign of the number does not change after rearranging the digits.

 

Example 1:

Input: num = 310
Output: 103
Explanation: The possible arrangements for the digits of 310 are 013, 031, 103, 130, 301, 310. 
The arrangement with the smallest value that does not contain any leading zeros is 103.
Example 2:

Input: num = -7605
Output: -7650
Explanation: Some possible arrangements for the digits of -7605 are -7650, -6705, -5076, -0567.
The arrangement with the smallest value that does not contain any leading zeros is -7650.
  */
  class Solution {
public:
    long long smallestNumber(long long num) {
        
     auto s = to_string(num);
    if (s.size() == 1 || s[0] == '-') {
        sort(begin(s) + 1, end(s), greater<int>());
    } else {
        sort(begin(s), end(s));
        swap(s[0], s[s.find_first_not_of('0')]);
    }
    return stoll(s);
    }
};
