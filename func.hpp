#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_set>
#include <queue>

using namespace std;

struct edge{
    string des;
    int time;
    int price;
};

class graph{
    private :
        map<string,vector<edge>> graph;
    public :

        void addRoute(string from,string to,int time,int price){
            bool exist = false;
            for(auto &a:graph[from]){
                if(a.des==to){
                    cout<<"Already exist"<<endl;
                    exist=true;
                    return;
                }
            }
            graph[from].push_back({to,time,price});
            graph[to].push_back({from,time,price});
        }

        void printRoute() {
            cout<<"Routes :"<<endl;
            for (auto &p : graph) {
                cout << p.first << " -> ";
                for (auto &e : p.second) {
                    cout << "[ " << e.des << " : " << e.time <<"h"<< " " << e.price <<"$"<< " ] ";
                }
                cout << endl;
            }
        }
        void reachability(string start) {
            if (graph.find(start) == graph.end()) {
                cout << "Airport " << start << " does not exist" << endl;
                return;
            }
            
            unordered_set<string> visited;
            queue<string> q;
            
            visited.insert(start);
            q.push(start);
            
            cout<<start<<" can reach :"<<endl;
            while(!q.empty()){
                string cur=q.front();
                q.pop();
                cout<<cur<<" ";
                for(auto &p:graph[cur]){
                    if (visited.find(p.des)==visited.end()){
                        visited.insert(p.des);
                        q.push(p.des);

                    }
                }
            }
            cout<<endl;
        }

        void pathPrint(string start,string end){
            unordered_set<string> visited;
            vector<string> path;

            visited.insert(start);
            path.push_back(start);

            cout<<"All Paths From "<<start<<" to "<<end<<endl;

            allpath(start,end,visited,path);
        }

        void allpath(string cur,string last,unordered_set<string>& visited,vector<string>& path){
            if (cur==last){
                cout<<"Route";
                for (auto &p:path){
                    cout<<" -> "<<p;
                }
                cout<<endl;
                return;
            }

            for (auto &p:graph[cur]){
                if (!visited.count(p.des)){
                    visited.insert(p.des);
                    path.push_back(p.des);

                    allpath(p.des,last,visited,path);

                    path.pop_back();
                    visited.erase(p.des);
                }
            }
        }

        

};