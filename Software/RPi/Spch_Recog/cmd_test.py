#!/usr/bin/python3


import os

cmd = 'echo \'it worked\''
record_cmd = 'arecord -D plughw:1,0 -d 2 -f S16_LE -c1 -r16000  test.wav'
#wait for user imput
play_cmd = 'aplay test.wav'
tf_cmd = 'python3 label_wav.py --graph=model_graph.pb --labels=conv_labels.txt --wav=test.wav'

#to_continue = 'y'

while True:
    to_continue = input('\ntry again? ')
    if to_continue == 'n':
        break
    os.system(record_cmd)
    os.system(play_cmd)
    os.system(tf_cmd)

print('\ndone!\n')




