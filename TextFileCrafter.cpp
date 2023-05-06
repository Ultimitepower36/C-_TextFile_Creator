#include <iostream>
#include <string>
#include <sstream>
#include <fstream>  
using namespace std;

bool z = false;
string x;


void File_Creation() {
    //user input should be an actual file name. IE: Text_File. the .txt bit comes automaticly.
    cout << "What would you like to name your file? (Note: the .txt bit has been done for you): " << endl;
    cin >> x;
    ofstream NewFile;
    NewFile.open(x + ".txt", ios::out | ios::trunc);
    if (!NewFile) {
        cout << "Could not create file!";
        return;
    }
    string quit = "y";
    string line;
    while (quit != "n") {
        cout << "What do you want written in the file?: " << endl;
        cin >> line;
        NewFile << line << endl;
        cout << "Do you want to add another line?(y/n)? " << endl;
        cin >> quit;
    }
    NewFile.flush();
    NewFile.close();
    
    cout << "Thank you for using this service, have a nice day!" << endl;
}


void File_Editing() {
    //User should give exact file location. IE: C:\Users\canon.h2net\Desktop\Projects\TextFileCrafter.cpp
    cout << "Where is the file you would like to edit? (Path to file): " << endl;
    cin >> x;
    ifstream ReadFile;
    stringstream outbuffer;
    ReadFile.open(x);

    string quit = "n";
    string word;
    string line;
    while (quit != "y" and ReadFile) {
        getline(ReadFile, word);
        cout << word << endl;
        cout << "Is this a line you want edited?(y/n): " << endl;
        cin >> quit;
        if (quit == "y"){
            cout << "What do you want written in this line?: " << endl;
            cin >> line;
            outbuffer << line;
            cout << "Do you want to edit another line?(y/n)? " << endl;
            cin >> quit;
            if (quit == "n"){
                quit = "y";
            }
            else if (quit == "y"){
                quit = "n";
            }
            else{
                cout << "That was not y or n, so we will take your answer as no." << endl;
                quit = "n";
            }
        }
        else{
            cout << "That was not y or n, so we will take your answer as no." << endl;
            quit = "n";
        }
    }
    ReadFile.close();
    ofstream Output;
    Output.open(x);
    Output << outbuffer.rdbuf();
    Output.close();

}

int main() {
    cout << "Hello User!" << endl;
    cout << "Welcome to the TEXT_EDITOR Software!" << endl;
    while (z == false){
        cout << "Would you like to make or edit a text file (Input: Make or Edit or No): " << endl;
        cin >> x;
        if (x == "Make")
        {
            File_Creation();
            z = true;
        } 
        else if (x == "Edit")
        {
            File_Editing();
            z = true;
        }
        else if (x == "No"){
            cout << "Understood. Have a great day!" << endl;
            cin >> x;
            z = true;
        }
        else{
            cout << "That is not a valid responce, please try again." << endl;
        }
    }
    return 0;
}