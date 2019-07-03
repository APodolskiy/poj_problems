#include <iostream>
#include <malloc.h>
#include <stdio.h>

using namespace std;

#define MAX_N 10000000

int main(int argc, char *argv[]){
    long n; // nubmer of cows
    long num_var = 0; // number of variants to obtain the number

    cin >> n;

    for (int i = 1; i*(i+1)/2 <= n; i++){
        if((n - i*(i+1)/2) % i == 0){
            ++num_var;
        }
    }

    cout << num_var << endl;
    return 0;
}
