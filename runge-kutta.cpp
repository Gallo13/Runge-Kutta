// C program to implement Runge Kutta method
#include<stdio.h>
#include<math.h>
#include<iostream> 
using namespace::std;
using std::cout;
using std::cin;


// A sample differential equation "dy/dx = (x - y)/2"
float dydx(float x, float y)
{
	return((-y + x + 1));
}

// Finds value of y for a given x using step size h
// and initial value y0 at x0.
void rungeKutta(float x0, float y0, float x, float h)
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
		y = y + (k1 + 2 * k2 + 2 * k3 + k4) / 6;

		// Update next value of x
		x0 = x0 + h;

		// show the x and y values
		cout << "\nX value=  " << x0 << endl;
		cout << "Y value = " << y << endl;
	}

}

// Driver method
int main()
{
	float x0, y, x, h;
	cout << "Please enter a value for x0: ";
	cin >> x0;
	cout << "Please enter a value for y: ";
	cin >> y;
	cout << "Please enter a value for x: ";
	cin >> x;
	cout << "Please enter a value for h: ";
	cin >> h;
	cout << "\nPerforming Runge-Kutta to the 4th order" << endl;
	rungeKutta(x0, y, x, h);
	system("pause");
	return 0;

}