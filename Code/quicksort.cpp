#include<bits/stdc++.h>
#include <iostream>
#include <chrono>
#include <thread>
    using std::cout;
    using std::endl;
    using namespace std::chrono_literals;
void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void print_array(int* array,int size){

    for(int i=0; i<size;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;   
}
int partition(int* array, int startpoint, int endpoint){
    int pivot=array[startpoint];
    int lp=startpoint;
    int rp=endpoint;
    cout<<"LP początkowe jest równe "<<lp<<endl;
    cout<<"RP początkowe jest równe "<<rp<<endl;

    while(true){
        while(array[lp]<=pivot){
            lp++;
            //std::this_thread::sleep_for(100ms);
            cout<<"LP jest równy "<<lp<<endl;
            if(lp==endpoint){
                break;
            }
        }
        while(pivot<array[rp]){
            rp--;
            //std::this_thread::sleep_for(100ms);
            cout<<"RP jest równy "<<rp<<endl;
            if(rp==startpoint){
                break;
            }
        }
        if(lp>rp){break;}
        else{
        //std::this_thread::sleep_for(100ms);
        cout<<"Tablica po zmianie lp i rp"<<endl;
        swap(&array[lp], &array[rp]);
        }
    }
    //std::this_thread::sleep_for(100ms);
    cout<<"Tablica po zmianie rp i pivota"<<endl;
    swap(&array[startpoint],&array[rp]);
    return rp;
}
void quicksort(int* array,int startpoint,int endpoint){
    int p;
    if(startpoint<endpoint){
        p=partition(array,startpoint,endpoint);
        cout<<"Partition pierwszej połowy"<<endl;
        quicksort(array,startpoint,p-1);
        cout<<"Partition drugiej połowy"<<endl;
        quicksort(array,p+1,endpoint);
    }
}
int main (void){
    int array[]={3,5,4,1,0,22,1,17,0,34,222,1,0,223,74,56,123,54,657,2346,76,0,123,54,3};
    int size=sizeof(array)/sizeof(array[0]);
    cout<<"Array before using quicksort"<<endl;
    print_array(array,size);
    quicksort(array,0,size-1);
    cout<<"Array after using quicksort"<<endl;
    print_array(array,size);
    return 0;
}