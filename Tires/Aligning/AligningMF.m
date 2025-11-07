function [Mz0,t] = AligningMF(CoeffAlign,SFAlign,alpha,Fz,gamma, pressure, CoeffLat,SFLat)

%Lateral Coefficients
PCY1 = CoeffLat(1);
PDY1 = CoeffLat(2);
PDY2 = CoeffLat(3);
PDY3 = CoeffLat(4);
PEY1 = CoeffLat(5);
PEY2 = CoeffLat(6);
PEY3 = CoeffLat(7);
PEY4 = CoeffLat(8);
PEY5 = CoeffLat(9);
PKY1 = CoeffLat(10);
PKY2 = CoeffLat(11);
PKY3 = CoeffLat(12);
PKY4 = CoeffLat(13);
PKY5 = CoeffLat(14);
PKY6 = CoeffLat(15);
PKY7 = CoeffLat(16);
PHY1 = CoeffLat(17);
PHY2 = CoeffLat(18);
PVY1 = CoeffLat(19);
PVY2 = CoeffLat(20);
PVY3 = CoeffLat(21);
PVY4 = CoeffLat(22);
RBY1 = CoeffLat(23);
RBY2 = CoeffLat(24);
RBY3 = CoeffLat(25);
RBY4 = CoeffLat(26);
RCY1 = CoeffLat(27);
REY1 = CoeffLat(28);
REY2 = CoeffLat(29);
RHY1 = CoeffLat(30);
RHY2 = CoeffLat(31);
RVY1 = CoeffLat(32);
RVY2 = CoeffLat(33);
RVY3 = CoeffLat(34);
RVY4 = CoeffLat(35);
RVY5 = CoeffLat(36);
RVY6 = CoeffLat(37);
PPY1 = CoeffLat(38);
PPY2 = CoeffLat(39);
PPY3 = CoeffLat(40);
PPY4 = CoeffLat(41);
PPY5 = CoeffLat(42);

% --- Scaling factors ---
LFZO   = SFLat(1);
LCY    = SFLat(2);
LMUY   = SFLat(3);
LEY    = SFLat(4);
LKY    = SFLat(5);
LKYC   = SFLat(6);
LKZC   = SFLat(7);
LHY    = SFLat(8);
LVY    = SFLat(9);
FNOMIN = SFLat(10);
NOMPRES= SFLat(11);

%Aligning Coefficients
QBZ1 = CoeffAlign(1);
QBZ2 = CoeffAlign(2);
QBZ3 = CoeffAlign(3);
QBZ4 = CoeffAlign(4);
QBZ5 = CoeffAlign(5);
QBZ6 = QBZ4;
QBZ9 = CoeffAlign(6);
QBZ10 = CoeffAlign(7);
QCZ1 = CoeffAlign(8);
QDZ1 = CoeffAlign(9);
QDZ2 = CoeffAlign(10);
QDZ3 = CoeffAlign(11);
QDZ4 = CoeffAlign(12);
QDZ6 = CoeffAlign(13);
QDZ7 = CoeffAlign(14);
QDZ8 = CoeffAlign(15);
QDZ9 = CoeffAlign(16);
QDZ10 = CoeffAlign(17);
QDZ11 = CoeffAlign(18);
QEZ1 = CoeffAlign(19);
QEZ2 = CoeffAlign(20);
QEZ3 = CoeffAlign(21);
QEZ4 = CoeffAlign(22);
QEZ5 = CoeffAlign(23);
QHZ1 = CoeffAlign(24);
QHZ2 = CoeffAlign(25);
QHZ3 = CoeffAlign(26);
QHZ4 = CoeffAlign(27);
PPZ1 = CoeffAlign(28);
PPZ2 = CoeffAlign(29);
SSZ1 = CoeffAlign(30);
SSZ2 = CoeffAlign(31);
SSZ3 = CoeffAlign(32);
SSZ4 = CoeffAlign(33);

%Aligning Scaling Factors
LFZ0 = SFAlign(1);
LMUY = SFAlign(2);
LKY = SFAlign(3);
LTR = SFAlign(4);
LRES = SFAlign(5);
LKYC = SFAlign(6);
LKZC = SFAlign(7);
UNLOADED_RADIUS = SFAlign(8);
FNOMIN = SFAlign(9);
NOMPRES = SFAlign(10);

if Fz==0
   Mz0 = 0;
   return
end
Fz0 = FNOMIN * LFZ0;
alpha = deg2rad(alpha);
dFz = (Fz - Fz0)/Fz0;
pi0 = NOMPRES;
pressure = pressure * 10^5;
dpi = (pressure - pi0)./pi0;
gamma_z = deg2rad(gamma);
gamma_y = gamma_z;
R0 = UNLOADED_RADIUS;


%LateralMF

Cy = PCY1 .* LCY;
MUY = (PDY1 + PDY2 .* dFz) .* (1 + PPY3 .* dpi + PPY4 .* dpi^2) .* (1 - PDY3 .* gamma_y^2) .* LMUY;
Dy = MUY .* Fz;
Kya = PKY1 .* Fz0 .* (1 + PPY1 .* dpi ) .* (1-PKY3*abs((gamma_y))) .* sin(PKY4 .* atan((Fz/Fz0)/(PKY2 + PKY5 .* gamma_y^2).*(1+PPY2 .* dpi))) .* LKY;
Kyg = Fz .* (PKY6+PKY7.*dFz).*(1+PPY5.*dpi).*LKY;
By = Kya/(Cy .* Dy);
Svyg = Fz .* (PVY3 + PVY4 .* dFz) .* gamma_y .* LKY .* LMUY;
Svy = Fz .* (PVY1 + PVY2 .* dFz)*LVY .* LMUY + Svyg;
SHy = (PHY1 + PHY2 .* dFz).*LHY + ((Kyg.*gamma_y - Svyg) ./ (Kya + eps)); 
alpha_y = alpha + SHy;

Ey = (PEY1 + PEY2 .* dFz) .* (1 + (PEY5.*gamma_y^2) - (PEY3 + PEY4 .* gamma_y).*sign(alpha_y)) .* LEY;
Fy0 = (Dy .* sin(Cy .* atan(By .*alpha_y - Ey.*(By .* alpha_y - atan(By .* alpha_y)))) + Svy);

%AligningMF
SHt = QHZ1 + QHZ2 .* dFz + (QHZ3 + QHZ4 .* dFz) .* gamma_z;
alpha_t = alpha + SHt;

SHf = SHy + Svy ./ Kya;
alpha_r = alpha + SHf;

Br = (QBZ9.*LKY./LMUY + QBZ10.*By.*Cy);
Cr = 1;
Dr = Fz.*R0 .* ((QDZ6 + QDZ7.*dFz).*LRES + ((QDZ8 + QDZ9.*dFz).*(1+PPZ2.* dpi) + (QDZ10 + QDZ11.*dFz).*abs(gamma_z)).*gamma_z.*LKYC);
Mzr0 = Dr .* cos(Cr .* atan(Br.*alpha_r)) .* cos(alpha);

Bt = (QBZ1 + QBZ2 .* dFz + QBZ3 .* dFz^2) .* (1 + QBZ5 .* abs(gamma_z) + QBZ6 .* gamma_z^2) .* LKY ./ LMUY;
Ct = QCZ1;
Dt0 = Fz .* (R0./Fz0) .* (QDZ1 + QDZ2.*dFz) .* (1 - PPZ1.*dpi) .* LTR;
Dt = Dt0 .* (1 + QDZ3.*abs(gamma_z) + QDZ4 .* gamma_z^2);
Et = (QEZ1 + QEZ2.*dFz + QEZ3.*dFz^2) .* (1 + (QEZ4 + QEZ5.*gamma_z).*(2/pi).*atan(Bt.*Ct.*alpha_t));

Kza0 = Dt0.*Kya;
Kzy0 = Fz .* R0 .* (QDZ8 + QDZ9.*dFz).*(1+PPZ2.*dpi).*LKYC.*LMUY - Dt0;

t0 = Dt .* cos(Ct .* atan(Bt.*alpha_t - Et.*(Bt.*alpha_t - atan(Bt.*alpha_t)))) .* cos(alpha);
Mz0p = -t0 .* Fy0;
Mz0 = Mz0p + Mzr0;
end
