class Solution {
public:

    int myAtoi(string s) {
//check if string is empty
        if(s.empty())
            return 0;
       //2 345 12 123
//remove empty space in the beggining
        int count=0;
        /*
        for(char c:s)
        {
            if(c != ' ')
                s[count++]=c;      
        }

        s[count]=  '\0';
        cout<<"count=="<<count<<endl;
        cout<<"s="<<s<<endl;
        int i=0;
        */
        int i=0;
        s.erase(remove(s.begin(), s.end(), ' '), s.end());
        char flag='+';
        if(s[0]=='-')
        {
            flag='-';
            i++;
        }
    else if(s[i]=='+')
        {
            i++;
        }
        double result=0;
        cout<<s.size()<<endl;
        cout<<i<<endl;
        cout<<s[i]<<endl;
        while(i<s.size() && s[i]<='9' && s[i]>='0')
        {
            cout<<s.size()<<endl;
            cout<<result<<endl;
            result=(result*10)+(s[i]-'0');
            cout<<result<<endl;
            i++;
        }
        if(flag=='-')
            result=-result;
        if(result<INT_MIN)
            return INT_MIN;
        else if(result>INT_MAX)
            return INT_MAX;
        return (int)result;
        
    }
};
