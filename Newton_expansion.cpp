#include <stdio.h>
#include <math.h>
#ifdef _WIN32
#include <conio.h>
#define clrscr() printf("\e[1;1H\e[2J")
#endif
int factorial(int a)
{
    int f = 1;
    for (int i = 1; i <= a; i++)
    {
        f *= i;
    }
    return f;
}
int ckn(int k, int n)
{
    int c;
    c = factorial(n) / (factorial(k) * factorial(n - k));
    return c;
}
void series(int a, int b, int d)
{
    printf("Newton expansion of your binomial:\n");
    {
        for (int i = 0; i <= d; i++)
        {
            int apow = pow(a, d - i);
            int bpow = pow(b, i);
            int n = apow * bpow * ckn(i, d);
            printf("%dx^%d", n, d - i);
            if (i != d)
            {
                if (b > 0)
                {
                    printf(" + ");
                }
                else if (b < 0)
                {
                    if (i % 2 == 0)
                    {
                        printf(" ");
                    }
                    else
                    {
                        printf(" +");
                    }
                }
            }
        }
    }
}
int main()
{
    clrscr();
    int a, b, d;
    printf("Type in a, b for the binomial ax + b:\n");
    scanf("%d %d", &a, &b);
    printf("Type in the degree d of the binomial: (%dx + %d)^d\n", a, b);
    scanf("%d", &d);
    printf("Your binomial:\n");
    printf("(%dx + %d)^%d\n", a, b, d);
    series(a, b, d);
    return 0;
}