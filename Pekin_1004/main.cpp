#include <iostream>
#include <stdio.h>
#include <malloc.h>

using namespace std;



int main(int argc, char *argv[]){
    freopen("input.txt", "r", stdin);
    double avg = 0;

    double v;
    for(int i = 0; i < 12; ++i){
        cin >> v;
        avg = avg * (i/(i+1.)) + v / (i+1.);
    }
    cout << "$" << avg << endl;

    return 0;
}
