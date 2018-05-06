syms s t x1
m=0.11;
x1 = 4;
y1 = 2;
rb=0.02;
Le=1;
Ip=0.5;
Ib=1.76*10^-5;
R=3.9;
Kt=6.879*10^-4;
Ke=1.9099*10^-7;
L = 12*10^-6;
d=3*10^-2;
Kp = 2.98e+07;
Ki = 1.72e+07;
B=10^-8;
%Hx = Kt/(s*(s+((Kt*Ke/(Ib+Ip+B))+R)/L));
%Px = 9.81*7/(5*s^2);
kx_x = (2.8146*(10^5)*(s^2)*(s+0.5773))/(s*(s^2)*(s+3.25e05)*(s^2 + 2*(1/(2*x1)^(1/2))*s + 1/(2*x1)));
kx_y = (2.8146*(10^5)*(s^2)*(s+0.5773))/(s*(s^2)*(s+3.25e05)*(s^2 + 2*(1/(2*y1)^(1/2))*s + 1/(2*y1)));
kx(t) = ilaplace(kx_x,t)
ky(t) = ilaplace(kx_y,t);

ezplot(kx(t),[0 100]);
%ezplot(ky(t),[0 100]);

%Kx = Hx*Px;
%Hx1 = zpk(0,[0,-((Kt*Ke/(Ib+Ip+B))+R)/L],Kt); %Hx=Thetax/Vx
%Px1 = zpk(0,[0,0],9.81*7/5); %Px=X/thetax
%Kx1 = Hx1*Px1; %X/Vx

%C = pidtune(Kx1,'pid',1);

%SF1=feedback(C*Kx1,1/9);
%step(SF1);