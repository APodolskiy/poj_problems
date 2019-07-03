#include <iostream>
#include <stdio.h>

using namespace std;


int main(int argc, char *argv[]){
    freopen("input.txt", "r", stdin);

    double value;
    int numCards = 0;

    while(true){
        cin >> value;
        if(value > 0){
            int stp = 0;
            double accum = 0;
            while(accum < value){
                accum += 1/(stp+2.0);
                ++stp;
            }
            cout << stp << " card(s)" << endl;
        }
        else{
            break;
        }
    }

    return 0;
}
