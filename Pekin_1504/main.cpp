#include <iostream>
#include <malloc.h>
#include <stdio.h>

using namespace std;

int rev_num(int num);

int main(int argc, char *argv[]){
    //freopen("input.txt", "r", stdin);
    int n;  // number of TC
    int v1, v2; // values to reverse sum
    int sum;

    cin >> n;
    for(int i = 0; i < n; ++i){
        sum = 0;
        cin >> v1 >> v2;

        sum += rev_num(v1);
        sum += rev_num(v2);

        cout << rev_num(sum) << endl;
    }

    return 0;
}

int rev_num(int num){
    int div = 1, mul = 1;
    int tmp = 0, dec = 0;
    int res = 0;
    // find max degree
    while(num / div != 0){
        div *= 10;
    }
    div /= 10;
    // find reverse number
    while(div != 0){
        //cout << div << " " << mul << " " << res << endl;
        dec = num / div - tmp;
        res += mul * dec;
        tmp = tmp*10 + dec*10;
        mul *= 10;
        div /= 10;
    }
    return res;
}
