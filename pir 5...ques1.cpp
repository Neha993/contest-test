/*Rory wants to impress his maths Professor, Mr. Shiv Dutt, so that he can pass with good grades. He knows that Professor likes Beautiful numbers a lot.

A Beautiful number is one whose binary representation (without leading 0s) is a palindrome. For example, 5 is represented as (101)2 in binary, and 101 is a palindrome.

Given a number, can you help Rory find out if its Beautiful or not?

Input Format

The first line contains T, the number of test cases.

Next T lines contain a single integer, the number Rory wants to check.

Constraints

1 <= T <= 105

1 <= N <= 1018

Output Format

Output T lines, each containing "YES" if the number is beautiful, "NO" if it is not.

Sample Input 0

4
1
2
3
4
Sample Output 0

YES
NO
YES
NO
Explanation 0

The binary representation of 1 is (1)2, which is a palindrome. The binary representation of 2 is (10)2, which is NOT a palindrome. The binary representation of 
3 is (11)2, which is a palindrome. The binary representation of 4 is (100)2, which is NOT a palindrome */
//t.64-tc
#include<bits/stdc++.h>
#include<algorithm>

#define spd_emergency ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

using namespace std;

const ll MAX_N=1e18;

int main()
{
    ll t=1;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        string s="";
        //k is the highest bit set for n. converting decimal representation into binary string
        while(n)        
        {
            if(n&1)
            {
                s.push_back('1');
            }
            else
                s.push_back('0');
            n/=2;
        }

        //flag is set whenever we find a mismatch.
        ll flag=0;

        //checking for palindrome
        for(ll i=0;i<s.length()/2;i++)
        {
            if(s[i] != s[s.length()-i-1])
                flag=1;
        }
        if(flag)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
    return 0;
}
