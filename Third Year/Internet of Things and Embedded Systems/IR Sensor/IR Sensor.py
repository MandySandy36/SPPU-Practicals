import RPi.GPIO as GPIO
import time
GPIO.setmode(GPIO.BOARD)
GPIO.setup(8,GPIO.IN)
GPIO.setup(10,GPIO.OUT)
while True:
        if GPIO.input(8)==0:
            GPIO.output(10,True)
            print("Obstacle detected")
            time.sleep(0.1)
        else:
            GPIO.output(10,False)
            print("No Obstacle detected")
            time.sleep(0.1)
