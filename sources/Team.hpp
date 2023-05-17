#pragma once
#include <vector>
#include <typeinfo>
#include <algorithm>
#include "Cowboy.hpp"
#include "Character.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"

namespace ariel {
    class Team{
        public:
            Team(Character*);
            //destructors
            virtual ~Team();
            //copy constructor
            Team(const Team&) = default;
            //copy assignment
            Team& operator=(const Team&) = default;
            //move constructor
            Team(Team&&) noexcept = default;
            //move assignment
            Team& operator=(Team&&) noexcept = default;

            virtual void add(Character*);
            virtual void attack(Team*);
            int stillAlive() const;
            virtual string print() const; 
            virtual Character* chooseVictim(Team*, Character*) const; 
            virtual void chooseLeader(Team*, Character*); 

            Character* getLeader() const;
            void setLeader(Character*);

            vector<Character*> getParticipants() const;

        private:
            Character* leader;
            vector<Character*> participants_;
    };

    
};