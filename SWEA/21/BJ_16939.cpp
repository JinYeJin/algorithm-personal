#include <stdio.h>

using namespace std;

int main(){
    FILE *stream = freopen("SWEA\\21\\16939_input.txt", "r", stdin);
    if(!stream) printf("freopen");

    
    return 0;
}