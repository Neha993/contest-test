/* Aparna, being a student of Professor Snape, is having nightmares about her upcoming Potions exam.

In order to maximize the chances of passing the exam, everyone is eager to collect as much potion as they can. You are given the vertical heights of N bars and you need to select two bars such that the amount of potion contained in between them together with the x-axis is maximum.

You need to print the maximum amount of potion that can be collected.

Help Aparna maximize her chances of passing Snape's Potions exam.

Constraints

N == No. of vertical bars
2 <= N <= 10 5
0 <= height[i] <= 10 9
Sample Input 0

9
1 8 6 2 5 4 8 3 7
Sample Output 0

49 */
// TC N
#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin>>n;
    vector<int> height(n);
    for (int i = 0; i < n; i++) {
        cin>>height[i];
    }
    long long int ans = INT_MIN;
    int i = 0, j = n-1;
    while(i < j) {
        ans = max(ans, (j-i)*1LL*min(height[i], height[j]));
        if (height[i] < height[j]) 
            i++;
        else j--;
    }
    cout<<ans<<endl;

}
