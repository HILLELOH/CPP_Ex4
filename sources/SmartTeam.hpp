#pragma once
#include "Team.hpp"

namespace ariel {
    class SmartTeam: public Team{
        public:
            SmartTeam(Character*);

            void attack(Team* team) override;
            string print() const override; 
            Character* chooseVictim(Team* team, Character* leader) const override; 
            void chooseLeader(Team* team, Character* leader) override; 
    };
};