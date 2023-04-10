/*
 * This is a number-guessing game:
 * A random number between 1 and 100 is generated based on computer current time.
 * You can enter a number to guess what the random number is in 5 runs.
*/
#include<iostream>
#include<cstdlib>   // This library allows us to generate random number based on time stamps.

using namespace std;
int main(){
    srand((unsigned) time(NULL));
    int num;
    int guess;
    int count = 5;        // you have 5 chances left
    num = rand()%100 + 1; // generate a random num between 1 and 100
    while(count > 0){
    cout << "-----------------------------------------" << endl;
    cout << "please enter a number between 1 to 100: " << endl;

    cin >> guess;
    
    if(guess > num){
        cout << "Too big" << endl;
    } else if(guess < num) {
        cout << "Too small" << endl;
    } else {
        cout << "Correct! You have found the number in " << 6-count << " turn(s)!" << endl;
        break;
    }
        count --;
        cout << "you have " << count << " turns left." << endl;
    
    }
    if(count == 0){
        cout << "You have run out of chances. The correct answer is " << num << endl;

    }

    return 0;
}