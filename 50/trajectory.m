

function [x, y, vx, vy] = trajectory(T, N, x0, y0, vx0, vy0)


  x = nan(1, N);
  y = nan(1, N);

  vx = nan(1, N);
  vy = nan(1, N);

  x(1) = x0;
  y(1) = y0;

  vx(1) = vx0;
  vy(1) = vy0;

  dt = T/N;
  disp(dt)

  for n=2:N
    [ax, ay] = grav(x(n-1),y(n-1), vx(n-1), vy(n-1));
    vx(n) = vx(n-1) + ax * dt;
    vy(n) = vy(n-1) + ay * dt;

    x(n) = x(n-1) + vx(n-1) * dt;
    y(n) = y(n-1) + vy(n-1) * dt;
  end

