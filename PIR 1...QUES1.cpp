/*Everyone loves Christmas because of the amazing gifts they received from Santa Claus. Ada is your best friend and this year she wished to get an array as her Christmas present. She will be very sad if she won't get the array. You know very well that she likes a specific kind of array and will only accept that array as a present.
Array liked by Ada has the following qualities:

The array should be of exactly N length.
All the N integers of the array should be unique.
The sum of the elements of the array should be exactly 0.
All the array elements should be in the range [-1000000,1000000]
Santa Claus is really busy and doesn't have enough time to find this on his own and thus you need to help him by finding such an array. 
Sample Input 0

2
5
2
Sample Output 0

-1 -2 -3 4 2
-1 1
*/
#include<bits/stdc++.h>
using namespace std;
void solution (){
int n;
cin>>n;
for(int i=1;i<=n/2; i++)
{cout<<i<<" ";
cout<<-i<<" ";
}
if(n%2!=0){
cout<<0;
}
cout<<endl;
}

int main()
{ int t;
cin>>t;
while(t--){
solution ();
}
return 0;
}
