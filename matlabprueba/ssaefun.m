function [t_emg, x_centrada, f_emg, P3] = ssaefun(x)
Fs_emg = 1000;
N_emg = size(x, 1);
x_centrada = x;
t_emg = linspace(0, N_emg - 1, N_emg);

X_emg = fft(x_centrada);
P4 = abs(X_emg/N_emg);
P3 = P4(1:N_emg/2+1);
P3(2:end-1) = 2*P3(2:end-1);
f_emg = Fs_emg*(0:(N_emg/2))/N_emg;
end