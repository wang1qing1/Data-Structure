#include"GRAPH.h"
int main()
{
	char vexs[] = "ABCDE";
	int visited[5] = { 0 };
	int vexsNum = sizeof(vexs) / sizeof(char)-1;
	Graph*G=InitGraph(vexsNum);
	//±ßÂ·Í¼
	int arcs[5][5] =
	{
		0,1,1,1,0,
		1,0,1,1,1,
		1,1,0,0,0,
		1,1,0,0,1,
		0,1,0,1,0
	}; 

	CreateGraph(G, vexs,arcs);
	BFS(G, visited, 0);
	return 0;
}