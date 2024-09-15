int toSumTree(Node *root)
    {
        if(root == NULL) return 0;
        
        int oldval = root->data;
        
        root->data = toSumTree(root->left) + toSumTree(root->right);
        
        return root->data + oldval;
    }