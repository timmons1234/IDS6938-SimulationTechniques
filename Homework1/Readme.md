#Homework 1 : The Jello Cube (Continuous Simulation Assignment
## IDS6938-Simulation Techniques - [University of Central Florida](http://www.ist.ucf.edu/grad/)


This is homework #1 by William Nettervirlle. 
[Homework writeup](HomeWork%231.pdf).

The assignment is due: Wednesday, March 01 at 11:59PM (EST)

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
 - 1) As we move from RK1 to RK4 we increase the sampling of the values along the curve. The more samples we take, the more accurate the final answer
 - 2) As we increase the X value we diverge from the exact value. While RK4 maintaines better accuracy due to greater sampling, given a high enough X it will begin to diverge
 - 3) The larger the step size, the faster we see divergence. 3 points vs 100 points allows RK4 to show high levels of divergence 
 - 4) RK4 is the better method because it takes greater sampling into account, but only when we maintain a small step size. 
 
 ## Part 2 Programming the cube
 - 1) Euler, Midpoint are implemented. Initially Midpoint had an error which made the cube fly sideways but has been resolved. 
 - 2) Forces was computed using the assistance in Piazza, then an implemented force equation. I think it's right?
 - 3a) Floor collision is implemented. Ran into an issue where it wasn't loading the floor which was resolved through an absolute file path.
 - 3b) Cylindercollision is not implemented. I took an initial shot at it, but it's beyond my programming ability.
 - 3bb) In floor collision, we're looking at a 2d plane. In Cylindercollision we need to look at it from 3 dimensions.
 - 3cc) Another aspect of this is the floor collision should reflect in an upward direction. Cylinder collision needs to look at the angle between the two end points to define the perpendicular. From there gravity will affect the cube as normal. 
 - 3dd) Another key aspect is using the defined radius and plotting the contact zone out in a line based on the end points. 
 - 3ee) I'd imagine if you could implement a cylinder, a sphere would be easy. Squares and rectangles would be the same basic concepts. 
 - 4) Resolve contact and collision are both implemented. cube bounces off the floor and spring forces seem to work as appropriate. From what i have, there isnt a good way to test this. If I've implemented a flawed model, especially over multiple components it's even harder to define if what i have if valid. 
 - 5) Extra springs are added, but incorrectly based on initial implementation. will try to implement using the hint posted on Piazza. It though implement shear springs from x to X+1,y+1 and x to X-1,y-1 without going outside of the bounds of the cube. Bend springs could implement as x to X+2, or y to Y+2
 - 6) Currently have not added additional features. Plan to add a video of my bouncing cube, unsure if there are other items i can implement
 - 6.1) Going to add notes here for any of the extra features, and ideas on how they could have been implemented. 
 - 6a) Cube and Sphere ideas listed above within point 3. One of the interesting videoes i saw which implemented this was where a cube fell between two spheres and had a smushing effect. 
 - 6b) We've really only implemented gravity and reflected force through springs. To generate this point you would need to implement a new forces which affects user chosen particles.
 - 6c) Same as above, but with a push effect. If implemented well, could base force generated based on mouse movements angry birds style, or as building forces based on duration of mouse click. 
 - 6d) This could be a secondary ground plane. Assign a mesh to it. Could turn into a sort of slide effect. Potentially assign multiple overlapping cylinders and let cylindercollision handle the mechanics. 
 - 6e) Unsure how to implement.
 - 6f) Unsure how to implement. Likely involves spawning a second cube at a new location, then iterating over the second cubes partles on every pass. maybe a for loop around your main section where you resolve the world and contacts for each cube. 
 - 6g) more stable integration methods would likely further slow down the cube. Not sure what any of these integration methods are. 
 - 6h) (bounce movie link)
 - 6i) (second movie with spring stiffness)
 - 6j) Unsure how to implement. 
 - 6k)  
 
 
 ## Part 3 - Written Questions
 - 1) Ks and Kd refer to the stiffness and damping effects granted to a spring. As Ks increases, you generate more kinetic force within the spring. As Kd increases it grants a higher damping effect to reduce kinetic force from the spring. As Ks increases you get more bounciness. As Kd increase it resets back to a static position faster. Each value has a tipping point. If Kd is too high, it damps the kinetic force before it can do anything. If Ks is too high you have too much reactive force. 
 - 2) The additional checkes are expensive. A potentially better way to handle it would be to use RK1 initially until you hit a closer epsilon and then convert to rk2 until you get to a closer episolon then convert to rk4. I think this method was explained with the bunny, we do specific checks based on our area based on what we expect to interact with. 
 - 3) Bridge physics simulation. Any sort of combined material simulator, like maybe the effect of hurricane fource winds on the exterior of a building. Hair, grass and cloth were all linked within the course. 
 - 4) The jello cube behaves realistically as far as gravity is concerned. With better implemented springs and collision models i would expect it to react realistically as well. The various spring constants might need additional tuning to resolve conflicts. I chose RK4 method. When using RK1 or RK2 the cube would destabalize and explode given enough time. 
 - 5) Link the molecules together, use a low Ks and minimal Kd. Implement some sort of penaly for friction. Water has unique properties which would need to be accounted for. 
 
 ## Part 4 - Final Report


| undeformed jello  | deformed jello |
| ------------- | ------------- |
| ![](images/undeformed3.png?raw=true)  | ![](images/deformed3.png?raw=true) |
