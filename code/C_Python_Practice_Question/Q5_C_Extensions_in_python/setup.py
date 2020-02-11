from distutils.core import setup, Extension
setup(name='Utils', version='1.0',  \
      ext_modules=[Extension('Utils', ['utils.cpp'])])
