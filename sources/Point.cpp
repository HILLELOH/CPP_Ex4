#include "Point.hpp"

namespace ariel {
    Point::Point(double a, double b): x_(a), y_(b){
        
    }

    double Point::get_x() const{
        return this->x_;
    }

    double Point::get_y() const{
        return this->y_;
    }

    void Point::set_x(double new_x){
        this->x_ = new_x;
    }

    void Point::set_y(double new_y){
        this->y_ = new_y;
    }

    double Point::distance(Point other) const{
        return sqrt(pow(this->x_ - other.get_x(), 2) + pow(this->y_ - other.get_y(), 2));
        
    }

    string Point::print() const{
        return "(" + to_string(this->x_) + ", " + to_string(this->y_) + ")";
    }
};