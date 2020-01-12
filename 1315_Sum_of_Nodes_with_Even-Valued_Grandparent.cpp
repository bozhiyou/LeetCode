/**
 *  * Definition for a binary tree node.
 *   * struct TreeNode {
 *    *     int val;
 *     *     TreeNode *left;
 *      *     TreeNode *right;
 *       *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *        * };
 *         */
class Solution {
	public:
		    inline int sumEvenGrandparent(TreeNode* root) {
			            int ret = 0;
				            if (NULL != root->left) {
						                ret += sumEvenGrandparent(root->left);
								            if ((root->val & int(1)) == 0) {
										                    if (NULL != root->left->left) ret += root->left->left->val;
												                    if (NULL != root->left->right) ret += root->left->right->val;
														                }
									            }
					            if (NULL != root->right) {
							                ret += sumEvenGrandparent(root->right);
									            if ((root->val & int(1)) == 0) {
											                    if (NULL != root->right->left) ret += root->right->left->val;
													                    if (NULL != root->right->right) ret += root->right->right->val;
															                }
										            }
						            return ret;
							        }
};
