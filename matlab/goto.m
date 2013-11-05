function [  ] = goto( x,y,z,serial )
%GOTO Summary of this function goes here
%   Detailed explanation goes here

[s,th1,th2,th3]=inverse_kinematics(x,y,z);
if s==1
    send_command(serial,th1,th2,th3);
end

end

