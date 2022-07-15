# Square equations solver
This program solves square equations.
## Installation

1. Make sure that gcc and git is installed on your computer.

2. Then you need to run:            

        git clone https://github.com/sovus-tartar/ded-s_projects

3. Then go to the "kvadratka" directory:

        cd ded's_projects/kvadratka

4. Run make:

        make
   
6. Enjoy!
   
## Tests

0. Manually created test is "111.in"
1. The test generator is included in folder tests.
2. To generate tests you have to run "test_generator" and put a number of tests you want to be. 
3. It will make tests in format: 
   
        3
        1 2 1 1 -1
        0 0 0 -1
        0 2 -4 1 2
    3 - number of tests
    
    1 2 1 - coefficients of ax^2 + bx + c
    
    1 - number of solutions. If -1 it means that all x are solutions

    -1 - solution(s)

4. To run kvadratka in test mode use "-t" parameter