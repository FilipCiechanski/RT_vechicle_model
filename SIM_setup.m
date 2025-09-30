% Initial Conditions
start_time = 1188; %Sekunda startu symulacji
run_number = 2;
manual = 1;
data_time = 1;

if run_number <= 1
    if manual == 1
        start_velocity_x = 0;
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
    start_velocity_x_ts = resample(out.Vel_X,data_time);
    start_velocity_y_ts = resample(out.Vel_Y,data_time);
    start_acc_x_ts = resample(out.Acc_X,data_time);
    start_acc_y_ts= resample(out.Acc_Y,data_time);
    start_yaw_rate_ts = resample(out.Vel_Yaw,data_time);
    start_yaw_acc_ts = resample(out.Acc_Yaw,data_time);
    
    start_velocity_x = double(start_velocity_x_ts.Data);
    start_velocity_y = double(start_velocity_y_ts.Data);
    start_acc_x = double(start_acc_x_ts.Data);
    start_acc_y = double(start_acc_y_ts.Data);
    start_yaw_rate = double(start_yaw_rate_ts.Data);
    start_yaw_acc = double(start_yaw_acc_ts.Data);
end


%Conditions

Vx_APPS_ON = 1; % 1 - APPS na PID; 0 - APPS z logów
Aeromaps_ON = 0; %1 - aeromapy włączone; 0 - stałe ClA, CdA i balans; !!!TYLKO DLA RT15e I DALEJ!!!
TV_ON = 0;

% Otoczenie
g = 9.81;
air_density = 1.2;
friction_coeficient = 1;