#!/usr/bin/python3
import binascii
import colorama

# http://patorjk.com/software/taag/#p=display&f=Poison&t=DDoor
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

print(banner)
header = b"!c"
linux_cmd = input("Linux Command> ").encode("utf-8")
windows_cmd = input("Windows Command> ").encode("utf-8")
encoded_header = binascii.hexlify(header + linux_cmd + b"!&" + windows_cmd).decode("utf-8")
print("\t>> {} <<".format(encoded_header))