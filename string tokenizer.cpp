#include<bits/stdc++.h>
using namespace std;
char* mystrtok(char* str,char delim)
{
    static char* input=NULL;
    if(str!=NULL)
    {
        input=str;
    }
    if(input==NULL)
        return NULL;
    char* output=new char [strlen(input)+1];
    int i;
    for(i=0;input[i]!='\0';i++)
    {
        if(input[i]!=delim)
        {
            output[i]=input[i];
        }
        else
        {
            output[i]='\0';
            input=input+i+1;
            return output;
        }
    }
    output[i]='\0';
    input=NULL;
    return output;
}
int main()
{
    char str[20];
    gets(str);
    puts(str);

    char *p;
   /* p=strtok(str," ");
    while(p!=NULL)
    {
        cout<<p<<endl;
        p=strtok(NULL," ");
    }*/
     p=mystrtok(str,' ');
    while(p!=NULL)
    {
        cout<<p<<endl;
        p=mystrtok(NULL,' ');
    }


}
