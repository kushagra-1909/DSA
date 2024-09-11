class Solution{
    public:
    void connect(Node *root)
    {
       queue<Node*>q;
       q.push(root);
       
       while(!q.empty()){
           int size = q.size();
           vector<Node*>arr;
           for(int i=0; i<size; i++){
               Node* node = q.front();
               q.pop();
               arr.push_back(node);
               if(node->left != NULL){
                   q.push(node->left);
               }
               if(node->right != NULL){
                   q.push(node->right);
               }
           }
           arr.push_back(NULL);
           for(int i=0; i<size; i++){
               arr[i]->nextRight = arr[i+1];
           }
       }
    }    
};