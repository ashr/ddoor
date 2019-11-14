# ddoor
cross platform backdoor using dns txt records
## What is ddor?
ddor is a cross platform backdoor that uses txt records to execute commands on infected machines.
## Features
+ Allows a single txt record to have commands for both linux and windows machines
+ List of around 10 public DNS servers that it randomly chooses from
+ Unpredictable call back time
+ ddoor checks for a password before executing a command from a txt record
#### Linux Features:
+ Anti-Debugging, if ptrace is detected as being attached to the shell it will exit.
+ Process Name/Thread names are cloaked, a fake name overwrites all of the system arguments and file name to make it seem like a legitimate program.
+ Automatically Daemonizes
+ Tries to set GUID/UID to 0 (root)
#### Windows Features (partially completed):
+ 
## Installation
To install the dependencies needed for the python generation script run.
```bash
pip3 install -r requirements.txt
```
Make sure to edit config.hpp and replace the provided domain with yours, you can change the fake name as well as the password as well.
#### To create a Linux binary:
Run the compile.sh script, this will create a file called binary in the bin folder.
#### To Create a Windows Binary:

## Usage
Run payload_generator.py with python3 to create a hex encoded payload, then update or create a txt record for your domain, make sure that the **TTL is set to 300 seconds!!!**