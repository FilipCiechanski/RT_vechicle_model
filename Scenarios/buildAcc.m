function Track = buildAcc(totalLength)

    defaultWidth = 3;   % domyślna szerokość toru

%% 1. Parametry toru
pts_per_m = 100;
L1 = totalLength;
N = max(10, round(L1 * pts_per_m));         
Track.points_number = N;
Track.point = linspace(0, totalLength, N);

%% 3. Szerokość
Track.width = ones(1, N) * defaultWidth;

%% 4. Długość toru
Track.length = 75;

%% 5. Krzywizna
Track.curvature = zeros(1, N);
Track.curvature(~isfinite(Track.curvature)) = 0;

%% 6. Kąt kierunkowy toru (zgodny z układem XY)
Track.angle = zeros(1, N);

end
