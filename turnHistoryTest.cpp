#include <iostream>

using namespace std;

int main() {
    int turnHistory[9][2] = {0};

    for(int i=0; i < 9; i++) {
        for(int j=0; j < 2; j++) {
            cout << i << "" << j << " : " << turnHistory[i][j];
        }
        cout << endl;
    }

    return 0;
}
