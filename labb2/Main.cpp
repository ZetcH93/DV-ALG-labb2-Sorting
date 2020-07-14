#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <chrono>
#include "SortingFunctions.hpp"

vector<long int> ReadValuesFromFile(const std::string& filepath)
{
	std::ifstream file(filepath);
	long int number;
	std::vector<long int> numbers;

	while (file >> number)
		numbers.push_back(number);

	return numbers;
}

void WriteValuesToFile(const std::vector<long int>& numbers, const std::string& filepath = "Output.txt")
{
	std::ofstream file(filepath);

	for (std::vector<long int>::size_type i = 0; i < numbers.size() - 1; ++i)
		file << numbers[i] << std::endl;

	file << numbers.back();
}

int main(long int argc, char** argv)
{
	if (argc < 4)
	{
		std::cout << "To few arguments" << std::endl;
		return -1;
	}

	vector<long int> numbers = ReadValuesFromFile(argv[1]);
	long int left = 0;
	long int right = (numbers.size() - 1);

	auto start = std::chrono::steady_clock::now();

	switch (argv[2][0])
	{
	case '1':
		cout << "mergesort" << endl;
		mergeSort(numbers);
		break;
	case '2':
		cout << "heapsort" << endl;
		heapSort(numbers);
		break;
	case '3':
		cout << "quicksort" << endl;
		quickSort(numbers, left, right);
		break;
	default:
		std::cout << "Incorrect argument for choosing the sorting algorithm!" << std::endl;
		std::cout << "Aborting process!" << std::endl;
		return -1;
	}

	auto end = chrono::steady_clock::now();
	chrono::duration<double> elapsed_seconds = end - start;
	cout << "Sorting took: " << elapsed_seconds.count() << " seconds" << std::endl;

	WriteValuesToFile(numbers, argv[3]);

	return 0;
}