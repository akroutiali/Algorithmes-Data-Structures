#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
time Complexity O(n^2)
spacecomplexity O(1)
*/

vector<int> insertionSort(vector<int> vec)
{
 
 for(int i=1;i<vec.size();i++)
 {
     int j=i;
     while(j>0)
     {
         if(vec[j]<vec[j-1])
         swap(vec[j],vec[j-1]);
        j--;
     }
 }
    return vec;
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
    vector<int> vec={17,1,15,2,9,6,8,10};
    vector<int> sortedVector=insertionSort(vec);
    print(sortedVector);
    return 0;
}
