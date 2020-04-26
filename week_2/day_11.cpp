/**

Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree
          1
         / \
        2   3
       / \     
      4   5    
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.

**/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define diameter first
#define depth second

class Solution {
public:
    pair<int, int> f(TreeNode* root)
    {
        if(!root) return {0, 0};
        pair<int, int> L = f(root->left);
        pair<int, int> R = f(root->right);
        int diam = max({L.diameter, R.diameter, L.depth + R.depth});
        return {diam, max(L.depth, R.depth) + 1};
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return f(root).diameter;
    }
};