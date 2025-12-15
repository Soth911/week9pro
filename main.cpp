#include "func.hpp"

int main(){
    graph p;
    p.addRoute("CAM","SIN",2,100);
    p.addRoute("CAM","SIN",2,100);
    p.addRoute("CAM","KOR",3,150);
    p.addRoute("CAM","TAI",3,150);
    p.addRoute("TAI","USA",4,200);
    p.addRoute("KOR","USA",1,120);
    p.addRoute("SIN","USA",1,120);
    p.printRoute();
    cout<<endl;
    p.reachability("CAM");
    cout<<endl;
    p.reachability("SIN");
    cout<<endl;
    p.pathPrint("CAM","USA");
    cout<<endl;
    cout<<endl;
    p.pathLowPrice("CAM","USA");
    cout<<endl;
    cout<<endl;
    p.pathHighPrice("CAM","USA");
    cout<<endl;
    cout<<endl;
    p.pathLowtime("CAM","USA");
    cout<<endl;
    cout<<endl;
    p.pathHightime("CAM","USA");
    cout<<endl;
    cout<<endl;
    

    return 0;
}