void inorder(Node* root, Node* &prev, Node* &first, Node* &middle, Node* &last){
        if(root == NULL) return;
        inorder(root->left,prev,first,middle,last);
        if(prev != NULL && root->data < prev->data){
            if(first == NULL){
                first = prev;
                middle = root;
            }
            else{
                last = root;
            }
        }
        prev = root;
        inorder(root->right,prev,first,middle,last);
    }
    struct Node *correctBST(struct Node *root) {
        Node* prev = new Node(INT_MIN);
        Node* first = NULL;
        Node* middle = NULL;
        Node* last = NULL;
        inorder(root,prev,first,middle,last);
        if(first && last) swap(first->data, last->data);
        else if(first && middle) swap(first->data, middle->data);
        return root;
    }