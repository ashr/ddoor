import binascii

header = b"!c"
linux_cmd = b"ps aux"
windows_cmd = b"dir"
encoded_header = binascii.hexlify(header + linux_cmd + b"!&" + windows_cmd).decode("utf-8")
print("generated command: {}".format(encoded_header))