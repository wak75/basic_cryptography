#include<iostream>
#include<ctype.h>
#include<string.h>

using namespace std;

int keycheck(char x[]);
int actual_hiding(char a[]);


int main(int argc, char* argv[])
{
	if(argc<2)
	{
		cout<<"the script needs a key!!"<<endl;
		return 1;
	}
	else if(argc>2)
	{
		cout<<"The script needs only one key!!!"<<endl;
		return 1;
	}

	else
	{
		string en_key=argv[1];
		char in_key[27];
		//char lower_key[27];
		
		int in_len=strlen(argv[1]);
		if(in_len!=26)
		{
			cout<<"The key must be of 26 digits!!!"<<endl;
			return 1;
		}
		else
		{

			//cout<<"key accepted"<<endl;
			strcpy(in_key,en_key.c_str());

			for(int i=0;i<27;i++)
			{
				in_key[i]=tolower(in_key[i]);
			}	

			
			//printf("%s\n",in_key);

			keycheck(in_key);
		}

		
	}
}


int keycheck(char x[])
{
	
	char key_cpy[27];
	strcpy(key_cpy,x);


	int count=0;
	char alpha[27]={"abcdefghijklmnopqrstuvwxyz"};
	char temp;
	for (int i=0;i<25;i++)
	{
		for(int j=i+1;j<26;j++)
		{
			if(x[i]>x[j])
			{
				temp=x[j];
				x[j]=x[i];
				x[i]=temp;
			}
		}
		
	}

	//printf("%s\n",x);
	//printf("%s\n",key_cpy);

		
	for(int i=0;i<26;i++)
	{
		if(alpha[i]==x[i])
		{
			count++;		
		}
	}
	
	if(count==26)
	{
		//cout<<"the key is perfect!!!"<<endl;
		actual_hiding(key_cpy);
	}
	else{
		cout<<"please make sure that there is no "<<endl;
		cout<<"1. repeating characters in the key"<<endl;
		cout<<"2. there is no spaceial characters in the key"<<endl;
		cout<<"3. there is no number in the key"<<endl;
		return 1;
	}

	return 0;
	
}

int actual_hiding(char a[])
{

	
	char text[100];
	cout<<"enter the text you want to convert:  ";
	cin.getline(text,100);
	int n=strlen(text);

	char alpha[27]={"abcdefghijklmnopqrstuvwxyz"};

	for(int i=0;i<n;i++)
	{
		text[i]=tolower(text[i]);
	}

	cout<<endl<<text<<endl;

	int key_code[27];
	for(int i=0;i<26;i++)
	{
		key_code[i]=a[i];
	}

	//int ascitxt[n];
	int flag;
	char final[n];
	for(int i=0;i<n;i++)
	{
		
		for(int j=0;j<26;j++)
		{
			if(text[i]==alpha[j])
			{
				cout<<a[j];
				flag=1;	
			}				
		
		}	
		if(flag==0)
		{
			cout<<text[i];
		}

		flag=0;

	}	
	return 0;
	
}
