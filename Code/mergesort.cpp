#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

void merge(int array[], int left, int mid, int right)
{
    int left_length = mid - left + 1;
    int right_length = right - mid;
 
    int *left_array = new int[left_length],
         *right_array = new int[right_length];
 
    for (int i = 0; i < left_length; i++)
        left_array[i] = array[left + i];
    for (int j = 0; j < right_length; j++)
        right_array[j] = array[mid + 1 + j];
 
    int left_index = 0;
    int right_index = 0;
    int result_index = left;
 
    while (left_index < left_length && right_index < right_length) {
        if (left_array[left_index] <= right_array[right_index]) {
            array[result_index] = left_array[left_index];
            left_index++;
        }
        else {
            array[result_index] = right_array[right_index];
            right_index++;
        }
        result_index++;
    }
    
    while (left_index < left_length) {
        array[result_index] = left_array[left_index];
        left_index++;
        result_index++;
    }
    
    while (right_index < right_length) {
        array[result_index] = right_array[right_index];
        right_index++;
        result_index++;
    }
    
    delete[] left_array;
    delete[] right_array;
}

void merge_sort(int* array, int first, int last){
    if (first >= last)
        return;
 
    int mid = first + (last - first) / 2;
    merge_sort(array, first, mid);
    merge_sort(array, mid + 1, last);
    merge(array, first, mid, last);
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
    merge_sort(array,0,size);
    cout<<"Sorted array: \n";
    print_array(array,size);
    cout<<endl;
    return 0;
}
