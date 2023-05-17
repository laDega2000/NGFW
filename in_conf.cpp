#include "in_conf.h"

in_conf::in_conf(/* args */){
    const char* p="pr.pcap";
    const char* pi="eth0.pcap";
    string ipp="192.168.1.1";
    interfaces i(p,pi,ipp,"trust");
    base b;b.interf=i;
    this->update(b,"rien");
     p="eth0.pcap";
    pi="eth1.pcap";
    ipp="192.168.2.1";
    interfaces ii(p,pi,ipp,"trust");
    base bb;bb.interf=ii;
    this->update(bb,"rien");
    p="pc.pcap";
    pi="eth2.pcap";
    ipp="192.168.3.1";
    interfaces iii(p,pi,ipp,"trust");
    base bbb;bbb.interf=iii;
    this->update(bbb,"rien");
 
 }

 base in_conf::get(string ss,base bo){
    /*for(interfaces po : interface_tab){
        if(po.name==ss)
        {
            bo.rules=po.rules;
            return bo;
        }else{printf("pas de interface_tabtique correspendante");}
    }*/
    }

    void in_conf::add(std::string ss){
            
    }




    base in_conf::get_all(base b){
        for(interfaces po : interface_tab){
            b.tab_interfaces.push_back(po);
        }return b;
    }


   /* base* in_conf::get(){

    }*/

   void in_conf::update(base rr,std::string nom){
            cout<<endl<<rr.interf.file_name<<endl;
            interface_tab.push_back(rr.interf);
    }
   /* void in_conf::set_sup_interfaces(Rule rr,string nom){
        for(interfaces po : interface_tab){
        if(po.name==nom)
        {
            po.;
            
        }else{printf("pas de interface_tabtique correspendante");}
    }
    }*/