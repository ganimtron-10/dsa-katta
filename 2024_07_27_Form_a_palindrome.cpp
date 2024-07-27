// https://www.geeksforgeeks.org/problems/form-a-palindrome1455/1

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int makePalindrome(string &str, int l, int h, vector<vector<int>> &dp)
    {
        if (l == h or l > h)
            return 0;

        if (dp[l][h] != -1)
        {
            return dp[l][h];
        }

        if (str[l] == str[h])
        {
            return dp[l][h] = makePalindrome(str, l + 1, h - 1, dp);
        }
        else
        {
            return dp[l][h] = min(1 + makePalindrome(str, l + 1, h, dp), 1 + makePalindrome(str, l, h - 1, dp));
        }
    }

    int countMin(string str)
    {
        // complete the function here
        vector<vector<int>> dp(str.size(), vector<int>(str.size(), -1));
        return makePalindrome(str, 0, str.size() - 1, dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
    return 0;
}

// } Driver Code Ends