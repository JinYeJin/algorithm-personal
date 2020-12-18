#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main(){
    FILE *stream = freopen("S2\\24\\input\\1120.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string A, B, AA;

    cin >> A >> B;

    AA = A;

    while(A.size() != B.size()){
        A = B[B.size()-A.size()-1] + A;
        cout <<"BBB: " <<  B[AA.size()] << "\n";
        AA = AA + B[AA.size()];
        cout << A << " " << AA;
    }

    int a_count = 0;
    int aa_count = 00;

    for(int i = 0; i < A.size(); i++){
        if(A[i] != B[i]) a_count++;
        if(AA[i] != B[i]) aa_count++;        
    }

    cout << (a_count < aa_count ? a_count : aa_count);

    return 0;
}