#include "interface_conf.h"

interface_conf::interface_conf(/* args */){
    const char* p="pc.pcap";
    const char* pi="capture.pcap";
    string ipp="192.168.1.1";
    interfaces i(p,pi,ipp,"trust");
    base b;b.interf=i;
    this->update(b,"rien");
 
 }

 base interface_conf::get(string ss,base bo){
    /*for(interfaces po : interface_tab){
        if(po.name==ss)
        {
            bo.rules=po.rules;
            return bo;
        }else{printf("pas de interface_tabtique correspendante");}
    }*/
    }

    void interface_conf::add(std::string ss){
            
    }




    base interface_conf::get_all(base b){
        for(interfaces po : interface_tab){
            b.tab_interfaces.push_back(po);
        }return b;
    }


   /* base* interface_conf::get(){

    }*/

   void interface_conf::update(base rr,std::string nom){
      
            interface_tab.push_back(rr.interf);
    }
   /* void interface_conf::set_sup_interfaces(Rule rr,string nom){
        for(interfaces po : interface_tab){
        if(po.name==nom)
        {
            po.;
            
        }else{printf("pas de interface_tabtique correspendante");}
    }
    }*/