#include<iostream>
#include<string>
using namespace std;

int next[1000+5];

void get_next(string t) //��ģʽ��T��next����ֵ
{ 
	int j=1, k=0;
	next[1]=0;
	while (j<t.length()) //ģʽ��t�ĳ���
		if (k==0||t[j-1]==t[k-1])
			next[++j]=++k;
		else
			k=next[k];
	for(int i=1;i<=t.length();i++) 
		cout<<next[i]<<" ";
}

int KMP(string s,string t,int pos)
{
	get_next(t);
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
			j=next[j];  //j���˵�next[j]
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
	cout<<KMP(s,t,pos)<<endl;
	return 0;
 } 
