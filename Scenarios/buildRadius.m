function Track = buildRadius(radius)

defaultWidth = 3; % domyślna szerokość toru

turnAngleDeg = 360; % domyślny kąt toru

%% --- Parametr łuku
turnAngleRad = turnAngleDeg * pi / 180;       % na radiany
arcLength = radius * turnAngleRad;            % długość toru

pts_per_m = 100;
L1 = 100;

N = max(10, round(L1 * pts_per_m));      % liczba próbek

% parametr toru – długość
Track.point = linspace(0, arcLength, N);
Track.points_number = N;

%% --- Definicja XY (parametr s -> kąt θ)
% θ(s) = s / R
theta = Track.point / radius;

% Punkt startowy przyjmujemy (0,0) i łuk w kierunku dodatniego Y:
Track.X = radius * sin(theta);
Track.Y = radius * (1 - cos(theta));   % Y rośnie do góry

%% --- Pochodne
% x' = R cos θ * θ'
dx = cos(theta);

% y' = R sin θ * θ'
dy = sin(theta);

%% --- Kąt kierunkowy toru
Track.angle = atan2(dy, dx);

%% --- Krzywizna (1/R)
Track.curvature = ones(1, N) / radius;

%% --- Szerokość toru
Track.width = ones(1, N) * defaultWidth;

%% --- Długość toru (numericznie)
dX = diff(Track.X);
dY = diff(Track.Y);
Track.length = sum(sqrt(dX.^2 + dY.^2));

end
