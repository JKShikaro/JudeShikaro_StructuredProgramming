#include <stdio.h>

#define PI 3.14159265358979

int main(void)
{
    double radius, area;

    printf("Enter the radius of the sphere: ");
    if (scanf("%lf", &radius) != 1 || radius < 0)
    {
        printf("Invalid radius.\n");
        return 1;
    }

    /* Surface area = 4 * pi * r^2 */
    area = 4 * PI * radius * radius;

    printf("Surface area of the sphere = %.2f\n", area);

    return 0;
}
