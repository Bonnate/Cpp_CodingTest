#include <iostream>
#include <cmath>

int sizes[9] { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

int main() {
    long long int answer = 0;
    int N;
    scanf("%d", &N);
    
    int digit = 1;
    for(; digit <= 10; ++digit)
    {
        if(!(N / (int)pow(10, digit - 1)))
        {
            --digit;
            break;
        }
    }
    
    for(int i = 1; i < digit; ++i)
        answer += (pow(10, i) - pow(10, i - 1)) * i;

    answer += (N - (int)pow(10, digit - 1) + 1) * sizes[digit - 1];
       
    printf("%lld", answer);
}