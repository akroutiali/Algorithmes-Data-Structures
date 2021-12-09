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
 
*/
//time Complexity O(n);space Complexity O(n)
void postOrderTraverse(BST*tree,vector<int> &vec)
{
   if(tree->left != nullptr)
   postOrderTraverse(tree->left,vec);
   if(tree->right != nullptr)
   postOrderTraverse(tree->right,vec);
   vec.push_back(tree->value);
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
    postOrderTraverse(node,vec);
    print(vec);
    return 0;
}
