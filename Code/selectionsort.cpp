#include <string.h>
#include <iostream>
using std::cout;
using std::endl; 
void selection_sort(int* array, int n){
    int index_of_lowest, lowest_value;
   
    for (int i=0;i<n;i++){
		index_of_lowest = i;
		lowest_value = array[i];
		for (int j=i;j<n;j++){
			if (lowest_value > array[j]){
				index_of_lowest = j;
				lowest_value = array[j];
			}
		}
		array[index_of_lowest] = array[i];
		array[i] = lowest_value;
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
    selection_sort(array,size);
    cout<<"Sorted array: \n";
    print_array(array,size);
    cout<<endl;
    return 0;
}
