#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int n;
    vector<int> v;
    vector<float> v2;
    int maxVal = 0;
    float sum = 0;

    cin>>n;
    v = vector<int>(n);
    v2 = vector<float>(n);

    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
        maxVal = max(v[i], maxVal);
    }

    for(int i = 0; i < n; i++)
    {
        v2[i] = (float)v[i] / maxVal * 100.0f;
        cout << v[i] << endl;
        sum += v2[i];
    }

    cout<<sum / n<<endl;

    return 0;
}
