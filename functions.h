#include <vector>
using namespace std;

void generateFile(string filename, unsigned int range, unsigned int count);
vector<int> readFile(string filename);
void outputNumbers(vector<int>& v);
void writeNumbers(vector<int>& v);
void BubbleSort(vector<int>& numbers);
void CountSort(vector<int>& numbers);
void InsertionSort(vector<int>& numbers);
void selectionSort(vector<int>& numbers);
void STLSort(vector<int>& numbers);
bool inOrder(vector<int>& numbers);
bool noVerification(vector<int>& numbers);