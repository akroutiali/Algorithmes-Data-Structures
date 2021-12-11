#include <iostream>
#include <climits>
using namespace std;
/*
      20
    10     30

Algorithme : 
if value<=getMax() the max value on the left node
return FALSE
if value >= getMin return the min value of the right subtree
return FALSE

 check the other node 
*/
class BST{
    public:
    int value;
    BST*right;
    BST*left;
    BST(int val)
    {
        value =val;
        right =nullptr;
        left=nullptr;
    }
};
int getMax(BST*node)
{
    int max=INT_MIN;
    if(node ==nullptr)
    return max;
    
    max=node->value;
    
    int ml=getMax(node->left);
    int mr=getMax(node->right);
    
    if(ml>max)
    max=ml;
    if(mr>max)
    max=mr;
    
    return max;
}
int getMin(BST*node)
{
    int min=INT_MAX;
    if(node ==nullptr)
    return min;
    min =node->value;
    int ml=getMin(node->left);
    int mr=getMin(node->right);
    
    if(ml<min)
    min=ml;
    if(mr<min)
    min=mr;

return min;
}
bool isBST(BST*node)
{
    if(node->value <=getMax(node->left))
    return false;
    if(node->value> getMin(node->right))
    return false;
    if(node->right != nullptr)
    {
        if(!isBST(node->right))
        return false;
    }
    if(node->left != nullptr)
    {
        if(!isBST(node->left))
        return false;
    }
    return true;
}
int main()
{
    BST*root=new BST(20);
    root->left=new BST(10);
    root->left->left=new BST(5);
    root->left->right =new BST(15);
    root->right=new BST(25);
    root->right->right=new BST(40);
    cout<<"is BST"<<isBST(root);

    return 0;
}
