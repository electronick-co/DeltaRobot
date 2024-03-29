function [ status,x0,y0,z0 ] = forward_kinematics( theta1,theta2,theta3 )
     
     % robot geometry
    e = 82.7;     % end effector
    f = 119.198;     % base
    re = 215.0;
    rf = 150.0;
 
    status=1;
    
     t = (f-e)*tand(30)/2;
     dtr = pi/180.0;
     theta1 = theta1*dtr;
     theta2 = theta2*dtr;
     theta3 = theta3*dtr;
 
     y1 = -(t + rf*cos(theta1));
     z1 = -rf*sin(theta1);
 
     y2 = (t + rf*cos(theta2))*sind(30);
     x2 = y2*tand(60);
     z2 = -rf*sin(theta2);
 
     y3 = (t + rf*cos(theta3))*sind(30);
     x3 = -y3*tand(60);
     z3 = -rf*sin(theta3);
 
     dnm = (y2-y1)*x3-(y3-y1)*x2;
 
     w1 = y1*y1 + z1*z1;
     w2 = x2*x2 + y2*y2 + z2*z2;
     w3 = x3*x3 + y3*y3 + z3*z3;
     
     % x = (a1*z + b1)/dnm
     a1 = (z2-z1)*(y3-y1)-(z3-z1)*(y2-y1);
     b1 = -((w2-w1)*(y3-y1)-(w3-w1)*(y2-y1))/2.0;
 
     % y = (a2*z + b2)/dnm;
     a2 = -(z2-z1)*x3+(z3-z1)*x2;
     b2 = ((w2-w1)*x3 - (w3-w1)*x2)/2.0;
 
     % a*z^2 + b*z + c = 0
     a = a1*a1 + a2*a2 + dnm*dnm;
     b = 2*(a1*b1 + a2*(b2-y1*dnm) - z1*dnm*dnm);
     c = (b2-y1*dnm)*(b2-y1*dnm) + b1*b1 + dnm*dnm*(z1*z1 - re*re);
  
     % discriminant
     d = b*b -4.0*a*c;
     if (d < 0) 
         status=0; % non-existing point
     else
         z0 = -0.5*(b+sqrt(d))/a;
         x0 = (a1*z0 + b1)/dnm;
         y0 = (a2*z0 + b2)/dnm;
     end

end



