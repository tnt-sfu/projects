lamda = [0.06, 0.07, 0.08, 0.09];
theta_0 = [4*pi/180, 12*pi/180, 18*pi/180]; 
m = 0.3;
r = 1;
g = 9.81;
t = linspace(0, 8, 1000);
for i = 1:length(theta_0)
figure;
for j = 1:length(lamda)
k = sqrt(m*g/r);

alpha = sqrt((k^2/m)-(lamda(j)^2/(4*m^2)));
theta =theta_0(i)*exp((-lamda(j)*t)/(2*m)).*((cos(alpha*t))+(lamda(j)*sin(alpha*t)/(2* m*alpha)));
plot(t, theta);
hold on;
end

xlabel('Time (s)');
ylabel('Position (m)');
legend('lamda = 0.06', 'lamda = 0.07', 'lamda = 0.08', 'lamda = 0.09'); title(sprintf('Position of Pendulum for theta_0 = %d degrees',theta_0(i)*180/pi));
end