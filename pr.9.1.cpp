#include <iostream>
#include <cmath>
#include <iomanip>

#include "sum.h"
#include "var.h"

using namespace std;

using namespace nsSum;
using namespace nsVar;

int main()
{
	cout << "x_p = "; cin >> x_p;
	cout << "x_k = "; cin >> x_k;
	cout << "dx  = "; cin >> dx;
	cout << "e   = "; cin >> e;
	cout << endl;

	// ряд збігається лише при |x| < 1
	if (x_p <= -1 || x_k >= 1 || x_p > x_k || dx <= 0 || e <= 0)
	{
		cout << "Error: need -1 < x_p <= x_k < 1, dx > 0, e > 0" << endl;
		return 1;
	}

	cout << "------------------------------------------------------" << endl;
	cout << "| " << setw(9) << "x"
		<< " | " << setw(12) << "Arth(x)"
		<< " | " << setw(12) << "sum"
		<< " | " << setw(6) << "terms" << " |" << endl;
	cout << "------------------------------------------------------" << endl;

	x = x_p;
	while (x <= x_k + 1e-9) // 1e-9 – запас на похибку накопичення dx
	{
		sum(); // виклик процедури обчислення суми

		cout << fixed << setprecision(6)
			<< "| " << setw(9) << x
			<< " | " << setw(12) << atanh(x)
			<< " | " << setw(12) << s
			<< " | " << setw(6) << n + 1 << " |" << endl; // +1: враховано перший доданок

		x += dx;
	}
	cout << "------------------------------------------------------" << endl;

	cin.get();
	cin.get();
	return 0;
}