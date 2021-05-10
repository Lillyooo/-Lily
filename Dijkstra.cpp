#include <iostream>
#include <cstdio>
#include <string.h>
#include <cstdio>

#define min(x,y) x<y?x:y
#define MaxN 1000
#define INF 9999999

using namespace std;

int dis[MaxN],g[MaxN][MaxN],vexnum,arcnum,v1,v2,w;  //dis[]:dp��̬���� ��������1������·��
bool v[MaxN];

void Dijkstra() {
    for(int i=1; i<=vexnum; ++i) dis[i]=INF;
    dis[1]=0;
    memset(v,0,sizeof(v));
    for(int i=1; i<=vexnum; i++) {
        int mark=-1,mindis=INF;
        for(int j=1; j<=vexnum; j++)
            if(!v[j] && dis[j]<mindis) {
                mindis=dis[j];              //mindis�����������
                mark=j;             //�ҵ��ӵ�ǰ���������ɵ��ĵ�
            }
        v[mark]=1;          //�ҵ�����һ�����ȷ�����ҵ����·������Ϊ���߹�
        for(int j=1; j<=vexnum; j++)
            if(!v[j])
                dis[j]=min(dis[j],dis[mark]+g[mark][j]);  //���ҵ��ĵ������ˢ�������㵽�õ�������룬ȡ�����1�㵽��ǰ�����Ŀ���ľ����Сֵ
    }
}

int main() {
    cin>>vexnum>>arcnum;        //vexnum:�����ܸ���  arcnum:·������
    for(int i=1; i<=vexnum; i++)
        for(int j=1; j<=vexnum; j++)
            g[i][j]=INF;
    for(int i=1; i<=arcnum; i++) {     //���ڽӾ��󱣴��ͼ!
        cin>>v1>>v2>>w;
        g[v1][v2]=w;
        g[v2][v1]=w;
    }
    Dijkstra();
    for(int i=1; i<=vexnum; i++)
        cout<<i<<" "<<dis[i]<<endl;
    return 0;
}

