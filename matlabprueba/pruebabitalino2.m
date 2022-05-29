%Alejandro Rodríguez 19131
%Jorge Lanza 19175
%Juan Diego Villafuerte 19593
%Brayan Castillo 19700
%Temas Especiales de Electrónica y Mecatrónica 2
%Sección 30
%Última actualización: 27/05/2022
%Proyecto Final Mano Controlada por señales EMG medidas con Bitalino 
%provenientes del pie

%Comunicación de Matlab con Arduino
P = serial('COM7','BaudRate', 9600);
fopen(P);
%Inicio comunicación Bitalino con Matlab por Bluetooth
% Create the object
b = Bitalino('BITalino-00-97', 1000);
% Start background acquisition
startBackground(b);
% Read the data from the device
%valores centinelas
time = 0;  %período de muestreo para cada medición
time2 = 0; %centinela para proceso de medición: 0 para medir, 1 para terminar
%comunicación con Bitalino y Arduino
%ciclo de medición
while (time2 < 1)
    %elección de continuar o terminar comunicación
    stopBackground(b);
    time2 = input("Continuar?")
    startBackground(b);
%medición
while (time < 5) 
    pause (1)
    time = time + 1
end
time = 0;            %fin de medición
data = read(b);      %lectura del buffer del Bitalino
EMG_raw = data(:,6); %adquisición de datos del puerto A1 (EMG) del Bitalino
EMG = ((EMG_raw/1024-0.5)*3.3/1009)*1000; %conversión de raw data a mV
%gráfica señal EMG
clf; figure(1);
plot(EMG);
xlabel('Tiempo discreto (5s)'); ylabel('mV'); title('Señal EMG vs tiempo discreto');
%gráfica del espectro de amplitud unilateral de la señal EMG
figure(2);
[t_emg, x_centrada, f_emg, P3] = ssaefun(EMG);
P3(1) = 0;
stem(f_emg,P3);
xlabel('Frecuencia (Hz)'); ylabel('Magnitud'); title('Espectro de amplitud unilateral');
%extracción del valor de magnitud máxima del espectro unilateral de
%frecuencia
maximo = max(P3)
%identificación de la frecuencia correspondiente (más predominante en la
%señal)
posicion = find(P3 == maximo) 
frecuencia = f_emg(posicion)
%condicionales de señales identificadas
%movimientos del pie / movimiento traducido a la mano robótica
% pie cerrado / mano cerrado
if(frecuencia >= 70 && frecuencia <= 155 && maximo >= 0.0125)
    valorEnviar = "4"
% dedos separados / signo paz y amor
elseif(frecuencia >= 70 && frecuencia <= 220 && maximo <= 0.012&& maximo >= 0.008)
    valorEnviar = "3"
% dedo pulgar arriba / pinza
elseif(frecuencia >= 70 && frecuencia <= 160 && maximo <= 0.0075&& maximo >= 0.003)
    valorEnviar = "1"
%dedo pulgar abajo / hacer 3 con la mano    
elseif(frecuencia >= 70 && frecuencia <= 150 && maximo <= 0.0029&& maximo >= 0.0006)
    valorEnviar = "2"
% pie en posición de descanso / mano abierta
else
    valorEnviar = "5"
end
%envio de valor a arduino
fprintf(P,valorEnviar);
end
%final de la comunicación
% Stop background acquisition of data
b.stopBackground;
% Clean up the bitalino object
delete(b)
fclose(P);
