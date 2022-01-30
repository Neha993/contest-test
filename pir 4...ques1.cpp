/*Gojo love cakes a lot, that's why sometimes he even forgets to drink water while eating them.

You are given a single array A, where the integer at ith index tells whether Gojo is eating or drinking at ith minute. If Ai is equal to 1 then Gojo is eating a single cake at ith minute and if Ai is 0 then Gojo is drinking a single glass of water at ith minute. You have to determine whether Gojo is eating cakes according to the following rules:

After every minute the number of cakes eaten by Gojo should be greater than or equal to the number of glasses of water he drank.
The total number of cakes eaten should be equal to the total glasses of water he drank.
Input Format

First line contains a single integer T the number of test cases. T test cases follows.
First line of each test case contains a single integer N the number of minutes i.e., the length of array A.
Second line of each test case contains N space separated integers, representing the array A (as described in the problem statement).

Constraints

1 <= T <= 10
1 <= N <= 105
0 <= Ai <= 1

Output Format

Print "YES" (without quotes and in uppercase) if Gojo is eating cakes according to the mentioned rules else print "NO" (without quotes and in uppercase).

Sample Input 0

3
6
1 0 1 1 0 0 
6
1 0 1 0 1 1 
6
1 0 1 0 1 0 
Sample Output 0

YES
NO
YES */

#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
     queue<string>v;
    while(t--){
        int n;
        cin>>n;
       
        int a[n];
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int n1=0,n2=0;
        for(int i=1;i<=n;i++){
            if(a[i]==0){
                n1++;
            }
          if(a[i]==1){
                n2++;
            }
            if(n2<n1){
                v.push("NO");
            }
        }
        if(n1==n2){
            v.push("YES");
        }
       if(n1!=n2){
            v.push("NO");
        }
        cout<<v.front()<<endl;
    int k=v.size();
        for(int i=0;i<k;i++){
            v.pop();
        }
}

    return 0;
}
