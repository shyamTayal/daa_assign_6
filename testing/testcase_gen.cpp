#include<bits/stdc++.h>
using namespace std;

#define RUN 3

// Define the maximum number of vertices of the graph
#define MAX_VERTICES 20
// Define the maximum number of edges
#define MAX_EDGES 1000

int main()
{
	set<pair<int, int>> container;
	set<pair<int, int>>::iterator it;

	freopen ("Test_Cases_Directed_Unweighted_Graph.in", "w", stdout);
	//For random values every time
	srand(time(NULL));

	int NUM; // Number of Vertices
	int NUMEDGE; // Number of Edges

	cout<<RUN<<'\n';
	for (int i=1; i<=RUN; i++)
	{
		NUM = 50 + rand() % MAX_VERTICES;			// As given minimum value of N should be atleast 50
		NUMEDGE = 10 + rand() % MAX_EDGES;

		while (NUMEDGE > NUM*(NUM-1)/2)
				NUMEDGE = 50 + rand() % MAX_EDGES;

		// First print the number of vertices and edges
		printf("%d %d\n", NUM, NUMEDGE);

		for (int j=0; j<NUMEDGE; j++)
		{
			int a = rand() % NUM;
			int b = rand() % NUM;
			pair<int, int> p = make_pair(a, b);

			while (container.find(p) != container.end())
			{
				a = rand() % NUM;
				b = rand() % NUM;
				p = make_pair(a, b);
			}
			container.insert(p);
		}

		for (it=container.begin(); it!=container.end(); ++it)
			printf("%d %d\n", it->first, it->second);

		container.clear();
		printf("\n");

	}
	// Uncomment the below line to store
	// the test data in a file
	fclose(stdout);
	return(0);
}
