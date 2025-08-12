#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    string number;
    int sum = 0;

    cin>>N;
    cin>>number;

    for(int i=0; i < N; i++)
    {
        const int num = number[i] - '0';
        sum += num;
    }

    cout<<sum;

    return 0;
}