#!/usr/bin/python3


import os

cmd = 'echo \'it worked\''
record_cmd = 'arecord -D plughw:1,0 -d 2 -f S16_LE -c1 -r16000  test_py.wav'
#wait for user imput
play_cmd = 'aplay test_py.wav'
tf_cmd = 'python3 label_wav.py --graph=NN_graph.pb --labels=conv_actions_labels.txt --wav=test_py.wav'

to_continue = 'y'

while to_continue != 'n':
    to_continue = input('try again? ')
    os.system(record_cmd)
    os.system(play_cmd)
    os.system(tf_cmd)

print('done!')




