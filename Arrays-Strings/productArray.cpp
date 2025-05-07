#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> result(n); 

        for (int i = 0; i < n; i++)
        {
            int product = 1;
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    product *= nums[j];
                }
            }
            result[i] = product; 
        }

        nums = result; 
        return nums;
    }
};

int main()
{
    vector<int> arr = {1, 2, 3};
    Solution sol1;
    sol1.productExceptSelf(arr); 

    for (auto it : arr)
    {
        cout << it << " ";
    }

    return 0;
}
