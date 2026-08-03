#include<iostream>
using namespace std;

int main(){
int numPlate[10]={1212, 2002, 0456, 6789, 5679, 4222, 7870, 2354, 6568, 3215};
int target=6789;
int n=9;

for(int i=0; i<=9; i++){
    if(numPlate[i]==target){
     cout << "the number plate that we are finding is : " << numPlate[i];
      break;
    }
}

    return 0;
}