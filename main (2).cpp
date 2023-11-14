#include <iostream>
#include <string>
#include <fstream>
#include <string.h>
#include <vector>
#include <cstdlib>

using namespace std;

// define the Player struct
struct Player {
    string lastName;
    string firstName;
    string college;
    double height;
    double weight;
};
ostream& operator<<(ostream& os, const Player& player){
    os << player.firstName << " " << player.lastName << " " << player.height << " " << player.weight << " " << player.college << endl;
    return os;
}
bool operator>( const Player& player1, const Player& player2){
    return player1.firstName>player2.firstName;
}
// Print the data
    void printPlayers(const vector<Player> &players){
        for(long unsigned int i = 0; i<players.size();i++){
            cout << players[i];
        }
    }


// BubbleSort here
void bubbleSort(vector<Player> &players, bool lastName){
    
    for(;;){
        bool sorted = true;
        for(long unsigned int i = 0; i<players.size()-1;i++){
            if(players[i]>players[i+1] && !lastName){
                Player tmp = players[i+1];
                players[i+1] = players[i];
                players[i] = tmp;
                sorted = false;
            }
            else if(lastName && players[i].lastName>players[i+1].lastName){
                Player tmp = players[i+1];
                players[i+1] = players[i];
                players[i] = tmp;
                sorted = false;
            }
        }
        if(sorted)
            return;
    }
}

// Read the data into a vector of Players
void readDataFile(vector<Player> &players) {
    ifstream inputFile;
    string filename;

    cout << "Enter a filename to read:" << endl;
    getline (cin, filename);  

    // Open the file.
    inputFile.open(filename);
 
   // If the file successfully opened, process it.
   if (!inputFile.fail())
   {
        char fline[1024];
        inputFile.getline (fline, 1024);  // eat the heading line
       // cout << "read: " << fline << endl;
     
        while(inputFile.getline (fline, 1024)) {
           // cout << "read: " << fline << "\n\n";

            // Returns first token 
            char* token = strtok(fline, ","); 
  
            int field = 1;
        
            Player p;
        
            while (token != NULL) { 
                if (field == 2) {
                    p.firstName = token;
                }
                else if (field == 3) {
                    p.lastName = token;
                }
                else if (field == 5) {
                    p.height = atof(token);
                }
                else if (field == 6) {
                    p.weight = atof(token);
                }
                else if (field == 7) {
                    p.college = token;
                }
                else if (field == 8) {
                    char temp[5];
                    for(int i = 0; i<4; i++) {
                        temp[i] = token[i];
                    }
                    temp[4]='\0';
                   
                }
                else if (field >9) {
                    break;
                }

                token = strtok(NULL, ","); 
                field++;
            } 
        
            players.push_back(p);
        
        }
    
        // Close the file.
        inputFile.close();
    }

}


int main()
{
    vector<Player> players;
    
    cout << "\n******************* Reading the data *********************\n";
    readDataFile(players);
    printPlayers(players);
    
    cout << "\n******************* Sorting *********************\n";
    bubbleSort(players, false);
    cout << "\n******************* Sorted First *********************\n";
    printPlayers(players);

    bubbleSort(players, true);
    cout << "\n******************* Sorted Last *********************\n";
    printPlayers(players);

    return 0;
}
