#include<iostream>
using namespace std;

int main(){
int numPlate[11] = {1267, 2452, 1256, 6642, 6779, 9022,
                      7210, 2245, 6146, 1245, 2541};
  int target = 1267;
  int n = 10;

for(int i=0; i<=10; i++){
    if(numPlate[i]==target){
     cout << "the number plate that we are finding is : " << numPlate[i];
      break;
    }
}

    return 0;
}


// Linear_Method.