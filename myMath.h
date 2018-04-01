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
