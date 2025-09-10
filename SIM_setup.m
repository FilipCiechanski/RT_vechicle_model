% Initial Conditions
start_time = 1116; %Sekunda startu symulacji
%start_velocity = 0; % Prędkość na starcie symulacji
start_velocity = maths_GPS_Velocity.Value(find(maths_GPS_Velocity.Time > start_time, 1)); %Pobieranie z logów
start_lat_acc = Xsens_MTI_670_accY.Value(find(Xsens_MTI_670_accY.Time > start_time, 1)); %Pobieranie z logów
start_long_acc = Xsens_MTI_670_accX.Value(find(Xsens_MTI_670_accX.Time > start_time, 1));

%Conditions

Vx_APPS_ON = 0; % 1 - APPS na PID; 0 - APPS z logów
Aeromaps_ON = 0; %1 - aeromapy włączone; 0 - stałe ClA, CdA i balans; !!!TYLKO DLA RT15e I DALEJ!!!
TV_ON = 0;

% Otoczenie
g = 9.81;
air_density = 1.2;
friction_coeficient = 1;