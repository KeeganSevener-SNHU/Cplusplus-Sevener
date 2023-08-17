# Cplusplus-Sevener

# Summarize the project and what problem it was solving.
	I was tasked to create a program that backups a dataset of sold items and allows a user to view that information in different ways. The user can search for a specific sold item and return its sales number, printer all the items and their quantity sold, or print a histogram of the sold items.


# What did you do particularly well?
	Everything turned out great. I am particularly proud of the histogram. I wanted to make it as legible as possible, so I developed a couple of loops to ensure the formatting is consistent. I also found a library to import and alterante the colors of each line in the histogram, yellow, blue, yellow, and so on. This makes it easier to discern which line belongs to each item.


# Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?
	I am not sure what enhancements to implement. The code is as minimal as I could make it, but maybe it could be reduced more. Fewer lines of code means less potential for bugs, the code is easier to navigate, and more secure. The simpler the code the better.


# Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?
	I had an issue with wrting the FindItem function. This was a loop in the FileBackUp. When I changed it to its own function, the syntax had no errors, but the vector never updated the qunaties for the item objects. The issue was my vector was passed by value instead of reference, so the memory address returned was wiped upon exit of the function,since the function was deleting its copy. Finding this error really helped me appreciate the logic of pointers and memory. I did not have any additional tools or resources to help me. All I used were print statements at various stages to narrow down the location of the logic error.


# What skills from this project will be particularly transferable to other projects or course work?
	C++ is a very widely use programming language. Understanding the language alone opens a wide range of opportunities. However, I think the most useful skill is using header files and separating the code out by file. Having a main (driver) file, a header file, and a .cpp file -which contains many of the function definitions from the header, pruces code that is easier to navigate. I initially contemplated creating two classes, one for the ItemsSold to store their information, and one class for the menu functions. However, a second class for just two functions seemed a bit much, so I stuck to a single class for KISS (keep it simple, stupid) principles.


# How did you make this program maintainable, readable, and adaptable?
	I was sure to make the code as minimal as possible. There was a loop in the FileBackUp function that I separated into its own function. The loop would have been copied and re-used for option 1. By making it its own function, the code has fewer lines, making it easier to adapt in other programs and maintain. Variables are named to be as clear and concise as possible, and comments are included throughout to explain the purpose of the different functions and variables in the program.
