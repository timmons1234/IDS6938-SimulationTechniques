#Homework 1 : The Jello Cube (Continuous Simulation Assignment
## IDS6938-Simulation Techniques - [University of Central Florida](http://www.ist.ucf.edu/grad/)


This is the framework for homework #1. Please first read the [homework writeup](HomeWork%231.pdf).

The assignment is due: Monday, February 27 at 11:59PM (EST)

| undeformed jello  | deformed jello |
| ------------- | ------------- |
| ![](images/undeformed3.png?raw=true)  | ![](images/deformed3.png?raw=true) |



## Part 1 Files
| Name | File |
| ---- | ---- |
| Data Export   | [files/Numeric.Analysis.xlsx] [File-a] |
| Method Graph  | [files/method.comparison.png] [File-b] |
| Error Graph   | [files/error.comparison.png]  [File-c] |
| 3 point RK4   | [files/rk4.comparison.png]    [File-d] |
| 3 point Error | [files/rk4.error.value.png]   [File-e] |

   [File-a]: <https://github.com/timmons1234/IDS6938-SimulationTechniques/tree/master/Homework1/files/Numeric.Analysis.xlsx>
   [File-b]: <https://github.com/timmons1234/IDS6938-SimulationTechniques/tree/master/Homework1/files/method.comparison.png>
   [File-c]: <https://github.com/timmons1234/IDS6938-SimulationTechniques/tree/master/Homework1/files/error.comparison.png>
   [File-d]: <https://github.com/timmons1234/IDS6938-SimulationTechniques/tree/master/Homework1/files/rk4.comparison.png>
   [File-e]: <https://github.com/timmons1234/IDS6938-SimulationTechniques/tree/master/Homework1/files/rk4.error.value.png>

## Part 1 - A

Integral: e^(x/2) * sin 5x

## Part 1 - B
Df function
```sh
double df(double x, double y)            //function for defining dy/dx
{
	 return y - .5* pow(M_E, (.5 * x))*sin(5 * x) + 5 * pow(M_E, (.5 * x))*cos(5 * x);
}
```
Exact function
```sh
double exact(double x)            //function for defining dy/dx
{
	return pow(M_E, (.5* x)) *sin(5 * x);
}
```
   
## Part 1 - C
| Item | File           |
| ---- | ----           |
| Data Output | [files/integration.md]   [File-f] |
   [File-f]: <https://github.com/timmons1234/IDS6938-SimulationTechniques/tree/master/Homework1/files/integration.md>

## Part 1-D
| Graph | File |
| ----- | ---- |
| Error Graph   | [files/error.comparison.png]  [File-c] |

## Part 1-E
| Graph | File |
| ----- | ---- |
| 3 point RK4   | [files/rk4.comparison.png]    [File-d] |
| 3 point Error | [files/rk4.error.value.png]   [File-e] |

## Part 1-F
 - 1) As we move from RK1 to RK4 we increase the sampling of the values along the curvle. The more samples we take, the more accurate the final answer
 - 2) As we increase the X value we diverge from the exact value. While RK4 maintaines better accuracy due to greater sampling, given a high enough X it will begin to diverge
 - 3) The larger the step size, the faster we see divergence. 3 points vs 100 points allows RK4 to show high levels of divergence 
 - 4) RK4 is the better method because it takes greater sampling into account, but only when we maintain a small step size. 
 
 ## Part 2 Programming the cube
 - 1) Euler, Midpoint are implemented. Initially Midpoint had an error which made the cube fly sideways but has been resolved. 
 - 2) Forces was computed using the assistance in Piazza, then then an implemented force equation. I think it's right?
 - 3a) Floor collision is implemented. Ran into an issue where it wasn't loading the floor which was resolved through an absolute file path.
 - 3b) Cylindercollision is not implemented. I took an initial shot at it, but it's beyond my programming ability.
 - 4) Resolve contact and collision are both implemented. cube bounces off the floor and spring forces seem to work as appropriate
 - 5) Extra springs are added, but incorrectly based on initial implementation. will try to implement using the hint posted on Piazza
 - 6) Currently have not added additional features. Plan to add a video of my bouncing cube, unsure if there are other items i can implement
 
 ## Part 3 - Written Questions
 - 1) the effects of Ks and Kd parameters are
 - 2) 
 - 3) 
 - 4) The jello cube behaves realistically as far as gravity is concerned. With better implemented springs and collision models i would expect it to react realistically as well. The various spring constants might need additional tuning to resolve conflicts. I chose RK4 method. When using RK1 or RK2 the cube would destabalize and explode given enough time. 
 - 5) 
 
 ## Part 4 - Final Report
