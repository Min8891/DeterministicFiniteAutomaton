//  main.cpp
//  Implement a DFA to extract all matching pattern strings
//  including at least two A's from a given input DNA sequence string
//  Created by Minjing Liang on 10/29/21.
#include <iostream>
#include <string>
using namespace std;
bool DFA(string str){
    int state = 0;                // Initialize start state
    size_t len = str.size();
    for(int n=0; n<len; n++){
        switch(str.at(n)){
            case 'A':            // Encounter letter A
                if(state < 2)    // If state is not the final state
                    state++;     // Transit to next state
                break;
            case 'T':            // Encounter letter T, G,and C
            case 'G':            // Stay at current state
            case 'C':
               break;
            default:
                return false;
        }
    }
    if(state == 2)
        return true;        // String ends at final state
    else
        return false;
}

int main(){
    string str;            // Declare string variable
    while(true){
        cout << "Input a DNA sequence: ";
        getline(cin, str);
        if(str.empty()){
            cout << "Empty string, program exit." << endl;
            return 0;
        }
        cout << "Matching patterns are: \n\n";
        size_t len = str.size();                       // Get the length of the string
        for(int p=0; p<len; p++){                      // The start position of the substring
            for(int l=1; l<=len-p; l++){               // The length of the substring
                if(DFA(str.substr(p,l)) == true)       // If the substring matchs the pattern
                    cout << str.substr(p,l) << endl;   // Print out the substring
            }
        }
        cout << endl;
    }
    return 0;
}
