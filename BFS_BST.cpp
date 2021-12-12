/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <climits>
#include <stack>
#include <queue>
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
       20          level 0 
    10       30    level 1
  5    15  25   40 level 2 
  
  breadth first search : traverse tree by level
  use helper and evry time you reach the level equal to 0 print


*/
void helper_BFS(BST*node,int level)
{
    if(node == nullptr)
    return;
    
    if(level == 0)
    {
        cout<<node->value<<" ";
        return;
    }
    else
    { 
        helper_BFS(node->left,level-1);
        helper_BFS(node->right,level-1);
    }
}
void BFS(BST*node)
{

for(int i=1;i<4;i++)
{
    helper_BFS(node,i-1);
}
    
}
/*
using stack 
traverse left node and store there pointer in the stack then right node
to resolve this problem we can use queue
*/
void BFS_queue(BST*node)
{
    BST*current=node;
    queue<BST*>s;
    s.push(current);
    while(!s.empty())
    {
        current=s.front();
        s.pop();
        cout<<current->value<<" ";
        if(current->left != nullptr)
        s.push(current->left);
        if(current->right != nullptr)
        s.push(current->right);
    }
    
}
int main()
{
    BST*root=new BST(20);
   // root->left=new BST(10);
   // root->left->left=new BST(5);
    //root->left->right =new BST(15);
    root->right=new BST(25);
    root->right->right=new BST(30);
    BFS(root);
    //BFS_queue(root);

    return 0;
}
//depth first search DFS:traverse left then right node  
//breadth first search DFS :to implement breadh first search traverse left node then right node 
