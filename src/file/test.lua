
require('file')

print('basename aa/bb/cc.aa', File.basename('aa/bb/cc.aa'))
print('basename aa/bb/cc', File.basename('aa/bb/cc'))
print('basename ab', File.basename('ab'))
print('basename ab.exe', File.basename('ab.exe'))
print('basename ab/', File.basename('ab/'))
print('basename .cc', File.basename('.cc'))
File.mkdir('testdir')
