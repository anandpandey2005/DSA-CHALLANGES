#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void helper(string &str, int i, string current, vector<string> &result)
    {
        if (i == str.length())
        {
            result.push_back(current);
            return;
        }

        helper(str, i + 1, current + str[i], result);

        helper(str, i + 1, current, result);
    }

    void subsequences(string str)
    {
        vector<string> result;
        helper(str, 0, "", result);

        for (string s : result)
        {
            if (s == "")
                cout << "{}" << endl;
            else
                cout << s << endl;
        }

        cout << "\nTotal subsequences (with duplicates, including empty): " << result.size() << endl;
    }

    void printSubsequence(int index, vector<int> &current, vector<int> arr)
    {
        if (arr.size() == index)
        {
            for (auto it : current)
            {
                cout << it << " ";
            }
            if (current.size() == 0)
            {
                cout << "{}";
            }
            return;
        }

        current.push_back(arr[index]);
        printSubsequence(index + 1, current, arr);
        current.pop_back();
        printSubsequence(index + 1, current, arr);
    }

    void printStringSubsequence(int index, string &result, string str)
    {

        if (index == str.length())
        {
            for (auto it : result)
            {
                cout << it << " ";
            }
            if (result.size() == 0)
            {
                cout << "{}";
            }
            cout << endl;
            return;
        }

        result += str[index];
        printStringSubsequence(index + 1, result, str);
        result.pop_back();
        printStringSubsequence(index + 1, result, str);
    }
};

int main()
{
    Solution obj;
    string str = "anand";
    vector<int> datastructure;
    vector<int> arr = {1, 2, 3};
    string s = "";
    obj.printStringSubsequence(0, s, "anand");
    return 0;
}
