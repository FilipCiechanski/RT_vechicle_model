function [Fx0, SVx, SHx, Kx]= LongitudinalMF(CoeffLong,SFLong,kappa,Fz,gamma,pressure)

% === Coefficients (Longitudinal) ===
PCX1 = CoeffLong(1);
PDX1 = CoeffLong(2);
PDX2 = CoeffLong(3);
PDX3 = CoeffLong(4);
PEX1 = CoeffLong(5);
PEX2 = CoeffLong(6);
PEX3 = CoeffLong(7);
PEX4 = CoeffLong(8);
PKX1 = CoeffLong(9);
PKX2 = CoeffLong(10);
PKX3 = CoeffLong(11);
PHX1 = CoeffLong(12);
PHX2 = CoeffLong(13);
PVX1 = CoeffLong(14);
PVX2 = CoeffLong(15);
PPX1 = CoeffLong(16);
PPX2 = CoeffLong(17);
PPX3 = CoeffLong(18);
PPX4 = CoeffLong(19);
RBX1 = CoeffLong(20);
RBX2 = CoeffLong(21);
RBX3 = CoeffLong(22);
RCX1 = CoeffLong(23);
REX1 = CoeffLong(24);
REX2 = CoeffLong(25);
RHX1 = CoeffLong(26);

% === Scaling Factors (Longitudinal) ===
LFZO   = SFLong(1);
LCX    = SFLong(2);
LMUX   = SFLong(3);
LEX    = SFLong(4);
LKX    = SFLong(5);
LHX    = SFLong(6);
LVX    = SFLong(7);
FNOMIN = SFLong(8);
NOMPRES= SFLong(9);

if Fz==0
    Fx0 = 0;
    return
end
Fz0 = FNOMIN * LFZO;
dFz = (Fz-Fz0)/Fz0;
pi0 = NOMPRES;
pressure = pressure * 10^5;
dpi = (pressure - pi0)/pi0;
gamma = deg2rad(gamma);

SHx = (PHX1+PHX2*dFz)*LHX;
kappa_x = kappa + SHx;

Cx = PCX1 * LCX;
MUX = (PDX1 + PDX2*dFz) .* (1 + PPX3 .* dpi + PPX4.*dpi^2) .* (1-PDX3*gamma^2)*LMUX;
Dx = MUX * Fz;

Kx = Fz * (PKX1 + PKX2*dFz) * exp(PKX3*dFz) * (1+PPX1.*dpi+PPX2.*dpi^2) .* LKX; 
Bx = Kx/(Cx*Dx+eps);

Ex = (PEX1+ PEX2*dFz +PEX3*dFz^2) * (1- PEX4 * sign(kappa_x))*LEX;

SVx = Fz * (PVX1 + PVX2*dFz)*LVX*LMUX;

Fx0 = Dx .* sin(Cx .* atan(Bx .* kappa_x - Ex.*(Bx.*kappa_x - atan(Bx.*kappa_x)))) + SVx;