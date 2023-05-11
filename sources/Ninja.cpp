# include "Ninja.hpp"

namespace ariel{
    Ninja::Ninja(const string name, const Point location, int healthPoints, int speed)
    : Character(name, location, healthPoints), speed_(speed) {}

    Ninja::Ninja(): Character(), speed_(0) {}
    
    string Ninja::print() const {
        return "";
    }

    
    int Ninja::getSpeed() const{
        return this->speed_;
    }

    void Ninja::setSpeed(int speed){
        this->speed_ = speed;
    }


    void Ninja::move(Character* enemy) {
       
    }


    void Ninja::slash(Character* enemy){

    }



    YoungNinja::YoungNinja(const string name, const Point location)
    : Ninja(name, location, 100, 14){}



    TrainedNinja::TrainedNinja(const string name, const Point location)
    : Ninja(name, location, 120, 12){}



    OldNinja::OldNinja(const string name, const Point location)
    : Ninja(name, location, 140, 10){}

  
};