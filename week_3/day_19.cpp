/**

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

**/

class Solution {
public:
    int bs(vector<int>& nums, int L, int R, int target)
    {
        int M;
        while(L <= R)
        {
            M = L + ((R-L)/2);
            if(nums[M] == target) return M;
            if(nums[M] > target) R = M - 1;
            else L = M + 1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int L,R,M;
        L = 0;
        R = nums.size() - 1;
        while(L < R)
        {
            M = L + ((R-L)/2);
            if(nums[M] > nums[R])
            {
                L = M + 1;
            }
            else 
            {
                R = M;
            }
        }
        int res = bs(nums, L, nums.size() - 1, target);
        if(res != -1) return res;
        res = bs(nums, 0, L - 1, target);
        if(res != -1) return res;
        return -1;
    }
};