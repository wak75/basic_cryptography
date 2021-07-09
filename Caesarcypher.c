#include<cs50.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

void cypher(string txt, int num);
int check(string key);

int main(int argc, string argv[])
{
    int flag=0;
    if(argc!=2)
    {
        printf("./ceasar key\n");
        return 1;
    }
    else 
    {
        flag =check(argv[1]);
        
        
        if(flag==0)
        {
            printf("./ceasar key\n");
        }
        else 
        {
            string text=get_string("plaintext: ");
            cypher(text,flag);
        }
        
    }
    
}

int check(string key)
{
   int n=strlen(key);
   for(int i=0;i<n;i++)
   {
       if(isdigit(key[i])==0)
       {
           return 0;
       }
    }
     
     int x=atoi(key);
          
    return x;
}

void cypher(string text, int flag)
{
    string up="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string low="abcdefghijklmnopqrstuvwxyz";
    int posup;
    int poslow;
    
    int c;
    int n =strlen(text);
    char final[n],x;
    
    for(int i=0;i<n;i++)
    {
        if(isalpha(text[i])!=0)
        {
            if(isupper(text[i])!=0)
            {
                for(int u=0;u<26;u++)
                {
                    if(text[i]==up[u])
                    {
                        posup=u;
                    }
                }
                
                c=(posup+flag)%26;
                //printf("%c",up[c]);
                x=up[c];
                final[i]=x;
            }
            
            else if(islower(text[i])!=0)
            {
                for(int u=0;u<26;u++)
                {
                    if(text[i]==low[u])
                    {
                        posup=u;
                    }
                }
                
                c=(posup+flag)%26;
                //printf("%c",low[c]);
                x=low[c];
                final[i]=x;
            }
        }
        else
        {
            //printf("%c",text[i]);
            x=text[i];
            final[i]=x;
        }
    }
    
    printf("ciphertext: %s\n",final);
}
