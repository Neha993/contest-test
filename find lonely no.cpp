/*You are given an integer array nums. A number x is lonely when it appears only once, and no adjacent numbers (i.e. x + 1 and x - 1) appear in the array.

Return all lonely numbers in nums. You may return the answer in any order.

Example 1:
Input: nums = [10,6,5,8]
Output: [10,8] */

class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int,int>m;
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        int k=m.size();
        for(int i=0;i<n;i++){
            if(!m[nums[i]-1] && !m[nums[i]+1] && m[nums[i]]<2){
                ans.push_back(nums[i]);
            }
        }
        
        return ans;
    }
};
