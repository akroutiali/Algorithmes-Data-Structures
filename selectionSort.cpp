#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
time Complexity O(n^2)
spacecomplexity O(1)
*/

vector<int> selectionSort(vector<int> vec)
{

    int start =0;
    while(start<vec.size())
    {
        int minindex=start;
        for(int i=start;i<vec.size();i++)
        {
            if(vec[minindex]>vec[i])
                minindex=i;
        }
        swap(vec[start],vec[minindex]);
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
    vector<int> sortedVector=selectionSort(vec);
    print(sortedVector);
    return 0;
}
