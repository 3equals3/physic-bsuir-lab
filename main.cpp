#include <iostream>

double m = 205;
double d = 0.0198;
double t = 4.443;
double h1 = 0.84;
double h2 = 0.573;

double g = 9.81;

double dm = 0.0005;
double dd = 0.00005;
double dt = 0.02;
double dh1 = 0.0005;
double dh2 = 0.0005;

double delta_I() {
	return sqrt(
		pow((d * d * g * h2 * t * t) / (4 * h1 * h1 + 4 * h1 * h2) * dm, 2) + 
		pow((d * g * m * h2 * t * t) / (2 * h1 * h1 + 2 * h1 * h2) * dd, 2) +
		pow((8 * d * d * g * h1 * h2 * m * t * t + 4 * d * d * g * m * h2 * h2 * t * t) / pow((4 * h1 * h1 + 4 * h1 * h2), 2) * dh1,2) +
		pow((4 * d * d * g * h1 * h1 * m * t * t) / pow((4 * h1 * h1 + 4 * h1 * h2), 2) * dh2, 2) +
		pow((d * d * g * m * h2 * t) / (2 * h1 * h1 + 2 * h1 * h2) * dt, 2)
	);
}

double delta_M() {
	return sqrt(
	    pow(((g * h1 - g * h2) * d) / (2 * h1 + 2 * h2) * dm, 2) + 
	    pow((g*m*(h1-h2)) / (2*(h1+h2)) * dd, 2) + 
	    pow((4*d*g*m*h2) / (4*(h1+h2)) * dh1, 2) + 
	    pow((d*g*m*h1) / (pow(h1+h2,2)) * dh2, 2)
	);
}

double M() {
    return m * g * d * (h1 - h2) / (2 * (h1 + h2));
}

double I() {
    return m*d*d / 4 * ((g * h2 * t* t)/(h1*(h1+h2)) - 1);
}

int main() {
    std::cout << "delta_I:\t" << delta_I() << "\nM:\t\t" << M() << "\ndelta_M:\t" << delta_M();
}
