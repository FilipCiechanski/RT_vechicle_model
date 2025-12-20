function Track = buildSkidpad(entryLength, exitLength)

defaultWidth = 3;

%% --- parametry skidpadu
D_center = 18.25;      % odległość między centrami pętli
R = D_center / 2;      % promień linii środkowej

CL = [-D_center/2, 0]; % środek pętli lewej
CR = [ D_center/2, 0]; % środek pętli prawej

%% --- próbkowanie
pts_per_m = 100;
L1 = 100;

N = max(10, round(L1 * pts_per_m));

thetaL = linspace(0,   2*pi, N/2);
thetaR = linspace(pi, 3*pi, N/2);

%% --- pętle skidpadu
XL = CL(1) + R * cos(thetaL);
YL = CL(2) + R * sin(thetaL);

XR = CR(1) + R * cos(thetaR);
YR = CR(2) + R * sin(thetaR);

%% --- punkt styczny (środek ósemki)
X_mid = 0;
Y_mid = 0;

%% --- pionowy wjazd (od dołu)
X_entry = zeros(1, 200) + X_mid;
Y_entry = linspace(-entryLength, Y_mid, 200);

%% --- pionowy wyjazd (w dół)
X_exit = zeros(1, 200) + X_mid;
Y_exit = linspace(Y_mid, +exitLength, 200);

%% --- złączenie w całą trasę
Track.X = [X_entry, XL, XR, X_exit];
Track.Y = [Y_entry, YL, YR, Y_exit];

%% --- pochodne numeryczne
dX = gradient(Track.X);
dY = gradient(Track.Y);

ddX = gradient(dX);
ddY = gradient(dY);

Track.angle = atan2(dY, dX);

%% --- krzywizna
num = abs(dX .* ddY - dY .* ddX);
den = (dX.^2 + dY.^2).^(3/2);
Track.curvature = num ./ den;
Track.curvature(~isfinite(Track.curvature)) = 0;

%% --- szerokość toru
Track.width = ones(size(Track.X)) * defaultWidth;

%% --- długość toru
ds = sqrt(diff(Track.X).^2 + diff(Track.Y).^2);

% usuwamy zerowe przyrosty, żeby Track.point był monotoniczny
valid = ds > 1e-12;
ds = ds(valid);

Track.point = [0, cumsum(ds)];

% dopasowanie rozmiarów
Track.X = Track.X([true, valid]);
Track.Y = Track.Y([true, valid]);
Track.width = Track.width([true, valid]);
Track.angle = Track.angle([true, valid]);
Track.curvature = Track.curvature([true, valid]);

% ponowna eliminacja powtórzeń
[Track.point, uniqueIdx] = unique(Track.point, "stable");

Track.X = Track.X(uniqueIdx);
Track.Y = Track.Y(uniqueIdx);
Track.width = Track.width(uniqueIdx);
Track.angle = Track.angle(uniqueIdx);
Track.curvature = Track.curvature(uniqueIdx);

Track.length = Track.point(end);
Track.points_number = length(Track.point);

end
