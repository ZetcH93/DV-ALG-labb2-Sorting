
#include "SortingFunctions.hpp"



void heapSort(vector<long int>& items)
{
	
	for (int i = items.size() / 2 - 1; i >= 0 ; --i)
	{
		percolateDown(items, i, items.size());	//buildheap
	}

	for (int j = (items.size() - 1); j > 0; --j)
	{
		swap(items[0], items[j]);	//deleteMin
		percolateDown(items, 0, j);	
	}
	
}


int leftChild(int i)
{
	return 2 * i + 1;
}

void percolateDown(vector<long int>& items, int percolateFrom, int percolateTo)	//perkulerar neråt, görs efter det att det översta värdet har tagits bort från priority kön, detta då man popar så flyttas det värdet 
{																//som är längst ner i heapen upp till roten(och detta kan vara stort vilket då gör att man dubbelkollar så att de är mindre än dess barn osv osv)
	int min = percolateFrom;
	int child;
	long int temp;
	
	for (temp = move(items[min]); leftChild(min) < percolateTo; min = child)	//flyttar minstavärdet till en temp, om det finns ett barn till vänster, min blir tilldelat barnet
	{
		child = leftChild(min);	// posititionen för det vänstra barnet
		if (child != percolateTo - 1 && items[child] > items[child + 1])	//om barnet är skillt från sistavärdet OCH om vänsterbarn är mindre än högerbarn:
				++child;	//barnet som ska percoleras upp kommer att vara högerbarnet
		if (temp > items[child])	// om barnet är mindre än föräldern så byts plats
			items[min] = move(items[child]);
		else
			break;
	}
	items[min] = move(temp); //föräldern byter plats med barnen kontinuerligt så att heapstrukturen(min) uppehålls
	
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
	

