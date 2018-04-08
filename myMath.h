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

double determinant(double a[4][4])
{
	double A[3][3] = {
					  a[1][1], a[2][1], a[3][1],
					  a[1][2], a[2][2], a[3][2],
					  a[1][3], a[2][3], a[3][3]
	};
	double B[3][3] = {
					  a[0][1], a[2][1], a[3][1],
					  a[0][2], a[2][2], a[3][2],
					  a[0][3], a[2][3], a[3][3]
	};
	double C[3][3] = {
					  a[0][1], a[1][1], a[3][1],
					  a[0][2], a[1][2], a[3][2],
					  a[0][3], a[1][3], a[3][3]
	};
	double D[3][3] = {
		a[0][1], a[1][1], a[2][1],
		a[0][2], a[1][2], a[2][2],
		a[0][3], a[1][3], a[2][3]
	};
	return a[0][0] * sarrus(A) - a[1][0] * sarrus(B) + a[2][0] * sarrus(C) - a[3][0] * sarrus(D);
}

double determinant(double a[3][3])
{
	return sarrus(a);
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
	double detA = determinant(A);
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
		x = determinant(X) / detA;
		y = determinant(Y) / detA;
		z = determinant(Z) / detA;
		return true;
	}
}
bool cramer4(double a[4], double b[4], double c[4], double d[4], double e[4], double& x, double& y, double& z, double& w)
{
	/*
	a1*x + b1*y + c1 *z + d1 *w = e1
	a2*x + b2*y + c2 *z + d2 *w = e2
	a3*x + b3*y + c3 *z + d3 *w = e3
	a4*x + b4*y + c4 *z + d4 *w = e4
	*/
	double A[4][4] = {
		a[0], b[0], c[0], d[0],
		a[1], b[1], c[1], d[1],
		a[2], b[2], c[2], d[2],
		a[3], b[3], c[3], d[3]
	};
	double detA = determinant(A);
	if (detA == 0)
	{
		return false;
	}
	else
	{
		double X[4][4] = {
			e[0], b[0], c[0], d[0],
			e[1], b[1], c[1], d[1],
			e[2], b[2], c[2], d[2],
			e[3], b[3], c[3], d[3]
		};
		double Y[4][4] = {
			a[0], e[0], c[0], d[0],
			a[1], e[1], c[1], d[1],
			a[2], e[2], c[2], d[2],
			a[3], e[3], c[3], d[3]
		};
		double Z[4][4] = {
			a[0], b[0], e[0], d[0],
			a[1], b[1], e[1], d[1],
			a[2], b[2], e[2], d[2],
			a[3], b[3], e[3], d[3]
		};
		double W[4][4] = {
			a[0], b[0], c[0], e[0],
			a[1], b[1], c[1], e[1],
			a[2], b[2], c[2], e[2],
			a[3], b[3], c[3], e[3]
		};
		x = determinant(X) / detA;
		y = determinant(Y) / detA;
		z = determinant(Z) / detA;
		w = determinant(W) / detA;
		return true;
	}
}
