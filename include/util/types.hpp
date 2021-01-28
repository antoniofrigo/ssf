#ifndef TYPES_H
#define TYPES_H

struct PDState {
  double x;
  double y;
  double z;

  double vx;
  double vy;
  double vz;
};

struct PDDeriv {
  double x;
  double y;
  double z;

  double vx;
  double vy;
  double vz;
};

#endif