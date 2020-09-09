/*
 * @File: 559. Maximum Depth of N-ary Tree.cpp
 * @Author: Chirag Rawal (@hackrhive)
 * @File Created: Thursday, 10th September 2020 1:03:49 am
 * @Last Modified: Thursday, 10th September 2020 1:40:02 am
 */
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};
class Solution
{
public:
    int maxDepth(Node *node)
    {
        if (node == NULL)
            return 0;
        if (node->children.size() == 0)
            return 1;
        int maxD = 0;
        for (auto x : node->children)
            maxD = max(maxD, maxDepth(x));
        return maxD + 1;
    }
};
int main()
{
    Solution *sol = new Solution();
    Node *node = new Node(5);
    Node *node2 = new Node(6);

    Node *node3 = new Node(3);
    node3->children = {node, node2};

    Node *node4 = new Node(2);
    Node *node5 = new Node(4);

    Node *root = new Node(1);
    root->children = {node3, node4, node5};
    cout << sol->maxDepth(root) << endl;
    return 0;
}