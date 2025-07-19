#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> a = {1, 2, 3};
    for (auto x : {1, 2, 3, 4}) {
        cout << x << " ";
    }
    return 0;
}

