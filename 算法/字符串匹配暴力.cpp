#include<iostream>
#include<string>
using namespace std;

int BF(string s,string t,int pos)
{
	int i=pos,j=1,sum=0;
	int slen=s.length();
	int tlen=t.length();
	while(i<=slen&&j<=tlen)
    {
        sum++;
        if(s[i-1]==t[j-1]) //�����ȣ�������ȽϺ�����ַ�
		{
			i++;
			j++;
		}
		else
		{
			i=i-j+2; //i���˵���һ�ֿ�ʼ�Ƚϵ���һ���ַ�
			j=1;  //j���˵���1���ַ�
		}
    }
	cout<<"һ���Ƚ���"<<sum<<"��"<<endl;
	if (j>tlen) // ƥ��ɹ�
		return i-tlen;
	else
		return 0;
}

int main()
{
	string s,t;
	int pos;
	cin>>s>>t>>pos;
	cout<<BF(s,t,pos)<<endl;
	return 0;
 } 
