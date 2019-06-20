#include <iostream>
#include <time.h>
using namespace std;

void my_fun1();
void my_fun2();
int main(){
    clock_t start,end;
    start = clock();
    for (int i = 0; i < 10000; i++)
    {
        my_fun1();
    }
    end = clock();
    cout << "Using only subscripting, Ending time of clock: " << (double)(end-start)/CLOCKS_PER_SEC<<"\n";
    
    
    start = clock();
    for(int i = 0; i<10000; i++)
    {
        my_fun2();
    }
    end = clock();
    cout << "Using pointers and pointer arithmetic, Ending time of clock: " << (double)(end-start)/CLOCKS_PER_SEC<<"\n";
    
}
void my_fun1(){
        int my_array[500][500] = {0};
        
        for(int i=0; i<500 ; i++){
            for(int j=0; j<500 ; j++){
                my_array[i][j];
            }
        }
        
        return;
    }

void my_fun2(){
        int *arr = (int *)malloc(500 * 500 * sizeof(int));
        for (int i = 0; i <500; i++)
            for (int j = 0; j <500; j++)
                *(arr + i*500 + j);
    }
    







