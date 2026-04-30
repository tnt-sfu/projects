% Clear the command window and workspace for a clean start
clc;
clear all;

%% Defining the Matrix A and Vector B for Both Circuit Configurations
% Define the system of equations for the original circuit configuration
A = [1 0 0 0 2200 0 0 0 0 0;
     1 -1 0 0 0 -12000 0 0 0 0;
     1 0 0 -1 0 0 -20000 0 0 0;
     0 1 0 -1 0 0 0 -18000 0 0;
     0 1 -1 0 0 0 0 0 -10000 0;
     0 0 1 -1 0 0 0 0 -20000 0;
     0 0 0 1 0 0 0 0 0 -15000;
     0 0 0 0 1 -1 -1 0 0 0;
     0 0 0 0 0 1 0 -1 -1 0;
     0 0 0 0 0 0 1 1 1 -1];

% Update A for the configuration with a 1 GΩ resistor between nodes 5 and 6
A_gig = A;
A_gig(7,10) = -1e9; % Adjusting the value for the modified resistor

B = zeros(10,1);
B(1) = 5; % Supply voltage

%% LU Decomposition and Solution for Original Circuit
% Perform LU decomposition
[L, U, P] = lu(A);
% Calculate the product of P and B
PB = P*B;

% Forward substitution to solve L*d = P*B
d = zeros(10,1); % Initialize vector d
for i = 1:10
    d(i) = PB(i);
    for j = 1:i-1
        d(i) = d(i) - L(i,j)*d(j);
    end
    d(i) = d(i) / L(i,i);
end

% Backward substitution to solve U*x = d
x = zeros(10,1); % Initialize solution vector x
for i = 10:-1:1
    x(i) = d(i);
    for j = i+1:10
        x(i) = x(i) - U(i,j)*x(j);
    end
    x(i) = x(i) / U(i,i);
end

% Display solution for original circuit
disp('Solution for original circuit:');
disp(x);

%% LU Decomposition and Solution for Modified Circuit (1 GΩ Resistor)
% Repeat the process for the circuit with a 1 GΩ resistor
[L_gig, U_gig, P_gig] = lu(A_gig);

% Calculate the product of P_gig and B for the modified circuit
PB_gig = P_gig*B;

% Forward substitution for modified circuit
d_gig = zeros(10,1); % Initialize vector d for modified circuit
for i = 1:10
    d_gig(i) = PB_gig(i);
    for j = 1:i-1
        d_gig(i) = d_gig(i) - L_gig(i,j)*d_gig(j);
    end
    d_gig(i) = d_gig(i) / L_gig(i,i);
end

% Backward substitution for modified circuit
x_gig = zeros(10,1); % Initialize solution vector x for modified circuit
for i = 10:-1:1
    x_gig(i) = d_gig(i);
    for j = i+1:10
        x_gig(i) = x_gig(i) - U_gig(i,j)*x_gig(j);
    end
    x_gig(i) = x_gig(i) / U_gig(i,i);
end

% Display solution for modified circuit
disp('Solution for circuit with 1 GΩ resistor:');
disp(x_gig);
