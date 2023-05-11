#include "Point.hpp"

namespace ariel {
    Point::Point(double a, double b): x_(a), y_(b){
        
    }

    double Point::get_x(){
        return -1;
    }

    double Point::get_y(){
        return -1;
    }

    void Point::set_x(double new_x){

    }

    void Point::set_y(double new_y){

    }

    double Point::distance(Point& other){
        return -1;
    }

    void Point::print(){

    }

    Point Point::moveTowards(Point curr, Point other, double){
        return Point(0,0);
    }
};