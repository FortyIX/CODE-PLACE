#(c) 2019 FU ZHANG
# Question 7
# Create a clock that runs actively in terminal, time should be updated with the real system time without start new line

#exampe input
#

#example output
#2019-06-19 03:02:33.315808




from datetime import datetime
import time,os

while True:
        print(datetime.now())
        time.sleep(1)
        os.system('clear')
