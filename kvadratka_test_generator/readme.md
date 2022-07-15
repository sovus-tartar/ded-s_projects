# Test generator for kvadratka
## Installation
### To compile run:
   
        make
For successful compilation you have to have all repo cloned because of dependencies with kvadratka project

## Generation
1. To generate tests run 
        
        ./test_generator
2. Enter number of tests you want to get
3. To put tests to file you may use ">>" in linux terminal

## The format of tests

        3
        1 2 1 1 -1
        0 0 0 -1
        0 2 -4 1 2

3 - number of tests
    
1 2 1 - coefficients of ax^2 + bx + c
   
1 - number of solutions. If -1 it means that all x are solutions

-1 - solution(s)

        