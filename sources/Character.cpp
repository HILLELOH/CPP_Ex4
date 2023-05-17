#include "Character.hpp"

namespace ariel {
    Character::Character(const string name, const Point location, int hit_points)
    : name_(name), location_(location), healthPoints_(hit_points), inTeam_(false){}

    bool Character::isAlive() const {
        return this->healthPoints_ > 0;
    }

    double Character::distance(const Character* other) const {
        return this->location_.distance(other->getLocation());
    }

    void Character::hit(int damage) {
        if(damage<0){
            throw invalid_argument("Damage must be non-negative");
        }
        this->healthPoints_ -= damage;
    }

    void Character::setName(string name){
        this->name_ = name;
    }

    const string& Character::getName() const{
        return this->name_;
    }

    void Character::setLocation(Point location){
        this->location_ = location;
    }

    const Point& Character::getLocation() const{
        return this->location_;
    }

    int Character::getHealthPoints() const{
        return this->healthPoints_;
    }  

    void Character::setHealthPoints(int healthPoints){
        this->healthPoints_ = healthPoints;
    }

    bool Character::inTeam() const{
        return this->inTeam_;
    }

    void Character::setInTeam(bool inTeam){
        this->inTeam_ = inTeam;
    }
};