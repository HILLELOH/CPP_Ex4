#include "Team.hpp"

using namespace std;
namespace ariel {
        Team::Team(Character* leader) : leader(leader){
            participants_.push_back(leader);
        }

        void Team::add(Character* character){

        }

        void Team::attack(Team* team){

        }

        int Team::stillAlive() const{
            return 0;
        }

        string Team::print() const{
            return "";
        }

        Team2::Team2(Character* leader) : Team(leader){
        }

        void Team2::attack(Team* team){
            
        }

        string Team2::print() const{
            return "";
        }

        SmartTeam::SmartTeam(Character* leader) : Team(leader){
        }

        void SmartTeam::attack(Team* team){
            
        }

        string SmartTeam::print() const{
            return "";
        }
};