#include <iostream>
#include <vector>
using namespace std;

/*

"c a"  "a b"

the longestsubsequence is calculating as below : 
we divide the problem into subproblem 
if(s[i]==s[j])
return 1+recursive(i-1,j-1);
else
return recursive(i-1,j),recursive(i,j-1);
*/

int longestsubq(string s1,string s2,int i,int j)
{
    if(i<0 || j<0)
    {
        return 0;
    }
    if(s1[i]==s2[j])
    return 1+longestsubq(s1,s2,i-1,j-1);
    else
    return max(longestsubq(s1,s2,i,j-1),longestsubq(s1,s2,i-1,j));
}
int main()
{
   string s1="bad";
   string s2="abd";
   int n=s1.size()-1;
   int m=s2.size()-1;
   cout<<"longest=="<<longestsubq(s1,s2,n,m);
    return 0;
}
