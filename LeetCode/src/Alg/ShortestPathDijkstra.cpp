
#include "AlgDefs.h"
#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief Dijkstra�㷨����v0��������������·��
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

	typedef int Patharc[MAXVEX];        /* ���ڴ洢���·���±������ */
	typedef int ShortPathTable[MAXVEX]; /* ���ڴ洢���������·����Ȩֵ�� */

	/*! 
	 * @brief Dijkstra�㷨����v0��������������·��
	 *
	 * Dijkstra�㷨����������G��v0���㵽���ඥ��v�����·��P[v]����Ȩ����D[v]
	 * 
	 * @param G ������G
	 * @param v0 ��ʼ��
	 * @param P P[v]��ֵΪǰ�������±�
	 * @param D D[v]��ʾv0��v�����·�����Ⱥ�
	 * @return  
	 * @note  
	 * @see
	*/
	void ShortestPath_Dijkstra(MGraph G, int v0, Patharc *P, ShortPathTable *D)
	{
		int v, w, k, min;
		int final[MAXVEX];  // final[w]=1��ʾ��ö���v0��vw�����·��

		// ��ʼ������ 
		for (v = 0; v < G.numVertexes; v++)    
		{
			final[v] = 0;			 // ȫ�������ʼ��Ϊδ֪���·��״̬ 
			(*D)[v] = G.arc[v0][v];  // ����v0�������ߵĶ������Ȩֵ 
			(*P)[v] = -1;		     // ��ʼ��·������PΪ-1 
		}
		(*D)[v0] = 0;  // v0��v0·��Ϊ0
		final[v0] = 1; // v0��v0����Ҫ��·��

		// ��ʼ��ѭ����ÿ�����v0��ĳ��v��������·��
		for (v = 1; v < G.numVertexes; v++)
		{
			min = INF;    // ��ǰ��֪��v0������������
			for (w = 0; w < G.numVertexes; w++) // Ѱ����v0����Ķ���
			{
				if (!final[w] && (*D)[w] < min)
				{
					k = w;
					min = (*D)[w];    // w������v0�������
				}
			}
			final[k] = 1;    // ��Ŀǰ�ҵ�������Ķ�����Ϊ1
			for (w = 0; w < G.numVertexes; w++) // ������ǰ���·��������
			{
				// �������v�����·������������·���ĳ��ȶ̵Ļ�
				if (!final[w] && (min + G.arc[k][w] < (*D)[w]))
				{ 
					// ˵���ҵ��˸��̵�·�����޸�D[w]��P[w]
					(*D)[w] = min + G.arc[k][w];  // �޸ĵ�ǰ·������
					(*P)[w] = k;
				}
			}
		}
	}

	

	/* ����ͼ */
	void CreateMGraph(MGraph *G)
	{
		int i, j;

		/* printf("����������Ͷ�����:"); */
		G->numEdges = 16;
		G->numVertexes = 9;

		for (i = 0; i < G->numVertexes; i++)/* ��ʼ��ͼ */
		{
			G->vexs[i] = i;
		}

		for (i = 0; i < G->numVertexes; i++)/* ��ʼ��ͼ */
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
		ShortPathTable D; /* ��ĳ�㵽�����������·�� */
		v0 = 0;

		CreateMGraph(&G);

		ShortestPath_Dijkstra(G, v0, &P, &D);

		printf("���·����������:\n");
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
		printf("\nԴ�㵽����������·������Ϊ:\n");
		for (i = 1; i < G.numVertexes; ++i)
			printf("v%d - v%d : %d \n", G.vexs[0], G.vexs[i], D[i]);
	}


	void myDij(const vector<vector<int>> &adjM, int v0, vector<int> &path, vector<int> &dist)
	{
		int vNum = adjM.size();
		int v, w, k, min;
		vector<int> find(vNum, 0);// find[w]=1��ʾ��ö���v0��vw�����·��, ȫ�������ʼ��Ϊδ֪���·��״̬ 

								   // ��ʼ������ 
		for (v = 0; v < vNum; v++)
		{ 
			dist[v] = adjM[v0][v];   // ����v0�������ߵĶ������Ȩֵ 
			path[v] = -1;		     // ��ʼ��·������PΪ-1 
		}
		dist[v0] = 0;  // v0��v0·��Ϊ0
		find[v0] = 1; // v0��v0����Ҫ��·��

		// ��ʼ��ѭ����ÿ�����v0��ĳ��v��������·��
		for (v = 1; v < vNum; v++)
		{
			min = INF;    // ��ǰ��֪��v0������������
			for (w = 0; w < vNum; w++) // Ѱ����v0����Ķ���
			{
				if (!find[w] && dist[w] < min)
				{
					k = w;
					min = dist[w];    // w������v0�������
				}
			}
			find[k] = 1;    // ��Ŀǰ�ҵ�������Ķ�����Ϊ1
			for (w = 0; w < vNum; w++) // ������ǰ���·��������
			{
				// �������v�����·������������·���ĳ��ȶ̵Ļ�
				if (!find[w] && (min + adjM[k][w] < dist[w]))
				{
					// ˵���ҵ��˸��̵�·�����޸�D[w]��P[w]
					dist[w] = min + adjM[k][w];  // �޸ĵ�ǰ·������
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

		

		printf("���·����������:\n");
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
		printf("\nԴ�㵽����������·������Ϊ:\n");
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