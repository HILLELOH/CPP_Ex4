#pragma once
#include "Character.hpp"
#include "Point.hpp"

namespace ariel{
    class Ninja : public Character {
        public:
            Ninja(string, Point, int, int);
             
            string print() const override;
            void move(Character*);
            void slash(Character*);

            int getSpeed() const;
            void setSpeed(int);

        private:
            int speed_;
    };
};