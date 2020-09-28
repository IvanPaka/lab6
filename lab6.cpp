#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

double f(double *x){
    return 2*x[0]*x[0] + 4*x[0] + 3*x[1]*x[1] - 39*x[1] + 129.75;
}

double dfdx(double *x){
    return 4*x[0] + 4;
}

double dfdy(double *x){
    return 6*x[1] - 39;
}

double f_s(double *x, double a, double *p){
    double x_new[] = {x[0] + a*p[0], x[1] + a*p[1]};
    return f(x_new);
}


double norm(double *x, int n=2) {
    double r = 0;
    for(int i = 0; i < n; i++)
        r += x[i]*x[i];
    return sqrt(r);
}



void mn(double *x0, double eps=1e-5){ // Метод Ньютона
    ofstream outfile("data.dat", ios_base::out);
    double x[] = {x0[0], x0[1]};
    outfile << x[0] << "," << x[1] << endl;
    double p[] = {-dfdx(x0)/4., -dfdy(x0)/6.};

    double x_n[] = {x[0] + p[0], x[1] + p[1]};
    outfile << x_n[0] << "," << x_n[1] << endl;
    int i = 0;
	double dx[] = {x[0] - x_n[0], x[1] - x_n[1]};
    while(abs(f(x_n) - f(x)) > eps && norm(dx) > eps){
        x[0] = x_n[0]; x[1] = x_n[1];
        p[0] = -dfdx(x)/4.; p[1] = -dfdy(x)/6.;
        x_n[0] = x[0] + p[0]; x_n[1] = x[1] + p[1];
        outfile << x_n[0] << "," << x_n[1] << endl;

		dx[0] = x[0] - x_n[0]; dx[1] = x[1] - x_n[1];
        i++;
    }
    outfile.close();
    cout << "iter: " << i << endl;
    cout << "xmin: (" << x_n[0] << ", " << x_n[1] << ")" << endl;
    cout << "f(" << x_n[0] << ", " << x_n[1] << ") = " << f(x_n) << endl;
}

int main()
{
    double x0[] = {0, -3};
    mn(x0);
    return 0;
}
