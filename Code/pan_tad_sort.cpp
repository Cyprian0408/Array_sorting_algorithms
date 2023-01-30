#include<iostream>
#include<fstream>
#include<string>
#include"sorting.h"
#include<bits/stdc++.h>
#include"pbPlots.hpp"
#include"supportLib.hpp"

const int size_of_text = 100000;
string array_q[size_of_text], array_b[size_of_text], array_s[size_of_text], array_m[size_of_text];

int main(void){
    bool success;
    StringReference *errorMessage = CreateStringReferenceLengthValue(0, L' ');
    RGBABitmapImageReference *imageRef=CreateRGBABitmapImageReference();
    int j=0;
    int size_of_text=100000;
    double n[]={10,100,1000,2000,3000,4000,5000,6000,7000,8000,9000,10000, 20000, 30000, 40000, 50000, 60000, 70000,100000};
    int size=sizeof(n)/sizeof(double);
    string s,text;  
    fstream file;
    std::chrono::time_point<std::chrono::high_resolution_clock> start,end;
    double time_taken_by_quicksort[size];
    double time_taken_by_bubblesort[size];
    double time_taken_by_selectionsort[size];
    double time_taken_by_mergesort[size];
    for (int i=0;i<size;i++){
        file.open("pan-tadeusz-unix.txt");
        if (file.fail()){
			cout<<"Error"<<endl;
			return 1;       
		}
		while(file>>s&&j<size_of_text){
			array_q[j]=s;
			array_b[j]=s;
			array_s[j]=s;
			array_m[j]=s;
			j++;
		}
        file.close();
        
        //rozpoczęcie badania czasu trwania algorytmów sortujących   
        std::ios_base::sync_with_stdio(false);
        start = std::chrono::high_resolution_clock::now();
        quicksort(array_q,0,n[i]-1);
        end = std::chrono::high_resolution_clock::now();
        //print_string_array(array_q,n[i]);
        time_taken_by_quicksort[i] = {double(((std::chrono::duration<double>)(end-start)).count())};

        std::ios_base::sync_with_stdio(false);
        start = std::chrono::high_resolution_clock::now();
        bubble_sort(array_b,n[i]);
        end = std::chrono::high_resolution_clock::now();
        //print_string_array(array_b,n[i]);
        time_taken_by_bubblesort[i] = {double(((std::chrono::duration<double>)(end-start)).count())};
        
        std::ios_base::sync_with_stdio(false);
        start = std::chrono::high_resolution_clock::now();
        selection_sort(array_s,n[i]);
        end = std::chrono::high_resolution_clock::now();
        //print_string_array(array_s,n[i]);
        time_taken_by_selectionsort[i] = {double(((std::chrono::duration<double>)(end-start)).count())};
     
        std::ios_base::sync_with_stdio(false);
        start = std::chrono::high_resolution_clock::now();
        merge_sort(array_m,0,n[i]-1);
        end = std::chrono::high_resolution_clock::now();
        //print_string_array(array_m,n[i]);
        time_taken_by_mergesort[i] = {double(((std::chrono::duration<double>)(end-start)).count())};
    }
    cout<<"Czas dla quicksorta"<<endl;
    print_double_array(time_taken_by_quicksort,size);
    cout<<endl;
    cout<<"Czas dla bubblesorta"<<endl;
    print_double_array(time_taken_by_bubblesort,size);
    cout<<"Czas dla selectionsorta"<<endl;
    print_double_array(time_taken_by_selectionsort,size);
    cout<<endl;
    cout<<"Czas dla mergesorta"<<endl;
    print_double_array(time_taken_by_mergesort,size);
    std::vector<double> time_q, time_b, time_s, time_m, num;
    for(int i=0;i<size;i++){
        time_q.push_back(time_taken_by_quicksort[i]);
    }
    for(int i=0;i<size;i++){
        time_b.push_back(time_taken_by_bubblesort[i]);
    }
    for(int i=0;i<size;i++){
        time_s.push_back(time_taken_by_selectionsort[i]);
    }
    for(int i=0;i<size;i++){
        time_m.push_back(time_taken_by_mergesort[i]);
    }
    for(int i=0;i<size;i++){
        num.push_back(n[i]);
    }
    success=DrawScatterPlot(imageRef, 600, 400, &num, &time_b,errorMessage);
    if(success){
		std::vector<double> *pngdata = ConvertToPNG(imageRef->image);
		WriteToFile(pngdata, "Bubblesort_time.png");
		DeleteImage(imageRef->image);
	}else{
		std::cerr << "Error: ";
		for(wchar_t c : *errorMessage->string){
			std::wcerr << c;
		}
		std::cerr << endl;
	}
    success=DrawScatterPlot(imageRef, 600, 400, &num, &time_q,errorMessage);
    if(success){
		std::vector<double> *pngdata = ConvertToPNG(imageRef->image);
		WriteToFile(pngdata, "Quicksort_time.png");
		DeleteImage(imageRef->image);
	}else{
		std::cerr << "Error: ";
		for(wchar_t c : *errorMessage->string){
			std::wcerr << c;
		}
		std::cerr << endl;
	}
	success=DrawScatterPlot(imageRef, 600, 400, &num, &time_s,errorMessage);
    if(success){
		std::vector<double> *pngdata = ConvertToPNG(imageRef->image);
		WriteToFile(pngdata, "Selectionsort_time.png");
		DeleteImage(imageRef->image);
	}else{
		std::cerr << "Error: ";
		for(wchar_t c : *errorMessage->string){
			std::wcerr << c;
		}
		std::cerr << endl;
	}
	success=DrawScatterPlot(imageRef, 600, 400, &num, &time_m,errorMessage);
    if(success){
		std::vector<double> *pngdata = ConvertToPNG(imageRef->image);
		WriteToFile(pngdata, "Mergesort_time.png");
		DeleteImage(imageRef->image);
	}else{
		std::cerr << "Error: ";
		for(wchar_t c : *errorMessage->string){
			std::wcerr << c;
		}
		std::cerr << endl;
	}
	FreeAllocations();
return 0;
}
// to compile g++ pan_tad_sort.cpp pbPlots.cpp supportLib.cpp -lm
