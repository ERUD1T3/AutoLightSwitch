# AutoLightSwitch
Repo for the development of an automatic light switcher for FIT dorm

# Sound processings
  $arecord for microphone recording. saves it into a .wav file
  $aplay for microphone playback
  
# Voice recording
    arecord -D plughw:1,0 -d 2 -f S16_LE -c1 -r16000  test2.wav && aplay test2.wav
# Voice playback
    aplay test.wav
    
# Running Tensorflow on .wav
    python3 label_wav.py --graph=model_graph.pb --labels=conv_labels.txt --wav=test.wav

