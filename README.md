# AutoLightSwitch
Repo for the development of an automatic light switcher for FIT dorms

# How install tensorflow
  sudo pip install tensorflow
  
# How to uninstall tensorflow
  cd /home/AIJ/tensorflow/_python_build
  python setup.py develop --uninstall

# Sound processings
  $arecord for microphone recording. saves it into a .wav file
  $aplay for microphone playback
  
# Voice recording
    arecord -D plughw:1,0 -d 2 -f S16_LE -c1 -r16000  test2.wav && aplay test2.wav

# Running Tensorflow on .wav

    python3 /home/pi/Desktop/tensorflow/tensorflow/examples/speech_commands/label_wav.py 
    --graph=my_frozen_graph.pb --labels=conv_actions_labels.txt --wav=test2.wav

  
# Activation of the Servo
