div=100;
ang_aux=0;
step=2*pi/div;
x=0;
y=0;
r=80; %Radio del circulo

z=-250;

for j=1:div
    y(j)=r*sin(ang_aux);
    x(j)=r*cos(ang_aux);
    ang_aux=ang_aux+step;
end



%%
%[s,t1,t2,t3]=inverse_kinematics(x(1),y(1),z);
%send_command(serialOne,angle_trans(t1),angle_trans(t2),angle_trans(t3));
%pause(2)

for i= 1:size(y,2)
    [s,t1(i),t2(i),t3(i)]=inverse_kinematics(x(i),y(i),z);
end


%% send commands
for i= 1:size(y,2)
    send_command(serialOne,t1(i),t2(i),t3(i));
    pause(0.01);
end


%%
% z=-36
% x=0
% y=0
[s,th1,th2,th3]=inverse_kinematics(0,0,z);
send_command(serialOne,th1,th2,th3);

