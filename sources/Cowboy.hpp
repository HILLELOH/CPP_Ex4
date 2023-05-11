# pragma once

# include "Character.hpp"
# include "Point.hpp"

namespace ariel{
    class Cowboy: public Character{
        public:
            Cowboy(string, Point);
            //default constructor
            Cowboy();
            //destructor
            ~Cowboy() override = default;
            //copy constructor
            Cowboy(const Cowboy&);
            //copy assignment
            Cowboy& operator=(const Cowboy&);
            //move constructor
            Cowboy(Cowboy&&) noexcept;
            //move assignment
            Cowboy& operator=(Cowboy&&) noexcept;

            void shoot(Character*);
            bool hasBullets() const;
            void reload();
            string print() const override;
            int getBullets() const;
            void setBullets(int);
        private:
            int bullets_;
    };

}