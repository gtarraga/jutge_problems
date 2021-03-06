//Solution for the problem: P68688

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

const int MAX_MEMORY = 30000; //#The number of 8 bit memory cells that the original brainfuck had

int main(){
    vector<char> memory(MAX_MEMORY, 0);
    string instructions = "++++++++[>+++++++++<-]>.<+++++[>+++++<-]>++++.+++++++..+++.<++++++++[>---------<-]>-------.<+++++++++[>+++++++++<-]>++++++.--------.+++.------.--------.<++++++++[>--------<-]>---."; //bf code here
    stack<int> pos_buc;
    int pointer = 0;

    for(int i = 0; i<instructions.size(); ++i){
        switch (instructions[i]) {
            case '+':
                memory[pointer]++;
                break;
            case '-':
                memory[pointer]--;
                break;
            case '>':
                pointer++;
                break;
            case '<':
                pointer--;
                break;
            case '[':
                pos_buc.push(i);
                break;
            case ']':
                if(memory[pointer] == 0) pos_buc.pop();
                else i = pos_buc.top();
                break;
            case '.':
                cout<<memory[pointer];
                break;
            case ',':
                char a;
                cin>>a;
                memory[pointer] = a;
                break;

        }
    }
    cout<<endl;
}
