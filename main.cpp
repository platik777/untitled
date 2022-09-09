#include <iostream>
using namespace std;
int main() {
    int i = 1, c;
    cin >> c;
    while (i * i <= c) {
        cout << i * i << " ";
        i++;
    }
    return 0;
}