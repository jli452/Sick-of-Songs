#pragma once
#include <iostream>
#include <vector>
#include <string> 
using namespace std;

class User{
 private:
  string username;
  bool isPrimaryUser;
  int friendCount;
  vector<User> adj;
  int graphIndex;
 public:
  User(string, bool);
  User();
  User(string, bool, int);
  User(string);
  void setUser(string);
  int getGraphIndex();
  string getUser();
  friend ostream& operator<<(ostream& os, const User& sg);
  friend bool operator==(const User &other, const User &other2);
  friend bool operator!=(const User& lhs, const User& rhs);
  friend bool operator> (const User &lhs, const User &rhs);
  friend bool operator< (const User &lhs, const User &rhs);
};
