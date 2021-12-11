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
 
 
 Algorithmes rightViewBSt: 
 -start iterating  the binary tree from right and for evry level of tree try to increment the value of level to not print two node in the same level
*/
//time Complexity O(n);space Complexity O(n)

void rightViewBST(BST*tree,vector<int> &vec,int level=0)
{
    if(level==vec.size())
    {
        vec.push_back(tree->value);
    }
   if(tree->right != nullptr)
        rightViewBST(tree->right,vec,level+1);
    if(tree->left != nullptr)
        rightViewBST(tree->left,vec,level+1);
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
    rightViewBST(node,vec);
    print(vec);
    return 0;
}
