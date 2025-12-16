% Overall parameters

    %Mass and Inertia
    Vehicle_mass = 215; %masa bolidu
    Driver_mass = 75; %masa kierowcy
    Mass = Vehicle_mass + Driver_mass; %masa bolidu z kierowcą
    Iz_wehicle = 120;

    %Center of Gravity
    CoG_x = 0.755;
    CoG_y = 0;
    CoG_z = 0.28;


% suspension
Wheelbase = 1.525;
Track_Front = 1.2;
Track_Rear = 1.18;
Lf = Wheelbase - CoG_x;
Lr = Wheelbase - Lf;

    %Setup
        %Toe [deg]
        Static_Toe_FL = 0;
        Static_Toe_FR = 0;
        Static_Toe_RL = 0;
        Static_Toe_RR = 0;
        
        %Camber [deg]
        Static_Camber_FL = 0;
        Static_Camber_FR = 0;
        Static_Camber_RL = 0;
        Static_Camber_RR = 0;

        %Pressures [bar]
        Tire_pressure_FL = 0.8;
        Tire_pressure_FR = 0.8;
        Tire_pressure_RL = 0.8;
        Tire_pressure_RR = 0.8;

    %Load Transfer
    Default_Fz_F = g*(Mass*(Lr/Wheelbase));
    Default_Fz_R = g*(Mass*(Lf/Wheelbase));
    Default_Fz_FL = Default_Fz_F/2 + (Default_Fz_F*CoG_y/Track_Front);
    Default_Fz_FR = Default_Fz_F/2 - (Default_Fz_F*CoG_y/Track_Front);
    Default_Fz_RL = Default_Fz_R/2 + (Default_Fz_R*CoG_y/Track_Rear);
    Default_Fz_RR = Default_Fz_R/2 - (Default_Fz_R*CoG_y/Track_Rear);
    LLTD = 0.50; % % na przód

    %Steering
    Data_Steering = readmatrix("Steering.xlsx","Sheet",1);
    Steering_Wheel_Angle = Data_Steering(1:end,1);
    Steering_Angle_FL = Data_Steering(1:end,2);
    Steering_Angle_FR = Data_Steering(1:end,3);

%Aero
A = 1.1;
CdA = 0.9*A;
ClA = 3.3*A;
Aero_balance = 55; % [%Front]


% tires
Tire_radius = 0.205;
Iz_wheel = 0.4;
Wheel_rolling_resistance = 0.06;
Data_Fy = readmatrix("Tabela_sil.xlsx");
Data_Fx = readmatrix("Tabela_sil.xlsx", "Sheet", 2);
Fz = Data_Fy(2:end,2);
SA = Data_Fy(1,3:end);
Fy = Data_Fy(2:end,3:end);
SR = Data_Fx(1,3:end);
Fx = Data_Fx(2:end,3:end);


%Brakes
Lock_brake_balance = false;
Front_brake_balance = 0.0; % exact if locked, else adjustment

Br_coef_of_friction_F = 0.48;
Br_pistons_area_F = 3617.26/1e6;
Effective_br_disk_r_F = 0.0905;
Br_coef_of_friction_R = 0.48;
Br_pistons_area_R = 2026.83/1e6;
Effective_br_disk_r_R = 0.0895;


%Regen braking
Front_desired_brake_p_balance = 0.6;
Front_brake_pump_area = 153.94;
Rear_brake_pump_area = 198.56;


%Powertrain
Motor_maximum_torque = 29.1;
Motor_maximum_power = 35366;
Gear_ratio = 12.9;
PRT_efficiency = 0.95;


%Ustawienia momentu
Torque_limit_set = 7;
Torque_limit_min = Motor_maximum_torque*0.1; % [Nm] Ustawienie momentu minimalne
Torque_limit_2 = Motor_maximum_torque*0.2; % [Nm] Ustawienie momentu 2
Torque_limit_3 = Motor_maximum_torque*0.3; % [Nm] Ustawienie momentu 3
Torque_limit_4 = Motor_maximum_torque*0.4; % [Nm] Ustawienie momentu 4
Torque_limit_5 = Motor_maximum_torque*0.5; % [Nm] Ustawienie momentu 5
Torque_limit_6 = Motor_maximum_torque*0.6; % [Nm] Ustawienie momentu 6
Torque_limit_7 = Motor_maximum_torque*0.7; % [Nm] Ustawienie     momentu 7
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

