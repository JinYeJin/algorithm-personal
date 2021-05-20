#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

int binary_to_decimal(int n) {
   int decimal_num = 0;
   int base = 1;
   int temp = n;

   while (temp) {
      int digit = temp % 10;
      temp = temp/10;
      decimal_num += digit * base;
      base = base*2;
   }
   return decimal_num;
}

int main(){
    FILE *stream =freopen("S2\\26\\input\\6568.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int pc = 0;
    int adder = 0;
    int memory[17];
    vector<string> commands;

    memset(memory, 0, sizeof(memory));

    for(int i = 0; i < 32; i++){
        string command;
        cin >> command;
        commands.push_back(command);
    }

    bool is_running = true;

    while(is_running){
        string command = commands[pc];
        string op = command.substr(0, 3);
        string address = command.substr(3);
        int deci_op = binary_to_decimal(stoi(op));
        int deci_address = binary_to_decimal(stoi(address));

        switch (deci_op)
        {
        case 0:// STA x   �޸� �ּ� x�� ������� ���� �����Ѵ�.
            memory[deci_address] = adder;
            break;
        case 1: // LDA x   �޸� �ּ� x�� ���� ������ �ҷ��´�.
            adder = memory[deci_address];
            break;
        case 2: // BEQ x   ������� ���� 0�̸� PC ���� x�� �ٲ۴�.
            if(adder == 0) pc = deci_address-1;
            break;
        case 3: // NOP     �ƹ� ���굵 ���� �ʴ´�.
            break;
        case 4: // DEC     ����� ���� 1 ���ҽ�Ų��.
            adder -= 1;
            adder %= 32;
            break;
        case 5: //INC     ����� ���� 1 ������Ų��.
            adder += 1;
            adder %= 32;
            break;
        case 6: // JMP x   PC ���� x�� �ٲ۴�.
            pc = deci_address;
            break;
        case 7: // HLT     ���α׷��� �����Ѵ�.
            is_running = false;
            break;
        }
        pc++;
        pc %= 32;
    }

    bool answer[8];

    for(int i = 7; i >= 0; i--){
        answer[i] = adder % 2;
        adder /= 2;
    }

    for(int i = 0; i < 8; i++){
        cout << answer[i];
    }

    return 0;
}