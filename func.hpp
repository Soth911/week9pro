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
            for(auto &a:graph[from]){
                if(a.des==to){
                    cout<<"Already exist"<<endl;
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
        
        
        void pathLowPrice(string start,string end){
            unordered_set<string> visited;
            vector<string> path;
            vector<string> bestPath;
            int minPrice ;

            visited.insert(start);
            path.push_back(start);
    
            lowPrice(start, end, visited, path, 0, minPrice, bestPath);
            cout << "Lowest price: "<<"$" << minPrice << endl;
            cout << "Path: ";
            for (auto &p : bestPath) cout << p << " -> ";
            cout << end << endl;
        }

        void lowPrice(string cur, string last, unordered_set<string>& visited, vector<string>& path, int curPathprice, int &minPrice, vector<string> &bestPath){
            if (cur == last){
                if (curPathprice < minPrice){
                    minPrice = curPathprice;
                    bestPath = path;
                }
                return;
            }
        
            for (auto &p : graph[cur]){
    
                if (!visited.count(p.des)){
                    visited.insert(p.des);
                    path.push_back(p.des);
        
                    lowPrice(p.des, last, visited, path, curPathprice + p.price, minPrice, bestPath);
        
                    path.pop_back();
                    visited.erase(p.des);
                    }
                }
        }
        
        void pathHighPrice(string start,string end){
            unordered_set<string> visited;
            vector<string> path;
            vector<string> bestPath;
            int maxPrice=INT_MIN;
    
            visited.insert(start);
            path.push_back(start);
    
            highPrice(start, end, visited, path, 0, maxPrice, bestPath);
            cout << "Highest price: " <<"$"<< maxPrice << endl;
            cout << "Path: ";
            for (auto &p : bestPath) cout << p << " -> ";
            cout << end << endl;
        }
    
        void highPrice(string cur, string last, unordered_set<string>& visited, vector<string>& path, int curPathprice, int &maxPrice, vector<string> &bestPath){
            if (cur == last){
                if (curPathprice > maxPrice){
                    maxPrice = curPathprice;
                    bestPath = path;
                }
                return;
            }
        
            for (auto &p : graph[cur]){
    
                if (!visited.count(p.des)){
                    visited.insert(p.des);
                    path.push_back(p.des);
        
                    highPrice(p.des, last, visited, path, curPathprice + p.price, maxPrice, bestPath);
        
                    path.pop_back();
                    visited.erase(p.des);
                    }
                }
        }
        
            
        void pathLowtime(string start,string end){
            unordered_set<string> visited;
            vector<string> path;
            vector<string> bestPath;
            int minTime;
    
            visited.insert(start);
            path.push_back(start);
    
            lowTime(start, end, visited, path, 0, minTime, bestPath);
            cout << "Lowest time : " << minTime <<"h"<< endl;
            cout << "Path: ";
            for (auto &p : bestPath) cout << p << " -> ";
            cout << end << endl;
        }
    
        void lowTime(string cur, string last, unordered_set<string>& visited, vector<string>& path, int curPathTime, int &mintime, vector<string> &bestPath){
            if (cur == last){
                if (curPathTime < mintime){
                    mintime = curPathTime;
                    bestPath = path;
                }
                return;
            }
        
            for (auto &p : graph[cur]){
                if (!visited.count(p.des)){
                    visited.insert(p.des);
                    path.push_back(p.des);
        
                    lowTime(p.des, last, visited, path, curPathTime + p.time, mintime, bestPath);
        
                    path.pop_back();
                    visited.erase(p.des);
                }
            }
    
        }
        
        void pathHightime(string start,string end){
            unordered_set<string> visited;
            vector<string> path;
            vector<string> bestPath;
            int maxTime=0;
    
            visited.insert(start);
            path.push_back(start);
    
            highTime(start, end, visited, path, 0, maxTime, bestPath);
            cout << "Longest time : " << maxTime<<"h" << endl;
            cout << "Path: ";
            for (auto &p : bestPath) cout << p << " -> ";
            cout << end << endl;
        }
    
        void highTime(string cur, string last, unordered_set<string>& visited, vector<string>& path, int curPathTime, int &maxtime, vector<string> &bestPath){
            if (cur == last){
                if (curPathTime > maxtime){
                    maxtime = curPathTime;
                    bestPath = path;
                }
                return;
            }
        
            for (auto &p : graph[cur]){
                if (!visited.count(p.des)){
                    visited.insert(p.des);
                    path.push_back(p.des);
        
                    highTime(p.des, last, visited, path, curPathTime + p.time, maxtime, bestPath);
        
                    path.pop_back();
                    visited.erase(p.des);
                }
            }
    
        }
};