#include <iostream>
#include <stdio.h>
#include <malloc.h>

using namespace std;

#define abs(x) ((x > 0) ? (x) : (-x))

int manh_dist(int i, int k, int j);

int main(int argc, char *argv[]){
    freopen("input.txt", "r", stdin);
    int tc;
    int ptrl;
    int dist;

    cin >> tc;

    for(int t = 0; t < tc; ++t){
        cin >> ptrl;

        cout << "Scenario #" << t + 1 << ":" << endl;
        if(ptrl == 0){
            cout << "slice #1:" << endl;
            cout << 0 << endl;
            cout << endl;
        }
        else{
            for(int k=-ptrl; k <= ptrl; ++k){
                cout << "slice #" << k + ptrl + 1 << ":" << endl;
                for(int j=ptrl; j >= -ptrl; --j){
                    for(int i=-ptrl; i <= ptrl; ++i){
                        dist = manh_dist(i, j, k);
                        //cout << i << " " << j << " " << k << " " << dist << endl;
                        if(dist > ptrl){
                            //cout << "Here! " << dist << " " << ptrl << endl;
                            cout << ".";
                        }
                        else{
                            //cout << "Printing dist " << endl;
                            //cout << dist << " " << ptrl << endl;
                            cout << dist;
                        }
                    }
                    cout << endl;
                }
            }
            cout << endl;
        }
    }

    return 0;
}

int manh_dist(int i, int k, int j){
    return abs(i) + abs(k) + abs(j);
}
