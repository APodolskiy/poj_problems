#include <iostream>
#include <stdio.h>
#include <malloc.h>

using namespace std;

#define MAX_NUM 1000

int speed[MAX_NUM + 1];
long time[MAX_NUM + 1];

int main(int argc, char *argv[]){
    int n = 0;

    while(true){
        cin >> n;
        if(n == 0){
            break;
        }
        for(int i = 0; i < n; ++i){
            cin >> speed[i] >> time[i];
        }

    }

    return 0;
}
