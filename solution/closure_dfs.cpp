#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod = 1e9 + 7;


int n;
int e;
int closure[1005][1005];
vector<vector<int>> graph(1005);


void dfs(int curr,int src)
{

    closure[src][curr]=1;

    for(auto child:graph[curr])
    {
        if(closure[src][child]==0)
        {
            dfs(child,src);
        }
    }
}
void solve()
{

    cout<<"Enter the number of node : ";
    cin>>n;

    cout<<"Enter the number of edges : ";
    cin>>e;

    int a,b;

    for (int i = 0; i < e; i++)
    {
        cin>>a>>b;

        graph[a].push_back(b);


    }

    memset(closure,0,sizeof(closure));

    for(int i=0;i<n;i++)
    {

        dfs(i,i);
    }
}

int main()
{

    int t=1;

    while(t)
    {
        solve();

        cout<<"\n****************** Reachability matrix ********************\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout<<closure[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"\n***********************************************************\n";
        cout<<"\nEnter the number of queries to check if v can reach u : ";
        int q;  cin>>q;
        while(q--){
            cout<<"Enter the pair (v,u) to check if node v can reach node u : ";
            int v,u;
            cin>>v>>u;
            if(closure[v][u] == 1)
                cout<<"Yes, "<<v<<" can reach "<< u <<" \n";
            else
                cout<<"No, "<<v<<" cannot reach "<< u <<" \n";
        }

        --t;
    }

    return 0;
}
