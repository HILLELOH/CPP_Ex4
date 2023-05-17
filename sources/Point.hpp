#pragma once
#include <iostream>
#include <cmath>
# include <string>
using namespace std;

namespace ariel {
    class Point{
        public:
            Point(double, double);

            double get_x() const;
            double get_y() const;

            void set_x(double);
            void set_y(double);

            double distance(Point) const;
            string print() const;

            static Point moveTowards(Point src, Point dest, double dist){
                if(dist<0){
                    throw std::invalid_argument("distance must be non-negative");
                }
                
                double dist_x = dest.get_x() - src.get_x();
                double dist_y = dest.get_y() - src.get_y();
                double currentDistance = std::sqrt(dist_x * dist_x + dist_y * dist_y);
                Point towards = Point(0, 0);
                if (currentDistance <= dist) {
                    towards=dest;

                } 
                else {
                    double ratio = dist / currentDistance;
                    double newX = src.get_x() + dist_x * ratio;
                    double newY = src.get_y() + dist_y * ratio;
                    towards = Point(newX, newY);
                }
                return towards;
            }
			
		private:
            double x_;
            double y_;
    };
};