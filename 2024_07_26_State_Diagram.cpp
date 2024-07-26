// https://www.naukri.com/code360/problems/state-diagram_762942

#include <bits/stdc++.h>
/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            char data;
            Node *next;
            Node *random
            Node(char data)
            {
                this->data = data;
                this->next = NULL;
                this->random = NULL;
            }
        };

*****************************************************************/

bool simulate(Node *head, string &str, int i, unordered_map<Node *, unordered_map<int, bool>> &memo)
{

    if (!head)
        return false;

    if (head->data != str[i])
        return false;

    if (i + 1 == str.size() && head->next == NULL)
        return true;

    if (memo.find(head) != memo.end() && memo[head].find(i) != memo[head].end())
    {
        return memo[head][i];
    }

    bool nextMatch = false, randomMatch = false;
    if (head->next)
    {
        nextMatch = simulate(head->next, str, i + 1, memo);
    }
    if (head->random)
    {
        randomMatch = simulate(head->random, str, i + 1, memo);
    }

    memo[head][i] = nextMatch || randomMatch;
    return memo[head][i];
}

bool isItAccepted(Node *head, string &str)
{
    // Write your code here.
    if (str.empty())
        return false;
    unordered_map<Node *, unordered_map<int, bool>> memo;
    return simulate(head, str, 0, memo);
}
