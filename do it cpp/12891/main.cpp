#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {

    int S, P, answer = 0;
    int acgt[4];
    map<char, int> map;
    map['A'] = 0;
    map['C'] = 0;
    map['G'] = 0;
    map['T'] = 0;
    string text;

    cin>>S>>P;
    cin>>text;
    cin>>acgt[0]>>acgt[1]>>acgt[2]>>acgt[3];

    for (int i = 0; i < P; ++i) {
        map[text[i]]++;
    }

    if (map['A'] >= acgt[0] &&
        map['C'] >= acgt[1] &&
        map['G'] >= acgt[2] &&
        map['T'] >= acgt[3]) {
        ++answer;
    }

    for (int i = 1; i <= S - P; ++i) {
        map[text[i - 1]]--;
        map[text[i + P - 1]]++;

        if (map['A'] >= acgt[0] &&
            map['C'] >= acgt[1] &&
            map['G'] >= acgt[2] &&
            map['T'] >= acgt[3]) {
            ++answer;
            }
    }

    cout << answer << endl;
    return 0;
}