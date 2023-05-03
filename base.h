#ifndef BASE_H
#define BASE_H

#include<string>
#include<vector>
#include "Rule.h"
#include "zone.h"
#include "groupe.h"
#include "user.h"
#include "aplication.h"
#include "domain.h"
#include "session.h"
#include "interfaces.h"
#include "Policy.h"

struct tab_stat
{
    std::string adr_dest;
    std::string next_hop;
};

struct tab_nat_stat
{
    std::string ip_prive;
    std::string ip_public;
};

class base
{

public:
    std::vector<Policy>polit;
   std::vector<Rule> rules;
   std::vector<interfaces> tab_interfaces;
   std::vector<session> tab_session;
  std:: vector<user> tab_use;
   std::vector<tab_stat> tab_r_statique;
   std::vector<tab_nat_stat>tab_n_statique;
    std::string name_policy;
    std::string zone_name;
    std::string name;
    std::string aplication_name;
    std::string user_name;
    std::string user_groupe_name;
    std::vector<zone> zii;
    std::vector<domain> domaine_liste;
    bool domaine;
    bool domaine_veu_liste;
    domain domaine_url;
    aplication pb;
    tab_stat r_statique;
    tab_nat_stat n_statique;
    groupe use;
    user u;
    session s;
    interfaces interf;
    bool test;
    zone zi;
    Rule rul;
    base();
};

#endif

