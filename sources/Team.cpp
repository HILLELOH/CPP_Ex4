#include "Team.hpp"

using namespace std;
namespace ariel {
    Team::Team(Character* leader) {
        if(leader->inTeam()){
            if (!count(this->getParticipants().begin(), this->getParticipants().end(), leader)){
                throw runtime_error("Leader is already in a team");
            }
        }
        else{
            this->leader = leader;
            this->leader->setInTeam(true);
            participants_.push_back(this->leader);
            
        }
    }

    Team::~Team(){
        for(Character* character : participants_){
            delete character;
        }
    }

    void Team::add(Character* character){
        if(size(this->getParticipants())==10){
            throw runtime_error("Team is full");
        }
        if(character->inTeam()){
            // if (!count(this->getParticipants().begin(), this->getParticipants().end(), character)){
            //     throw runtime_error("Character is already in a team");
            // }
            throw runtime_error("Character is already in a team");
        }
        else{
            participants_.push_back(character);
            character->setInTeam(true);
        }
    }

    Character* Team::chooseVictim(Team* team, Character* leader) const{
        Character* new_victim = nullptr;
        for(Character* character : team->getParticipants()){
            if(character->isAlive()){
                Cowboy* iter = dynamic_cast<Cowboy*>(character);
                if(iter==nullptr){
                    continue;
                }
                else{
                    if(new_victim == nullptr){
                        new_victim = character;
                    }
                    else{
                        if(character->distance(leader) < new_victim->distance(leader)){
                            new_victim = character;
                        }
                    } 
                        
                    
                }
            }
        }

        for(Character* character : team->getParticipants()){
            if(character->isAlive()){
                Ninja* iter = dynamic_cast<Ninja*>(character);
                if(iter==nullptr){
                    continue;
                }
                else {
                    if(character->isAlive()){
                        if(new_victim == nullptr){
                            new_victim = character;
                        }
                        else{
                            if(character->distance(leader) < new_victim->distance(leader)){
                                new_victim = character;
                            }
                        } 
                    }
                }
            }
        }
        return new_victim;
    }

    void Team::chooseLeader(Team* team, Character* leader){
        Character* newLeader = nullptr;

        Cowboy* curr_cowboy=nullptr;
        for (Character* character : team->getParticipants()){
            curr_cowboy = dynamic_cast<Cowboy*>(character);
            if(curr_cowboy!=nullptr){
                if (curr_cowboy->isAlive()){
                    if (newLeader == nullptr){
                        newLeader = character;
                    }
                    else{
                        if (character->distance(leader) < newLeader->distance(leader)){
                            newLeader = character;
                        }
                    }
                }
            }
        }
        Ninja* curr_ninja=nullptr;
        for (Character* character : team->getParticipants()){
            curr_ninja = dynamic_cast<Ninja*>(character);
            if(curr_ninja!=nullptr){
                if (character->isAlive()){
                    if (newLeader == nullptr){
                        newLeader = character;
                    }
                    else{
                        if (character->distance(leader) < newLeader->distance(leader)){
                            newLeader = character;
                        }
                    }
                }
            }
        }
        if(newLeader==nullptr){
            cout<<"no leader avail"<<endl;
            return;
        }
        this->setLeader(newLeader);
    }

    void Team::attack(Team* team){
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
            //cout<<"no victim3"<<endl;    
            return;
        }
            
        for(Character* character : this->getParticipants()){
            victim = chooseVictim(team, this->getLeader());
            if(victim==nullptr){
                //cout<<"no victim1"<<endl;
                //cout<<team->print()<<endl;
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

        for(Character* character : this->getParticipants()){
            victim = chooseVictim(team, this->getLeader());
            if(victim==nullptr){
                // cout<<"no victim2"<<endl;
                // cout<<team->print()<<endl;
                break;
            }
            Ninja* curr_ninja = dynamic_cast<Ninja*>(character);
            if(curr_ninja!=nullptr){
                if (curr_ninja->isAlive()){
                    if(curr_ninja->getLocation().distance(victim->getLocation())<=1){
                        curr_ninja->slash(victim);
                    }
                    else{
                        curr_ninja->move(victim);
                    }
                }
            }
        }
    }

    int Team::stillAlive() const{
        int counter = 0;
        for (Character* character : participants_){
            if (character->isAlive()){
                counter++;
            }
        }
        return counter;
    }

    string Team::print() const{
        string ans = "";
        for (Character* character : this->getParticipants()){
            Character* curr = dynamic_cast<Cowboy*>(character);
            if(curr!=nullptr){
                ans.append(character->print());
            }
        }
        for (Character* character : this->getParticipants()){
            Character* curr = dynamic_cast<Ninja*>(character);
            if(curr!=nullptr){
                ans.append(character->print());
            }
        }
        return ans;
    }

    vector<Character*> Team::getParticipants() const{
        return this->participants_;
    }


    Character* Team::getLeader() const{
        return this->leader;
    }

    void Team::setLeader(Character* leader){
        this->leader = leader;
    }
};