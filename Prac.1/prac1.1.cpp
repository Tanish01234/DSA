#include <iostream>
using namespace std;

int main(){
    int n,h;
    cout << "Enter number of items and hours: ";
    cin >> n >> h;

    int arr[n];

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    int rotation = h%n;

    for(int i=0;i<n;i++){
        cout << arr[(i+rotation)%n];
    }
    return 0;
}