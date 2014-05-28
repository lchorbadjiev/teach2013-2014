function [ax, ay] = grav(x, y, vx, vy)

  r2 = x^2 + y^2;
  r = sqrt(r2);

  G = 10000;
  
  ax = - G * x / (r2 * r);
  ay = - G * y / (r2 * r);
