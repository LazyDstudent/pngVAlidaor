# pngValidator
**It ain't that safe and doesn't check the file structure. I will later add the full checks after I finish my exams.**

A super simple PNG validator in C to help me write checks later.  
This program checks if a given file is a valid PNG file by reading its first 8 bytes (the PNG file signature) and comparing them to the standard PNG header.

How?

Byte 0:   25  (0x25)  --> %  
Byte 1:   50  (0x50)  --> P  
Byte 2:   44  (0x44)  --> D  
Byte 3:   46  (0x46)  --> F  
Byte 4:   2D  (0x2D)  --> -  
Byte 5:   31  (0x31)  --> 1  
Byte 6:   2E  (0x2E)  --> .  
Byte 7:   35  (0x35)  --> 5  

Compare it with the file you give. If they both have the first 8 bytes correct, then it passes.

+------------------+------------------+------------------------+-------------------+  
| PNG Signature    | IHDR Chunk       | Other Chunks (e.g., IDAT, PLTE) | IEND Chunk      |  
| (8 bytes)        | (13 bytes)       | (Variable length)       | (12 bytes)        |  
+------------------+------------------+------------------------+-------------------+
