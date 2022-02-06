/*You are given an array of N integers. Find the number of pairs (i < j) such that a[i]&a[j] >= a[i]?a[j], where & is the Bitwise AND operator and ? is Bitwise XOR operator .

Input Format

The first line contains one positive integer N — length of the array.

The second line contains N positive integers a[i] — elements of the array.

Constraints

1 = N = 2 * 105
1 = a[i] = 109
Output Format

Print one non-negative integer — the answer to the problem.

Sample Input 0

5
1 4 3 7 10
Sample Output 0

1
Sample Input 1

3
1 1 1
Sample Output 1

3

 
 
 The questions wants us to find all pairs {a[i], a[j]} where (i < j), such that a[i]&a[j] >= a[i]^a[j]. The brute force solution is very obvious, check for all pairs if they satify the constraints and increase the count. The time complexity will be O(N^2).

Brute Force Solution :
*/
#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int t = 1;
 
    while(t--){
        int n;
        cin>>n;
        vector<long long int> v(n);
        for (int i = 0 ; i < n; i++) cin>>v[i];
        long long int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if ((v[i]&v[j]) >= (v[i]^v[j]))
                    ans++;
            }
        }
        cout<<ans;
    }
}
/*Optimization : Let us observe two numbers a and b in binary representation. For this we will follow the bits of a and b from highest to lowest. If we meet two zero bits, the values of a & b and a?b will match in this bit, so we move on. If we meet a zero bit in a and in b —one bit(or vice versa), then we get a&b < a?b, and we can immediately say that the required condition is false. And if we meet two one bits, then the required condition is fulfilled, e. a&b > a?b, and then the bits can no longer be considered.

We will store for every number, the position of it's highest set bit. Now, this number can only be paired with a number whose highest set bit is present at this exact position.

Also note that we we have to add valid pairs a[i], a[j] such that i < j;

The time complexity of this solution is O(N);

C++ Solution :*/

#include<bits/stdc++.h>
#define ll long long int 
using namespace std;
int main(){
	int t=1,n,i,j;
	
	while(t--){
		int n;
		cin>>n;
		vector<int>b(32,0);
		ll c,ans=0,x;
		for(i=0;i<n;i++){
			cin>>x;
			c=0;
			while(x){
				c++;
				x/=2;
			}
			ans+=b[c];
			b[c]++;
		}
		cout<<ans<<endl;
	}
}
