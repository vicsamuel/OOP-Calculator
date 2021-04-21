<h1 align="center">Object Oriented Programming - Case Study Calculator</h1>

<p align="center">
  <img src=/calc.jpeg>
    <br>Figure 1</br>
</p>

**Goals**
- Develop an object-oriented calculator (basic PEMDAS functionality) using _patterns & frameworks_
- Demonstrate commonality/variability analysis in the context of a concrete application
- Illustratge how Object Oriented frameworks can be combined with the generic programming features of C++ & STL
- Compare & contrast different Object Oriented design approaches and apply many of the patterns

**Overview of the Calculator**
- Designed to handle basic math expressions for example:
<p align="center">
  2 + 7
  <br>6 - 3 / 8 * 9
  <br>(6 % 2) + 7 / 87 - (329 + 9)
  </br>
</p>
- Calculator should be extensible to handle new math operators like square root, powers, etc.
  

**MPC - Makefile Project Creator**
MPC is used thoughout this entire project to help with creating the makefiles for this project. The software is relatively simple to use though it must be used in a Linux environment
- Software can be downloaded from their Github at the following link: [https://github.com/DOCGroup/MPC](https://github.com/DOCGroup/MPC)

**Part 1 - Composition**
To warm up my C++ skills I will be designing the libraries for the Array, Stack, Queue, and Fixed Array classes. I will also be adding a Base Array class to prevent the issue of the Liskov Substitution Principle. No standard library classes will be used for this and these base classes will be used for the other three parts of this project. This part had to be redone because my project was failing in the later sections.

**Part 2 - Calculator (1)**
For this part of the project we will be extending our written library files into creating our Calculator. The algorithm for converting an Infix to Postfix Expression will be used as it allows the expression to be processed in O(n) time. In addition to this the following requirements must be satisfied:
- The Command Pattern will be used to evaluate the Postfix Expression
- The Abstract Factory pattern will be used to create the commands based on parsing the Infix Expression to convert it into a Postfix expression

**Part 3 - Calculator (2)**
The third part of this project is similar to the last part in that the same expression will be evaluated, but this time different patterns will be used. The Infix to PostFix expression was tough to work with and had a high complexity so that will need to be abstracted as well. The following requirements will be satisfied:
- The Composite, Visitor, and Builder patterns will be used to design and implement this version of the expression evaluator
- A Facade pattern will be implemented to improve the complexity of the Infix to Postfix evaluator

**Part 4 - Shared Library**
This final part of this project was more of an exploration into the benefits of MPC and how shared libraries could be created and used. This shows that these binaries can be resolved at runtime, instead of linked directly into the library at compile time. The goal of shared libraries is to reduce the amount of duplicate code linked to an executable.

**Software Required**
- A GCC Compiler was used
- Visual Studio Code was used, download link: [https://code.visualstudio.com/Download](https://code.visualstudio.com/Download)
