/* Once upon a time, There was a golden era when students were attending offline classes and living in college hostel. Every Monday they were served Aaloo paratha and Pyaaj Paratha (referred as 0 and 1 respectively) as Breakfast in Swami Vivekanand Hostel. But they were allowed to take any one of the parathas as the number of parathas is equal to the number of students in the hostel. Each student has their own preference referred by 0 for Aaloo Paratha and 1 for Pyaaj Paratha. Students are standing in queue for Breakfast and paratha is arranged in stack manner. For every front student of the queue

If paratha of his preference is on top of the stack, He picks it and leaves the queue.
Else, He will leave that paratha and go to the queue’s end again for his turn.
This process continues until none of the students standing in the queue wants the paratha on the top of the stack. The remaining Students will become sad. You are given two array students and paratha where students[i] represents the preference of ith student (0th index is front of the queue) and paratha[i] represents the ith paratha in the stack. (0th index represents the top of the stack). Find the number of sad students

Input Format

First line will contain N, The number of students.

Second line will contain N integers representing students array.

Third line will contain N integers representing paratha array.

Constraints

1 <= N <= 100.

student[i] will be either 0 (representing student wants Aaloo paratha) or 1 (representing student wants Pyaaj paratha).

paratha[i] will be either 0 (representing Aaloo paratha at ith position of stack) or 1 (representing Pyaaj paratha at ith position of stack).

Output Format

Print a single integer representing number of sad students.

Sample Input 0

3
0 1 0
1 0 0
Sample Output 0

0
Explanation 0

paratha[0] represents top of stack and student[0] represents front of queue.
First student wants 0 (Aaloo paratha) but 1 is on top of stack so he go back to the queue
Second student wants 1 and it is on the top so he will take it and leave.
Third student wants 0 and it is on the top so he will take it and leave.
First student again come and this time 0 is on the top so he will take it and leave. Hence, no student is sad.
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    int b[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    stack<int>s;
    queue<int>q;
    for(int i=n-1;i>=0;i--){
        s.push(b[i]);
    }
    for(int i=0;i<n;i++){
        q.push(a[i]);
    }
    while(!q.empty() and !s.empty()){
        int count=0;
        while(!q.empty() and !s.empty()){
            if(count==q.size())break;
            if(q.front()==s.top()){
                q.pop();
                s.pop();
                count=0;
                break;
            }
            else{
                int x=q.front();
                q.pop();
                q.push(x);
            }
            count++;
        }
        if(count>=q.size())break;
    }
    
    
    cout<<q.size();
    return 0;
}
 

