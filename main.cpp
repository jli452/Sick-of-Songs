#include "System.h"
#include "Heap.h"
#include "Graph.h"
#include "Library.h"
#include <sstream>
#include <iostream>   
#include <string> 
using namespace std;

bool isNumber(const string& str)
{
    for (char const &c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}

std::string trim(const std::string &s){
    auto start = s.begin();
    while (start != s.end() && std::isspace(*start)) {
        start++;
    }
    auto end = s.end();
    do {
        end--;
    } while (std::distance(start, end) > 0 && std::isspace(*end));

    return std::string(start, end + 1);
}

int main(){
  string full_userinp;
  string user_input = "";
  string user_input2 ="";
  Library lib;
  System sys;
  Graph friends;
  Heap heap;
  bool isRunning = true;
  string use = "";
  string space = " ";
  int numUsers = 0;
  int radius = 1;
  vector<User> adj[10000];
  cout << "Enter Primary User's username: " << endl;
  getline(cin, use);
  sys.addUser(User(use, true, numUsers));
  numUsers++;
  cout << "Enter a command:" << endl;
    cout << "  add user" << endl;
    cout << "  add friend " << endl;
    cout << "  remove friend " << endl;
    cout << "  add song " << endl;
    cout << "  listen " << endl;
    cout << "  set EFN " << endl;
    cout << "  recommend " << endl;
    cout << "  remove song " << endl;
    cout << "  show friends " << endl;
    cout << "  show songs lib" << endl;
    cout << "  show songs sys" << endl;
  while (isRunning) {
    string input = "";
    getline(cin, full_userinp);
    full_userinp = trim(full_userinp);
    std::istringstream iss(full_userinp);
    iss >> user_input;
    getline(iss,user_input2);
    user_input = trim(user_input);
    user_input2 = trim(user_input2);
    
    //ADD
    if (full_userinp == "add") cout << "error: Improper use of add. Use 'add user <username>'" << endl;
    //ADD user
    if (user_input == "add") {
      if(user_input2 == "user"){
        string username;

        cout << "Enter User name: "<<endl;
        getline(cin, username);
        username = trim(username);
        User temp = User(username);
        if (!sys.userExist(temp)) numUsers++;
        sys.addUser(User(username, false, numUsers));
      }
      else if(user_input2 == "song"){
        string songTitle;

        cout << "Enter Song: "<<endl;
        getline(cin, songTitle);
        songTitle = trim(songTitle);

        sys.addSong(Song(songTitle));
        heap.insert(Song(songTitle));
      }
      else if(user_input2 == "friend"){
        string friendA;
        string friendB;

        cout << "Enter first Friend: " << endl;
        getline(cin, friendA);
        friendA = trim(friendA);

        cout << "Enter 2nd Friend: " << endl;
        getline(cin, friendB);
        friendB = trim(friendB);

        User temp1 = User(friendA);
        User temp2 = User(friendB);
        if (sys.userExist(temp1) && sys.userExist(temp2)) {
          User userA = sys.getUserObj(friendA);
          User userB = sys.getUserObj(friendB);
          if (!(friends.hasEdge(adj,userA,userB))) {
            friends.addEdge(adj, userA, userB);
            cout << userA.getUser() << " has added " << userB.getUser() << endl;
          } 
          else cout << "error: " << userA.getUser() << " has already added " << userB.getUser() << endl;
        }
        else cout << "error: One of the users doesn't exist" << endl;
      }
      else cout << "error: invalid input use:\n\tadd user/song" << endl;
    }

    if(user_input == "remove"){
      if(user_input2 == "friend"){
        string friendA;
        string friendB;

        cout << "Enter first Friend: " << endl;
        getline(cin, friendA);
        friendA = trim(friendA);

        cout << "Enter 2nd Friend: " << endl;
        getline(cin, friendB);
        friendB = trim(friendB);

        User temp1 = User(friendA);
        User temp2 = User(friendB);
        if (sys.userExist(temp1) && sys.userExist(temp2)) {
          User userA = sys.getUserObj(friendA);
          User userB = sys.getUserObj(friendB);
          if (friends.hasEdge(adj, userA, userB)) {
              friends.delEdge(adj, userA, userB);
              cout << userA.getUser() << " has removed " << userB.getUser() << endl;
          } 
          else cout << "error: " << userA.getUser() << " is not friends with " << userB.getUser() << endl;
        }
	      else cout << "error: One of the users doesn't exist" << endl;
      }
      else if(user_input2 == "song"){
        string songTitle;
        cout <<"Enter song Title: " << endl;
        getline(cin, songTitle);
        songTitle = trim(songTitle);
        lib.removeSong(Song(songTitle));
        heap.insert(Song(songTitle));
      }
      else cout << "error: invalid input use:\n\tremove friend/song" << endl;
    }
    if(user_input == "listen"){
      if(user_input2 == ""){
        string tempUser;
        string tempSongTitle;
        string numTimes;
        int tempnum;

        cout << "Enter User: "<< endl;
        getline(cin, tempUser);
        tempUser = trim(tempUser);

        cout << "Enter Song: " << endl;
        getline(cin, tempSongTitle);
        tempSongTitle = trim(tempSongTitle);

        cout << "Enter #of times: "<< endl;
        getline(cin, numTimes);
        numTimes = trim(numTimes);

        if(isNumber(numTimes)){
          User temp1 = User(tempUser);
          Song temp2 = Song(tempSongTitle);
          if (sys.userExist(temp1)) {
            if (sys.songExist(temp2)) {
              User userA = sys.getUserObj(tempUser);
              int dist = friends.minEdgeBFS(adj, 0, userA.getGraphIndex(), numUsers);
              if (dist <= radius && dist != 0) {
                heap.incSong(tempSongTitle, stoi(numTimes));
              }
            } 
            else cout << "error: Song doesn't exist" << endl;
          } 
          else cout << "error: User doesn't exist" << endl;
        }
        else cout << "error: Enter a real number" << endl;
      }
      else cout << "error: invalid input use:\n\tlisten" << endl;
    }

    if(user_input == "set"){
      if(user_input2 == "EFN"){
        string efn;
        cout << "Enter EFN: "<<endl;
        getline(cin, efn);
        efn = trim(efn);
        if(isNumber(efn)){
         stringstream var(efn);
         var >> radius;
        }
      }
      else cout << "error: invalid input use:\n\tset EFN" << endl;
    }

    if(user_input == "recommend"){
      if(isNumber(user_input2)){
        int num;
        stringstream var(user_input2);
        var >> num;
        for (int i = 0; i < num; i++) {
          Song temp = heap.extractMax();
          temp.resetListen();
          lib.addSong(temp);
        }
      }
      else cout << "error: invalid input use:\n\trecommend <number>" << endl;
    }

    if(user_input == "show"){
      if(user_input2 == "friends"){
        string username;
        cout << "Enter User: "<< endl;
        getline(cin, username);
        username = trim(username);
        User temp = User(username);
        if (sys.userExist(temp)) {
          User user = sys.getUserObj(username);
          friends.printGraph(adj, numUsers, username, user.getGraphIndex());
        }
	      else cout << "error: User does not exist" << endl;
      }
      else if(user_input2 == "songs sys"){
        heap.printAll();
      }
      else if(user_input2 == "songs lib"){
        lib.showSongs();
      }
      else if(user_input2 == "users"){
        sys.showUsers();
      }
      else cout << "error: invalid input use one of the following:\n\tshow friends\n\tshow songs sys\n\tshow sobngs lib\n\tshow users" << endl;
    }

    //SHOW song sys
    
    
    //EXIT
    //else if (full_userinp == "test EFN")friends.printEFNUsers(adj, numUsers, radius);
    else if (full_userinp == "exit") isRunning = false;
    
    //DEFAULT UNKNOWN COMMANDS
    //else cout << "Error: Command not found. Try again" << endl;
    // cin.clear();
   }
}
