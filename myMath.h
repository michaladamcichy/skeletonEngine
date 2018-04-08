const double PI=3.141593;
const double HALF_PI=1.570796;
const double SQRT_2 = 1.414214;
const double EULER = 2.718282;

int8_t sgn(double value)
{
	if (value>0) return 1;
	else if (value == 0) return 0;
	else return -1;
}

double roundCent(double x)
{
	x *= 100;
	x = round(x);
	x /= 100;
	return x;
}

bool cramer(double a, double b, double e, double c, double d, double f, double& x, double& y)
{
    /*
    a*x + b*y = e
    c*x + d*y = f
    */

    if (a*c - b*d == 0)
    {
        // 0 or infinite number of solutions
        return false;
    }
    else
    {
    x = (e*d-b*f)/(a*d-b*c);
    y = (a*f-e*c)/(a*d-b*c);
    return true;
    }
}

double sarrus(double a[3][3])
{
	return a[0][0] * a[1][1] * a[2][2] +
		a[0][1] * a[1][2] * a[2][0] +
		a[0][2] * a[1][0] * a[2][1] -
		a[2][0] * a[1][1] * a[0][2] -
		a[2][1] * a[1][2] * a[0][0] -
		a[2][2] * a[1][0] * a[0][1];
}

bool cramer3(double a[3], double b[3], double c[3], double d[3], double& x, double& y, double& z)
{
	/*
	a1*x + b1*y + c1 *z = d1
	a2*x + b2*y + c2 *z = d2
	a3*x + b3*y + c3 *z = d3
	*/
	double A[3][3] = {
		a[0], b[0], c[0],
		a[1], b[1], c[1],
		a[2], b[2], c[2]
	};
	double detA = sarrus(A);
	if (detA == 0)
	{
		return false;
	}
	else
	{
		double X[3][3] = {
			d[0], b[0], c[0],
			d[1], b[1], c[1],
			d[2], b[2], c[2]
		};
		double Y[3][3] = {
			a[0], d[0], c[0],
			a[1], d[1], c[1],
			a[2], d[2], c[2]
		};
		double Z[3][3] = {
			a[0], b[0], d[0],
			a[1], b[1], d[1],
			a[2], b[2], d[2]
		};
		x = sarrus(X) / detA;
		y = sarrus(Y) / detA;
		z = sarrus(Z) / detA;
		return true;
	}
}	
