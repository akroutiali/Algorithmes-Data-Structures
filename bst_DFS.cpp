#include <iostream>
#include <climits>
#include <stack>
using namespace std;


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
/*
Alorithme : 
/*
       20
    10       30
  5    15  25   40
  
  Depth first search : traverse left node then traverse right node


*/
void DFS(BST*node)
{
    cout<<node->value<<" ";
    if(node->left != nullptr)
    DFS(node->left);
    if(node->right != nullptr)
    DFS(node->right);
    
}
/*
using stack 
traverse left node and store there pointer in the stack then right node
*/
void DFS_Stack(BST*node)
{
    BST*current=node;
    stack<BST*>s;
    s.push(current);
    while(!s.empty())
    {
        current=s.top();
        s.pop();
        cout<<current->value<<" ";
        if(current->right != nullptr)
        s.push(current->right);
        if(current->left != nullptr)
        s.push(current->left);
    }
    
}
int main()
{
    BST*root=new BST(20);
    root->left=new BST(10);
    root->left->left=new BST(5);
    root->left->right =new BST(15);
    root->right=new BST(25);
    root->right->right=new BST(30);
    DFS(root);
    DFS_Stack(root);

    return 0;
}
