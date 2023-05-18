# pragma once

# include "Character.hpp"
# include "Point.hpp"

namespace ariel{
    class Cowboy: public Character{
        public:
            Cowboy(string, Point);

            void shoot(Character*);
            bool hasboolets() const;
            void reload();
            string print() const override;
            int getBullets() const;
            void setBullets(int);
            
        private:
            int bullets_;
    };

}