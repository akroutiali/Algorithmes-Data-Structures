
#include <iostream>
#include<vector>
#include<cmath>

using namespace std;
/*
Alogorithme : 
1 2 3 
number of combination equal 2^n =8

1 2 3 
0 0 0
1 0 0  i & 1<<j => result =1 
0 1 0
1 1 0
. . .
using bitmask :we can iterate all combination and check wether we must add number or not
time complexity O(N*2^n)
space complexity O(1)
*/
vector<vector<int>> subset_iterative(vector<int>input)
{
    int count=pow(input.size(),2)-1;
    vector<int> subset;
    vector<vector<int>>out;
    for(int i=0;i<count;i++)
    {
        subset={};
        for(int j=0;j<input.size();j++)
        {
            if(i & (1<<j))
            {
                subset.push_back(input[j]);
            }
        }
        out.push_back(subset);
    }
    return out;
}
 void subset(vector<int> input)
 {
     int i=0;
     vector<int> mask= vector<int>(3);
     while(true)
     {
        for(int j=0;j<input.size();j++)
        {
        mask[j]=i &(1<<j);
        //cout<<"mask j"<<mask[j]<<endl;
        }
         cout<<"set == "<<endl;
         for(int k=0;k<input.size();k++)
         {   
             if(mask[k]&(1<<k))
             {
                 cout<<input[k]<< " ";
             }
         }

        i++;
        if(i==8)
        break;
     }
 }
int main()
{
    vector<int> input ={1,2,3};
    vector<vector<int>>out=subset_iterative(input);
    for(int i=0;i<out.size();i++)
    {
        for(int j=0;j<out[i].size();j++)
        {
            cout<<out[i][j]<< " ";
        }
    }

    return 0;
}
