#include<bits/stdc++.h>
using namespace std;

#define RUN 100

// Define the maximum number of vertices of the graph
#define MAX_VERTICES 200
// Define the maximum number of edges
#define MAX_EDGES 2000

int main()
{
	set<pair<int, int>> container;
	set<pair<int, int>>::iterator it;

	freopen ("input_testcase.txt", "w", stdout);
	//For random values every time
	srand(time(NULL));

	int NUM; // Number of Vertices
	int NUMEDGE; // Number of Edges

	cout<<RUN<<'\n';
	for (int i=1; i<=RUN; i++)
	{
		NUM = 20 + rand() % MAX_VERTICES;
		NUMEDGE = 10 + rand() % MAX_EDGES;

		while (NUMEDGE > NUM*(NUM-1)/2)
				NUMEDGE = 20 + rand() % MAX_EDGES;

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

	}
	// Uncomment the below line to store
	// the test data in a file
	fclose(stdout);
	return(0);
}
