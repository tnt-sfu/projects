% Clear the command window and workspace for a clean start
clc; clear;

%% Defining the System of Equations for the Circuit
% The matrix A represents the coefficients of the system of linear equations
% derived from Kirchhoff's laws for the electrical circuit.
A = [1 0 0 0 2000 0 0 0 0 0;
    1 -1 0 0 0 -12000 0 0 0 0;
    1 0 0 -1 0 0 -20000 0 0 0;
    0 1 0 -1 0 0 0 -18000 0 0;
    0 1 -1 0 0 0 0 0 -10000 0;
    0 0 1 -1 0 0 0 0 -20000 0;
    0 0 0 1 0 0 0 0 0 -15000;
    0 0 0 0 1 -1 -1 0 0 0;
    0 0 0 0 0 1 0 -1 -1 0;
    0 0 0 0 0 0 1 1 1 -1];

% The vector b represents the constants on the right-hand side of the equations.
b = [5; 0; 0; 0; 0; 0; 0; 0; 0; 0];

%% Solve the Linear System to Find Circuit Parameters
% Solves for x in A*x = b to find currents and voltages in the circuit.
x = A\b;

% Calculate the discrepancy vector c to analyze the accuracy of the solution.
c = A*x - b;

% Display the norm of vector c as a measure of solution accuracy.
disp(norm(c));

% Calculate and display the condition number of the matrix A using various norms.
disp(['Frobenius norm condition number: ', num2str(cond(A))]);
disp(['1-norm condition number: ', num2str(cond(A,1))]);
disp(['Infinity norm condition number: ', num2str(cond(A, 'inf'))]);

%% Modify the Circuit by Replacing Resistor and Repeat Analysis
% Update matrix A for the circuit with a 1 gigohm resistor between nodes 5 and 6.
A_gig = A;
A_gig(7,10) = -1e9; % Adjusting the value for the modified resistor

% Solve the modified linear system.
x_gig = A_gig\b;

% Calculate the discrepancy vector for the modified circuit.
c_gig = A_gig*x_gig - b;

% Display the norm of vector c for the modified circuit.
disp(norm(c_gig));

% Calculate and display the condition number of the modified matrix.
disp(['Modified Frobenius norm condition number: ', num2str(cond(A_gig))]);
disp(['Modified 1-norm condition number: ', num2str(cond(A_gig,1))]);
disp(['Modified Infinity norm condition number: ', num2str(cond(A_gig, 'inf'))]);
