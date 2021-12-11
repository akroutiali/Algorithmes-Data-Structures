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
    void insert(int val);
    bool contains(int val);
    void del(int val,BST* parent);
    
};

/*
                   20
              10        30
           5      15  25    40
        2                       60
                                    70
 
 
 
*/
//time Complexity O(n);space Complexity O(n)

/*
Algorithme :
-if value >root->value  go to right node
-if value <root->left go to left node
-repeat step 1 & 2 until you find left or right node is null

time Complexity :O(log n).
space Complexity : O(1).
*/
void BST::insert(int val)
{
    if(value <val)
    {
        if(right != nullptr)
        {
            right->insert(val);
        }
        else
        {
            BST* newnode=new BST(val);
            right=newnode;
        }
    }
    else
    {
        if(left != nullptr)
        {
            left->insert(val);
        }
        else
        {
            BST* newnode=new BST(val);
            left=newnode;
        }
    
    }
}
/*
check if the value of the actual node equal to the searched value :
if yes retun true:
if no : 
 if superior and the right node not equal to null go to the right node and repeat the job
 if inferior and the left node not equal to null got to the left node and repeat the jon
 
 else
 return false
 time Complexity O(n)
 space Complexity O(1)
*/
bool BST::contains( int val)
{
    if(value==val)
    return true;
    if(val>value && right!= nullptr)
       return right->contains(val);
    else if(val<value && left!= nullptr)
       return left->contains(val);
    
    return false;   
}

/*
return the min value of the left node
*/
int getMin(BST*tree)
{
    if(tree->left ==nullptr)
    return tree->value;
    else
        return getMin(tree->left);
}

/*
Algotihme : 
-if the node to delete has right and left not equal to null 
-replace the node to delete by the node has the minimum value in the right
else
-if the node to delete is the root node : 
 if right != null 
 node->value=right->value
 node->left=right->left
 node->right=right->right
 if left != null ptr 
 node->value =left->value
 node->left =left->left 
 node->right= left->right
 
-else
parent->left==this 
parent->left=left != nullptr?left:right
-if the node  to delete is the root node : 
find the minimum node in riht node
 time Complexity O(n)
 space Complexity O(1)
*/
void BST::del(int val,BST* parent = nullptr)
{
    if(value<val)
    {
        if(right != nullptr)
        right->del(val,this);
    }
    else if(value>val)
    {
        if(left != nullptr)
        left->del(val,this);
    }
    else
    {
        if(right != nullptr && left != nullptr)
        {
            value=getMin(right);
            right->del(value,this);
        }
        else
        {
            if(parent ==nullptr)
            {
                if(right != nullptr)
                {
                    value=right->value;
                    right=right->right;
                    left=right->left;
                }
                else if(left != nullptr)
                {
                    value=left->value;
                    left=left->left;
                    right=left->right;
                }
            }
            else if(parent->left ==this)
            {
               parent->left=left!= nullptr?left:right; 
            }
            else if(parent->right == this)
            {
                parent->right=left != nullptr?left:right;
            }
            
        }
    }
}

void print(BST*tree)
{
    if(tree->left!=nullptr)
    print(tree->left);
    cout<<tree->value<<" ";
    if (tree->right != nullptr)
    print(tree->right);
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
    node->insert(70);
    node->del(25);
    cout<<"is found =="<<node->contains(30);
    print(node);
    return 0;
}
