#ifndef BODY_H
#define BODY_H

class Body {
  public:
    double m;
    double state[9]; // x, y, z, vx, vy, vz, ax, ay, az
    double state_old[9]; // x, y, z, vx, vy, vz, ax, ay, az
    Body(double a[9], double mass) : m(mass) {for (int i = 0; i < 9; ++i) state[i] = a[i];}
    Body() : state{0.0}, state_old{0.0} {}

    void update_acceleration(Body &obj2);
    void update_position(Body &obj1, double &dt);
    void get_r_square(double &rsq, Body &obj2);
    void reset_force();
};

#endif
