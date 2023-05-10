#ifndef GROUPE_H
#define GROUPE_H
#include <string>
#include <vector>
#include "user.h"
#include <sstream> // nécessaire pour utiliser std::istringstream
#include <fstream> // nécessaire pour lire un fichier
using namespace std;
class groupe
{

public:
    int id;
    string name;
    vector<user>user_tab;
    groupe();
    void add_user(user u);
    user get_user(string name);
};
#endif