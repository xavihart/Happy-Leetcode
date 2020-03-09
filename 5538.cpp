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
    int max_len(TreeNode* root){
        int max1=0, max2=0;
        int f = 1;
        TreeNode* node = root;
        while(node){
            if(!node) break;
            if(f == 1){
                node = node -> left;
            }else{
                node = node -> right;
            }
            max1++;
            f *= -1;
        }
        node = root;
        f = -1;
        while(node){
            if(!node) break;
            if(f == 1){
                node = node -> left;
            }else{
                node = node -> right;
            }
            max2++;
            f *= -1;
        }
        return max(max1, max2);
    }
    
    //pruning section
    TreeNode* find_left_most(TreeNode *root){
        int f = 1;
        root = root -> left;
    
        while(root && (root -> left || root -> right)){
            if(f == 1){
                if(root -> right && !(root -> left))
                    root = root -> right;
                else{
                    return root;
                }
            }else{
                if(root -> left && !(root -> right))
                    root = root -> left;
                else{
                    return root;
                }
            }
            f *= -1;
        }
        return NULL;
    }

     TreeNode* find_right_most(TreeNode *root){
        int f = -1;
        root = root -> right;
        while(root && (root -> left || root -> right)){
            if(f == 1){
                if(root -> right && !(root -> left))
                    root = root -> right;
                else{
                    return root;
                }
            }else{
                if(root -> left && !(root -> right))
                    root = root -> left;
                else{
                    return root;
                }
            }
            f *= -1;
        }
         return NULL;
    }


    int longestZigZag(TreeNode* root) {
        if(!root) return 0;
        TreeNode *left_most, *right_most;
        left_most = find_left_most(root);
        right_most = find_right_most(root);
        
        return max(max_len(root) - 1, max(longestZigZag(left_most), longestZigZag(right_most)));
    }
};
