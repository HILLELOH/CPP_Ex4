# include "Cowboy.hpp"

using namespace std;
namespace ariel {
        
    Cowboy::Cowboy(const string name, const Point location): Character(name, location, 100), bullets_(6) {}


    Cowboy::Cowboy(): Character(), bullets_(6) {}

    void Cowboy::shoot(Character* p_enemy) {
        
    }

    bool Cowboy::hasBullets() const {
        return -1;
    }

    void Cowboy::reload() {
        
    }

    string Cowboy::print() const {
        return "";
    }

    int Cowboy::getBullets() const{
        return this->bullets_;
    }


    void Cowboy::setBullets(int bullets){
        this->bullets_ = bullets;
    }
};