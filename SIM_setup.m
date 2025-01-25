% Warunki początkowe
start_time = 1208; % Sekunda startu symulacji
%start_velocity = 0; % Prędkość na starcie symulacji

%Pobieranie z logów dla ułatwienia
start_velocity = Xsens_MTI_670_vel.Value(find(Xsens_MTI_670_vel.Time > start_time, 1)) * 1000 / 3600;

% Otoczenie
g = 9.81;
air_density = 1.29;
friction_coeficient = 1;

% Mass and inertia
CoG_x = 0.755;
CoG_y = 0;
CoG_z = 0.328;
Mass = 300; %bolid + lekki kierowca
Default_Fz_F = 62*g;
Default_Fz_R = 79*g;
Iz_wehicle = 120;
Iz_wheel = 0.15;
Lateral_load_transfer_distribution = 0.55; % 1 - all distributtion on rear

%Aero
Cd = 1.387;
Cl = 3.299;
A = 1.12;
Aero_balance = 0.55;

% suspension
Lf = 0.770;
Lr = 0.755;
Wheel_base = 1.525;
Half_track = 0.6;

% tires
Tire_radius = 0.203;
Wheel_rolling_resistance = 0.055;
Data_Fy = xlsread("Tabela_sil.xlsx");
Data_Fx = xlsread("Tabela_sil.xlsx", 2);
Fz = Data_Fy(2:end,1);
SA = Data_Fy(1,2:end);
Fy = Data_Fy(2:end,2:end);
SR = Data_Fx(1,2:end);
Fx = Data_Fx(2:end,2:end);

%Brakes
Br_coef_of_friction_F = 0.25;
Br_pistons_area_F = 3617.26/1e6;
Effective_br_disk_r_F = 0.0905;
Br_coef_of_friction_R = 0.25;
Br_pistons_area_R = 2026.83/1e6;
Effective_br_disk_r_R = 0.0895;

%Powertrain
Max_Torque = 29.1;
Motor_maximum_torque = 29.1;
Transmission_gear_ratio = 12.9;

%Ustawienia momentu
Torque_limit_min = Motor_maximum_torque*0.1; % [Nm] Ustawienie momentu minimalne
Torque_limit_2 = Motor_maximum_torque*0.2; % [Nm] Ustawienie momentu 2
Torque_limit_3 = Motor_maximum_torque*0.3; % [Nm] Ustawienie momentu 3
Torque_limit_4 = Motor_maximum_torque*0.4; % [Nm] Ustawienie momentu 4
Torque_limit_5 = Motor_maximum_torque*0.5; % [Nm] Ustawienie momentu 5
Torque_limit_6 = Motor_maximum_torque*0.6; % [Nm] Ustawienie momentu 6
Torque_limit_7 = Motor_maximum_torque*0.7; % [Nm] Ustawienie momentu 7
Torque_limit_8 = Motor_maximum_torque*0.8; % [Nm] Ustawienie momentu 8
Torque_limit_9 = 29.1; % [Nm] Ustawienie momentu 9
Torque_limit_max = Motor_maximum_torque; % [Nm] Ustawienie momentu maksymalne

%Ograniczenia momentu regen brakingu
RB_torque_setting_1 = -2; % [Nm] Ustawienie regen brakingu 1 (maksymalny ujemny moment)
RB_torque_setting_2 = -4; % [Nm] Ustawienie regen brakingu 2 (maksymalny ujemny moment)
RB_torque_setting_3 = -6; % [Nm] Ustawienie regen brakingu 3 (maksymalny ujemny moment)
RB_torque_setting_4 = -8; % [Nm] Ustawienie regen brakingu 4 (maksymalny ujemny moment)
RB_torque_setting_5 = -10; % [Nm] Ustawienie regen brakingu 5 (maksymalny ujemny moment)
RB_torque_setting_6 = -12; % [Nm] Ustawienie regen brakingu 6 (maksymalny ujemny moment)
RB_torque_setting_7 = -14; % [Nm] Ustawienie regen brakingu 7 (maksymalny ujemny moment)
RB_torque_setting_8 = -16; % [Nm] Ustawienie regen brakingu 8 (maksymalny ujemny moment)
RB_torque_setting_9 = -18; % [Nm] Ustawienie regen brakingu 9 (maksymalny ujemny moment)
RB_torque_setting_10 = -20; % [Nm] Ustawienie regen brakingu 10 (maksymalny ujemny moment)


%Torque Vectoring Understeer Gradient
TV_understeer_gradient_1 = -0.5;
TV_understeer_gradient_2 = -0.1;
TV_understeer_gradient_3 = 0.06;
TV_understeer_gradient_4 = 0.05;
TV_understeer_gradient_5 = 0.04;
TV_understeer_gradient_6 = 0.03;
TV_understeer_gradient_7 = 0.02;
TV_understeer_gradient_8 = 0.01;
TV_understeer_gradient_9 = 0.005;
TV_understeer_gradient_10 = 0.002;

%Torque Vectoring RB Understeer Gradient
TV_RB_understeer_gradient_1 = -0.5;
TV_RB_understeer_gradient_2 = -0.1;
TV_RB_understeer_gradient_3 = 0.08;
TV_RB_understeer_gradient_4= 0.06;
TV_RB_understeer_gradient_5 = 0.05;
TV_RB_understeer_gradient_6 = 0.04;
TV_RB_understeer_gradient_7 = 0.03;
TV_RB_understeer_gradient_8 = 0.02;
TV_RB_understeer_gradient_9 = 0.01;
TV_RB_understeer_gradient_10 = 0.005;

%Steering
Steering_ratio_table = [3.25 3.24 3.23 3.20 3.16 3.10 3.04 2.97 2.90 2.77];
Steering_angle_table = [0 9.9 19.9 30.14 40.57 51.05 61.29 70.87 79.38 91.9];