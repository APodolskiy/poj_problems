#include <iostream>
#include <malloc.h>
#include <stdio.h>
#include <cstring>

using namespace std;

#define MAX_LEN 1000
#define O (int)'0'

char *mult(char *a, char *b);
unsigned long strlenc(const char *a);
char *strip(char *s);
int find_dot_pos(const char *s);
char *revert_str(char *s);


char num[MAX_LEN];

int main(int argc, char *argv[]){
    freopen("input.txt", "r", stdin);
    int n;

    while(scanf("%s%d", num, &n) == 2){
        char res[MAX_LEN] = {'\0'};
        char copy_num[MAX_LEN] = {'\0'};
        if(n == 0){
            cout << '1' << endl;
            continue;
        }
        unsigned long l = strlenc(num);

        if(l == 0){
            cout << '0' << endl;
            continue;
        }
        else{
            num[l] = '\0';
        }

        revert_str(num);
        char *p = num;
        int stp = 0;
        while(*p != '\0'){
            copy_num[stp] = *p;
            res[stp++] = *p;
            ++p;
        }
        res[stp] = '\0';

        for(int i = 0; i < n - 1; ++i){
            mult(res, copy_num);
        }

        //cout << "Striped number " << revert_str(strip(num)) << endl;
        //cout << res << endl;
        revert_str(res);
        strip(res);
        cout << res << endl;
        cout << flush;
        //cout << revert_str(mult(num, num)) << endl;
        memset(num, '\0', MAX_LEN);
        memset(res, '\0', MAX_LEN);
        memset(copy_num, '\0', MAX_LEN);
    }


    return 0;
}

int find_dot_pos(const char *s){
    int step = 0;
    while(*s != '\0'){
        if(*s == '.'){
            return step;
        }
        ++s;
        ++step;
    }
    return -1;
}

char *revert_str(char *s){
    unsigned long l = strlenc(s);
    for(int i = 0; i < l/2; ++i){
        swap(s[i], s[l - i - 1]);
    }
    return s;
}

char *mult(char *a, char *b){
    char result[MAX_LEN] = {'\0'};
    unsigned long result_len = 0;
    unsigned long r_cur_pos = 0;
    int carry = 0;
    int value = 0;
    int cur_value = 0;

    unsigned long size_a = strlenc(a);
    unsigned long size_b = strlenc(b);

    // find dot positions
    unsigned long dot_pos = -1;
    unsigned long a_dot_pos = find_dot_pos(a);
    unsigned long b_dot_pos = find_dot_pos(b);

    if(a_dot_pos == -1 and b_dot_pos == -1){
        dot_pos = -1;
    }
    else{
        dot_pos = ((a_dot_pos == -1) ? 0 : a_dot_pos) + ((b_dot_pos == -1) ? 0 : b_dot_pos);
    }
    result[dot_pos] = '.';

    bool dot_a = false, dot_b = false, dot_r=false;
    // multiply as a convolution
    for(int i = 0; i < size_a; ++i){
        if(a[i] == '.'){
            dot_a = true;
            continue;
        }
        dot_b = false;
        for(int j = 0; j < size_b; ++j){
            if(b[j] == '.'){
                dot_b = true;
                continue;
            }
            r_cur_pos = i + j + (dot_a ? -1 : 0) + (dot_b ? -1 : 0);
            if(r_cur_pos >= dot_pos){
                ++r_cur_pos;
            }
            value = ((int)a[i] - O)*((int)b[j] - O);
            cur_value = (int)result[r_cur_pos];
            if(cur_value < O || cur_value > O + 9 || r_cur_pos > result_len){
                cur_value = 0;
            }
            else{
                cur_value = cur_value - O;
            }
            cur_value = cur_value + value + carry;
            carry = cur_value / 10;
            cur_value = cur_value % 10;
            result[r_cur_pos] = (char)(O + cur_value);
            if(r_cur_pos > result_len){
                result_len = r_cur_pos;
            }
        }

        r_cur_pos = result_len + 1;
        if(r_cur_pos >= dot_pos && result_len < dot_pos){
            ++r_cur_pos;
        }

        while(carry > 0){
            cur_value = (int)result[r_cur_pos];
            if(cur_value < O || cur_value > O + 9){
                cur_value = 0;
            }
            else{
                cur_value = cur_value - O;
            }
            value = carry - 10*(carry / 10) + cur_value;
            result[r_cur_pos] = (char)((value % 10) + O);
            carry = carry / 10 + value / 10;
            if(r_cur_pos > result_len){
                result_len = r_cur_pos;
            }
            ++r_cur_pos;
        }
    }

    result[result_len + 1] = '\0';
    for(int i = 0; i < result_len + 1; ++i){
        a[i] = result[i];
    }

    return a;
}

unsigned long strlenc(const char *a){
    const char *str;
    for(str = a; *str; ++str){}
    return (str - a);
}

char *strip(char *s){
    unsigned long length = strlenc(s);
    char *str_end;
    bool has_dot = false;
    bool has_num = false;
    char *tmp;

    if(length <= 0){
        return s;
    }
    // copy char array
    tmp = (char *)malloc((length + 1) * sizeof(char));
    unsigned long tmp_l = 0;
    for(int i = 0; i < length; ++i){
        if(s[i] == '.'){
            has_dot = true;
            has_num = true;
        }
        if(!has_num){
            if(s[i] != '0'){
                has_num = true;
            }
            else{
                continue;
            }
        }
        tmp[tmp_l++] = s[i];
    }
    tmp[tmp_l] = '\0';
    // Remove trailing zeros
    length = strlenc(tmp);
    str_end = tmp + tmp_l - 1;
    while((*str_end == '0') && (str_end != tmp)){
        --str_end;
    }
    if(*str_end != '.'){
        *(str_end + 1) = '\0';
    }
    else{
        *str_end = '\0';
    }
    // copy data to original array

    char *p_t = tmp;
    char *p_o = s;
    for(;*p_t != '\0'; ++p_t, ++p_o){
        (*p_o) = (*p_t);
    }
    *p_o = '\0';

    free(tmp);
    return s;
}
