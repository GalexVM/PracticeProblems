/*
    Find the minimmun number of coins to pay the n price. The quantity and weigth of the coins is also variable
    -Backtracking and Dinamic Programming
    -Time measure
*/
#include <iostream>
#include <vector>
#include <deque>
#include <chrono>
using std::vector;
using std::min;
using std::cout;
using std::endl;
using std::deque;
using std::chrono::milliseconds;
using std::chrono::steady_clock;
long int BTKCoin(int n, vector<int> m);
long int DPCoin(int n, vector<int>m, deque<long int>& resp);
long int FindMinimun(vector<long int>vect);
long int FindMinimun(deque<long int>vect);

int main()
{
    auto start = steady_clock::now();
    auto end = steady_clock::now();
    std::chrono::duration<double, std::milli> float_ms;

    long int n = 20;
    vector<int> monedas{ 1,2,3,5 };
    deque<long int> resp(n + 1);

    //btk
    start = steady_clock::now();
    cout << BTKCoin(n, monedas) << endl;
    end = steady_clock::now();
    float_ms = end - start;
    cout << float_ms.count() << "ms" << endl;

    //dp
    start = steady_clock::now();
    cout << DPCoin(n, monedas, resp) << endl;
    end = steady_clock::now();
    float_ms = end - start;
    cout << float_ms.count() << "ms" << endl;
}
long int DPCoin(int n, vector<int> m, deque<long int>& resp)
{
    if (n == 0)
        return 0;
    if (n < 0)
        return  2000000000;
    if (resp[n])
    {
        return resp[n];
    }

    else
    {
        vector<long int> vect;
        for (auto i = 0; i < m.size(); i++)
            vect.push_back(DPCoin(n - m[i], m, resp));
        long int min = FindMinimun(vect);
        resp[n] = 1 + min;
        return 1 + min;
    }
}
long int BTKCoin(int n, vector<int> m)
{
    if (n == 0)
        return 0;
    if (n < 0)
        return  2000000000;
    vector<long int> vect;
    for (auto i = 0; i < m.size(); i++)
        vect.push_back(BTKCoin(n - m[i], m));
    long int min = FindMinimun(vect);
    return 1 + min;
}

long int FindMinimun(vector<long int>vect)
{
    if (vect.empty())
        return 0;
    int min = vect[0];
    for (auto i = 0; i < vect.size(); ++i)
        if (vect[i] < min)
            min = vect[i];
    return min;
}
int FindMinimun(deque<int>vect)
{
    if (vect.empty())
        return 0;
    int min = vect[0];
    for (auto i = 0; i < vect.size(); ++i)
        if (vect[i] < min)
            min = vect[i];
    return min;
}



