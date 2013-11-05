function [ status,theta1,theta2,theta3 ] = inverse_kinematics( x0,y0,z0)
% robot geometry
% (look at pics above for explanation)
    e = 82.7;     % end effector
    f = 119.198;     % base
    re = 215.0;
    rf = 150.0;

     theta2 = 0;
     theta3 = 0;
     [status,theta1] = aux_inverse_kinematics(x0,y0,z0,f,e,rf,re);
     if (status == 1) 
         [status,theta2] = aux_inverse_kinematics(x0*cosd(120) + y0*sind(120), y0*cosd(120)-x0*sind(120), z0,f,e,rf,re );  % rotate coords to +120 deg
     end
     if (status == 1)
         [status,theta3] = aux_inverse_kinematics(x0*cosd(120) - y0*sind(120), y0*cosd(120)+x0*sind(120), z0, f,e,rf,re);  % rotate coords to -120 deg
     end

end
