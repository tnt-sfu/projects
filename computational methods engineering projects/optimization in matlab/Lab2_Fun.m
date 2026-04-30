function [f, grad] = Lab2_Fun(x)
   f = (x(1)^2 + x(2) - 11)^2 + (x(1) + x(2)^2 - 7)^2;
   if nargout > 1  % Check if gradient is requested
       grad = [4*x(1)*(x(1)^2 + x(2) - 11) + 2*(x(1) + x(2)^2 - 7);
               2*(x(1)^2 + x(2) - 11) + 4*x(2)*(x(1) + x(2)^2 - 7)];
   end
end
