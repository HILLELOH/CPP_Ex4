# include "SmartTeam.hpp"

namespace ariel{
    SmartTeam::SmartTeam(Character* leader) : Team(leader){
    }

    void SmartTeam::attack(Team* team){
        // the astrategy is to first, iterate the ninjas and attck the victim with each of them that can attak 
        //then, iterate the cowboys and attack with each of them each time on the lowest hp enemy)
        if(team==nullptr){
            throw invalid_argument("Team is null");
        }

        if(!team->stillAlive()){
            throw runtime_error("Team is dead");
        }
        
        if(!this->getLeader()->isAlive()){
            this->chooseLeader(this, this->getLeader());   
            if(this->getLeader()==nullptr){
                //cout<<"no alive"<<endl;
                return;
            }
        }

        Character* victim = chooseVictim(team, this->getLeader());
        
        if (victim == nullptr){   
            return;
        }
        vector<Ninja*> ninjas; //create a container for the ninjas who couldent attak and will attak later 
        //iterate the ninjas that can attak the victim first
        for(Character* character : this->getParticipants()){
            victim = chooseVictim(team, this->getLeader());
            if(victim==nullptr){
                break;
            }

            Ninja* curr_ninja = dynamic_cast<Ninja*>(character);

            if(curr_ninja!=nullptr){
                if (curr_ninja->isAlive()){
                    if(curr_ninja->getLocation().distance(victim->getLocation())<=1){
                        curr_ninja->slash(victim);
                    }
                    else{
                        ninjas.push_back(curr_ninja);
                    }
                }
            }
        }

        //now attack with all cowboys
        for(Character* character : this->getParticipants()){
            victim = chooseVictim(team, this->getLeader());
            if(victim==nullptr){
                break;
            }
            Cowboy* curr = dynamic_cast<Cowboy*>(character);
            if(curr!=nullptr){
                if (curr->isAlive()){
                    if(curr->hasboolets()){
                        curr->shoot(victim);
                    }
                    else{
                        curr->reload();
                    }
                }
            }
        }
        cout<<"ninjas size: "<<ninjas.size()<<endl;

        for(Ninja* ninja : ninjas){
            victim = chooseVictim(team, this->getLeader());
            if(victim==nullptr){
                break;
            }

            if (ninja->isAlive()){
                if(ninja->getLocation().distance(victim->getLocation())<=1){
                    ninja->slash(victim);
                }
                else{
                    ninja->move(victim);
                }
            }
        
        }
    }

    
};