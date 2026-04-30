function [X, traj, f, k, Err] = Lab2_sdm(x0, tol)
   % Initialize variables
   k = 0; % Iteration counter
   X = x0; % Initial guess
   traj = [x0]; % Store trajectory of X
   f = [himmelblausFunction(X)]; % Evaluate function at X
   Err = [];
   ea = tol + 1; % Ensure loop starts
   % Main optimization loop
   while ea > tol
       grad = Lab_2_Grad(X); % Gradient of Himmelblau's function at X
       H = Lab_2_Hess(X); % Hessian of Himmelblau's function at X
      
       % Calculate step size using the formula from the manual
       h = abs(grad' * grad) / abs(grad' * H * grad);
      
       % Update X using the steepest ascent formula
       xnew = X + h * grad;
       ea = norm(xnew - X); % Approximation error
      
       % Update variables for the next iteration
       X = xnew;
       traj = [traj, X];
       f = [f, himmelblausFunction(X)];
       Err = [Err, ea];
       k = k + 1;
   end
end
function val = himmelblausFunction(x)
   val = (x(1)^2 + x(2) - 11)^2 + (x(1) + x(2)^2 - 7)^2;
end
