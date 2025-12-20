% Initial Conditions
start_time = 2.282366875588375e+03; %Sekunda startu symulacji
run_number = 1;
manual = 0;
data_time = 50;
steering_offset = 0;

%Conditions
Vx_APPS_ON = 0; % 1 - APPS na PID; 0 - APPS z logów
Aeromaps_ON = 0; %1 - aeromapy włączone; 0 - stałe ClA, CdA i balans; !!!TYLKO DLA RT15e I DALEJ!!!
TV_ON = 0;

%Scenarios
addpath("Scenarios")
Track = buildRadius(20);

%Manual Skidpad Configuration
Constant_vel = 1; % 1 - stała prędkość i promień; 0 - stały promień
Corner_radius = 8.5;
Skid_side = 1; %Kierunek skida; 1 - prawo; 0 - lewo

% Otoczenie
g = 9.81;
air_density = 1.2;

if run_number <= 1
    if manual == 1
        start_velocity_x = 9;
        start_velocity_y = 0;
        start_acc_x = 0;
        start_acc_y = 0; 
        start_yaw_rate = 0;
        start_yaw_acc = 0;
    else
        start_velocity_x = maths_GPS_Velocity.Value(find(maths_GPS_Velocity.Time > start_time, 1));
        start_velocity_y = 0;
        start_acc_x = Xsens_MTI_670_accX.Value(find(Xsens_MTI_670_accX.Time > start_time, 1));
        start_acc_y = Xsens_MTI_670_accY.Value(find(Xsens_MTI_670_accY.Time > start_time, 1))*-1; 
        start_yaw_rate = Xsens_MTI_670_gyrZ.Value(find(Xsens_MTI_670_gyrZ.Time > start_time, 1))*-1;
        start_yaw_acc = 0;
    end

else
    vel_x_simout = struct('Time',out.vel_x.time,'Value',out.vel_x.signals.values);
    vel_y_simout = struct('Time',out.vel_y.time,'Value',out.vel_y.signals.values);
    acc_x_simout = struct('Time',out.acc_x.time,'Value',out.acc_x.signals.values);
    acc_y_simout = struct('Time',out.acc_y.time,'Value',out.acc_y.signals.values);
    yaw_rate_simout = struct('Time',out.vel_yaw.time,'Value',out.vel_yaw.signals.values);
    yaw_acc_simout = struct('Time',out.acc_yaw.time,'Value',out.acc_yaw.signals.values);
    
    [~, idx] = min(abs(vel_x_simout.Time - data_time)); %znajdowanie najbliższego punktu do wybranego czasu

    start_velocity_x = vel_x_simout.Value(idx);
    start_velocity_y = vel_y_simout.Value(idx);
    start_acc_x = acc_x_simout.Value(idx);
    start_acc_y = acc_y_simout.Value(idx);
    start_yaw_rate = yaw_rate_simout.Value(idx);
    start_yaw_acc = yaw_acc_simout.Value(idx);
end


