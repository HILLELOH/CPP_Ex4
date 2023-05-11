#pragma once
#include "Character.hpp"
#include "Point.hpp"
namespace ariel{
    class Ninja : public Character {
        public:
            Ninja(string, Point, int, int);
            //default constructor
            Ninja();
            //destructor
            ~Ninja() override = default;
            //copy constructor
            Ninja(const Ninja&);
            //copy assignment
            Ninja& operator=(const Ninja&);
            //move constructor
            Ninja(Ninja&&) noexcept;
            //move assignment
            Ninja& operator=(Ninja&&) noexcept;

             
            string print() const override;
            void move(Character*);
            void slash(Character*);

            int getSpeed() const;
            void setSpeed(int);

        private:
            int speed_;
    };


    //YoungNinja are like ninja but 100 health points and 14 speed
    class YoungNinja: public Ninja{
        public:
            YoungNinja(string, Point);
    };

    //TrainedNinja  are like ninja but 120 health points and 12 speed
    class TrainedNinja: public Ninja{
        public:
            TrainedNinja(string, Point);
    };
    //OldNinja are like ninja but 150 health points and 10 speed
    class OldNinja: public Ninja{
        public:
            OldNinja(string, Point);
    };
};