#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod = 1e9 + 7;


int n;
int e;
int closure[1005][1005];
int graph[1005][1005];
int cnt;

void solve()
{
    int a,b;

    memset(graph,0,sizeof(graph));
    memset(closure,0,sizeof(closure));

    for (int i = 0; i < e; i++){
        cin>>a>>b;
        graph[a][b]=1;
        closure[a][b]=1;
    }
    for (int i = 0; i < n; i++){
        closure[i][i]=1;
    }

    for (int k = 0; k < n; k++){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                closure[i][j]=closure[i][j] || (closure[i][k]&&closure[k][j]);
                cnt++;
            }
        }
    }

}

int main()
{

    freopen("input_testcase.txt","r",stdin);
    ofstream outF("output_flloyd.txt");
    freopen("time_comp_graph_flloyd.csv","w",stdout);
    int t;
    cin>>t;
    int x = 1;
    while(x<=t)
    {
        n =0 ;e = 0;
        cin>>n>>e;
        cnt = 0;
        solve();

        cout<<n<<","<<cnt<<"\n";

        outF<<"\n*************** Reachability matrix - "<<x<<" *****************\n";
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                outF<<closure[i][j]<<" ";
            }
            outF<<"\n";
        }
        outF<<"***********************************************************\n";
        x++;
    }
    fclose(stdout);
    fclose(stdin);
    outF.close();

    return 0;
}
