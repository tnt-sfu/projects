function H = Lab_2_Hess(x)
   % Hessian of Himmelblau's function
   syms x1 x2
   f = (x1^2 + x2 - 11)^2 + (x1 + x2^2 - 7)^2;
   H_f = hessian(f, [x1, x2]);
   H = double(subs(H_f, {x1, x2}, {x(1), x(2)}));
end
