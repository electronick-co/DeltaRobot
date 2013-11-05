function [  ] = draw_circle( x,y,z,r,points,serial )
%DRAW_CIRCLE Summary of this function goes here
%   Detailed explanation goes here

div=points;
ang_aux=0;
step=2*pi/div;
x_aux=0;
y_aux=0;

for j=1:div
    y_aux(j)=r*sin(ang_aux)+y;
    x_aux(j)=r*cos(ang_aux)+x;
    ang_aux=ang_aux+step;
end

for i= 1:size(y_aux,2)
    [s,t1(i),t2(i),t3(i)]=inverse_kinematics(x_aux(i),y_aux(i),z);
end

for i= 1:size(y_aux,2)
    send_command(serial,t1(i),t2(i),t3(i));
    pause(0.01);
end

[s,th1,th2,th3]=inverse_kinematics(0,0,z);
send_command(serial,th1,th2,th3);

end

