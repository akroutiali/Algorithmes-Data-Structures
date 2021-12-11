#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class BST
{
    public: 
    int value;
    BST*right;
    BST*left;
    BST(int val)
    {
        value=val;
        right=nullptr;
        left=nullptr;
    }
};

/*
                   20
              10        30
           5      15  25    40
        2                       60
 
 
 Algorithmes : 
 -print   all left boundaires  node exept leaf node .
 -print leaf node
 -print right boundaries  node 
*/
//time Complexity O(n);space Complexity O(n)
void left(BST*tree,vector<int>& vec)
{
    if(tree->left != nullptr)
    {
        vec.push_back(tree->value);
        left(tree->left,vec);
    }
    
}
void right(BST*tree,vector<int>& vec)
{
    stack<BST*>s;
    BST*current=tree;;
    while (current->right != nullptr)
    {
        s.push(current);
        current=current->right;
    }
    
    while(!s.empty())
    {
        current=s.top();
        vec.push_back(current->value);
        s.pop();
    }
}
void in(BST*tree,vector<int>&vec)
{
    if(tree->left == nullptr && tree->right == nullptr)
    {
        vec.push_back(tree->value);
    }
     if (tree->left != nullptr)
    {
        in(tree->left,vec);    
    }
    if(tree->right != nullptr)
    {
        in(tree->right,vec);
    }
}
void boundariesTraverse(BST*tree,vector<int> &vec)
{
left(tree,vec);
in(tree,vec);
right(tree->right,vec);
}

void print(vector<int> vec)
{
    for(int i=0;i<vec.size();i++)
    {
        cout<<vec[i]<<" ";
    }
}
int main()
{
    BST*node= new BST(20);
    node->left= new BST(10);
    node->left->left=new BST(5);
    node->left->left->left=new BST(2);
    node->left->right =new BST(15);
    node->right=new BST(30);
    node->right->right=new BST(40);
    node->right->right->right= new BST(60);
    node->right->left = new BST(25);
    vector<int> vec;
    boundariesTraverse(node,vec);
    print(vec);
    return 0;
}
