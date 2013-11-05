%%
%serialOne=serial('COM5', 'BaudRate', 115200);
%fopen(serialOne);



%%

goto(0,0,-350,serialOne)


%%
aux1 = [ 39.1630,20.6569,28.9534,34.2561];
 aux2 = [ 39.1630,22.4614,32.3249,33.4456];
 aux3 = [ 39.1630,22.4614,24.5582,33.4456];
for i=1:1
 for R = 1:size(aux1,2)
    send_command(serialOne,aux1(R),aux2(R),aux3(R))
    pause(1);
end
end
%fclose(serialOne);