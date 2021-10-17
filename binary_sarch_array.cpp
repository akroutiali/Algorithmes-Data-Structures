#include <iostream>

using namespace std;


int binary_search(int tab [],int start,int end,int target)
{
    if(start>end)
    return -1;
    int mid=(end-start)/2;
    if(target==tab[mid])
    return mid;
    else if(target>tab[mid])
    binary_search(tab,mid+1,end,target);
    else if (target<tab[mid])
    binary_search(tab,start,mid-1,target);
}

int main()
{
    int tab []={1,10,12,45,50,80,90};
    cout<<binary_search(tab,0,7,45)<<endl;
    cout<<tab[4]<<endl;

    return 0;
}
