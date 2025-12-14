#include "func.hpp"

int main(){
    graph p;
    p.addRoute("PHN","SIN",2,100);
    p.addRoute("PHN","SIN",2,100);
    p.addRoute("PHN","ICN",3,150);
    p.addRoute("PHN","TPE",3,150);
    p.addRoute("TPE","USA",4,200);
    p.addRoute("ICN","USA",1,120);
    p.addRoute("SIN","USA",1,120);
    p.printRoute();
    cout<<endl;
    p.reachability("PHN");
    cout<<endl;
    p.reachability("SIN");
    cout<<endl;
    p.pathPrint("PHN","USA");
    cout<<endl;
    cout<<endl;
    p.pathLowPrice("PHN","USA");
    cout<<endl;
    cout<<endl;
    p.pathHighPrice("PHN","USA");
    cout<<endl;
    cout<<endl;
    p.pathLowtime("PHN","USA");
    cout<<endl;
    cout<<endl;
    p.pathHightime("PHN","USA");
    cout<<endl;
    cout<<endl;
    

    return 0;
}