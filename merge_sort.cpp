
#include <iostream>

using namespace std;

/*merge sort 
    
    1 5 4 3 6 9 8 7 
    
    1 5 4 3    6 9 8 7
    
    1 5   4 3      6 9  8 7

    1 5   3 4      6 9  7 8
    
    1 3 4 5        6 7 8 9
    
    1 3 4 5 6 7 8 9 
    
   merge(tab,0,2,4)
m=1  1  5
merge(tab,0,1,1);
    Algorithme :
    
    if l<r :
    -m =l+r/2;
    mergesort(tab,l,m);
    mergesort(tab,m+1,r);
    merge(tab,l,m,r)
    
Average time complexity	O(n*log n)
Space complexity	O(n)
    
    
    
    */
void merge(int tab [],int l ,int m,int r)
{
    int i=l;
    int j=m+1;
    int k=l;
    int arr[r];
    
    while(i<=m && j<=r )
    {
        if(tab[i]<tab[j])
        {
            arr[k]=tab[i];
            i++;
            k++;
        }
        else
        {
            arr[k]=tab[j];
            j++;
            k++;
        }
    }
    while(i<=m)
    {
        arr[k]=tab[i];
        i++;
        k++;
    }
    while(j<=r)
    {
        arr[k]=tab[j];
        j++;
        k++;
    }
    for(int s=l ;s<k;s++)
    {
        tab[s]=arr[s];
    }
        
}
void mergesort(int tab [],int l ,int r)
{
    if(l<r)
    {
        auto m=(r+l)/2;
        mergesort(tab,l,m);
        mergesort(tab,m+1,r);
        merge(tab,l,m,r);
    }
}
int main()
{
    int tab []={1,5,2,4,3,6,9,8};
    int n=sizeof(tab)/sizeof(tab[0]);
    cout<<"n= "<<n<<endl;
    mergesort(tab,0,n-1);
    for(int i =0;i<n;i++)
    {
        cout<<"tab["<<i<<"] ="<<tab[i]<<endl;
    }

    return 0;
}
