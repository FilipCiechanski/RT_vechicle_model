function [Fy, Svy, SHy, Kya, By, Cy] = CombinedLateralMF(CoeffLat,SFLat,kappa,alpha,Fz,gamma,pressure)

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
LYKA = SFLat(12);

if Fz==0
   Fy = 0;
   return
end
Fz0 = FNOMIN * LFZO;
alpha = (deg2rad(alpha));
dFz = (Fz - Fz0)./Fz0;
pi0 = NOMPRES;
pressure = pressure * 10^5;
dpi = (pressure - pi0)./pi0;
gamma_y = sin(deg2rad(gamma));

%Pure Fy
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

%Combined Fy

SHyk = RHY1 + RHY2.*dFz;
kappa_s = kappa + SHyk;
Byk = (RBY1 + RBY4.*gamma_y^2).*cos(atan(RBY2.*(alpha-RBY3))).*LKY;
Cyk = RCY1;
Eyk = REY1 + REY2.*dFz;
DVyk = Fy0.*(RVY1 + RVY2.*dFz + RVY3.*gamma_y).*cos(atan(RVY4.*alpha));
SVyk = DVyk.*sin(RVY5.*atan(RVY6.*kappa)).*LYKA;


Gyk0 = cos(Cyk.*atan(Byk.*SHyk - Eyk.*(Byk.*SHyk - atan(Byk.*SHyk))));
Gyk = cos(Cyk.*atan(Byk.*kappa_s - Eyk.*(Byk.*kappa_s - atan(Byk.*kappa_s))))./Gyk0;
Fy = Gyk .* Fy0 + SVyk;
end