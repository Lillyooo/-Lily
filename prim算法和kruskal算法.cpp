#include<stdio.h>
#include<stdlib.h>
#define MaxVexNum 50
#define MaxInt 32767
#define MaxEdgeNum 50

typedef int VertexType;
typedef int EdgeType;
typedef struct AMGraph {
	VertexType vexs[MaxVexNum];
	EdgeType arcs[MaxVexNum][MaxVexNum];
	int vexnum, edgenum;
}AMGraph;

void createGraph(AMGraph& g) {
	printf("请输入顶点数:");
	scanf("%d", &g.vexnum);
	printf("\n请输入边数:");
	scanf("%d", &g.edgenum);
 
	for (int i = 0; i < g.vexnum; i++) {
		g.vexs[i] = i;
	}
	for (int i = 0; i < g.vexnum; i++) {
		for (int j = 0; j < g.vexnum; j++) {
			g.arcs[i][j] = MaxInt;
			if (i == j) g.arcs[i][j] = 0;
		}
	}
	printf("请输入边的信息以及边的权值（顶点是0~n-1）\n");
	for (int i = 0; i < g.edgenum; i++) {
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		g.arcs[x][y] = w;
		g.arcs[y][x] = w;
	}
}
void PrintGraph(AMGraph g) {
	printf("邻接矩阵是:\n");
	for (int i = 0; i < g.vexnum; i++) {
		printf("  %d", g.vexs[i]);
	}
	printf("\n");
	for (int i = 0; i < g.vexnum; i++) {
		printf("%d ", g.vexs[i]);
		for (int j = 0; j < g.vexnum; j++) {
			if (g.arcs[i][j] == 32767) {
				printf("8 ");
			}
			else {
				printf("%d  ", g.arcs[i][j]);
			}
		}
		printf("\n");
	}
}



//Prim算法
struct Node    
{
	int adjvex; 
	int lowcost;    
}MinTree[MaxVexNum];

void Prim(AMGraph g, int k) {
	printf("最小路径:\n");
	int n = g.vexnum;
	int i;
	for (i = 0; i < n; i++) {
		if (i != k) { 
			MinTree[i].adjvex = k;
			MinTree[i].lowcost = g.arcs[i][k];
		}
	}
	MinTree[k].lowcost = 0;
	int min, u0, v0, sum = 0;
	for (int i = 0; i < n - 1; i++) {
		min = MaxInt;
		for (int j = 0; j < n; j++) {
			if (MinTree[j].lowcost > 0) {
				if (MinTree[j].lowcost < min) {
					k = j;
					min = MinTree[j].lowcost;
					sum += min;
				}
			}
		}
		u0 = MinTree[k].adjvex;
		v0 = MinTree[k].lowcost;
		printf("[%d,%d]\n", u0, v0);
		MinTree[k].lowcost = 0;
		for (int j = 0; j < n; j++) {
			if (g.arcs[k][j] < MinTree[j].lowcost) {
				MinTree[j].lowcost = g.arcs[k][j];
				MinTree[j].adjvex = g.vexs[k];
			}
		}

	}
	printf("最小路径长度为:%d\n", sum);
}

//Kruskal算法
int GetRoot(int v[], int p) {
	while (p != v[p]) {
		p = v[p];
	}
}
void Kruskal(AMGraph g) {
	int v[g.vexnum];
	for (int i = 0; i < g.vexnum; i++) v[i] = i;
	int sum = 0;

	for (int q = 0; q < g.vexnum - 1; q++) {
		int x, y;
		int  min = MaxInt;
		for (int i = 0; i < g.vexnum; i++) {
			for (int j = 0; j < g.vexnum; j++) {
				if (g.arcs[i][j] < min && g.arcs[i][j]>0 && GetRoot(v, i) != GetRoot(v, j)) {
					min = g.arcs[i][j];
					x = i;
					y = j;

				}
			}
		}
		printf("[%d %d]\n", x, y);
		sum += min;
		g.arcs[x][y] = 0;
		g.arcs[y][x] = 0;
		v[y] = x;
	}
	printf("\n最短路径长度为:%d\n", sum);
}
int main() {
	AMGraph g;
	createGraph(g);
	//PrintGraph(g);
	Prim(g, 0);
	Kruskal(g);
}
