####  base64 encoder in Python(encodes a String in base64)
import base64 #Python module for working with base64

inputString = input("Enter your string to encode in base-64: ")
#Converting the input string to bytes
inputStringInBytes = inputString.encode("utf-8")
#Now Converting the bytes to base64 encoded bytes
base64_bytes = base64.b64encode(inputStringInBytes)
print(base64_bytes)
print(type(base64_bytes))
#this converts the base64 bytes to a base 64 string
base64_string = base64_bytes.decode('utf-8')
print("Encoded String: "+base64_string)
print(type(base64_string))
#### So we have now succesfully created a base64 encoder

#### base64 decoder in python(Decode base64 to String)
#import base64 #Python module for working with base64

base64_string = input("Enter the base64 string to decode: ")
#Converting the base64 string to bytes
base64_bytes = base64_string.encode('utf-8')
#decoding the base64 bytes to normal bytes
output_string_bytes = base64.b64decode(base64_bytes)
print(output_string_bytes)
print(type(output_string_bytes))
#convert the bytes to string
output_string = output_string_bytes.decode("utf-8")
print("Decoded String: "+output_string)
print(type(output_string))
### This is the required python base64 decoder


