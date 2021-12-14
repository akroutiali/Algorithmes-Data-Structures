#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

/*
4  1 3 4 6 7  
find min used divide and conquor algorithme 
4 5 6 7 8 9
*/

/*Solution Description : 

using divide and conquor to determine the min and the max of the array : 

base case 1 :if the array size is equal to 1 
base case 2 : if the array size is equal to 2

divide :m= (start+end)/2 
conquor:  
  min=minmax(array,start,m)
  max=minmax(array,m+1,end)

combine :
now we find the overall from both the max and the min by comparing the max and the min for both half


time complexity :O(n)
space Complexity : O(logn)
*/
vector<int>  minmax(vector<int>vec,int start,int end)
{
    int min,max;
    if(start ==end)
    {
        min=vec[start];
        max=vec[start];
        
    }
    else if(start+1==end)
    {
        if(vec[end]>vec[start])
        {
            min=vec[start];
            max=vec[end];
        }
        else
        {
            min=vec[end];
            max=vec[start];
        }
    }
    else
    {
        int mid=(start+end)/2;
        vector<int>minmaxl=minmax(vec,start,mid);
        vector<int>minmaxr=minmax(vec,mid+1,end);
        if(minmaxl[0]>minmaxr[0])
        min=minmaxr[0];
        else
        min=minmaxl[0];
        if(minmaxr[1]>minmaxl[1])
        max=minmaxr[1];
        else
        max=minmaxl[1];
        
    }

    
    return {min,max};
}
/*

     20 5 10 2 8 9 


     20 5 10      2 8 9     min 5 max=10  min=2 max=9  ===>min 2 max=10 

     20 5    10   2 8    9

*/
int main()
{
    vector<int> v={20,5,10,2,8,9};
    vector<int>out=minmax(v,0,5);
    
    cout<<"min="<<out[0]<<endl;
    cout<<"max="<<out[1]<<endl;
    

    return 0;
}
