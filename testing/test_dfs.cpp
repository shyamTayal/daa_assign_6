#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;
#define ll long long int
const ll mod = 1e9 + 7;


int n;
int e;
int closure[1005][1005];
vector<vector<int>> graph(1005);
int cnt;

void dfs(int curr,int src)
{
    closure[src][curr]=1;
    for(auto child:graph[curr]){
        if(closure[src][child]==0){
            dfs(child,src);
        }
    }
}
void solve()
{
    int a,b;
    for (int i = 0; i < e; i++){
        cin>>a>>b;
        graph[a].push_back(b);
    }
    memset(closure,0,sizeof(closure));
    for(int i=0;i<n;i++){
        cnt++;
        dfs(i,i);
    }
}

int main()
{

    freopen("input_testcase.txt","r",stdin);
    ofstream outF("output_dfs.txt");
    freopen("time_comp_graph_dfs.csv","w",stdout);
    int t;
    cin>>t;
    int x = 1;
    while(x<=t)
    {
        n =0 ;e = 0;
        cin>>n>>e;
        cnt = 0;
        solve();

        outF<<"\n*************** Reachability matrix - "<<x<<" *****************\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cnt++;
                outF<<closure[i][j]<<" ";
            }
            outF<<endl;
        }
        outF<<"\n***********************************************************\n";
        x++;
        cout<<n<<","<<cnt<<"\n";
    }
    fclose(stdout);
    fclose(stdin);
    outF.close();

    return 0;
}
