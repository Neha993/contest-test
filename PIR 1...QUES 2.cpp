/* Ada is working with MS Excel. The problem is on MS Excel Sheet, the column title is represented as a string and Ada always struggles to convert the column title into an integer. Column titles are converted from string to number as follows:

A -> 1
B -> 2
C -> 3
.
.
.
Y -> 25
Z -> 26
AA -> 27
AB -> 28
...so on
You (Ada's best friend) have to help her by converting the given column title into a number modulo 1000000007.

Sample Input 0

3
A
AB
ZY
Sample Output 0

1
28
701 */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll titleToNumber(string s) {
    ll n = s.size();
    ll ans = 0ll;
    ll val = 1ll;
    for(int i=n-1;i>=0;i--) {
        ll temp = ((s[i]-'A'+1)*val)%mod;
        ans = (ans + temp)%mod;
        val = (val*26ll)%mod;
    }
    return ans;
}
int main()
{
    ll t;
    cin >> t;
    while(t--) {
        string str;
        cin >> str;
        cout << titleToNumber(str) << '\n';
    }
    return 0;
}
