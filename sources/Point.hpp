#pragma once
#include <iostream>
using namespace std;

namespace ariel {
    class Point{
        public:
            Point(double, double);

            double get_x();
            double get_y();

            void set_x(double);
            void set_y(double);

            double distance(Point&);
            void print();
            Point moveTowards(Point, Point, double);
			
		private:
            double x_;
            double y_;
    };
};