/**
 * Transforming functions to a single-return style, where the value is only returned at the end of the
 * function, may make some transformations such as inlining easier. However, it makes the high-level CFG more complicated.
 */

double funky_function(double a, double b, double magic_number, unsigned int factor)
{
    double __return_value;
    if (b > -0.01 && b < 0.01)
    {
        // kind of is a 0, so we return 0
        __return_value = 0.0;
        goto __return_label;
    }

    // we want a big number so we divide/mutliply by b accordingly
    double c = (b > 1.0 || b < -1.0) ? a * b : a / b;

    double acc = 1.0;
    for (unsigned int i = 0; i < factor; i++)
    {
        double delta = acc - magic_number;
        if (delta > -0.01 && delta < 0.01)
        {
            __return_value = magic_number;
            goto __return_label;
        }
        acc = acc * c;
    }

    __return_value = acc;
    goto __return_label;
__return_label:
    return __return_value;
}
