#include <iostream>
#include <stdio.h>

using namespace std;

#define N 50
#define M 100

short str[M][N];
//short a[N], tmp[N];
int inv_arr[M];
int rng[M];

int main(int argc, char *argv[]){
    freopen("input.txt", "r", stdin);

    int n, m;
    cin >> n >> m;
    char c;

    for(int i = 0; i < m; ++i){
        inv_arr[i] = 0;
        rng[i] = i;
        for(int j = 0; j < n; ++j){
            cin >> c;
            str[i][j] = (short)c;
        }
    }

    for(int k = 0; k < m; ++k){
        for(int i = 0; i < n - 1; ++i){
            for(int j = i + 1; j < n; ++j){
                if(str[k][i] > str[k][j]){
                    inv_arr[k] ++;
                }
            }
        }
    }

    // Sort elements in the array
    for(int i = 0; i < m - 1; ++i){
        for(int j = i + 1; j < m; ++j){
            if(inv_arr[i] > inv_arr[j]){
                swap(inv_arr[i], inv_arr[j]);
                swap(rng[i], rng[j]);
            }
        }
    }

    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            cout << (char)str[rng[i]][j];
        }
        cout << endl;
    }

    return 0;
}
