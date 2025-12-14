function Track = buildDoubleLaneChange(offsetY, L2, L3, L4)

    defaultWidth = 3;

pts_per_m = 100;
L1 = 12;
L5 = 12;
%% Ustalona liczba punktów dla płynności
N1 = max(10, round(L1 * pts_per_m));
N2 = max(10, round(L2 * pts_per_m));
N3 = max(10, round(L3 * pts_per_m));
N4 = max(10, round(L4 * pts_per_m));
N5 = max(10, round(L5 * pts_per_m));

%% ============================================
%             SEKCJA 1 – PROSTA 12 m
% =============================================
L1 = 12;
s1 = linspace(0, L1, N1);
X1 = s1;
Y1 = zeros(1, N1);

%% ============================================
%  SEKCJA 2 – ZMIANA PASA 0 → offsetY (długość L2)
% =============================================
s2 = linspace(0, L2, N2);
X2 = L1 + s2;

% gładna zmiana pasa (półcosinus)
Y2 = (offsetY/2) * (1 - cos(pi * s2 / L2));

%% ============================================
%      SEKCJA 3 – PROSTA NA DRUGIM PASIE
% =============================================
s3 = linspace(0, L3, N3);
X3 = L1 + L2 + s3;
Y3 = ones(1, N3) * offsetY;

%% ============================================
%   SEKCJA 4 – POWRÓT NA PIERWSZY PAS (dł. L4)
% =============================================
s4 = linspace(0, L4, N4);
X4 = L1 + L2 + L3 + s4;

Y4 = offsetY - (offsetY/2) * (1 - cos(pi * s4 / L4));

%% ============================================
%             SEKCJA 5 – PROSTA 12 m
% =============================================
L5 = 12;
s5 = linspace(0, L5, N5);
X5 = L1 + L2 + L3 + L4 + s5;
Y5 = zeros(1, N5);

%% ============================================
%     ŁĄCZENIE WSZYSTKICH SEKCJI W JEDEN TOR
% =============================================

Track.X = [X1, X2, X3, X4, X5];
Track.Y = [Y1, Y2, Y3, Y4, Y5];


%% --- Liczenie pochodnych, kąta i krzywizny
dX = gradient(Track.X);
dY = gradient(Track.Y);

ddX = gradient(dX);
ddY = gradient(dY);

Track.angle = atan2(dY, dX);

num = abs(dX .* ddY - dY .* ddX);
den = (dX.^2 + dY.^2).^(3/2);
Track.curvature = num ./ den;
Track.curvature(~isfinite(Track.curvature)) = 0;

%% --- Szerokość toru
N = length(Track.X);
Track.width = ones(1, N) * defaultWidth;

%% --- Łączna długość toru
ds = sqrt(diff(Track.X).^2 + diff(Track.Y).^2);
Track.length = sum(ds);

%% --- Track.point – wymagane przez Simulink
Track.points_number = N;
Track.point = linspace(0, Track.length, N);

end
