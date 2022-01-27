/* Ada has two strings s and t. She wants to know whether s is a subsequence of t or not. In case s is a subsequence of t, output "Yes" otherwise output "No" (without double quotes).

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

Sample Input 0

2
abc
placementandinternship
abc
wahhbhaiyachhhhhhhhhhh
Sample Output 0

No
Yes
*/
//This is an O(N + M) solution.

#include<bits/stdc++.h>
using namespace std;
bool isSubsequence(string s, string t) {
    int i = 0;
    int j = 0;
    int n = s.size();
    int m = t.size();
    if(n > m)
    	return false;
    while(i<n && j<m) {
        while(j<m && t[j] != s[i])
            j++;
        if(j!=m) {
            i++,j++;
        }
    }
    if(i==n)
        return true;
    return false;
}

int main()
{
    int t;
    cin >> t;
    while(t--) {
        string s,t;
        cin >> s >> t;
        if(isSubsequence(s,t)) {
            cout << "Yes\n";
        }
        else {
            cout << "No\n";
        }
    }
    return 0;
}
 
