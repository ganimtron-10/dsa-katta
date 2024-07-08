// https://leetcode.com/problems/find-the-winner-of-the-circular-game

class Solution
{
public:
    int findTheWinner(int n, int k)
    {
        vector<int> list;
        for (int i = 1; i < n + 1; i++)
        {
            list.push_back(i);
        }
        int curK = 0;
        while (list.size() > 1)
        {
            int temp = ((curK + k - 1) % list.size());
            list.erase(list.begin() + temp);
            curK = temp;
        }
        return list[0];
    }
};