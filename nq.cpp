#include<iostream>
#include<vector>
#include<chrono>
#include<algorithm>
using namespace std::chrono;
using namespace std;
std::vector<bool>col(1000,false),dia1(1000,false),dia2(1000,false);
int count1=0;
void queen(int y,int grid,int nq){
    if(y==nq){
        ++count1;
        return;
    }
    for(int i=0;i<grid;i++){
        if(col[i] || dia1[y+i] || dia2[i-y+grid-1])
        continue;
        col[i]=dia1[i+y]=dia2[i-y+grid-1]=true;
        queen(y+1,grid,nq);
        col[i]=dia1[i+y]=dia2[i-y+grid-1]=false;
        
    }
}
int main(){
    auto starttime=high_resolution_clock::now();
    int grid;
    std::cout<<"Enter the grid size"<<std::endl;
    std::cin>>grid;
    int nq;
    std::cin>>nq;
    queen(0,grid,nq);
    std::cout<<count1<<std::endl;
    auto stoptime=high_resolution_clock::now();

    auto duration=duration_cast<microseconds>(stoptime-starttime);
    
    std::cout<<"Seconds "<<duration.count()/1000000<<std::endl;

}