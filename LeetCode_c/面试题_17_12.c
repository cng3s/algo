/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode *head = NULL;

void inOrder(struct TreeNode *root, struct TreeNode *nodeArr[], int *ixArr){
    if (root->left)
        inOrder(root->left, nodeArr, ixArr);
    nodeArr[(*ixArr)] = root;
    *ixArr = *ixArr + 1;
    if (root->right)
        inOrder(root->right, nodeArr, ixArr);
}

struct TreeNode* convertBiNode(struct TreeNode* root){
    if (!root)
        return NULL;
    struct TreeNode **nodeArr = (struct TreeNode**) malloc(sizeof(struct TreeNode*) * 100005);
    memset(nodeArr, 0, sizeof(struct TreeNode*) * 100005);
    int ixArr = 0;
    inOrder(root, nodeArr, &ixArr);
    for (int i = 0; i < ixArr; ++i) {
        struct TreeNode *curNode = nodeArr[i];
        curNode->left = NULL;
        if (i+1 != ixArr)
            curNode->right = nodeArr[i+1];
    }
    struct TreeNode *ans = nodeArr[0];
    free(nodeArr);

    return ans;
}
