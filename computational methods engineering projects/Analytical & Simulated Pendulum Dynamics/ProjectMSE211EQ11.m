% Solving EQ 11 analytically to obtain velocity curves

m = 0.3;
r = 1;
g = 9.81;
theta_0 = [4, 12, 18];
lamda = [0.06, 0.07, 0.08, 0.09];
k = sqrt(m*g/r);

% the time vector
t = 0:0.01:8;
% Loop for the values of theta_0

for i = 1:length(theta_0)
    % Calculating  alpha
    alpha = sqrt((k^2/m)-(lamda.^2/(4*m^2)));

    % Calculating the value of theta_dot for all the values of lamda

    theta_dot = zeros(length(lamda), length(t));

    for j = 1:length(lamda)
        theta_dot(j,:) = theta_0(i)*exp((-lamda(j)*t)/(2*m)).*((alpha(j)*sin(alpha(j)*t))+(lamda(j)*cos( alpha(j)*t)/(2*m)));
    end

    % Plotting the graph
    figure(i);
    plot(t, theta_dot);
    xlabel('Time (s)');
    ylabel('Angular velocity (rad/s)'); 
    legend(cellstr(num2str(lamda', 'lambda=%-g'))); 
    title(['theta_0 = ' num2str(theta_0(i))]);
    
end