/* It's the 1st of September, and Sree and her friends are going to Hogwarts to study witchcraft and wizardry, but they will require a wand. But Ollivanders has wandered out for a spell and has left the shop in your hand and left you with the secret of choosing correct wands.

Every wand has been made with w ingredients and every student has a number associated with them, say s. Now, a wand is suitable for a student if s is equal to wC0 + wC2 + wC4 + wC6 + ...

Since the value of the above summation can be large, calculate it modulo 109+7

So you have to help Sree and her friends to choose their wands. Don't be too hard on yourself, do your best.

Constraints

1 = t = 105
1 = s < 2 * 109
1 = w = 109
Sample Input 0

3
4 3
6 3
16 5
Sample Output 0

Perfect
Definitely Not
Perfect */
// TC LOGN
#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

//modulo multiplication
int mul(int a,int b){        
    return (a*1ll*b)%MOD;
}

//binary exponentiation
int calc(int a, int b){        
    if(b==0)
        return 1;
    int temp = calc(a,b/2);
    temp = mul(temp,temp);
    if(b&1)
        return mul(temp,a);
    else    
        return temp;
}


int main() {
    long long t,w,s;
    cin>>t;
    while(t--){
        cin>>s>>w;
        if(s==calc(2,w-1)){
            cout<<"Perfect\n";
        }
        else{
            cout<<"Definitely Not\n";
        }
    }
}

