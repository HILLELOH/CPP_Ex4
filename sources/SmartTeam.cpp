# include "SmartTeam.hpp"

namespace ariel{
    SmartTeam::SmartTeam(Character* leader) : Team(leader){}

    Character* SmartTeam::chooseVictim(Team* team, Character* leader) const{
        return nullptr;
    }

    void SmartTeam::chooseLeader(Team* team, Character* leader){
        
    }

    void SmartTeam::attack(Team* team){
        
    }

    string SmartTeam::print() const{
        return "";
    }
};