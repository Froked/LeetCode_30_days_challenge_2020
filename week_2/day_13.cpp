/**

Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
Note: The length of the given binary array will not exceed 50,000.

**/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums[0] == 0) nums[0] = -1;
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] == 0) nums[i] = -1;
            nums[i] = nums[i - 1] + nums[i];
        }
        int max_size = 0;
        unordered_map<int, int>mp;
        mp[0] = -1;
        for(int i = 0; i < nums.size(); i++)
        {
            if(mp.find(nums[i]) != mp.end())
            {
                max_size = max(max_size, i - mp[nums[i]]);
            }
            else mp[nums[i]] = i;
        }
        return max_size;
    }
};