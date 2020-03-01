/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    bool root_match(ListNode* head, TreeNode* root){
        if(head == NULL)
            return 1;
        if(root == NULL)
            return 0;
        if(head -> val != root -> val)
            return 0;
            
        return root_match(head->next, root->left) || root_match(head->next, root->right);
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!head)
           return 1;
        if(!root)
           return 0;
       return root_match(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};
