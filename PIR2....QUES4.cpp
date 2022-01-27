/*Shreya was left in charge of Buckbeak when Hagrid had to leave with Dumbledore. She realizes Buckbeak only sleeps when a particular sequence of spells is cast.

Shreya has learnt 6 base spells having having power A[0]...A[5]. If Shreya uses I strength of her own, the resulting spell powers are is (A[0]+I)...(A[5]+I). Now, Shreya has to cast a sequence of N spells to make Buckbeak sleep. The difficulty in casting is defined by the difference between the maximum and the minimum strength she had to use.

Help Shreya find the minimum difficulty she can achieve, while casting the spells.

Input Format

First line: An array of 6 integers, representing the powers of the base spells.

Second line: N, defines the number of frequencies to be played.

Third line: An array of N integers, B[0] to B[n-1].

Constraints

1 = N = 105.
1 = A[i] = 109, for 0 = i = 5
1 = B[i] = 1010, for 0 = i = N-1
B[i] > A[j], 0 = i = N-1, 0 = j = 5.
It is guaranteed that all the spells can be cast.

Output Format

Output a single integer, the minimum difficulty, i.e minimum difference between the largest and the smallest set number played.

Sample Input 0

1 2 3 4 5 6
4
10 11 12 13
Sample Output 0

0
Explanation 0

Here, if shreya uses spells 1,2,3 and 4, then

spell 10 can be cast by using base spell 1 with strength 9.
spell 11 can be cast by using base spell 2 with strength 9.
spell 12 can be cast by using base spell 3 with strength 9.
spell 13 can be cast by using base spell 4 with strength 9.
Maximum strength used by Shreya is 9. Minimum strength used by her is also 9. Hence the difficulty in casting the sequence of spells in the above described way is (9-9) = 0.

There are multiple ways to cast the same set of spells. The one with minimum difficulty is to be found.

Submissions: 25
Max Score: 200
Difficulty: Hard
Rate This Challenge:

    
More
 
*/
Using the fact the every spell can be cast, we can find out the strength Shreya is using to cast each of the N spells, for all the 6 base spells. Formally, this means that find out B[i] - A[j] for all valid i and j. Store {B[i]-A[j], i} pair in an array.

Now, to find the minimum difficulty in casting, sort this array. The problem now reduces to finding a "window", i.e a subarray in this array in which all i from 0 to N-1 are present at least once, and the difference between the values of B[i]-A[j] at the end points is minimum. This difference is the answer. This can be solved using two-pointers/sliding-window technique.

 Set by hackko_20

Problem Setter's code :
#include<bits/stdc++.h>
#include<algorithm>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define ff first
#define ss second
#define mloop(i) for(auto i=m.begin();i!=m.end();i++)
#define pb push_back
#define pll pair<ll,ll> 
#define pii pair<int,int> 
#define endl '\n'


using namespace std;

int main()
{
    int t=1;
    //cin>>t;
    while(t--)
    {
        vector<pll> pr;
        map<ll,ll> m = {};
        vector<ll> a(6);
        ll n, result=LLONG_MAX;
        for(ll i=0;i<6;i++)
            cin>>a[i];
        cin>>n;
        vector<ll> b(n);

        // make an array of {b[i]-a[j],i} pair ans sort it
        for(ll i=0;i<n;i++)
        {
            cin>>b[i];
            for(ll j=0;j<6;j++)
                pr.pb({b[i]-a[j],i});
        }
        sort(pr.begin(),pr.end());


        ll i; // i-->right pointer, j-->left pointer to the window

        // iterate to get the optimal "window", map stores the count of i's in the current window being explored.
        for(ll j=0;j<6*n;j++)
        {
            if(j == 0)
            {
                for(i=0;i<6*n;i++)
                {
                    m[pr[i].ss]++;

                    // if m has atleast n elements with count >=1, break from the loop
                    if(m.size() == n)
                        break;
                }
                // update the value of result with the difference of the current end points
                result = min(pr[i].ff-pr[0].ff,result);
            }
            else
            {
                // shifting the window by updating left and right pointers to the next subarray which satisfies the conditions
                ll f = pr[j-1].ss;
                m[f]--;
                if(m[f] == 0)
                {
                    m.erase(f);
                    i++;
                    while(pr[i].ss!=f && i<6*n)
                    {
                        m[pr[i].ss]++;
                        i++;
                    }
                    if(i<6*n)
                        m[f]++;
                }
                if(i<6*n)
                {
                    result = min(pr[i].ff-pr[j].ff,result);
                }                
            }
            // if right pointer goes out of array bounds, break
            if(i>=6*n)
                break;
        }
        cout<<result<<endl;
    }
    return 0;
}
 ///Tested by wsLord




//Problem Tester's code :
#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
#define mp make_pair

using namespace std;

int n;
vector<int> a (6);
vector<int> b;
vector<int> freq;

int main()
{
    fastio

    for (int i = 0; i < 6; ++i)
    {
        cin >> a[i];
    }

    cin >> n;
    b = vector<int> (n);
    for (int i = 0; i < n; ++i)
    {
        cin >> b[i];
    }

    vector<pair<int, int>> nums;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 6; ++j)
        {
            nums.pb(mp(b[i] - a[j], i+1));
        }
    }

    sort(nums.begin(), nums.end());

    int m = nums.size();
    freq = vector<int> (n+1, 0);
    int positives = 0;
    
    int i = 0, j = -1;
    int ans = 1e9 + 7;

    while(i < m && j < m)
    {
        if(positives < n || i > j)
        {
            j++;

            freq[nums[j].second]++;
            if(freq[nums[j].second] == 1)
                positives++;
        }
        else
        {
            ans = min(ans, nums[j].first - nums[i].first);

            freq[nums[i].second]--;
            if(freq[nums[i].second] == 0)
                positives--;

            i++;
        }
    }

    cout << ans << "\n";

    return 0;
}

