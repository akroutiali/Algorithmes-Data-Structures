#include <iostream>
#include<vector>
#include<cmath>

using namespace std;
/*
Alogorithme : 


backtracking algorithme : 

the idea is to  push the element and try all the combinations then pop the element and try the other combinations 

1 2 3 

1 2 3 

1


time complexity O(n)
space complexity O(1)
*/
void backtrackingutils(vector<int>input,vector<vector<int>> &out,vector<int>subset,int index)
{
    out.push_back(subset);
    for(int i=index;i<input.size();i++)
    {
        subset.push_back(input[i]);
        
        backtrackingutils(input,out,subset,i+1);
        subset.pop_back();
    }
}
vector<vector<int>> subset_backtracking(vector<int> input )
{
    vector<vector<int>>out;
    vector<int>subset;
    backtrackingutils(input,out,subset,0);
    return out;
}
int main()
{
    vector<int> input ={1,2,3};
    vector<vector<int>>out=subset_backtracking(input);
    for(int i=0;i<out.size();i++)
    {
        for(int j=0;j<out[i].size();j++)
        {
            cout<<out[i][j]<< " ";
        }
    }

    return 0;
}
