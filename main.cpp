#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

class Point {
    protected:
        vector<double> mCoordinates;
        double mDistance;
        friend class Point2D;
        friend class Point3D;
        friend class Point4D;

    public:
        virtual void print() = 0;
        
        virtual void calculateDistance() = 0;
        
        virtual Point* add(Point* point) = 0;

        virtual Point* multiply(Point* point) = 0;

        double getDistance() {
            return mDistance;
        }

        unsigned long getSize() {
            return (long)mCoordinates.size();
        }
};

class Point2D : public Point {   
    public:
        Point2D() {
            this->mCoordinates.push_back(0);
            this->mCoordinates.push_back(0);
            this->mDistance = 0;
        }

        Point2D(double x, double y) {
            this->mCoordinates.push_back(x);
            this->mCoordinates.push_back(y);
            calculateDistance();
        }

        void print() {
            printf("%.3lf", mCoordinates[0]);
            if (mCoordinates[1] >= 0) {
                printf("+");
            }
            printf("%.3lfi", mCoordinates[1]);
        }

        void calculateDistance() {
            mDistance = abs(mCoordinates[0] + mCoordinates[1]) / 2 + sqrt(abs(mCoordinates[0] * mCoordinates[1]));
        }

        Point* add(Point* point) {
            double newX = mCoordinates[0] + point->mCoordinates[0]; 
            double newY = mCoordinates[1] + point->mCoordinates[1];
            Point* newPoint = new Point2D(newX, newY);
            return newPoint; 
        }

        Point* multiply(Point* point) {
            double newX = mCoordinates[0] * point->mCoordinates[0] - mCoordinates[1] * point->mCoordinates[1]; 
            double newY = mCoordinates[1] * point->mCoordinates[0] + mCoordinates[0] * point->mCoordinates[1];
            Point* newPoint = new Point2D(newX, newY);
            return newPoint; 
        }
};

class Point3D : public Point {   
    public:
        Point3D() {
            this->mCoordinates.push_back(0);
            this->mCoordinates.push_back(0);
            this->mCoordinates.push_back(0);
            this->mDistance = 0;
        }

        Point3D(double x, double y, double z) {
            this->mCoordinates.push_back(x);
            this->mCoordinates.push_back(y);
            this->mCoordinates.push_back(z);
            calculateDistance();
        }

        void print() {
            printf("%.3lf", mCoordinates[0]);
            if (mCoordinates[1] >= 0) {
                printf("+");
            }
            printf("%.3lfi", mCoordinates[1]);
            if (mCoordinates[2] >= 0) {
                printf("+");
            }
            printf("%.3lfj", mCoordinates[2]);
        }

        void calculateDistance() {
            mDistance = abs(mCoordinates[0] + mCoordinates[1] + mCoordinates[2]) / 3 + pow(abs(mCoordinates[0] * mCoordinates[1] * mCoordinates[2]), (double)1/3);
        }

        Point* add(Point* point) {
            double newX = mCoordinates[0] + point->mCoordinates[0]; 
            double newY = mCoordinates[1] + point->mCoordinates[1];
            double newZ = mCoordinates[2] + point->mCoordinates[2];
            Point* newPoint = new Point3D(newX, newY, newZ);
            return newPoint; 
        }

        Point* multiply(Point* point) {
            double newX = mCoordinates[0] * point->mCoordinates[0] - mCoordinates[1] * point->mCoordinates[1] - mCoordinates[2] * point->mCoordinates[2]; 
            double newY = mCoordinates[0] * point->mCoordinates[1] + mCoordinates[1] * point->mCoordinates[0];
            double newZ = mCoordinates[0] * point->mCoordinates[2] + mCoordinates[2] * point->mCoordinates[0];
            Point* newPoint = new Point3D(newX, newY, newZ);
            return newPoint; 
        }
};

class Point4D : public Point {   
    public:
        Point4D() {
            this->mCoordinates.push_back(0);
            this->mCoordinates.push_back(0);
            this->mCoordinates.push_back(0);
            this->mCoordinates.push_back(0);
            this->mDistance = 0;
        }

        Point4D(double x, double y, double z, double t) {
            this->mCoordinates.push_back(x);
            this->mCoordinates.push_back(y);
            this->mCoordinates.push_back(z);
            this->mCoordinates.push_back(t);
            calculateDistance();
        }

        void print() {
            printf("%.3lf", mCoordinates[0]);
            if (mCoordinates[1] >= 0) {
                printf("+");
            }
            printf("%.3lfi", mCoordinates[1]);
            if (mCoordinates[2] >= 0) {
                printf("+");
            }
            printf("%.3lfj", mCoordinates[2]);
            if (mCoordinates[3] >= 0) {
                printf("+");
            }
            printf("%.3lfk", mCoordinates[3]);
        }

        void calculateDistance() {
            mDistance = abs(mCoordinates[0] + mCoordinates[1] + mCoordinates[2] + mCoordinates[3]) / 4 + pow(abs(mCoordinates[0] * mCoordinates[1] * mCoordinates[2] * mCoordinates[3]), (double)1/4);
        }

        Point* add(Point* point) {
            double newX = mCoordinates[0] + point->mCoordinates[0]; 
            double newY = mCoordinates[1] + point->mCoordinates[1];
            double newZ = mCoordinates[2] + point->mCoordinates[2];
            double newT = mCoordinates[3] + point->mCoordinates[3];
            Point* newPoint = new Point4D(newX, newY, newZ, newT);
            return newPoint; 
        }

        Point* multiply(Point* point) {
            double newX = mCoordinates[0] * point->mCoordinates[0] - mCoordinates[1] * point->mCoordinates[1] - mCoordinates[2] * point->mCoordinates[2] - mCoordinates[3] * point->mCoordinates[3]; 
            double newY = mCoordinates[0] * point->mCoordinates[1] + mCoordinates[1] * point->mCoordinates[0];
            double newZ = mCoordinates[0] * point->mCoordinates[2] + mCoordinates[2] * point->mCoordinates[0];
            double newT = mCoordinates[0] * point->mCoordinates[3] + mCoordinates[3] * point->mCoordinates[0];
            Point* newPoint = new Point4D(newX, newY, newZ, newT);
            return newPoint; 
        }
};

int main() {
    string line;
    string intermediateLine;
    string intermediatePoint;
    vector<Point*> points;

    double point2DTotalX = 0;
    double point2DTotalY = 0;

    double point3DTotalX = 0;
    double point3DTotalY = 0;
    double point3DTotalZ = 0;

    double point4DTotalX = 0;
    double point4DTotalY = 0;
    double point4DTotalZ = 0;
    double point4DTotalT = 0;
    
    while (getline(cin, line)) {
        stringstream ssWords(line);

        while (getline(ssWords, intermediateLine, ' ')) {
            stringstream ssPoints(intermediateLine);
            vector<double> components;

            while (getline(ssPoints, intermediatePoint, ';')) {
                components.push_back(stod(intermediatePoint));
            }

            if (components.size() == 2) {
                points.push_back(new Point2D(components[0], components[1]));
                point2DTotalX += components[0];
                point2DTotalY += components[1];
            } else if (components.size() == 3) {
                points.push_back(new Point3D(components[0], components[1], components[2]));
                point3DTotalX += components[0];
                point3DTotalY += components[1];
                point3DTotalZ += components[2];
            } else if (components.size() == 4) {
                points.push_back(new Point4D(components[0], components[1], components[2], components[3]));
                point4DTotalX += components[0];
                point4DTotalY += components[1];
                point4DTotalZ += components[2];
                point4DTotalT += components[3];
            }
        }
    }

    Point2D total2DSum(point2DTotalX, point2DTotalY);
    Point3D total3DSum(point3DTotalX, point3DTotalY, point3DTotalZ);
    Point4D total4DSum(point4DTotalX, point4DTotalY, point4DTotalZ, point4DTotalT);

    vector<Point*> filteredPoints;
    for (int i = 0; i < points.size(); i++) {
        if (points[i]->getSize() == 2 && points[i]->getDistance() >= total2DSum.getDistance()) {
            filteredPoints.push_back(points[i]);
        } else if (points[i]->getSize() == 3 && points[i]->getDistance() >= total3DSum.getDistance()) {
            filteredPoints.push_back(points[i]);
        } else if (points[i]->getSize() == 4 && points[i]->getDistance() >= total4DSum.getDistance()) {
            filteredPoints.push_back(points[i]);
        }
    }

    sort(filteredPoints.begin(), filteredPoints.end(), [ ](Point* first, Point* second )
    {
        if (first->getSize() == second->getSize()) {
            return first->getDistance() > second->getDistance();
        } else {
            return first->getSize() > second->getSize();
        }
    });

    for (int i = 0; i < filteredPoints.size(); i++) {
        double oldDistance = filteredPoints[i]->getDistance();
        (filteredPoints[i]->multiply(filteredPoints[i]))->print();
        printf(" -> %.3lf\n", oldDistance);
    }
}