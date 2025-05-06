#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
// not in order 
    void moveZeroes(vector<int> &nums)
    {
        int end = nums.size() - 1;
        int start = 0;

        while (start < end)
        {

            if ((nums[end] != 0) && (nums[start] == 0))
            {
                swap(nums[start], nums[end]);
                start++;
                end--;
            }
            else if (nums[start] != 0)
            {
                start++;
            }
            else if (nums[end] == 0)
            {
                end--;
            }
        }
        return;
    }

    // it will do operation inorder of the element

    void moveZeroes2(vector<int> &nums)
    {

        int lastNonZeroIndex = 0;

        for (int i = 0; i < nums.size(); i++)
        {

            if (nums[i] != 0)
            {
                swap(nums[i], nums[lastNonZeroIndex]);
                lastNonZeroIndex++;
            }
        }
        return;
    }
};

int main()
{

    vector<int> arr = {0, 3, 0, 4, 5, 6, 0, 67, 0, 0, 0, 0, 0, 5, 0, 0, 0};
    Solution sol1;
    sol1.moveZeroes2(arr);
    for (auto it : arr)
    {
        cout << it << " ";
    }

    return 0;
}
