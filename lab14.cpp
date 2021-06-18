#include<iostream>
#include<string>
using namespace std;
int minNumber(int i, int j, int k)  //�ж����ϣ��������ĸ�������С  
{
	return i<j?(i<k?i:k):(j<k?j:k);
}
//����С�༭���� 
int MinDistance(string strX, string strY){ 
	int len1=strX.size();  //��ȡ�����ַ������� 
	int len2=strY.size();
	int **s=new int *[len1];
	for (int i=0;i<=len1;i++){  //���ݳ��ȶ����ʼ������ 
		s[i]=new int[len2];
	}
	for (int i=0;i<=len1;i++){  //����ȡ����һ���ַ�����ÿ����ĸ��Ϊ�������� 
		s[i][0]=i;
	}
	for (int j=1;j<len2;j++){  //����ȡ���ڶ����ַ�����ÿ����ĸ��Ϊ������� 
		s[0][j]=j;
	}
	for (int i=1;i<=len1;i++){
		for (int j=1;j<=len2;j++){
			if (strX[i-1]==strY[j-1]){  //����һ���ַ�����i���ͺ͵ڶ����ַ�����j��ȡ�����бȽϣ���������ȡ��λ���Ͻǵ�ֵ 
				s[i][j]=s[i-1][j-1];
			}
			else{
				s[i][j]=minNumber(s[i][j-1],s[i-1][j],s[i-1][j-1])+1;  //�������ͬһ����ĸ�������ϣ�����ȡ��С��Ȼ���һ 
			}
		}	
	}	
	int res=s[len1-1][len2-1];
	for (int i=0;i<=len1;i++){
		delete[]s[i];
	}
	delete[]s;
	return res;
}

int main(){
	string X,Y;
	cout<<"������Դ�ַ���"<<endl;
	cin>>X;
	cout<<"������Ŀ���ַ���"<<endl;
	cin>>Y;
	cout<<"��С��������Ϊ��"<< MinDistance(X,Y) << endl;
	return 0;
}
