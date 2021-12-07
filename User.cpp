#include <iostream>
#include "User.h"
#include <string> 

using namespace std;

User::User(){
    username = "";
    isPrimaryUser = false;
    friendCount = 0;
    vector<User> adj;
    graphIndex = 0;
}
User::User(string t){
    username = t;
    isPrimaryUser = false;
    friendCount = 0;
    vector<User> adj;
    graphIndex = 0;
}
User::User(string t, bool isPrim){
    username = t;
    isPrimaryUser = isPrim;
    friendCount = 0;
    vector<User> adj;
    graphIndex = 0;
}
User::User(string t, bool isPrim, int index){
    username = t;
    isPrimaryUser = isPrim;
    friendCount = 0;
    vector<User> adj;
    graphIndex = index;
}

ostream& operator<<(ostream& os, const User& sg){
    os << sg.username;
    return os;
}   
bool operator==(const User &other, const User &other2) {
    return (other.username == other2.username);
}
bool operator!=(const User& lhs, const User& rhs){ 
    return !(lhs.username == rhs.username); 
}
bool operator> (const User &lhs, const User &rhs){
    if(lhs.username > rhs.username) {
    return true;
    }
    return false;
}
bool operator< (const User &lhs, const User &rhs){
    if(lhs.username < rhs.username) {
        return true;
    }
    return false;
}
string User::getUser(){
    return username;
}
int User::getGraphIndex(){
    return graphIndex;
}
void User::setUser(string s){
    username = s;
}
