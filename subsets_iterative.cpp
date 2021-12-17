#include <iostream>
#include <vector>

#include <math.h>
#include <cstddef>
using namespace std;
/*
1  2   3 

*/
 
 /*
 algorithme using bitmasq to resolv this problem 
 retrieve the number of all possibilt 
 2^n-1
 run for loop from the 0 to sum of all possibilty 
 iterate the array and apply this masq 
 
 counter & (j<<1)
 
 
 */
 /*
 count =0 
 *count=1 
 j=0
   
 *//*
 void subset(vector<int> input)
 {
     int count=pow(2,input.size())-1;
     cout<<"count=="<<count<<endl;
     for(int i=0;i<=count;i++)
     {   cout<<"set======"<<endl;
         for(int j=0;j<input.size();j++)
         {
            // cout<<"j"<<(1<<j)<<endl;
             if(i & (1<<j))
             {
                 cout<<input[j]<<" ";
             }
         }
     }
     
 }*/
 /*
 time complexity O(n*2^n)
 space complexity O(1)
 */
 
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
    vector<int> input={1,2,3};
    subset(input);
    return 0;
}
