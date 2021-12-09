#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
time Complexity O(n^2)
spacecomplexity O(1)
*/

vector<int> bubbleSort(vector<int> vec)
{
    int start=0;
    while(start <vec.size())
    {
        for(int i=0;i<vec.size()-1-start;i++)
        {
            if(vec[i]>vec[i+1])
            swap(vec[i],vec[i+1]);
        }
        start++;
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
    vector<int> sortedVector=bubbleSort(vec);
    print(sortedVector);
    return 0;
}
