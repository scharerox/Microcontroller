import smbus
import time
bus = smbus.SMBus(1)
address = 0x04

def getOutput():
    output = bus.read_byte_data(address,1)
    return output

while True:

    try:
        #x = int(bus.read_byte_data(address,0))
        #print x
        
        
        rep = bus.read_i2c_block_data(address,0)
    except:
        continue
    string = ""
    for i in range(0,8):
        string += chr(rep[i])
    print string
    time.sleep(0.1)

    
