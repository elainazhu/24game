#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> cards = {6,1,6,8};
    vector<double> inputs(cards.begin(),cards.end());
    vector<char> ops = {'+', '-', '*', '/'};
    sort(inputs.begin(), inputs.end());
    do {
        for(auto op1 : ops){
            for(auto op2 : ops){
                for(auto op3 : ops){
                    // cout<<inputs[0]<<op1<<inputs[1]<<op2<<inputs[2]<<op3<<inputs[3]<<endl;
                    auto apply = [](double a, double b, char op) -> double {
                        switch (op) {
                            case '+': return a + b;
                            case '-': return a - b;
                            case '*': return a * b;
                            default: return b != 0.0 ? a / b : -999999.0;
                        }
                    };
                    double eval1 = apply(inputs[0],inputs[1],op1);
                    double eval2 = apply(eval1,inputs[2],op2);
                    double eval3 = apply(eval2,inputs[3],op3);
                    if(abs(eval3 - 24.0) < 1e-8){
                        cout<<"(("<<inputs[0]<<op1<<inputs[1]<<')'<<op2<<inputs[2]<<')'<<op3<<inputs[3]<<endl;
                        //return true;
                    }
                    eval1 = apply(inputs[2],inputs[3],op3);
                    eval2 = apply(inputs[1],eval1,op2);
                    eval3 = apply(inputs[0],eval2,op1);
                    //cout<<eval3<<endl;
                    //cout<<inputs[0]<<op1<<'('<<inputs[1]<<op2<<'('<<inputs[2]<<op3<<inputs[3]<<"))"<<endl;
                    if(abs(eval3 - 24.0) < 1e-8){
                        cout<<inputs[0]<<op1<<'('<<inputs[1]<<op2<<'('<<inputs[2]<<op3<<inputs[3]<<"))"<<endl;
                        //return true;
                    }
                    eval1 = apply(inputs[0],inputs[1],op1);
                    eval2 = apply(inputs[2],inputs[3],op3);
                    eval3 = apply(eval1,eval2,op2);
                    if(abs(eval3 - 24.0) < 1e-8){
                        cout<<'('<<inputs[0]<<op1<<inputs[1]<<')'<<op2<<'('<<inputs[2]<<op3<<inputs[3]<<")";
                        //return true;
                    }
                    eval1 = apply(inputs[1],inputs[2],op2);
                    eval2 = apply(inputs[0],eval1,op1);
                    eval3 = apply(eval2,inputs[3],op3);
                    if(abs(eval3 - 24.0) < 1e-8){
                        cout<<'('<<inputs[0]<<op1<<'('<<inputs[1]<<op2<<inputs[2]<<')'<<")"<<op3<<inputs[3];
                        //return true;
                    }
                    eval1 = apply(inputs[1],inputs[2],op2);
                    eval2 = apply(eval1,inputs[3],op3);
                    eval3 = apply(inputs[0],eval2,op1);
                    if(abs(eval3 - 24.0) < 1e-8){
                        cout<<inputs[0]<<op1<<"(("<<inputs[1]<<op2<<inputs[2]<<')'<<op3<<inputs[3]<<")";
                        //return true;
                    }
                }
            }
        }
    } while (next_permutation(inputs.begin(), inputs.end()));
    //return false;
}