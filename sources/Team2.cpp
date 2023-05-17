# include "Team2.hpp"

namespace ariel{
    Team2::Team2(Character* leader) : Team(leader){}

    void Team2::chooseLeader(Team* team, Character* leader){
        Character* newLeader = nullptr;
        for (Character* character : team->getParticipants()){
            if (character->isAlive()){
                if (newLeader == nullptr){
                    newLeader = character;
                }
                else{
                    if(leader==nullptr){
                        break;
                    }
                    if (character->distance(leader) < newLeader->distance(leader)){
                        newLeader = character;
                    }
                } 
            }
        }
        if (newLeader == nullptr){
            
            cout<< "no more alive member on the group" << endl;
            return;
        }
        this->setLeader(newLeader);
    }


    Character* Team2::chooseVictim(Team* team, Character* leader) const{
        Character* victim = nullptr;
        for (Character* character : team->getParticipants()){
            if (character->isAlive()){
                if (victim == nullptr){
                    victim = character;
                }
                else{
                    if (character->distance(leader) < victim->distance(leader)){
                        victim = character;
                    }
                } 
            }
        }
        return victim;
    }


    void Team2::attack(Team* team){
        if(team==nullptr){
            throw invalid_argument("Team is null");
        }
        if(!this->getLeader()->isAlive()){
            this->chooseLeader(this, this->getLeader());
        }

        Character* victim = chooseVictim(team, this->getLeader());
            

        for(Character* character : this->getParticipants()){
            if (!victim->isAlive()){
                victim = chooseVictim(team, this->getLeader());
                if(victim==nullptr){
                    //cout<<"no victim"<<endl;
                    return;
                }
            } 
            Cowboy* curr = nullptr;
            if (character->isAlive()){
                curr = dynamic_cast<Cowboy*>(character);
                if(curr==nullptr){
                    Ninja* curr_ninja = dynamic_cast<Ninja*>(character);
                    if(curr_ninja->isAlive()){
                        if(curr_ninja->getLocation().distance(victim->getLocation())<=1){
                            curr_ninja->slash(victim);
                        }
                        else{
                            curr_ninja->move(victim);
                        }
                    }
                }
                else{
                    if(curr->isAlive()){
                        if(curr->hasBullets()){
                            curr->shoot(victim);
                        }
                        else{
                            curr->reload();
                        }
                    }
                    
                }
            }
        }
    }

    string Team2::print() const{
        string ans = "";
        for (Character* character : this->getParticipants()){
            ans.append(this->print());
        }
        cout << ans << endl;
        return ans;
    }
};