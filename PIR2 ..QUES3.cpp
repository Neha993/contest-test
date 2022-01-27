/* Priyanshu is one of the favourite students of Professor Dumbledore. Dumbledore has given him the "Book of Spells" and asked him to make copies of some specific pages of the book that are in continuous groups. These copies would be sent to the Ministry of Magic so that those spells are added to the Hogwarts' curriculum.
Priyanshu has already made copies of some groups of pages but Dumbledore is adding more and more such groups of pages.
Help Priyanshu to make the copies and put them in order such that there is only one copy of each page and the page groups are completely separate (i.e. you have to merge the groups if needed).

Each page group, denoted by a, b, is group of consecutive pages numbered a, a+1, …, b-1, b.
Single page numbered 5 is denoted as 5, 5
You are given the initial unsorted set of N page groups whose copies are already made by Priyanshu. In this set, there is only one copy of each page.
Then you are given Q requests made by Dumbledore in form of u, v, p where u, v denotes page group and p is 0 or 1
For each request, add the requested pages to the set obtained until last request and if p == 1 print the ordered sequence of groups of pages
Input Format

First line contains single integer N denoting number of page groups in the initial set
Next N lines contains two integers a, b denoting each page group
(N+2)th line contains single integer Q denoting the number of requests
Next Q lines contains three integers u, v, p where u, v denotes the page group that needs to be further added to the set and p denotes if the obtained ordered sequence needs to be printed
Constraints

1 = N = 105
1 = Q = 500
1 = a = b = 109
1 = u = v = 109
0 = p = 1
It is guaranteed that at least one request is such that p == 1

Output Format

For each request where p == 1,
• Print an integer M denoting number of consecutive page groups in the obtained set
• Next M line contains two integers p, q denoting each page group

Sample Input 0

3
1 3
17 19
5 9
4
11 12 1
4 6 1
15 18 1
22 31 1
Sample Output 0

4
1 3
5 9
11 12
17 19
3
1 9
11 12
17 19
3
1 9
11 12
15 19
4
1 9
11 12
15 19
22 31
Explanation 0

Initial set: (1, 3), (5, 9), (17, 19)
In 1st request, (11, 12) is added: (1, 3), (5, 9), (11, 12), (17, 19)
In 2nd request, (4, 6) is added: (1, 9), (11, 12), (17, 19)
Here, (5, 6) is already copied. Hence, only (4, 4) needs to be copied resulting in (1, 9) continuous page group.

Sample Input 1

3
1 3
10 20
6 7
2
4 5 1
9 9 1
Sample Output 1

2
1 7
10 20
2
1 7
9 20
Explanation 1

Initial set: (1, 3), (6, 7), (10, 20)
In 1st request, (4, 5) is added: (1, 7), (10, 20)
Here, (1, 3), (4, 5), (6, 7) becomes a continuous group and are not completely separate. So, they would be merged resulting in (1, 7) continuous page group.
In 2nd request, (9, 9) is added: (1, 7), (9, 20)
Here, (9, 9) & (10, 20) becomes a continuous group and are not completely separate. So, they would be merged resulting in (9, 20) continuous page group.

*/
/*Here, we are initially given unsorted non-overlapping separate page groups. So, we would sort the page groups so that the requests could be processed in O(N) time complexity.
This sorting would take O(NlogN) time complexity.

For each request, we need to insert the page group into the set and merge the groups if they are continuous or overlapping.
For eg:

(2, 7) and (8, 12) are continuous and would result in (2, 12) page group.
(3, 9) and (7, 11) are partially overlapping and would result in (3, 11) page group.
(3, 9) and (5, 7) are completely overlapping and would result in the same (3, 9) page group.
(2, 5) and (8, 10) are separate and would not require merging.
Now, for insertion of the page groups into the set, we can do the following (although many ways are possible):

First, we would insert the given page group u, v after the page groups having start < u
The total number page groups would become n+1 (0, 1, ..., n-1, n)
Then, we would iterate from 0 to n-1 merging the groups as shown above and adding to the result set.
Let p[i] be the ith page group. Then, p[i] and p[i+1] would be
continuous if p[i].end == p[i+1].start - 1 and
overlapping if p[i].end >= p[i+1].start.
So, when they are continuous or overlapping, we would merge p[i] into p[i+1] by updating p[i+1].start = p[i].start and p[i+1].end = max(p[i+1].end, p[i].end).
Otherwise, we would simply insert p[i] into the result set.
We need to swap result pageset and initial pageset so that next request could be processed using the same loop.
Each request takes O(N) time complexity.
Hence, net complexity is O(NlogN + N * Q)

 Set by wsLord

Problem Setter's code : */
#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back

using namespace std;

// Struct for Page Group
struct PGROUP
{
    int start;
    int end;

    PGROUP(int tstart, int tend)
    {
        start = tstart;
        end = tend;
    }
};

// Custom comparator for sorting
bool page_comp(PGROUP &a, PGROUP &b)
{
    return a.start < b.start;
}

int main()
{
    fastio

    int n, a, b, q, u, v, p;
    vector<PGROUP> pageset;
    
    cin >> n;
    
    for (int i = 0; i < n; ++i)
    {
        cin >> a >> b;
        pageset.pb(PGROUP(a, b));
    }

    // Sorting the page groups in ascending order
    sort(pageset.begin(), pageset.end(), page_comp);

    cin >> q;

    // Processing the requests
    while (q--)
    {
        cin >> u >> v >> p;

        int i = 0;
        n = pageset.size();
        while(i < n && pageset[i].start < u)
            i++;

        pageset.insert(pageset.begin() + i, PGROUP(u, v));

        vector<PGROUP> result;
        for (i = 0; i < n; ++i)
        {
            if(pageset[i].end >= (pageset[i+1].start - 1))
            {
                pageset[i+1].start = pageset[i].start;
                pageset[i+1].end = max(pageset[i+1].end, pageset[i].end);
            }
            else
            {
                result.pb(pageset[i]);
            }
        }
        result.pb(pageset[n]);

        // Printing output
        if(p == 1)
        {
            int rsize = result.size();
            cout << rsize << "\n";

            for (i = 0; i < rsize; ++i)
            {
                cout << result[i].start << " " << result[i].end << "\n";
            }
        }
        
        // Swapping result set with pageset for next request
        swap(result, pageset);
    }

    return 0;
}
 

