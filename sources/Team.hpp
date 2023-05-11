#pragma once
#include <vector>
#include "Cowboy.hpp"
#include "Ninja.hpp"

namespace ariel {
    class Team{
        public:
            Team(Character*);
            //destructors
            virtual ~Team() = default;
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


        private:
            Character* leader;
            vector<Character*> participants_;
            
    };

    class Team2: public Team{
        public:
            Team2(Character*);
            ~Team2() override = default;
            //copy constructor
            Team2(const Team2&) = default;
            //copy assignment
            Team2& operator=(const Team2&) = default;
            //move constructor
            Team2(Team2&&) noexcept = default;
            //move assignment
            Team2& operator=(Team2&&) noexcept = default;

            void attack(Team* team) override;
            string print() const override; 
    };

    class SmartTeam: public Team{
        public:
            SmartTeam(Character*);
            ~SmartTeam() override = default;
            //copy constructor
            SmartTeam(const SmartTeam&) = default;
            //copy assignment
            SmartTeam& operator=(const SmartTeam&) = default;
            //move constructor
            SmartTeam(SmartTeam&&) noexcept = default;
            //move assignment
            SmartTeam& operator=(SmartTeam&&) noexcept = default;

            void attack(Team* team) override;
            string print() const override; 
    };
};