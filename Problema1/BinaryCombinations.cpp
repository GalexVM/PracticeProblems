/*
    Backtracking solution
    Get all the binary combinations of length n
*/
#include <iostream>
#include <string>
using std::cout;
using std::string;


void BinaryBT(int n, string cadena = "");

int main()
{
    BinaryBT(6);
}

void BinaryBT(int n, string cadena)
{
    if (n == 1)
    {
        cout << cadena + "0" << std::endl;
        cout << cadena + "1" << std::endl;
        return;
    }
    BinaryBT(n - 1, cadena + "0");
    BinaryBT(n - 1, cadena + "1");
}
