#include<iostream>
using namespace std;

int main() {

    int age,c;
    cout << "Enter age of a user:";
    cin>>age;

    if (age >= 18) {
    	cout << "Are you an indian citizen Press '1 for yes' or '0 for no'";
    	cin>>c;
    	if(c==1)
        cout << "You are eligible for voting";
        else 
        cout << "You are not eligible for voting";
    }
    else 
        cout << "You are not eligible for voting";

    return 0;
}
