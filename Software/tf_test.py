#!/usr/bin/python3

import tensorflow as tf

print ('tensorflow version', tf.__version__)


#tf.enable_eager_execution()

activate  = tf.constant('TensorFlow up and running!')
#print(activate)
sess = tf.Session()
print(sess.run(activate))


