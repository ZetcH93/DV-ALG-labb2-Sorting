
#include "SortingFunctions.hpp"



void heapSort(vector<long int>& items)
{
	
	for (unsigned int i = 0; i < items.size(); i++)
	{
		percolateDown(items, i);
	}
	
}

void percolateDown(vector<long int>& items, int percolateFrom)	//perkulerar neråt, görs efter det att det översta värdet har tagits bort från priority kön, detta då man popar så flyttas det värdet 
{																//som är längst ner i heapen upp till roten(och detta kan vara stort vilket då gör att man dubbelkollar så att de är mindre än dess barn osv osv)
	int min = percolateFrom;
	unsigned int l = 2 * percolateFrom + 1; // left child
	unsigned int r = 2 * percolateFrom + 2; // right child


	if (l < items.size() && items[l] < items[min])		// If left child is smaller than root 
		min = l;


	if (r < items.size() && items[r] < items[min])		// If right child is smaller than root/left child
		min = r;


	if (items[min] != items[percolateFrom]) {		// If min is not root 
		swap(items[percolateFrom], items[min]);
		
		int parent = percolateFrom;
		
		
		if (percolateFrom % 2 == 0 && parent != 0) //högerbarn
		{
			while (percolateFrom != (2 * parent + 2))
				parent--;
			percolateDown(items, parent);
		}
	
		else if (percolateFrom % 2 > 0 && parent != 0) //vänsterbarn
		{
			while (percolateFrom != (2 * parent + 1))
				parent--;
			percolateDown(items, parent);
		}
		
	}
	
}






void insertionSort(vector<long int>& items, long int left, long int right)
{
	if (left == right)	// base case condition for the quicksort
		return;
			
		for (long int p = left + 1; p < right+1; ++p)
		{
			long int tmp = move(items[p]);
			long int j;

			for (j = p; j > 0 && tmp < items[j - 1]; --j)
				items[j] = move(items[j - 1]);
			items[j] = move(tmp);
		}
}


void quickSort(vector<long int>& items, long int left, long int right)
{
	if ((left + 10) <= right) 
	{
				
		long int pivot = items[right]; //pivot furthest to the right
		long int i = (left-1);
		
		// Begin partitioning
		for (int j = left; j <= right - 1; j++)
		{
			if (items[j] < pivot)
			{
				i++;
				swap(items[i], items[j]);
			}

		}
			swap(items[i+1], items[right]); 			
		
			quickSort(items, left, i);		// Sort elements left of pivot
			quickSort(items, i + 2, right); // Sort elements right of pivot
		
	}
	else // Do an insertion sort on the subarray 
		insertionSort(items, left, right);
	
}






void mergeSort(vector<long int>& items)
{
	vector<long int> tmpArray(items.size());  // second "array" made for the mergesort
	mergeSort(items, tmpArray, 0, (items.size() - 1));

}

void mergeSort(vector<long int> & items, vector<long int> & tmpArray, long int left, long int right)
{
	if (left < right)
	{
		long int center = (left + right) / 2;				//splits the array in two
		mergeSort(items, tmpArray, left, center);			 // part left of the center
		mergeSort(items, tmpArray, center + 1, right);		// part right of the center
		merge(items, tmpArray, left, center + 1, right);	// merge the parts together in a sorted temp array and then
															// moves the values over to the real array.
	}
				
}

void merge(vector<long int>& items, vector<long int>& tmpArray,long int leftPos, long int rightPos, long int rightEnd)
{
	long int leftEnd = rightPos - 1;
	long int tmpPos = leftPos;
	long int numElements = rightEnd - leftPos + 1;
		
		while (leftPos <= leftEnd && rightPos <= rightEnd)
			if (items[leftPos] <= items[rightPos])
				tmpArray[tmpPos++] = move(items[leftPos++]);
			else
				tmpArray[tmpPos++] = move(items[rightPos++]);

		while(leftPos <= leftEnd) // Copy rest of first half
			tmpArray[tmpPos++] = move(items[leftPos++]);

		while(rightPos <= rightEnd) // Copy rest of right half
			tmpArray[tmpPos++] = move(items[rightPos++]);

			// Copy tmpArray back
		for (long int i = 0; i < numElements; ++i, --rightEnd)
			items[rightEnd] = move(tmpArray[rightEnd]);
}
	

