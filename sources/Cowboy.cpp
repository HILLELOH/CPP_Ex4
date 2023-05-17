# include "Cowboy.hpp"

using namespace std;
namespace ariel {
        
    Cowboy::Cowboy(const string name, const Point location): Character(name, location, 110 ), bullets_(6) {}

    void Cowboy::shoot(Character* enemy) {
        if (this==enemy){
            throw runtime_error("cowboy cannot shoot himself");
        }

        if (!enemy->isAlive() || !this->isAlive()){
            throw runtime_error("Character is dead");
        }

        else {
            if(!this->hasBullets()){
                return;
            }
            
            else {
                enemy->hit(10);
                this->bullets_--;
            }
        }
        
    }

    bool Cowboy::hasBullets() const {
        return this->bullets_ > 0;
    }

    void Cowboy::reload() {
        if(!this->isAlive()){
            throw runtime_error("dead cowboy cannot reload");
        }
        this->bullets_ = 6;
    }

    string Cowboy::print() const {
        if (this->isAlive() == false){
            return "(C " + this->getName() + ")\n";
        }
        else{
              return "Name: " + this->getName() + "\n" + "Location: " + this->getLocation().print() + "\n" + "Health: " + to_string(this->getHealthPoints()) + "\n";

        }
        
    }

    int Cowboy::getBullets() const{
        return this->bullets_;
    }


    void Cowboy::setBullets(int bullets){
        this->bullets_ = bullets;
    }
};