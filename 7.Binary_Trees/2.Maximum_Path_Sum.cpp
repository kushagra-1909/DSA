int maxSum(Node* root, int &maxi){
        if(root == NULL){
            return 0;
        }
        
        int leftSum = max(0, maxSum(root->left,maxi));
        int rightSum = max(0,maxSum(root->right, maxi));
        maxi = max(maxi,root->data+rightSum+leftSum);
        return root->data + max(leftSum,rightSum);
        
    }
    int findMaxSum(Node* root)
    {
        int maxi = INT_MIN;
        maxSum(root,maxi);
        return maxi;
    }