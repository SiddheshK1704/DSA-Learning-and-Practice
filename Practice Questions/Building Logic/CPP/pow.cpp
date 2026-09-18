#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter the number:\n";
    cin >> n;
    
    cout << "Enter the power you want:\n";
    int p;
    cin >> p;

    int ans = 1;

    for(int i = 0; i < p; i++){
        ans *= n;
    }

    cout << "The number is:\n";
    cout << ans;

    return 0;
}