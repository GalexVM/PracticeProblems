/*
	Show the sum of all the possible addends
	Decreasing order
	Backtracking
*/
#include<iostream>
#include<deque>
#include <stack>
#include <chrono>

using std::cout;
using std::endl;
using std::deque;
using std::stack;
using std::chrono::milliseconds;
using std::chrono::steady_clock;

void sumas(int n, int r, deque<int>& result);
void PrintDeque(deque<int>st);
void sumas(int n, int r, deque<int>& result);

int main()
{
	auto start = steady_clock::now();
	auto end = steady_clock::now();
	std::chrono::duration<double, std::milli> float_ms;

	// Backtracking
	cout << "Solucion Backtracking:\n";
	start = steady_clock::now();
	deque<int> almacenador;
	sumas(5, 0, almacenador);
	end = steady_clock::now();
	float_ms = end - start;
	cout << float_ms.count() << "ms" << endl;
}

void sumas(int n, int r, deque<int>& result)
{
	result.push_back(r);
	if (n == 0)
	{
		PrintDeque(result);
		result.pop_back();
		return;
	}
	for (auto i = n; i > 0; i--)
	{
		if (i <= result.back() || result.back() == 0)
			sumas(n - i, i, result);
	}
	result.pop_back();
}

void PrintDeque(deque<int> dq)
{
	int size = dq.size();
	for (auto i = 1; i < size; i++)
	{
		cout << dq[i];
		if (i != size - 1)
			cout << " + ";
	}cout << endl;

}





