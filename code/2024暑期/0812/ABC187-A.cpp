#include <iostream>

using namespace std;

int sum_of_digits(int number)
{
    int sum = 0;
    while (number > 0)
    {
        sum += number % 10;  // 1
        number /= 10;
    }
    return sum;
}

int main()
{
    int A, B;
    cin >> A >> B; // 输入A，B
    
    int sum_A = sum_of_digits(A); // 计算S(A)
    int sum_B = sum_of_digits(B);
    
    if (sum_A >= sum_B)
    {
        cout << sum_A << endl;
    }
    else
    {
        cout << sum_B << endl;
    }
    
    return 0;
}
