/* Ayush was asked to write a code which can generate t palindrome strings but in a hurry he wrote a faulty code and the strings weren't palindrome, so to quickly fix the bug you were asked to add minimum no of characters at the end of the string so that it becomes a palindrome.

Input Format

The first line of the input contains a single integer t.
And the next t lines contains a string s.

Constraints

1 = t = 5 * 104
1 = length(s) = 500

Output Format

For each testcase, print a palindromic string.

Sample Input 0

3
abc
zoz
abcbc
Sample Output 0

abcba
zoz
abcbcba
Explanation 0

In the first test case adding two characters we can make it a palindrome.
In the second test case the string is already a palindrome, so no characters are added.
In the third test case again adding 2 characters instead of 6 we can make it a palindrome.

Submissions: 178
Max Score: 200
Difficulty: Medium
Rate This Challenge:

    
More
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> compute_lps(const string& A)
{
    int n = A.size();
    vector<int> lps(n);
    lps[0] = 0;
    for(int i = 1; i < n; i++) {
        int j = lps[i - 1];
        while(j > 0 && A[i] != A[j]) {
            j = lps[j - 1];
        }
        if(A[i] == A[j]) {
            j++;
        }
        lps[i] = j;
    }
    
    return lps;
}

void solve() {
    string A;
    cin>>A;
    string ans=A;
    string rev = A;
    reverse(rev.begin(), rev.end());
    string concat = rev+ "$" + A;
    vector<int> lps = compute_lps(concat);
    int k = lps[lps.size() - 1];
   ans+=rev.substr(k,rev.size()-k);
    cout<< ans<<endl;
    
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
