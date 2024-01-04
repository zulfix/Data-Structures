#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>
#include <iomanip>
using namespace std;


class Player {
public:
void setName(string inputlast, string inputName);
string getLastName() const;
string getName() const;
void setweight(double Playerweight);
double getweight() const;
void setheight(double Playerheight);
double getheight() const;

private:
string lastname;
string name;
double weight;
double height;
};

class Players {
public:
void InputPlayers();
void PrintPlayerList();
void PrintInfoPlayers();
void SortAscendingList();
void RemovePlayerInfo();
void SearchPlayer();
void RankPlayersW();
void RankPlayersH();
void ReverseList();

private:
vector<Player> PlayerList;

};

void Player::setName(string inputlast, string inputName) { 
lastname= inputlast;
name = inputName; }
string Player::getLastName() const { 
  return lastname; }
string Player::getName() const { 
  return name; }
void Player::setweight(double inputweight) { weight = inputweight; }
double Player::getweight() const { 
  return weight; }
void Player::setheight(double inputheight) { height = inputheight; }
double Player::getheight() const { 
  return height; }

void Players::PrintPlayerList() {
    for (unsigned int i = 0; i < PlayerList.size(); ++i) {
        const Player& currPlayer = PlayerList.at(i);
        cout << i + 1 << ") " << currPlayer.getLastName() << " " << currPlayer.getName() << endl;
    } 
    cout << endl << endl;
}

void Players::PrintInfoPlayers() {
    for (unsigned int i = 0; i < PlayerList.size(); ++i) {
        const Player& currPlayer = PlayerList.at(i);
        cout << i + 1 << ") " << currPlayer.getLastName() << " " << currPlayer.getName() << endl
             << "Weight in pounds: " << currPlayer.getweight() << endl
             << "Height (feet.inches): " << currPlayer.getheight() << endl << endl;
    }
    cout << endl << endl;
}

void Players::SortAscendingList() {
  Player currPlayer;
  Player postPlayer;
  Player smallPlayer;
  Player tempPlayer;
  unsigned int i;
  unsigned int j;
  unsigned int k=1;
    for (i = 0; i < PlayerList.size() -1; ++i) {
      currPlayer=PlayerList.at(i);
      smallPlayer=PlayerList.at(i);
      for(j=i+1; j< PlayerList.size(); j++){
        postPlayer=PlayerList.at(j);
        if((postPlayer.getLastName().at(0)<smallPlayer.getLastName().at(0))|| ((postPlayer.getLastName().at(0)==smallPlayer.getLastName().at(0)) && (postPlayer.getLastName().at(1)==smallPlayer.getLastName().at(1)) && (postPlayer.getLastName().at(2)<smallPlayer.getLastName().at(2))) || ((postPlayer.getLastName().at(0)==smallPlayer.getLastName().at(0)) && (postPlayer.getLastName().at(1)<smallPlayer.getLastName().at(1)))||((postPlayer.getLastName()==smallPlayer.getLastName()) && (postPlayer.getName().at(0)<smallPlayer.getName().at(0)))){
        smallPlayer= PlayerList.at(j);
          tempPlayer=PlayerList.at(i);
          currPlayer=PlayerList.at(j);
          PlayerList.at(i)=currPlayer;
          PlayerList.at(i)=smallPlayer;
          PlayerList.at(j)=tempPlayer;
        }
        else{
          smallPlayer=PlayerList.at(i);
        }
 }
      cout<<k<<") "<<currPlayer.getLastName()<< " "<<currPlayer.getName()<<endl;
      k++;
}
    postPlayer=PlayerList.at(PlayerList.size()-1);
    cout<<PlayerList.size()<<") "<<postPlayer.getLastName()<< " "<<postPlayer.getName()<<endl;
}

void Players::ReverseList() {
    unsigned int playerStart = 0;
    unsigned int playerEnd = PlayerList.size() - 1;

    while (playerStart < playerEnd) {
        Player tempPlayer = PlayerList[playerStart];
        PlayerList[playerStart] = PlayerList[playerEnd];
        PlayerList[playerEnd] = tempPlayer;

        playerStart++;
        playerEnd--;
    }
}

void::Players::InputPlayers() {
  Player CP;
  int addplayer, i;
  string lastName, firstName;
  double weight, height;
  cout << "Type 1 to add new player.." << endl;
  cout << "Type 2 to add a new player in a specific position." << endl;
  cout << "Type 3 to go back." << endl;
  cout << "Enter your choice: "<< endl;

  cin >> addplayer;

  while (addplayer == 1) {
    cin.ignore(); 
      cout << "Enter first name: ";
      getline(cin, firstName);
     cout << "Enter last name: ";
     getline(cin, lastName);
      CP.setName(lastName, firstName);
     cout << "Enter weight in pounds: ";
     cin >> weight;
     CP.setweight(weight);
      cout << "Enter height (feet, inches): ";
      cin >> height;
     CP.setheight(height);
     PlayerList.push_back(CP);
     cout << endl;
     cout << "Type 1 to add new player." << endl;
     cout << "Type 2 to add a new player in a specific position." << endl;
     cout << "Type 3 to go back. " << endl;
     cout <<"Enter your choice: " << endl;
     cin >> addplayer;
  }

  if (addplayer == 2) {
    cout << "Please enter the position in the list of players you want to add: "<< endl;
    cin >> i;
    cin.ignore();
    cout << "Enter first name: ";
    getline(cin, firstName);
    cout << "Enter last name: ";
    getline(cin, lastName);
    CP.setName(lastName, firstName);
    cout << "Enter weight in pounds: ";
    cin >> weight;
    CP.setweight(weight);
    cout << "Enter height (feet, inches): ";
    cin >> height;
    CP.setheight(height);
    PlayerList.insert(PlayerList.begin() + i - 1, CP);
    cout << endl;
  }

  else if (addplayer == 3) {
       cout << "Out." << endl<< endl;
  } else {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(),'\n');
      InputPlayers();
      cout << endl;
  }

}

void Players::RemovePlayerInfo(){
  Player cPlayer;
    string Pfirst;
    string Plast;
    cin.ignore(); 
      cout<< "Enter first name: ";
      getline(cin, Pfirst);
      cout<< "Enter last name: ";
      getline(cin, Plast);

    cPlayer.setName(Plast, Pfirst);
    for(int i = 0; i < PlayerList.size(); i++){
      if((cPlayer.getName()==PlayerList.at(i).getName()) && (cPlayer.getLastName()==PlayerList.at(i).getLastName())){
      PlayerList.erase(PlayerList.begin()+i);
        cout << "Your player had been removed."<<endl;
        cout << endl;
      }
      else{
        cout << "Player not found, sorry. Try again later." <<endl;
        cout << endl;
      }
    }
    cout << endl;

}

void Players::SearchPlayer(){
  Player cPlayer;
    string Pfirst;
    string Plast;
    cin.ignore();
    cout<< "Enter first name: ";
    getline(cin, Pfirst);
    cout<< "Enter last name: ";
    getline(cin, Plast);

    cPlayer.setName(Plast, Pfirst);
    int count = 0;
    for(int i=0; i<PlayerList.size(); i++){
      if((cPlayer.getName()==PlayerList.at(i).getName()) && (cPlayer.getLastName()==PlayerList.at(i).getLastName()))  {
        cout << "Found it" << endl;
        cout << PlayerList.at(i).getName();
        cout << " " <<PlayerList.at(i).getLastName() << " with ";
        cout << PlayerList.at(i).getweight();
        cout << " pounds and " << PlayerList.at(i).getheight();
        cout << " (feet.inches)" << endl;
        cout << "The Player was found in the list at position number ";
        cout << i+1 << endl;
        cout << endl;
      count++;
      }

    }

    if (count == 0) {
      cout << "Player not found, sorry. Try later." << endl;
      cout << endl;
    }
}

void Players::RankPlayersW(){
  Player currPlayer;
  Player postPlayer;
  Player tempPlayer;
  Player smallPlayer;
  Player maxPlayer;
  unsigned int i=0;
  unsigned int j=i+1;
      for (i = 0; i < PlayerList.size() -1; ++i) {
        currPlayer=PlayerList.at(i);
        smallPlayer=PlayerList.at(i);
        for(j=i+1; j< PlayerList.size(); j++){
          postPlayer=PlayerList.at(j);
          if(postPlayer.getweight()<currPlayer.getweight()){
            smallPlayer= PlayerList.at(j);
            tempPlayer=PlayerList.at(i);
            currPlayer=PlayerList.at(j);
            PlayerList.at(i)=currPlayer;
            PlayerList.at(i)=smallPlayer;
            PlayerList.at(j)=tempPlayer;

          }
        }
      }
  cout<<endl<<endl;
  smallPlayer=PlayerList.at(0);
  postPlayer=PlayerList.at(PlayerList.size()-1);
  cout<<"The player with the maximum weight within the list is "<< postPlayer.getName()<<endl;
  cout<<"with "<< postPlayer.getweight()<<" pounds."<<endl;
  cout<<"The player with the minimum weight within the list is "<<smallPlayer.getName()<<endl;
  cout<<"with "<< smallPlayer.getweight()<<" pounds."<<endl<<endl;

}

void Players::RankPlayersH(){
  Player currPlayer;
    Player postPlayer;
    Player tempPlayer;
    Player smallPlayer;
    Player maxPlayer;
    unsigned int i=0;
    unsigned int j=i+1;
        for (i = 0; i < PlayerList.size() -1; ++i) {
          currPlayer=PlayerList.at(i);
          smallPlayer=PlayerList.at(i);
          for(j=i+1; j< PlayerList.size(); j++){
            postPlayer=PlayerList.at(j);
            if(postPlayer.getheight()<currPlayer.getheight()){
              smallPlayer= PlayerList.at(j);
              tempPlayer=PlayerList.at(i);
              currPlayer=PlayerList.at(j);
              PlayerList.at(i)=currPlayer;
              PlayerList.at(i)=smallPlayer;
              PlayerList.at(j)=tempPlayer;

            }
          }
        }
  cout<<endl<<endl;
  smallPlayer=PlayerList.at(0);
  postPlayer=PlayerList.at(PlayerList.size()-1);
  cout<<"The player with the maximum height within the list is "<< postPlayer.getName()<<endl;
  cout<<"with "<< postPlayer.getheight()<<" (feet.inches)."<<endl;
  cout<<"The player with the minimum height within the list is "<<smallPlayer.getName()<<endl;
  cout<<"with "<< smallPlayer.getheight()<<" (feet.inches)."<<endl<<endl;
  }


int main() {
  Players AllPlayers;
  int input0;
  int input1;
  int input5;
  while(true){
  cout<<"Welcome to Go Go Cardinals !!!"<< endl;
  cout << "1. List of Players" << endl;
  cout << "2. Add Player" << endl;
  cout << "3. Remove Player" << endl;
  cout << "4. Search Player" << endl;
  cout << "5. Rank of Players" << endl;
  cout << "6. Quit" << endl;
  cout << "Enter your Choice: " << endl;

    cin >> input0;
    if (input0 < 1 || input0 > 6) {
      cout << "Invalid input. Please enter a number between 1 and 6." << endl;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(),'\n');
      cout<<endl;
    }
  else{
  switch (input0){
        case 1: 
          cout<<endl<<endl;
          cout<< "Choose between 1 or 2:"<<endl;
          cout<< "1. See the list of players in the adding order. "<<endl;
          cout<< "2. See the list in reverse sequence. "<<endl;
          cout<< "3. See the list of players in ascending alphabetical order. "<<endl;
          cout<< "4. See the list of players (information included)."<<endl;
          cout<<"Enter your Choice:"<<endl;
          cin>>input1;
          cout<<endl<<endl;
          if(input1==1){
          AllPlayers.PrintPlayerList();
          cout<<endl<<endl;
          }
          else if(input1==2){
            AllPlayers.ReverseList();
            AllPlayers.PrintPlayerList();
            cout<<endl<<endl;
          }
          else if(input1==3){
            cout << "Players Sorted in Ascending Alphabetical order:" << endl << endl;
            AllPlayers.SortAscendingList();
            cout<<endl<<endl;
          }
          else if(input1==4){
            cout << "List of Players including information" << endl << endl;
            AllPlayers.PrintInfoPlayers();
            cout<<endl<<endl;
          }
          break;
        case 2:          
          AllPlayers.InputPlayers();
         break;
        case 3: 
          cout<<endl<<endl;
          AllPlayers.RemovePlayerInfo();
          cout<<endl<<endl;
          break;
        case 4: 
          cout<<endl<<endl;
          AllPlayers.SearchPlayer();
          cout<<endl<<endl;
          break;
        case 5: 
          cout<<endl<<endl;
          cout << "Rank of Players" << endl;
          cout<< "Chooose between 1 or 2:"<<endl;
          cout<< "1. Players with maximum and minimum weight."<<endl;
          cout<< "2. Players with maximum and minimum height."<<endl;
          cout<< "Enter your choice: "<<endl;
          cin>>input5;
          if(input5==1){
            cout<<endl<<endl;
            AllPlayers.RankPlayersW();
            cout<<endl<<endl;
          }
          else if(input5==2){
            cout<<endl<<endl;
            AllPlayers.RankPlayersH();
            cout<<endl<<endl;
          }
          break;
        case 6: 
          cout << "Bye." << endl;
          return 0;
          break;
        default: 
          return 0; break;
       } 
   }
  }
}

/*CS 291 Final Project*/
