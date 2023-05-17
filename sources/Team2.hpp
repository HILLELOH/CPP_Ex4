#pragma once
#include "Team.hpp"

namespace ariel {
    class Team2: public Team{
        public:
            Team2(Character*);

            void attack(Team* team) override;
            string print() const override; 
            Character* chooseVictim(Team* team, Character* leader) const override; 
            void chooseLeader(Team* team, Character* leader) override;
    };
};