#include <stdio.h>
#include <math.h>

float recursive_sqrt(float x, float guess, double tol)
{
    if (fabs((guess * guess) - x) <= tol) return guess;
    else {
        float new_guess = ((guess * guess) + x)/(2 * guess);
        return recursive_sqrt(x, new_guess, tol);
    } 
}

int main()
{    
    float quadrada = recursive_sqrt(13, 3.2, 0.001);
    printf("%f\n", quadrada);
    float quadrada2 = recursive_sqrt(100, 90, 0.0001);
    printf("%f\n", quadrada2);
}
