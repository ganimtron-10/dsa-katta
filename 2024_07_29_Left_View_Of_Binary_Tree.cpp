// https://www.naukri.com/code360/problems/moderate_8143332

vector<int> printLeftView(BinaryTreeNode<int> *root)
{
    // Write your code here.

    vector<int> res;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        int qSize = q.size();
        res.push_back(q.front()->data);
        while (qSize)
        {
            BinaryTreeNode<int> *cur = q.front();
            q.pop();
            if (cur->left != NULL)
            {
                q.push(cur->left);
            }
            if (cur->right != NULL)
            {
                q.push(cur->right);
            }
            qSize--;
        }
    }
    return res;
}