#include <stdio.h>

int main(){
	int D[100][100];
	int i,j,a,b,c,n;
	printf("�����������");
	scanf("%d",&n); 
	printf("������Ȩ�ؾ���\n");
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&D[i][j]);//Ϊ��ʼ�������ֵ 
		}
	}
	
	for(a=0;a<n;a++){ //Floyd�㷨�����·�� 
		for(b=0;b<n;b++){
			if(D[a][b]>0 && D[a][b]<10000){
				for(c=0;c<n;c++){
					if(D[c][a]>0 && D[c][a]<10000){
						D[c][b]=D[c][b]<(D[c][a]+D[a][b])?D[c][b]:(D[c][a]+D[a][b]);
					}
				}
			}
		}
	}
	
	for(i=0;i<n;i++){//���������� 
		for(j=0;j<n;j++){
			if(D[i][j]==10000){
				printf("inf");
			}
			else{
				printf("%-6d",D[i][j]);	
			}
		}
		printf("\n");
	}
	
	return 0; 
}
