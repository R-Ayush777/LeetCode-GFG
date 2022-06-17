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

    /*
        -1 -> if need a camera
        0 -> if have a camera
        1 -> if covered by a cmera
    */

public:
    int cameras = 0;

    int require(TreeNode *node)
    {
        if (!node)
            return 1;
        int lc = require(node->left);
        int rc = require(node->right);

        if (lc == -1 or rc == -1)
        {
            cameras++;
            return 0;
        }
        if (lc == 0 or rc == 0)
            return 1;

        return -1;
    }

    int minCameraCover(TreeNode *root)
    {
        if (require(root) == -1)
            cameras++;

        return cameras;
    }
};