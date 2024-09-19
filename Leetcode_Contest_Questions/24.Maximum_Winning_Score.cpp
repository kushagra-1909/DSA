class Solution {
  public:
    //Function to return maximum path product from any node in a tree.
    long long findMaxScore(Node* root)
    {
        if(root == NULL) return 1;
        long long v1 = root->data*findMaxScore(root->left);
        long long v2 = root->data*findMaxScore(root->right);
        return max(v1,v2);
    }
};