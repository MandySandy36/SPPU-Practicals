import Adafruit_DHT
import RPi.GPIO as GPIO
import time
GPIO.setwarnings(False)
DHT_SENSOR=Adafruit_DHT.DHT11
DHT_PIN=4
GPIO.setmode(GPIO.BOARD)
GPIO.setup(10,GPIO.OUT,initial=GPIO.LOW)

while True:
    humidity,temperature=Adafruit_DHT.read(DHT_SENSOR,DHT_PIN)
    if humidity is not None and temperature is not None:
        print("temp=",temperature,"Humidity=",humidity)
        i=GPIO.input(10)
        if temperature>25 or temperature<20:
            GPIO.output(10,GPIO.HIGH)
            print("Threshold Reached")
        else:
            GPIO.output(10,GPIO.LOW)
    else:
        print("Sensor Failed")
    time.sleep(1)