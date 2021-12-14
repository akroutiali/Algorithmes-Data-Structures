#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

/*
4  1 3 4 6 7  target =4
we can use two loops :O(n^n)
otherwise we can use vector to reduce time complexity to O(n)
*/
vector<int> twosum(vector<int>vec,int target)
{
    vector<int> v;
    for(int i=0;i<vec.size();i++)
    {
        if(find(v.begin(),v.end(),target-vec[i])!=v.end())
        {
            return{vec[i],target-vec[i]};
        }
        else
        v.push_back(vec[i]);
    }
    return {};
}
int main()
{
    vector<int> v={1,5,10,2,8,9};
    vector<int>out=twosum(v,15);
    for(int i=0;i<out.size();i++)
    {
        cout<<"vec["<<i<<"]"<<out[i];
    }

    return 0;
}
