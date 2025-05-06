/*
1. Two Sum
Easy

Hint
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].


Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.


Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?
*/

#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {

        /*

        ✅ Brute Appraoch o(n^2)

        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    return {i, j};
                }
            }
        }

        ✅  Two pointer Approach 0(n)

        sort(nums.begin(), nums.end());

        int start = 0;
        int end = nums.size() - 1;

        while (start < end)
        {

            if (nums[start] + nums[end] == target)
            {
                return {start, end};
            }
            else if (nums[start] + nums[end] > target)
            {
                end--;
            }
            else if (nums[start] + nums[end] < target)
            {
                start++;
            }
            else
            {
                start++;
                end--;
            }
        }
       ✅  Hashing Approach O(n) || O(n)

   */

        unordered_map<int, int> myMap;
        for (int i = 0; i < nums.size(); i++)
        {

            int complement = target - nums[i];
            if (myMap.find(complement) != myMap.end())
            {
                return {myMap[complement], i};
            }

            myMap[nums[i]] = i;
        }

        return {};
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = sol.twoSum(nums, target);

    for (int index : result)
        cout << index << " ";
}