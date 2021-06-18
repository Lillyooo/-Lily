#include<iostream>
#include<string>
using namespace std;
int minNumber(int i, int j, int k)  //判断左，上，左上中哪个数字最小  
{
	return i<j?(i<k?i:k):(j<k?j:k);
}
//求最小编辑距离 
int MinDistance(string strX, string strY){ 
	int len1=strX.size();  //获取两个字符串长度 
	int len2=strY.size();
	int **s=new int *[len1];
	for (int i=0;i<=len1;i++){  //根据长度定义初始化矩阵 
		s[i]=new int[len2];
	}
	for (int i=0;i<=len1;i++){  //依次取出第一个字符串的每个字母置为矩阵竖列 
		s[i][0]=i;
	}
	for (int j=1;j<len2;j++){  //依次取出第二个字符串的每个字母置为矩阵横列 
		s[0][j]=j;
	}
	for (int i=1;i<=len1;i++){
		for (int j=1;j<=len2;j++){
			if (strX[i-1]==strY[j-1]){  //将第一个字符串第i个和和第二个字符串第j个取出进行比较，如果相等则取该位左上角的值 
				s[i][j]=s[i-1][j-1];
			}
			else{
				s[i][j]=minNumber(s[i][j-1],s[i-1][j],s[i-1][j-1])+1;  //如果不是同一个字母则在左上，左，上取最小，然后加一 
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
	cout<<"请输入源字符串"<<endl;
	cin>>X;
	cout<<"请输入目的字符串"<<endl;
	cin>>Y;
	cout<<"最小操作次数为："<< MinDistance(X,Y) << endl;
	return 0;
}
