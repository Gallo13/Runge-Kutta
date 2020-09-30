// C program to implement Runge Kutta method
#include<stdio.h>
#include<math.h>
#include<iostream>
using std::cout;
using std::cin;
using std::endl;

// A sample differential equation "dy/dx = (x - y)/2"
float dydx(float x, float y)
{
	return((-y) + x +1);
}

// Finds value of y for a given x using step size h
// and initial value y0 at x0.
float rungeKutta(float x0, float y0, float x, float h)
{
	// Count number of iterations using step size or
	// step height h
	int n = (int)((x - x0) / h);

	float k1, k2, k3, k4, k5;

	// Iterate for number of iterations
	float y = y0;
	for (int i = 1; i <= n; i++)
	{
		// Apply Runge Kutta Formulas to find
		// next value of y
		k1 = h*dydx(x0, y);
		k2 = h*dydx(x0 + 0.5*h, y + 0.5*k1);
		k3 = h*dydx(x0 + 0.5*h, y + 0.5*k2);
		k4 = h*dydx(x0 + h, y + k3);

		// Update next value of y
		y = y + ((k1 + 2 * k2 + 2 * k3 + k4)/6);

		// Update next value of x
		x0 = x0 + h;
	}

	return y;
}

// Driver method
int main()
{
	float x0, y, x, h;
	cout << " Enter your variables:";
	cout << "\n x0 = ";
	cin >> x0;
	cout << " y = ";
	cin >> y;
	cout << " x = ";
	cin >> x;
	cout << " h = ";
	cin >> h;
	printf(" \nThe value of y at x is : %f",
		rungeKutta(x0, y, x, h));
	printf("\n");
	system("pause");
	return 0;
}