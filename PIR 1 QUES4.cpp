/* On christmas Ada recieves a box of n chocolates. She decided to eat an equal amount of chocolate each morning until there are no more chocolate. However, Bob also noticed the box and decided to get some chocolate for himself.

This means the process of eating chocolate is the following: in the beginning Ada chooses a single integer k, same for all days. After that, in the morning she eats chocolate from the box (if there are less than k chocolate in the box, she eats them all), then in the evening Bob eats 10% of the chocolate remaining in the box. If there are still chocolate left in the box, the process repeats — next day Ada eats k chocolate again, and Bob — 10% of the chocolate left in a box, and so on.

If the amount of chocolate in the box is not divisible by 10. Bob, rounds the amount he takes from the box down. For example, if there were 97 chocolates in the box, Bob would eat only 9 of them. In particular, if there are less than 10 chocolate in a box, Bob won't eat any at all.

Your task is to find out the minimal amount k that can be chosen by Ada so that she would eat at least half of the n chocolate she initially got. Note that the number k must be integer.

Sample Input 0

68
Sample Output 0

3
Sample Input 1

738
Sample Output 1

29
Sample Input 2

4
Sample Output 2

1
*/
// TC LOGN
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll check(ll n,ll k){
    ll h=0;
    while(n>0){
        if(n>=k)h+=k,n-=k;
        else h+=n,n=0;
        n-=n/10;
    }
    return h;
}
int main(){
    ll n;
    cin>>n;
    ll low=1,high=n,mid,ans=n;
    while(low<=high){
        mid=(low+high)>>1;
        ll k=check(n,mid);
        if(k>=ceil((long double)n/2))ans=min(ans,mid),high=mid-1;
        else low=mid+1;
    }
    cout<<ans;
    return 0;
}
