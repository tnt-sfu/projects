% --- System Specifications (Table I) ---
Pr_hp = 3;              % Rated Power (hp)
Vr_LL = 220;            % Rated Voltage Line-to-Line (V)
f_s = 60;               % Rated Frequency (Hz)
P = 4;                  % Number of Poles
rs = 0.435;             % Stator Resistance (Ohms)
Xls = 0.754;            % Stator Leakage Reactance (Ohms)
Xm = 26.13;             % Magnetizing Reactance (Ohms)
Xlr = 0.754;            % Rotor Leakage Reactance (Ohms)
rr = 0.816;             % Rotor Resistance (Ohms)
J = 0.089;              % Moment of Inertia (kg m^2)

% --- Calculated Parameters ---
w_b = 2 * pi * f_s;     % Base electrical frequency (rad/s)
V_peak = (Vr_LL / sqrt(3)) * sqrt(2); % Phase Voltage Peak (V)

% Inductances (L = X / w_b)
Lls = Xls / w_b;
Lm  = Xm  / w_b;
Llr = Xlr / w_b;

% Self Inductances
Ls = Lls + Lm;
Lr = Llr + Lm;

% Determinant for Inverse Calculation (Slide 15)
D = Ls * Lr - Lm^2;