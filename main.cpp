#include "func.hpp"

int main(){
    graph p;
    p.addRoute("A","B",2,100);
    p.addRoute("A","B",2,100);
    p.addRoute("A","C",3,150);
    p.addRoute("A","E",3,150);
    p.addRoute("E","D",4,200);
    p.addRoute("C","D",1,120);
    p.addRoute("B","D",1,120);
    p.printRoute();
    cout<<endl;
    p.reachability("A");
    cout<<endl;
    p.reachability("B");
    cout<<endl;
    p.pathPrint("A","D");
    cout<<endl;
    p.pathLowPrice("A","D");
    cout<<endl;
    p.pathHighPrice("A","D");
    cout<<endl;
    p.pathLowtime("A","D");
    cout<<endl;
    p.pathHightime("A","D");
    cout<<endl;
    

    return 0;
}