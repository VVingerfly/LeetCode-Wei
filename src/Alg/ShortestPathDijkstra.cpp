
#include "AlgDefs.h"
#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief Dijkstra算法，求v0到其他个点的最短路径
 *
 * Detailed explanation.
 * @note 
 * @see 
 */
class AlgDij
{
public:
#define MAXVEX 20
#ifndef INF
#define INF 65535
#endif // !INF


	typedef struct
	{
		int vexs[MAXVEX];
		int arc[MAXVEX][MAXVEX];
		int numVertexes, numEdges;
	}MGraph;

	typedef int Patharc[MAXVEX];        /* 用于存储最短路径下标的数组 */
	typedef int ShortPathTable[MAXVEX]; /* 用于存储到各点最短路径的权值和 */

	/*! 
	 * @brief Dijkstra算法，求v0到其他个点的最短路径
	 *
	 * Dijkstra算法，求有向网G的v0顶点到其余顶点v的最短路径P[v]及带权长度D[v]
	 * 
	 * @param G 有向网G
	 * @param v0 起始点
	 * @param P P[v]的值为前驱顶点下标
	 * @param D D[v]表示v0到v的最短路径长度和
	 * @return  
	 * @note  
	 * @see
	*/
	void ShortestPath_Dijkstra(MGraph G, int v0, Patharc *P, ShortPathTable *D)
	{
		int v, w, k, min;
		int final[MAXVEX];  // final[w]=1表示求得顶点v0至vw的最短路径

		// 初始化数据 
		for (v = 0; v < G.numVertexes; v++)    
		{
			final[v] = 0;			 // 全部顶点初始化为未知最短路径状态 
			(*D)[v] = G.arc[v0][v];  // 将与v0点有连线的顶点加上权值 
			(*P)[v] = -1;		     // 初始化路径数组P为-1 
		}
		(*D)[v0] = 0;  // v0至v0路径为0
		final[v0] = 1; // v0至v0不需要求路径

		// 开始主循环，每次求得v0到某个v顶点的最短路径
		for (v = 1; v < G.numVertexes; v++)
		{
			min = INF;    // 当前所知离v0顶点的最近距离
			for (w = 0; w < G.numVertexes; w++) // 寻找离v0最近的顶点
			{
				if (!final[w] && (*D)[w] < min)
				{
					k = w;
					min = (*D)[w];    // w顶点离v0顶点更近
				}
			}
			final[k] = 1;    // 将目前找到的最近的顶点置为1
			for (w = 0; w < G.numVertexes; w++) // 修正当前最短路径及距离
			{
				// 如果经过v顶点的路径比现在这条路径的长度短的话
				if (!final[w] && (min + G.arc[k][w] < (*D)[w]))
				{ 
					// 说明找到了更短的路径，修改D[w]和P[w]
					(*D)[w] = min + G.arc[k][w];  // 修改当前路径长度
					(*P)[w] = k;
				}
			}
		}
	}

	

	/* 构件图 */
	void CreateMGraph(MGraph *G)
	{
		int i, j;

		/* printf("请输入边数和顶点数:"); */
		G->numEdges = 16;
		G->numVertexes = 9;

		for (i = 0; i < G->numVertexes; i++)/* 初始化图 */
		{
			G->vexs[i] = i;
		}

		for (i = 0; i < G->numVertexes; i++)/* 初始化图 */
		{
			for (j = 0; j < G->numVertexes; j++)
			{
				if (i == j)
					G->arc[i][j] = 0;
				else
					G->arc[i][j] = G->arc[j][i] = INF;
			}
		}

		G->arc[0][1] = 1;
		G->arc[0][2] = 5;
		G->arc[1][2] = 3;
		G->arc[1][3] = 7;
		G->arc[1][4] = 5;

		G->arc[2][4] = 1;
		G->arc[2][5] = 7;
		G->arc[3][4] = 2;
		G->arc[3][6] = 3;
		G->arc[4][5] = 3;

		G->arc[4][6] = 6;
		G->arc[4][7] = 9;
		G->arc[5][7] = 5;
		G->arc[6][7] = 2;
		G->arc[6][8] = 7;

		G->arc[7][8] = 4;


		for (i = 0; i < G->numVertexes; i++)
		{
			for (j = i; j < G->numVertexes; j++)
			{
				G->arc[j][i] = G->arc[i][j];
			}
		}

	}

	void runTest()
	{
		int i, j, v0;
		MGraph G;
		Patharc P;
		ShortPathTable D; /* 求某点到其余各点的最短路径 */
		v0 = 0;

		CreateMGraph(&G);

		ShortestPath_Dijkstra(G, v0, &P, &D);

		printf("最短路径倒序如下:\n");
		for (i = 1; i < G.numVertexes; ++i)
		{
			printf("v%d - v%d : ", v0, i);
			j = i;
			while (P[j] != -1)
			{
				printf("%d ", P[j]);
				j = P[j];
			}
			printf("\n");
		}
		printf("\n源点到各顶点的最短路径长度为:\n");
		for (i = 1; i < G.numVertexes; ++i)
			printf("v%d - v%d : %d \n", G.vexs[0], G.vexs[i], D[i]);
	}


	void myDij(const vector<vector<int>> &adjM, int v0, vector<int> &path, vector<int> &dist)
	{
		int vNum = adjM.size();
		int v, w, k, min;
		vector<int> find(vNum, 0);// find[w]=1表示求得顶点v0至vw的最短路径, 全部顶点初始化为未知最短路径状态 

								   // 初始化数据 
		for (v = 0; v < vNum; v++)
		{ 
			dist[v] = adjM[v0][v];   // 将与v0点有连线的顶点加上权值 
			path[v] = -1;		     // 初始化路径数组P为-1 
		}
		dist[v0] = 0;  // v0至v0路径为0
		find[v0] = 1; // v0至v0不需要求路径

		// 开始主循环，每次求得v0到某个v顶点的最短路径
		for (v = 1; v < vNum; v++)
		{
			min = INF;    // 当前所知离v0顶点的最近距离
			for (w = 0; w < vNum; w++) // 寻找离v0最近的顶点
			{
				if (!find[w] && dist[w] < min)
				{
					k = w;
					min = dist[w];    // w顶点离v0顶点更近
				}
			}
			find[k] = 1;    // 将目前找到的最近的顶点置为1
			for (w = 0; w < vNum; w++) // 修正当前最短路径及距离
			{
				// 如果经过v顶点的路径比现在这条路径的长度短的话
				if (!find[w] && (min + adjM[k][w] < dist[w]))
				{
					// 说明找到了更短的路径，修改D[w]和P[w]
					dist[w] = min + adjM[k][w];  // 修改当前路径长度
					path[w] = k;
				}
			}
		}
	}

	void runTest2()
	{
		int vNum = 6;
		vector<vector<int>> adjM(vNum);
		adjM[0] = vector<int>{ INF,INF,  10, INF,  30, 100 };
		adjM[1] = vector<int>{ INF,INF,   5, INF, INF, INF };
		adjM[2] = vector<int>{ INF,INF, INF,  50, INF, INF };
		adjM[3] = vector<int>{ INF,INF, INF, INF, INF,  10 };
		adjM[4] = vector<int>{ INF,INF, INF,  20, INF,  60 };
		adjM[5] = vector<int>{ INF,INF, INF, INF, INF, INF };


		vector<int> path(vNum);
		vector<int> dist(vNum);
		int v0 = 0;
		myDij(adjM, v0, path, dist);

		

		printf("最短路径倒序如下:\n");
		for (int i = 1; i < vNum; ++i)
		{
			printf("v%d - v%d : ", v0, i);
			int j = i;
			while (path[j] != -1)
			{
				printf("%d ", path[j]);
				j = path[j];
			}
			printf("\n");
		}
		printf("\n源点到各顶点的最短路径长度为:\n");
		for (int i = 1; i < vNum; ++i)
			printf("v%d - v%d : %d \n", v0, i, dist[i]);
	}
};


#ifdef RUN_AlgDij
int main()
{
	AlgDij dij;
	//dij.runTest();

	dij.runTest2();
	return 0;
}
#endif