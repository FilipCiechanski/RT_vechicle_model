function Track = buildSlalom(totalLength, spacing)

    defaultWidth = 3;
    amplitude = 2;

pts_per_m = 100;
L1 = totalLength;
N = max(10, round(L1 * pts_per_m));
Track.points_number = N;
Track.point = linspace(0, totalLength, N);

%% --- Tor XY
X = Track.point;
Y = amplitude * sin(2*pi*(X - spacing/2)/(2*spacing));

Track.X = X;
Track.Y = Y;

%% --- Pochodne
dY  = amplitude * (2*pi/(2*spacing)) * cos(2*pi*X/(2*spacing));
ddY = -amplitude * (2*pi/(2*spacing))^2 * sin(2*pi*X/(2*spacing));

dx = ones(1, N);
dy = dY;

%% --- Kąt kierunkowy
Track.angle = atan2(dy, dx);

%% --- Krzywizna
num = abs(dx .* ddY - dy .* 0);
den = (dx.^2 + dy.^2).^(3/2);
Track.curvature = num ./ den;
Track.curvature(~isfinite(Track.curvature)) = 0;

%% --- Szerokość
Track.width = ones(1, N) * defaultWidth;

end
