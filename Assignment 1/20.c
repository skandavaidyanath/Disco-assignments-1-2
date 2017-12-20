#include<stdio.h>
#include<math.h>
int main()
{
    int m,n;
    scanf("%d %d", &m, &n);
    int unit_digit_number= m%10;
    int unit_digit_power= n%4;
    if(unit_digit_power==0) unit_digit_power=4;
    int answer= (int)pow(unit_digit_number, unit_digit_power);
    answer = answer % 10;
    printf("%d",answer);
    return 0;
}
