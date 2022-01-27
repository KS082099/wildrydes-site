#include<iostream>
#include<stdlib.h>
using namespace std;

int main() {
    //Declare required variables and initialize as required.
    int dice;
    int totalScore = 0;
    int success = 0;
    int failed = 0;
    int highest = 1;
    int lowest = 6;
    int maxScore = INT_MIN;

    //Roll the Dice.
    srand(time(0));
    for(int i = 0; i < 10; i++) {
        dice = (int)(rand()%6 + 1);
        if(dice == 1 || dice == 2 || dice == 3 || dice == 6) {
            totalScore += dice;
            success++;
            if(dice > highest) {
                highest = dice;
            }
            if(dice < lowest) {
                lowest = dice;
            }
            if(totalScore > maxScore) {
                maxScore = totalScore;
            }
        }
        else if(dice == 4) {
            totalScore = 0;
            failed++;
        }
        else if(dice == 5) {
            failed++;
            break;
        }
    }

    //Print Output.
    cout<<"\nTotal Score: "<<totalScore<<endl;
    cout<<"Number of Successful Attempts: "<<success<<endl;
    cout<<"Number of Failed Attempts: "<<failed<<endl;
    cout<<"Highest Attempt: "<<highest<<endl;
    cout<<"Lowest Attempt: "<<lowest<<endl;
    if(maxScore == INT_MIN) //So that we do not print INT_MIN if we get 5 on the first attempt.
        cout<<"Maximum Score: 0"<<endl;
    else
        cout<<"Maximum Score: "<<maxScore<<endl;
    cout<<"\n";
    return 0;
}
