function [ SF ] = PID_Ball( x )
m=0.11;
rb=0.02;
Le=1;
Ip=0.5;
Ib=1.76*10^-5;
R=3.9;
Kt=6.879*10^-4;
Ke=1.9099*10^-7;
L = 12*10^-6;
d=3*10^-2;
B=10^-8;
Hx = zpk(0,[0,-((Kt*Ke/(Ib+Ip+B))+R)/L],Kt); %Hx=Thetax/Vx
Px = zpk(0,[0,0],9.81*7/5); %Px=X/thetax
Kx = Hx*Px; %X/Vx

C = pidtune(Kx,'pid',1);
D = pid(C,0,40);
SF=feedback(D*Kx,1/x);
step(SF);
end

