/**
 * Transforming functions to a single-return style, where the value is only returned at the end of the
 * function, may make some transformations such as inlining easier. However, it makes the high-level CFG more complicated.
 */

double funky_function(double a, double b, double magic_number, unsigned int factor)
{
    if (b > -0.01 && b < 0.01)
    {
        // kind of is a 0, so we return 0
        return 0.0;
    }

    // we want a big number so we divide/mutliply by b accordingly
    double c;
    if (b > 1.0 || b < -1.0)
    {
        c = a * b;
    }
    else
    {
        c = a / b;
    }

    double acc = 1.0;
    for (unsigned int i = 0; i < factor; i++)
    {
        double delta = acc - magic_number;
        if (delta > -0.01 && delta < 0.01)
        {
            return magic_number;
        }
        acc = acc * c;
    }

    return acc;
}
