#include <iostream>
#include <time.h>
using namespace std;


static void staticArray(){
    static int staticArray[100000];
}

void stackArray(){
    int stackArray[100000];
}

void heapArray(){
    int *heapArray = new int [100000];
}

int main() {
    int i =0;
    clock_t start,end;
    start = clock();
    while(i<300000){
        staticArray();
        i++;}
    end = clock();
    cout<<"static array output time"<<(double)(end-start)/CLOCKS_PER_SEC<<"\n";
    
    
    i = 0;
    start = clock();
    while(i<300000){
        stackArray();
        i++;}
    end = clock();
    cout<<"stack array output time"<<(double)(end-start)/CLOCKS_PER_SEC<<"\n";
    
    
    i = 0;
    start = clock();
    while(i<300000){
        heapArray();
        i++;}
    end = clock();
    cout<<"heap array output time"<<(double)(end-start)/CLOCKS_PER_SEC<<"\n";
    
    
    
    return 0;
   
    
}




