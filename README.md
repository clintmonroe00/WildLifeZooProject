# Cplusplus-Program

# Summarize the project and what problem it was solving.
This was the third project for my CS-210 Programming Languages class at SNHU. The brief asked me to create a proof of concept for an RFID tracking system that would allow for the creation, viewing, and deletion of animals for tracking purposes. Additionally, it should be able to save to and load data from a .txt file.

# What did you do particularly well?
I spent a great deal of time going beyond the course resources to understand the factory design pattern when approaching this project. I felt that it would reduce a lot of potential redundancy and make adding new animal types and subtypes significantly easier in the future.

# Where could you enhance your code? How would these improvement make your code more efficient, secure, etc?
One major area of improvement for this could would be the file management, specifically, the loading of data from the file and adding objects to a vector. I was unable to complete this portion of the project due to time constraints and would very much like to work on this more eventually. I also do not like the way I managed the removal of objects from the vector. I was attempting to use std::vector::erase, but could not get the code to work properly.

# Did you find writing any piece of this code challenging and how did you overcome this? What tools and/or resources are you adding to your support network?
I found a great deal of this assignment challening. Going beyond some of the coursework and committing to use a design pattern made this quite a challenge. I used books on design patterns, the zyBooks materials, YouTube, and Stack Overflow to answer specific questions or help me solve problematic areas.

# What skills from this project will be particularly transferable to other projects and/or course work?
I believe that everything I did with this project is transferable. I managed my time to the best of my ability and planned out what I wanted to accomplish within certain amounts of time. I built out methods slowly and made sure to compile and run often to reduce my time chasing bugs later. I also spent a lot of time becoming familiar with concepts beyond what was reviewed in this course that I believe will come in handy later (ie- design patterns).

# How did you make this program maintainable, readable, and adaptable?
I made this program maintainable by using the factory design pattern. I strongly believe that this would reduce the amount of new code that would need to be written any time a new type or subtype of animal would be added to the program. I aimed to keep my code readable by using whitespace properly, keeping smaller pieces aligned when possible and separating blocks with lines when appropriate. I also made it a point to review my comments to ensure that they properly expressed my thoughts or notes on each line or block of code. 
