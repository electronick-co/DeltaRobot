%Delta Robot
%Basic parameters in cm
clear all;
d_up=4;
d_down=3;
l_up=11;
l_down=22;

l_status=0;
iterations=500;
z=linspace(.1,40,iterations);
for i=1:iterations
    [status,t1,t2,t3]=inverse_kinematics(0,0,z(i),d_up,d_down,l_up,l_down);
    if l_status<status
        zmin=z(i);
        t1min=t1;
        t2min=t2;
        t3min=t3;
    end
    if l_status >status
        [x,t1,t2,t3]=inverse_kinematics(0,0,z(i-1),d_up,d_down,l_up,l_down);
        t1max=t1;
        t2max=t2;
        t3max=t3;
        zmax=z(i);
    end
    l_status = status;
end
t1max
t2max
t3max
zmax
zmin
t1min
t2min
t3min