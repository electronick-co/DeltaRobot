function [  ] = send_command( serial, ang1,ang2,ang3 )
%SEND_COMMAND Summary of this function goes here
%   Detailed explanation goes here
str = sprintf('%d,%d,%d\n', angle_trans(ang1), angle_trans(ang2), angle_trans(ang3) );
fprintf(serial,'%s\n', str);
end

