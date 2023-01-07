#include<iostream>
#include<Eigen/Dense>
#include<cmath>
using namespace std;
using namespace Eigen;

Matrix<double,3,3> fixed_find_R12(double angle_x,double angle_y,double angle_z)
{
    Matrix<double,3,3> R,Rx,Ry,Rz;
    Rx<<1,           0,            0,
        0,cos(angle_x),-sin(angle_x),
        0,sin(angle_x), cos(angle_x);

    Ry<<cos(angle_y) ,0,sin(angle_y),
        0            ,1,           0,
        -sin(angle_y),0,cos(angle_y); 

    Rz<<cos(angle_z),-sin(angle_z),0,
        sin(angle_z), cos(angle_z),0,
        0           ,0            ,1;  
    R = Rz * Ry * Rx;
    return R;
}
int main()
{   
    #if 1
    //p1 = R12 * p2;
    //e1 * p1 = e2 * p2;
    //p1 = e1.transpose() * e2 * p2;
    //R12 = e1.transpose() * e2;

    //p2 = R21 * p1;
    //e1 * p1 = e2 * p2;
    //p2 = e2.transpose() * e1 * p1;
    //R21 = e2.transpose() * e1;

    //R12 = Rz * Ry * Rx;


    Matrix<double,3,3> e1;
    e1<<1,0,0,
        0,1,0,
        0,0,1;
    cout<<"base1:"<<endl<<e1<<endl;

    Matrix<double,3,3> e2;
    e2<<0, 0,-1,
        1, 0, 0,
        0,-1, 0;
    cout<<"base2:"<<endl<<e2<<endl;

    Matrix<double,3,3> R12;
    Matrix<double,3,3> R21;

    Matrix<double,3,1> p1;
    p1<<1,1,1;

    Matrix<double,3,1> p2;
    p2<<0,0,0;

    R12 = e1.transpose() * e2;
    R21 = e2.transpose() * e1;
    p2 = R21 * p1;
    
    
    cout<<"Rotation Matrix from base 1 to base 2:"<<endl;
    cout<<R12<<endl;

    R12 = fixed_find_R12(-M_PI/2.0,0,M_PI/2.0);
    cout<<"Rotation Matrix from base 1 to base 2:"<<endl;
    cout<<R12<<endl;

    cout<<"Coordinate in base1:"<<endl;
    cout<<p1.transpose()<<endl;
    cout<<"Coordinate in base2:"<<endl;
    cout<<p2.transpose()<<endl;
    return 0;
    #endif

}