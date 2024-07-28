// https://www.geeksforgeeks.org/problems/remove-duplicates3034/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    string removeDups(string str)
    {
        // Your code goes here
        char charFreq[26] = {};
        string unqiueStr = "";

        for (char c : str)
        {
            if (!charFreq[c - 'a'])
            {
                unqiueStr.push_back(c);
                charFreq[c - 'a'] = 1;
            }
        }
        return unqiueStr;
    }
};

//{ Driver Code Starts.

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.removeDups(s) << "\n";
    }

    return 0;
}
// } Driver Code Ends