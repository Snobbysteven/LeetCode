/**
Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
*/






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
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        //If root have no leaves, return 0
        if(!root){
            return 0;
        } 
       //If Left leaf has no left or right leaves on it, then it is the last left leave, use that value to then
        //do a recursive call of the right side of the tree to solve that side and add the two values together 
        if(root->left && !root->left->left && !root->left->right) {
            return root->left->val + sumOfLeftLeaves(root->right);
        }
        //Combine the left leaves values for the left and right side of the tree
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};
