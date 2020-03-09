//
// Created by Yejin on 2020-02-03.
// 문제이름: 시각덧셈
// Problem address here.
// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PttaaAZIDFAUq&categoryId=AV5PttaaAZIDFAUq&categoryType=CODE&&&
//

#include <iostream>

using namespace std;

int main(){
    int test_case;
    cin >> test_case;

    for(int i = 0; i < test_case; i++){
        int time1[2];
        int time2[2];
        int sum_time1;
        int sum_time2;
        int total_time;
        int hour;
        int minute;

        // input
        for(int j = 0; j < 2; j++){
            cin >> time1[j];
        }

        for(int j = 0; j < 2; j++){
            cin >> time2[j];
        }

        // 시간을 분으로 환산해서 모두 더함
        sum_time1 = (time1[0] * 60) + time1[1];
        sum_time2 = (time2[0] * 60) + time2[1];
        total_time = sum_time1 + sum_time2;

        //분을 시로 바꿈
        hour = (total_time / 60) % 12;
        minute = total_time % 60;

        cout << "#" << i+1 << " ";
        cout << hour << " " << minute;
    }
}

