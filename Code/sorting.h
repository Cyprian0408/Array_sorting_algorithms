#include <string.h>
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using std::cout;
using std::endl; 
using std::string;
using std::fstream;
void swap(string *a, string *b){
    string temp=*a;
    *a=*b;
    *b=temp;
}
void bubble_sort(string* array, int n){
    for (int i=0;i<n-1;i++){
        for (int j=0;j<n-i-1;j++){
            if(array[j]>array[j+1]){
                swap(&array[j],&array[j+1]);
            }
        }
    }
}
void print_string_array(string* array, int n){
    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}
void print_double_array(double* array, int n){
        for(int i=0;i<n;i++){
        cout<<std::fixed<<array[i]<<std::setprecision(10)<<' ';
    }
    cout<<endl;
}
int partition(string* array, int startpoint, int endpoint){
    string pivot=array[startpoint];
    int lp=startpoint;
    int rp=endpoint;
    //cout<<"LP początkowe jest równe "<<lp<<endl;
    //cout<<"RP początkowe jest równe "<<rp<<endl;
    while(true){
        while(array[lp]<=pivot){
            lp++;
            //std::this_thread::sleep_for(100ms);
            //cout<<"LP jest równy "<<lp<<endl;
            if(lp>=endpoint){
                break;
            }
        }
        while(array[rp]>pivot){
            rp--;
            //std::this_thread::sleep_for(100ms);
            //cout<<"RP jest równy "<<rp<<endl;
            if(rp==startpoint){
                break;
            }
        }
        if(lp>rp){break;}
        else{
        //std::this_thread::sleep_for(100ms);
        //cout<<"Tablica po zmianie lp i rp"<<endl;
        swap(&array[lp], &array[rp]);
        //print_array(array,n);
        }
    }
    //std::this_thread::sleep_for(100ms);
    //cout<<"Tablica po zmianie rp i pivota"<<endl;
    swap(&array[startpoint],&array[rp]);
    //print_array(array,n);
    return rp;
}
void quicksort(string* array,int startpoint,int endpoint){
    int p;
    if(startpoint<endpoint){
        p=partition(array,startpoint,endpoint);
        //cout<<"Partition pierwszej połowy"<<endl;
        quicksort(array,startpoint,p-1);
        //cout<<"Partition drugiej połowy"<<endl;
        quicksort(array,p+1,endpoint);
    }
} 

void selection_sort(string* array, int n){
    int index_of_lowest;
    string lowest_value;
   
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

void merge_arrays(string array[], int left, int mid, int right)
{
    int left_length = mid - left + 1;
    int right_length = right - mid;
 
    string *left_array = new string[left_length],
         *right_array = new string[right_length];
 
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

void merge_sort(string* array, int first, int last){
    if (first >= last)
        return;
 
    int mid = first + (last - first) / 2;
    merge_sort(array, first, mid);
    merge_sort(array, mid + 1, last);
    merge_arrays(array, first, mid, last);
}
