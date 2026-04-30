m = 1;
g = 9.81;
r = 1;
k = sqrt(m*g/r);
lambda_values = [0.06, 0.07, 0.08, 0.09];
theta0_values = [4, 12, 18];
tspan = [0, 8];
h = 0.1;

% Equation 4: m*theta'' + lambda*theta' + (m*g*sin(theta))/r = 0 
for i = 1:length(theta0_values)
    theta0 = theta0_values(i); 
    figure(i)
    for lambda = lambda_values
    f = @(t, theta, omega) -(lambda*omega + (m*g*sin(theta))/r)/m;
    [t, theta, omega] = rungeKutta4SecondOrder(f, tspan, theta0*pi/180, 0, h);
    plot(t, theta*180/pi, 'DisplayName', ['\lambda = ' num2str(lambda)]); 
    hold on
    end
    xlabel('Time (s)')
    ylabel('Angular displacement (deg)')
    title(['Equation 4: Angular displacement vs time for \theta_0 = ',num2str(theta0) '\circ']) 
    legend('Location', 'northwest') 
    hold off
end

% Equation 6: m*theta'' + lambda*theta' + k^2*theta = 0
for i = 1:length(theta0_values) 
    theta0 = theta0_values(i); 
    figure(length(theta0_values) + i) 
    for lambda = lambda_values
        f = @(t, theta, omega) -((lambda/m)*omega + (k^2/m)*theta);
        [t, theta, omega] = rungeKutta4SecondOrder(f, tspan, theta0*pi/180, 0, h);
        plot(t, theta*180/pi, 'DisplayName', ['\lambda = ' num2str(lambda)]);
        hold on 
    end
    xlabel('Time (s)')
    ylabel('Angular displacement (deg)')
    title(['Equation 6: Angular displacement vs time for \theta_0 = ',num2str(theta0) '\circ']) 
    legend('Location', 'northwest') 
    hold off
end

% Fourth-order Runge-Kutta method for solving a second-order ODE
function [t, x, v] = rungeKutta4SecondOrder(f, tspan, x0, v0, h)
t = tspan(1):h:tspan(2); N = length(t);
x = zeros(N, 1);
v = zeros(N, 1);
x(1) = x0;
v(1) = v0;

% Runge-Kutta method
for i = 2:N
    k1x = v(i-1);
    k1v = f(t(i-1), x(i-1), v(i-1));
    k2x = v(i-1) + (h/2)*k1v;
    k2v = f(t(i-1) + h/2, x(i-1) + (h/2)*k1x, v(i-1) + (h/2)*k1v);
    k3x = v(i-1) + (h/2)*k2v;
    k3v = f(t(i-1) + h/2, x(i-1) + (h/2)*k2x, v(i-1) + (h/2)*k2v);
    k4x = v(i-1) + h*k3v;
    k4v = f(t(i-1) + h, x(i-1) + h*k3x, v(i-1) + h*k3v);    
    x(i) = x(i-1) + (h/6)*(k1x + 2*k2x + 2*k3x + k4x);
    v(i) = v(i-1) + (h/6)*(k1v + 2*k2v + 2*k3v + k4v);
end 
end
