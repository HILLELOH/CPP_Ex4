#include "Character.hpp"

namespace ariel {
    Character::Character(const string name, const Point location, int hit_points)
    : name_(name), location_(location), healthPoints_(hit_points){}

    Character::Character(): name_(""), location_(Point(0,0)), healthPoints_(0){}

    bool Character::isAlive() const {
        return -1;
    }

    double Character::distance(const Character* other) const {
        return -1;
    }

    void Character::hit(int damage) {

    }

    const string& Character::getName() const {
        return this->name_;
    }

    const Point& Character::getLocation() const {
        return this->location_;
    }

    string Character::print() const {
        return "";
    }
};