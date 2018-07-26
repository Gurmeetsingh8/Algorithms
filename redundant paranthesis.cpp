#include<bits/stdc++.h>
using namespace std;
bool isredundant(char ch[])
{
    stack<char>s;
     for(int i=0;ch[i]!='\0';i++)
    {
        char j=ch[i];
        switch(j)
        {
            case '(': s.push(j);
                      break;
            case ')': if(s.top()=='(')
                    return false;
                    else
                    {
                        while(s.top()!='('){
                                s.pop();
                        }
                           s.pop();
                        break;
                    }
            default : s.push(j);

        }

    }
    return true;
}
int main()
{
    char ch[]="(((a+b)+c)";
    cout<<isredundant(ch);

}
