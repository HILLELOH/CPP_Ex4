# include "Ninja.hpp"

namespace ariel{
    Ninja::Ninja(const string name,  Point location, int healthPoints, int speed)
    : Character(name, location, healthPoints), speed_(speed) {}

    string Ninja::print() const {
        if (this->isAlive() == false){
            return "(N " + this->getName() + ")\n";
        }
        else{
              return "Name: " + this->getName() + "\n" + "Location: " + this->getLocation().print() + "\n" + "Health: " + to_string(this->getHealthPoints()) + "\n";

        }
    }


    int Ninja::getSpeed() const{
        return this->speed_;
    }

    void Ninja::setSpeed(int speed){
        this->speed_ = speed;
    }


    void Ninja::move(Character* enemy) {
        if (enemy->isAlive()) {
            Point move = Point::moveTowards(this->getLocation(), enemy->getLocation(), this->speed_);
            this->setLocation(move);
        }
        
    }


    void Ninja::slash(Character* enemy){
        if(this==enemy){
            throw runtime_error("ninja cannot slash himself");
        }
        
        if (!enemy->isAlive() || !this->isAlive()){
            throw runtime_error("Character is dead");
        }

        if(this->distance(enemy) > 1){
            return;
        }
        else{
            enemy->hit(40);
        }
            
    }    
};