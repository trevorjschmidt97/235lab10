#include <iostream>
#include <fstream>
#include <string>
#include "QS.h"

// Memory Check Includes
#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK
#endif
// End Memory Check Includes

using namespace std;

int main(int argc, char* argv[])
{
	VS_MEM_CHECK // Memory check

	// Set in stream and out stream
	ifstream in(argv[1]);
	ofstream out(argv[2]);

	QS<int> intQS;
	string line;

	// While parsing through the file
		//QuickSort
		//AddToArray
		//PrintArray
		//Sort
		//Stats
		//SortAll
		//Clear
		//Size
		//Capacity
		//MedianOfThree
		//Partition
	while (!in.eof())
	{
		getline(in, line);

		if (line.substr(0, 9) == "QuickSort")
		{
			out << line;
			line = line.substr(10);
			stringstream ss(line);
			size_t capacity;
			ss >> capacity;
			intQS.clear();
			intQS.setCapacity(capacity);
			out << " OK";
		}

		else if (line.substr(0, 10) == "AddToArray")
		{
			line = line.substr(11);
			stringstream ss(line);
			int input;
			ss >> input;
			out << "AddToArray " << input;
			intQS.addElement(input);
			while (ss >> input)
			{
				out << "," << input;
				intQS.addElement(input);
			}
			out << " OK";
		}

		else if (line.substr(0, 10) == "PrintArray")
		{
			out << "PrintArray " << intQS.toString();
		}

		else if (line.substr(0, 5) == "Sort ")
		{
			line = line.substr(5);
			stringstream ss(line);
			size_t input1, input2;
			ss >> input1 >> input2;
			out << "Sort " << input1 << "," << input2;
			if (intQS.sort(input1, input2))
			{
				 out << " OK";
			}
			else
			{
				out << " NOT OK";
			}
		}

		else if (line.substr(0, 5) == "Stats")
		{
			out << "Stats " << intQS.comp() << "," << intQS.exchan();
		}

		else if (line.substr(0, 7) == "SortAll")
		{
			if (intQS.sortAll())
			{
				out << "SortAll OK";
			}
			else
			{
				out << "SortAll NOT OK";
			}
		}

		else if (line.substr(0, 5) == "Clear")
		{
			if (intQS.clear())
			{
				out << "Clear OK";
			}
			else
			{
				out << "Clear NOT OK";
			}
		}
		
		else if (line.substr(0, 4) == "Size")
		{
			out << "Size " << intQS.getSize();
		}

		else if (line.substr(0, 8) == "Capacity")
		{
			out << "Capacity " << intQS.getCapacity();
		}

		else if (line.substr(0, 13) == "MedianOfThree")
		{
			size_t left;
			size_t right;
			line = line.substr(14);
			stringstream ss(line);
			ss >> left >> right;
			out << "MedianOfThree " << left << "," << right << " = " << intQS.medianOfThree(left, right);
		}

		else if (line.substr(0, 9) == "Partition")
		{
			int left, right, index;
			line = line.substr(9);
			stringstream ss(line);
			ss >> left >> right >> index;
			out << "Partition " << left << "," << right << "," << index << " = " << intQS.partition(left, right, index);
		}

		out << endl;
	}  // End Parsing through File

	system("pause");
	return 0;
}