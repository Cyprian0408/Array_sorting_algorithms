#include <string.h>
#include <iostream>
using std::cout;
using std::endl; 
void bubble_sort(int* array, int n){
    int pom;
   
    for (int i=0;i<n-1;i++){
        for (int j=0;j<n-i-1;j++){
            if(array[j]>array[j+1]){
                array[j]=array[j]+array[j+1];
                array[j+1]=array[j]-array[j+1];
                array[j]=array[j]-array[j+1];
            }
        }
    }

}
void print_array(int* array, int n){
    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}
int main (int argc, char** argv){
    int array[]={6,1,2,1,7,3,4,9,22,124,124,542,124,0};
    int size=sizeof(array)/sizeof(array[0]);
    bubble_sort(array,size);
    cout<<"Sorted array: \n";
    print_array(array,size);
    cout<<endl;
    return 0;
}
