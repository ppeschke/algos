#include <vector>
using namespace std;

void generateFile(string filename, unsigned int range, unsigned int count);
vector<int> readFile(string filename);
void outputNumbers(vector<int>& v);
void writeNumbers(vector<int>& v);
void BubbleSort(vector<int>& numbers);
void CountSort(vector<int>& numbers);
void InsertionSort(vector<int>& numbers);
void SelectionSort(vector<int>& numbers);
void STLSort(vector<int>& numbers);
void HeapSort(vector<int>& numbers);
void TreeSortIterative(vector<int>& numbers);
void TreeSortRecursive(vector<int>& numbers);
void ShellSort(vector<int>& numbers);
void MergeSort(vector<int>& numbers);
bool inOrder(vector<int>& numbers);
bool noVerification(vector<int>& numbers);