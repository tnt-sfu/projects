% Optimization options
options = optimoptions('fminunc', 'GradObj', 'on', 'Algorithm', 'trust-region');
% Starting points
startingPoints = [[0; 0], [-1; 0], [3; 2], [-2; -2]];
for i = 1:size(startingPoints, 2)
   x0 = startingPoints(:, i);  % Initial guess
   % Run optimization
   [X, FVAL, EXITFLAG, OUTPUT] = fminunc(@Lab2_Fun, x0, options);
   % Display results
   fprintf('Starting Point: [%d, %d]\n', x0(1), x0(2));
   fprintf('Iterations: %d, Final Point: [%f, %f], Function Value: %f\n', ...
           OUTPUT.iterations, X(1), X(2), FVAL);
end

