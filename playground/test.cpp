#include<iostream>
#include<vector>
#include<queue>
#define INF 1e9
using namespace std;
 
int main()
{
    int V,E;
    scanf("%d %d", &V ,&E); //����� ������ ������ ������ �Է¹޽��ϴ�. 
    int start;
    scanf("%d",&start);        //�������� �Է¹޽��ϴ�. 
    vector<pair<int,int> > arr[V+1];
    
    for(int i=0;i<E;i++){
        int from,to,val;
        scanf("%d %d %d", &from , &to,&val); //�׷��� ���� �����鿡 ���� ������ �Է¹޽��ϴ�. 
        arr[from].push_back({to,val});
    }
    int dist[V+1];    //�ִܰŸ��� �������ִ� �迭�Դϴ�. 
    fill(dist,dist+V+1,INF);    //���� ���Ѵ�� ���� �ʱ�ȭ�� ���ѵӴϴ�. 
    priority_queue<pair<int,int> > qu;     
    
    qu.push({0,start});    //�켱���� ť�� �������� �־��ݴϴ�. 
    dist[start]=0;    //�������� �ִܰŸ��� �����մϴ�. 
    
    while(!qu.empty()){
        int cost=-qu.top().first;    // cost�� ���� �湮�� ���� dist���� ���մϴ�. 
        int here=qu.top().second;     // here�� �湮�� ���� ��ȣ�� ���մϴ� 
        
        qu.pop();
            
        for(int i=0; i<arr[here].size(); i++){
            int next=arr[here][i].first;
            int nextcost=arr[here][i].second;
            
            if(dist[next] > dist[here] + nextcost){    
                //���� next�� ����� dist�ǰ����� ������ ���� ���ļ� �� ��찡 
                // �Ÿ��� ��ª���� ������ �ְ� ť�� �ֽ��ϴ�. 
                dist[next]=dist[here]+nextcost;
                qu.push({-dist[next],next});
            }
        }
        
    }
    for(int i=1;i<=V;i++){
        printf("%d ", dist[i]);
    }
}