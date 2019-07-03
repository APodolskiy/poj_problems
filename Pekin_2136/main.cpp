#include <iostream>
#include <malloc.h>
#include <stdio.h>


using namespace std;

#define LETTERS_NUM 26
#define MAX_LENGTH 72
#define LINE_NUM 4

#define MY

int alph[LETTERS_NUM + 1];
char line[MAX_LENGTH + 1];

#ifdef MY
int main(int argc, char *argv[]){
    freopen("input.txt", "r", stdin);
    short start_ch = (short)'A';
    short ch_pos = 0;
    int max_cnt = 0;

    for(int i = 0; i < LETTERS_NUM; ++i){
        alph[i] = 0;
    }

    for(int i = 0; i < LINE_NUM; ++i){
        cin.getline(line, MAX_LENGTH, '\n');
        char *pos = line;
        while((*pos) != '\0'){
            //cout << *pos << endl;
            ch_pos = (short)(*pos) - start_ch;
            //cout << ch_pos << endl;
            if(ch_pos >= 0 && ch_pos <= LETTERS_NUM){
                alph[ch_pos]++;
                //cout << alph[ch_pos] << endl;
                if(max_cnt < alph[ch_pos]){
                    max_cnt = alph[ch_pos];
                }
            }
            pos++;
        }
    }

    for(int i = max_cnt; i >= 0; --i){
        for(int j = 0; j < LETTERS_NUM; ++j){
            if(alph[j] >= i){
                if(i > 0){
                    cout << "*";
                }
                else{
                    cout << (char)(start_ch + j);
                }
                if(j < LETTERS_NUM - 1){
                    cout << " ";
                }
            }
            else{
                cout << " ";
                if(j < LETTERS_NUM - 1){
                    cout << " ";
                }
            }
        }
        cout << endl;
    }

    return 0;
}
#elif

#include <string.h>

int main()
{
    freopen("input.txt", "r", stdin);
    char a[100];
    int b[26],max,cnt,no;
    for(int i=0;i<26;i++)
        b[i]=0;
    max=0;
    for(int i=0;i<4;i++)
    {
        cin.getline(a,99);
        for(int j=0;j<strlen(a);j++)
        {
            if(a[j]>=65&&a[j]<=90)
            {
                b[a[j]-65]++;
                if(b[a[j]-65]>max)
                    max=b[a[j]-65];
            }
        }
    }
    while(max)
    {
        cnt=no=0;
        for(int i=0;i<26;i++)
            if(b[i]==max)
            {
                if(cnt)
                {
                    printf(" ");
                    for(int j=0;j<no;j++)
                        printf("  ");
                    no=0;
                }
                printf("*");
                cnt=1;
                b[i]--;
            }
            else
            {
                if(!cnt)
                    printf("  ");
                else
                    no++;
            }
        printf("\n");
        max--;
    }
    for(int i=0;i<26;i++)
        printf("%c ",i+65);
    return 0;
}
#endif
