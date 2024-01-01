#ifndef TEAMH
#define TEAMH

#include <string>

using namespace std;

class Team {
public:
   Team();
   Team(const string &teamName, int teamWins, int teamLosses);
   void SetName(const string &teamName);
   void SetWins(int teamWins);
   void SetLosses(int teamLosses);
   string GetName() const;
   int GetWins() const;
   int GetLosses() const;
   double GetWinPercentage() const;
   void PrintStanding() const;
   
private:
   string name;
   int wins;
   int losses;

};

#endif

#include <iostream>
#include <iomanip> 
#include "Team.h"
using namespace std;

Team::Team() {
    name = "";
    wins = 0;
    losses = 0;
}

Team::Team(const string &teamName, int teamWins, int teamLosses) {
    name = teamName;
    wins = teamWins;
    losses = teamLosses;
}

void Team::SetName(const string &teamName) {
    name = teamName;
}

void Team::SetWins(int teamWins) {
    wins = teamWins;
}

void Team::SetLosses(int teamLosses) {
    losses = teamLosses;
}

string Team::GetName() const {
    return name;
}

int Team::GetWins() const {
    return wins;
}

int Team::GetLosses() const {
    return losses;
}

double Team::GetWinPercentage() const {
    return static_cast<double>(wins) / (wins + losses);
}

void Team::PrintStanding() const {
    double winPercentage = GetWinPercentage();
    cout << "Win percentage: " << fixed << setprecision(2) << winPercentage << endl;

    if (winPercentage >= 0.5) {
        cout << "Congratulations, Team " << name << " has a winning average!" << endl;
    } else {
        cout << "Team " << name << " has a losing average." << endl;
    }
}

#include <iostream>
#include <string>
#include "Team.h"
using namespace std;

int main() {
   string name;
   int wins;
   int losses;
   Team team;

   cin >> name;
   cin >> wins;
   cin >> losses;

   team.SetName(name);
   team.SetWins(wins);
   team.SetLosses(losses);

   team.PrintStanding();
   
   return 0;
}

/*7.23 LAB: Winning team (classes)
Given main(), define the Team class (in files Team.h and Team.cpp). For class member function GetWinPercentage(), the formula is:
wins / (wins + losses). Note: Use casting to prevent integer division.

For class member function PrintStanding(), output the win percentage of the team with two digits after the decimal point and whether the team has a winning or losing average. A team has a winning average if the win percentage is 0.5 or greater.

Ex: If the input is Ravens 13 3, where Ravens is the team's name, 13 is the number of team wins, and 3 is the number of team losses, the output is:

Win percentage: 0.81
Congratulations, Team Ravens has a winning average!
Ex: If the input is Angels 80 82, the output is:

Win percentage: 0.49
Team Angels has a losing average.
*/