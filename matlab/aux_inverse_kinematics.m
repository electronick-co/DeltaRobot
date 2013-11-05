function [ status,theta ] = aux_inverse_kinematics( x0,y0,z0,f,e,rf,re )
     status=1;
     y1 = -0.5 * 0.57735 * f; % f/2 * tg 30
     y0 = y0-0.5 * 0.57735    * e;    % shift center to edge
     % z = a + b*y
     a = (x0*x0 + y0*y0 + z0*z0 +rf*rf - re*re - y1*y1)/(2*z0);
     b = (y1-y0)/z0;
     % discriminant
     d = -(a+b*y1)*(a+b*y1)+rf*(b*b*rf+rf); 
     if (d < 0) 
         status= 0; % non-existing point
         theta=0;
     else
         yj = (y1 - a*b - sqrt(d))/(b*b + 1); % choosing outer point
         zj = a + b*yj;
         aux=0;
         if yj>y1
             aux=180;
         end
         theta = atand(-zj/(y1 - yj)) + aux;
     end
end

