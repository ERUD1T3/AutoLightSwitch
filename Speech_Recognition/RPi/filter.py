#!/usr/bin/python3

#implementation of bandpass filter in python

from scipy.signal import butter, lfilter
from scipy.io.wavfile import read, write
import wave
import numpy as np
import matplotlib.pyplot as plt
from scipy.signal import freqz

def printwav(wavefile):
    spf = wave.open(wavefile,'r')

    #Extract Raw Audio from Wav File
    signal = spf.readframes(-1)
    signal = np.fromstring(signal, 'Int16')
    plt.figure(1)
    plt.title('Signal Wave...')
    plt.plot(signal)
    plt.show()


wav_file = "test.wav"
#plt.plot(wav_file)

lo,hi=300,3400
sr,y = read(wav_file)
b,a=butter(N=6, Wn=[2*lo/sr, 2*hi/sr], btype='band')
x = lfilter(b,a,y)


write('test_filtered.wav', sr, x.astype(np.int16))


printwav('test.wav')
printwav('test_filtered.wav')
