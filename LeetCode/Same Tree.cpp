#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == NULL && q == NULL)
            return true;
        else if (p == NULL || q == NULL)
            return false;

        queue<TreeNode *> pQ;
        queue<TreeNode *> qQ;
        pQ.push(p);
        qQ.push(q);
        while (!pQ.empty())
        {
            TreeNode *frontP = pQ.front();
            pQ.pop();
            TreeNode *frontQ = qQ.front();
            qQ.pop();

            if (frontQ->val != frontP->val)
                return false;
            bool lp = false, rp = false, lq = false, rq = false;
            if (frontP->left != NULL)
            {
                lp = true;
                pQ.push(frontP->left);
            }
            if (frontP->right != NULL)
            {
                rp = true;
                pQ.push(frontP->right);
            }
            if (frontQ->left != NULL)
            {
                if (lp)
                    qQ.push(frontQ->left);
                else
                    return false;
            }
            if (frontQ->right != NULL)
            {
                if (rp)
                    qQ.push(frontQ->right);
                else
                    return false;
            }
        }
        return true;
    }
};
int main()
{
    Solution *sol = new Solution();
    TreeNode *pRoot = new TreeNode(1);
    pRoot->left = new TreeNode(2);
    pRoot->right = new TreeNode(1);
    TreeNode *qRoot = new TreeNode(1);
    qRoot->right = new TreeNode(2);
    qRoot->left = new TreeNode(1);
    cout << sol->isSameTree(pRoot, qRoot) << endl;
    return 0;
}