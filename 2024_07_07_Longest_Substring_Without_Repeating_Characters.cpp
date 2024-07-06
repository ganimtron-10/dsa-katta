#include <bits/stdc++.h>
int uniqueSubstrings(string input)
{
    // Write your code here
    int maxLength = 0;
    map<char, int> charMap;

    int n = input.size();
    int s = 0, e = 0;
    while (s < n and e < n)
    {
        char curChar = input[e];
        if (charMap.find(curChar) != charMap.end())
        {
            if (charMap[curChar] + 1 > s)
            {
                s = charMap[curChar] + 1;
            }
            charMap[curChar] = e;
        }
        else
        {
            charMap[curChar] = e;
            // cout << s << " " << e << " " << input.substr(s,e-s+1) << endl;
        }
        maxLength = max(maxLength, e - s + 1);
        e++;
    }

    return maxLength;
}