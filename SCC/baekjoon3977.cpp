#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
struct _node{
    int id;
    int scc_id;
    vector<int> edge;
};
class SCC_tarjan{
private:
    vector<_node> graph;
    vector<vector<int>> SCC;
    vector<int> SCC_indegree;
    stack<int> st;
    int id,scc_id;
    int N,M;
public:
    SCC_tarjan(){
        std::cin >> N >> M;
        id=1;
        scc_id=0;
        graph.resize(N,{0,-1,});
        set_connect();
    }
    void set_connect(){
        int a,b;
        for(int i=0;i<M;i++){
            std::cin >> a >> b;
            graph[a].edge.push_back(b);
        }
    }
    void start_tarjan(){
        for(int i=0;i<N;i++)
            if(graph[i].id==0)
                tarjanDFS(i);
        SCC_indegree.resize(scc_id,0);
        int tmp;
        for(int i=0;i<N;i++)
            for(int j=0;j<graph[i].edge.size();j++){
                tmp=graph[i].edge[j];
                if(graph[i].scc_id!=graph[tmp].scc_id)
                    SCC_indegree[graph[tmp].scc_id]++;
            }

        int sol=0,sol_num;
        for(int i=0;i<scc_id;i++)
            if(SCC_indegree[i]==0){
                sol++;
                sol_num=i;
            }
        if(sol==1)
            for(int i=0;i<SCC[sol_num].size();i++){
                std::cout << SCC[sol_num][i] <<'\n';
            }
        else
            std::cout << "Confused\n";
        std::cout << '\n';
    }
    int tarjanDFS(int cur){
        st.push(cur);
        graph[cur].id=id++;
        int lowlink= graph[cur].id;
        int tmp;
        for(int i=0;i<graph[cur].edge.size();i++){
            tmp=graph[cur].edge[i];
            if(graph[tmp].scc_id!=-1)
                continue;
            if(graph[tmp].id==0)
                lowlink = min(lowlink,tarjanDFS(tmp));
            else
                lowlink = min(lowlink,graph[tmp].id);
        }
        if(lowlink==graph[cur].id){
            vector<int> scc;
            while(1){
                tmp=st.top();
                st.pop();
                scc.push_back(tmp);
                graph[tmp].scc_id=scc_id;
                if(tmp==cur)
                    break;
            }
            sort(scc.begin(),scc.end());
            SCC.push_back(scc);
            scc_id++;
        }

        return lowlink;
    }


};
int main(){
    int n;
    std::cin >> n;
    for(int i=0;i<n;i++){
        SCC_tarjan scct;
        scct.start_tarjan();
    }
    return 0;
}   