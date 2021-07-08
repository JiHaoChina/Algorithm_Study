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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
    }
    TreeNode* build(vector<int>& inorder,int l1,int r1, vector<int>& postorder,int l2,int r2)
    {
        if(l1>r1) return nullptr;
        TreeNode* root = new TreeNode(postorder[r2]);
        int mid_root_index = 0;
        while(inorder[mid_root_index]!= root->val)
        {
            mid_root_index++;
        }
        //左子树的大小
        int leftsize = mid_root_index - l1;
        //右子树的大小
        int rightsize = r1- mid_root_index;

        //左子树
        root->left = build(inorder,l1,mid_root_index-1,postorder,l2,l2+leftsize-1);
        //右子树
        root->right=build(inorder,mid_root_index+1,r1,postorder,l2+leftsize,r2-1);

        return root;
    }
};