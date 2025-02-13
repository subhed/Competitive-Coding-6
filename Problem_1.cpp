// Author: Subhed Chavan
// Batch: December 24
// Problem Statement: Binary Tree Zigzag Level Order Traversal
// Approach: BFS (Breadth-First Search)
// TC: O(N)
// SC: O(N)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> result;

        // Base Case
        if (root == NULL)
        {
            return result;
        }

        int depth = 0;
        queue<TreeNode *> q;
        q.push(root);

        // BFS Traversal
        while (!q.empty())
        {
            int size = q.size();
            vector<int> storeLevelNode;

            for (int i = 0; i < size; i++)
            {
                TreeNode *curr = q.front();
                q.pop();
                storeLevelNode.push_back(curr->val);

                if (curr->left)
                {
                    q.push(curr->left);
                }
                if (curr->right)
                {
                    q.push(curr->right);
                }
            }

            // Reverse on odd levels
            if (depth % 2 == 1)
            {
                reverse(storeLevelNode.begin(), storeLevelNode.end());
            }

            result.push_back(storeLevelNode);
            depth++;
        }

        return result;
    }
};
