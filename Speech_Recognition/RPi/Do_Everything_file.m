%% Fast Fourrier Transform for Piano Bird
[input, Fs] = audioread('test.wav');              % read the audio file

nffta = 2^nextpow2(length(input));                      % length of signal in power of 2 
myffta = fft(input, nffta); 
% FFT 
myfft2a = myffta(1:nffta/2);                            % FFT is symmetric, remove second half 
xffta = Fs * (0:nffta/2-1)/nffta;                       % Frequency vector 
                                                        % Create a new figure 
ax1 = subplot(3, 1, 1);                                 % set up the first graph on the top axis
plot(ax1, xffta, abs(myfft2a));                         % Plot the magnitude of fft of x 
xlabel('Frequency (Hz)');                               % laber x -axis as frequency
ylabel('Power');                                        % label y -axis as Power
title('Comparison of Power Spectrum of filtered Piano bird'); %title of graph
axis([0 25000 0 inf])                                   % X-axis from 0 to 25k and Y-axis from 0 to infinity

%%
song= audioplayer(input,Fs);                            % create a player object 

%%
play(song);                                             % play the song

%%
stop(song);                                             % stop playing the song 

%%
filt = lpf74();                                         % open the filter that is saved in your work space (lab9) 
                 
%%
output = filter(filt, input);                           % attenuate your input by applying the filter filt. 

%%
filtered_song = audioplayer(output,Fs);                 % create a player object 

%%
play(filtered_song );                                   % play the filtered song.

%%
stop(filtered_song);                                    % stop playing the filtered song.

%% Fast Fourrier Transform for Filtered Piano Bird

nfftb = 2^nextpow2(length(output));                     % length of signal in power of 2 
myfftb = fft(output, nfftb); 
% FFT 
myfft2b = myfftb(1:nfftb/2);                            % FFT is symmetric, remove second half 
xfftb = Fs * (0:nfftb/2-1)/nfftb;                       % Frequency vector 
                                                        % Create a new figure 
ax2 = subplot(3, 1, 2);
plot(ax2, xfftb, abs(myfft2b));                         % Plot the magnitude of fft of x
xlabel('Frequency (Hz)'); 
ylabel('Power'); 
title('Comparison of Power Spectrum of filtered Piano bird'); 
axis([0 25000 0 inf])

%% Combined graphs
ax3 = subplot(3, 1, 3);
plot(xffta, abs(myfft2a), xfftb, abs(myfft2b)); % Plot the magnitude of fft of the song and the filter song 
xlabel('Frequency (Hz)'); 
ylabel('Power'); 
title('Comparison of Power Spectrum of Piano bird and filtered Piano Bird'); 
axis([0 25000 0 inf])