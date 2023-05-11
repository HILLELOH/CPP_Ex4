#pragma once
#include <iostream>
#include <cmath>
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
            const string& getName() const;
            const Point& getLocation() const;
            virtual string print() const;

        private:
    
            string name_;
            Point location_;
            int healthPoints_;
            
    };

};