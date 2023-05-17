#pragma once
#include <iostream>
#include <cmath>
#include <string>
#include "Point.hpp"

using namespace std;
namespace ariel {
    class Character{
        public:
            Character(string, Point, int);
            //default constructor
            Character();
            //destructor
            virtual ~Character() = default;
            //copy constructor
            Character(const Character&);
            //copy assignment
            Character& operator=(const Character&);
            //move constructor
            Character(Character&&) noexcept;
            //move assignment
            Character& operator=(Character&&) noexcept;

            bool isAlive() const;
            double distance(const Character*) const;
            void hit(int);

            void setName(string);
            const string& getName() const;

            void setLocation(Point);
            const Point& getLocation() const;
            
            void setHealthPoints(int);
            int getHealthPoints() const;
            
            virtual string print() const = 0;
            bool inTeam() const;
            void setInTeam(bool);


        private:
            string name_;
            Point location_;
            int healthPoints_;
            bool inTeam_;
            
    };

};