#include<iostream>
#include<queue>
#include<stack>
#include<vector>
using namespace std;

class graph
{
    int no_of_vertices;
    int no_of_edges;
    vector<int>vertices;
    vector<vector<int>>adj_list;
    vector<vector<int>>adj_matrix;

    public:
       graph(){ 
         cout<<"Enter the no of vertices: ";
         cin>>no_of_vertices;
         cout<<"Enter the no of egde :";
         cin>>no_of_edges;
         vertices={};
         adj_list.resize(no_of_vertices);
         for(int i= 0;i< no_of_vertices;i++)
         {
            adj_matrix.push_back(vector<int>(no_of_vertices,0));
         }
         for(int i=0;i< no_of_vertices;i++){
            add_vertex(i);
         }
         for(int i=0;i< no_of_edges;i++){
            cout<<"Enter the edge vertex : ";
            int vertex1,vertex2;
            cin>>vertex1>>vertex2;
            add_edge(vertex1,vertex2);
         }
       }

         void add_vertex(int vertex){
             vertices.push_back(vertex);
         }

         void add_edge(int vertex1 , int vertex2){
            adj_list[vertex1].push_back(vertex2);
            adj_list[vertex2].push_back(vertex1);
            adj_matrix[vertex1][vertex2]=1;
            adj_matrix[vertex2][vertex1]=1;

         }

         void print_adj_list(){
             for(int i=0;i<no_of_vertices;i++){
                  cout<<vertices[i]<<"->" ;
                  for(int j =0;j<adj_list[i].size()-1;j++){
                     cout<<adj_list[i][j]<<"->";
                  }
                  cout<<adj_list[i].back()<<endl;
             }
             
         } 
         void print_adj_matrix(){
           for(int i =0;i< no_of_vertices;i++){
            for(int j =0 ;j<no_of_vertices ;j++){
                cout<<adj_matrix[i][j]<<" ";           
            }
            cout<<endl;
           } 
         }

         void bfs(int start_vertex){
            vector<int>visited(no_of_vertices,0);
            queue<int>q;
             q.push(start_vertex);
             visited[start_vertex]=1;
             

         }

       
};