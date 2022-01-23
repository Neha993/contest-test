/* You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.

You should rearrange the elements of nums such that the modified array follows the given conditions:

Every consecutive pair of integers have opposite signs.
For all integers with the same sign, the order in which they were present in nums is preserved.
The rearranged array begins with a positive integer.
Return the modified array after rearranging the elements to satisfy the aforementioned conditions.

Example 1:

Input: nums = [3,1,-2,-5,2,-4]
Output: [3,-2,1,-5,2,-4] */

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
	int n=nums.size();
	   vector<int>v1;
        vector<int>v2;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                v2.push_back(nums[i]);
            }
            else{
                v1.push_back(nums[i]);
            }
        }
        vector<int>ans;
        int j=0;
        int k=0;
        for(int i=0;i<n;i++){
        	
            if(i&1){
            	
                ans.push_back(v1[j]);
                j++;
            }
            else{
            	
                ans.push_back(v2[k]);
                k++;
            }
        }
        
      return ans;
    }
};
