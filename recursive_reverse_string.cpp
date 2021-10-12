#include <iostream>

using namespace std;

/*reverse string 
    
Average time complexity	O( n)
Space complexity	O(1)
    
*/

void reverse(string &s,int i=0)
{
    int n=s.length();
    if (i==n/2)
    return;
    
    swap(s[i],s[n-i-1]);
    reverse(s,i+1);
}
int main()
{
    string s="akrouti";
    reverse(s);
    cout<<"reverse string ="<<s<<endl;

    return 0;
}
