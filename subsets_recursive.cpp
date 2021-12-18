#include <iostream>
#include<vector>
#include<cmath>

using namespace std;
/*
Alogorithme : 
1 2 3 

         [1]            []
    [2]      []    [2]      []
[3]    []  [3] [] [3] []   [3] []

time complexity O(n)
space complexity O(1)
*/
void subsetutils(vector<int>input,vector<vector<int>> &out,vector<int>subset,int index)
{
    if(index==input.size())
    out.push_back(subset);
    if(index<input.size())
    {
        
        subsetutils(input,out,subset,index+1);
        subset.push_back(input[index]);
        subsetutils(input,out,subset,index+1);
    }
}
vector<vector<int>> subset_recursive(vector<int> input )
{
    vector<vector<int>>out;
    vector<int>subset;
    subsetutils(input,out,subset,0);
    return out;
}
int main()
{
    vector<int> input ={1,2,3};
    vector<vector<int>>out=subset_recursive(input);
    for(int i=0;i<out.size();i++)
    {
        for(int j=0;j<out[i].size();j++)
        {
            cout<<out[i][j]<< " ";
        }
    }

    return 0;
}
