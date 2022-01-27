class Solution {
public:
    int longestPalindromeSubseq(string s) {
    return longestsubsequence(s,0,s.size()-1);
        
    }
    int longestsubsequence(string s,int left,int right)
    {
        //basic case string contains one character
        
        if(left==right)
           return 1;
        
        //basic case string contais 2 character and those character are the same
        
        if(s[left]==s[right] && right==left+1)
            return 2;
        
        if(s[left]==s[right])
            return longestsubsequence(s,left+1,right-1)+2;
        
        return max(longestsubsequence(s,left+1,right),longestsubsequence(s,left,right-1));
            
    }
};
