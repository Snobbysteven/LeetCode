/**
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]


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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        //Check for empty root
        if(!root) return vector<vector<int>> ();
        
       //initialize 
        vector<vector<int>> ord;
        queue<TreeNode*> que;
        
        //floor is to switch between left and right for ziggzagg
        int floor = 0;
        
        //push root into que
        que.push(root);
        
        while(!que.empty()) {
            int siz = que.size();
            vector<int> cur(siz);
            
            for(int i = 0; i < siz; i++) {
                TreeNode* tmp = que.front();
                que.pop();
                
                if(floor == 0) {
                    cur[i] = tmp->val;
                } else {
                    cur[siz - i - 1] = tmp->val;
                }
                if(tmp->left) que.push(tmp->left);
                if(tmp->right) que.push(tmp->right);
            }
            ord.push_back(cur);
            floor = !floor;
        }
        return ord;
    }
};
