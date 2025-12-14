function Track = buildLaneChange(offsetY, L2, L3)

    defaultWidth = 3; % domyślna szerokość toru

pts_per_m = 100;
L1 = 12;

%% --- Parametry globalne
N1 = max(10, round(L1 * pts_per_m));
N2 = max(10, round(L2 * pts_per_m));
N3 = max(10, round(L3 * pts_per_m));


%   SEKCJA 1 — PROSTA

L1 = 12;                   % Zawsze 12 metrów
s1 = linspace(0, L1, N1);
X1 = s1;
Y1 = zeros(1, N1);


%   SEKCJA 2 — ZMIANA PASA

s2 = linspace(0, L2, N2);
X2 = L1 + s2;

% gładkie przejście 0 → offsetY
Y2 = (offsetY/2) * (1 - cos(pi * s2 / L2));


%   SEKCJA 3 — PROSTA NA NOWYM PASIE

s3 = linspace(0, L3, N3);
X3 = L1 + L2 + s3;
Y3 = ones(1, N3) * offsetY;


%% --- Połączenie wszystkich sekcji
Track.X = [X1, X2, X3];
Track.Y = [Y1, Y2, Y3];

%% --- Liczenie pochodnych numerycznie
dX = gradient(Track.X);
dY = gradient(Track.Y);

ddX = gradient(dX);
ddY = gradient(dY);

%% --- Kąt kierunkowy toru
Track.angle = atan2(dY, dX);

%% --- Krzywizna
num = abs(dX .* ddY - dY .* ddX);
den = (dX.^2 + dY.^2).^(3/2);
Track.curvature = num ./ den;
Track.curvature(~isfinite(Track.curvature)) = 0;

%% --- Szerokość toru
N = length(Track.X);
Track.width = ones(1, N) * defaultWidth;

%% --- Długość toru
ds = sqrt(diff(Track.X).^2 + diff(Track.Y).^2);
Track.length = sum(ds);

%% --- Parametr toru (Simulink-friendly)
Track.points_number = N;
Track.point = linspace(0, Track.length, N);

end
