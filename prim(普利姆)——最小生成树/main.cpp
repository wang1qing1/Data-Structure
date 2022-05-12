#include"PRIM.h"
int main()
{
	char vexs[] = "12345";
	int visited[5] = { 0 };
	int vexsNum = strlen(vexs);
	Graph* G = InitGraph(vexsNum);
	int arsc[5][5] =
	{
		0,1,5,MAX,4,
		1,0,3,4,5,
		5,3,MAX,2,5,
		MAX,4,2,0,6,
		4,5,MAX,6,0
	};

	CreatGraph(G, arsc,vexs);
	DFS(G, visited, 0);
	printf("\n");
	Prim(G, 0);

	return 0;
}