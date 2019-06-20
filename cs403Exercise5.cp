#include <iostream>
#include <time.h>
using namespace std;

void byValue(int x){
      x*=2;
}

void byReference(int &x){
    x*=2;
}

void byAddress(int *x){
    *x *=2;
}




int main() {
    clock_t start,end;
    int arr1[100000];
    int arr2[100000];
    int arr3[100000];
    for(int i=0;i<100000;i++){
        arr1[i]=i;
        arr2[i]=i;
        arr3[i]=i;
    }

    start = clock();
    for(int i=0;i<100000;i++){
        byValue(arr1[i]);
    }
    end = clock();
    cout<<"By value, Ending time of clock: "<<(double)(end-start)/CLOCKS_PER_SEC<<"\n";


    start = clock();
    for(int i=0;i<100000;i++){
        byReference(arr2[i]);
    }
    end = clock();
    cout << "By reference, Ending time of clock: " << (double)(end-start)/CLOCKS_PER_SEC<<"\n";

    start = clock();
    for(int i=0;i<100000;i++){
        byAddress(&arr3[i]);
    }
    end = clock();
    cout << "By address, Ending time of clock: " << (double)(end-start)/CLOCKS_PER_SEC<<"\n";

    return 0;

}





