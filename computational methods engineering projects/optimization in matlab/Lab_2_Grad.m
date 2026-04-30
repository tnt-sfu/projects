function grad = Lab_2_Grad(x)
   % Gradient of Himmelblau's function
   syms x1 x2
   f = (x1^2 + x2 - 11)^2 + (x1 + x2^2 - 7)^2;
   grad_f = gradient(f, [x1, x2]);
   grad = double(subs(grad_f, {x1, x2}, {x(1), x(2)}));
end
