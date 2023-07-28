/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *left, *right;
    Node()
    {
        this->data = 0;
        left = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->left = NULL;
        this->right = NULL;
    }
    Node(int data, Node* left, Node* right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};
*/

bool isParentSum(Node *root){
    // Write your code here.
    
    queue<Node*> q;
    q.push(root);
    
    
    while(!q.empty())
    {
        auto root1 = q.front();
        q.pop();
        
        if(root1->left==NULL && root1->right==NULL)
            continue;
        
        int val = root1->data;
        int sum = 0;
        
        if(root1->left!=NULL)
        {
            sum+=root1->left->data;
            q.push(root1->left);
        }
        
        if(root1->right!=NULL)
        {
            sum+=root1->right->data;
            q.push(root1->right);
        }
        
        if(sum!=val)
            return false;
    }
    
    return true;
    
}
