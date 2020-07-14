#pragma once

#include <fstream>
#include <string>
#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include "SortingFunctions.hpp"


using namespace std;


//heapsort
void heapSort(vector<long int>& items);
void percolateDown(vector<long int>& items, int percolateFrom);


//QuickSort
void quickSort(vector<long int>& items, long int left, long int right);
void insertionSort(vector<long int>& items, long int left, long int right);


//mergeSort
void mergeSort(vector<long int>& items);
void merge(vector<long int>& items, vector<long int>& tmpArray, long int leftPos, long int rightPos, long int rightEnd);
void mergeSort(vector<long int>& items, vector<long int>& tmpArray, long int left, long int right);
